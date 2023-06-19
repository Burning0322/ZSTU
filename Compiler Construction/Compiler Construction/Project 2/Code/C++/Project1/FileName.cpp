#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>

using namespace std;

string typeName[6] = { "undefine","number","identifier","leftBracket","rightBracket","endInput" };
enum MyTokenType
{
	undefine, number, identifier, leftBracket, rightBracket, endInput
};

struct Token
{
	MyTokenType tokenType;
	string value;
};

//采用孩子兄弟表示法的树节点
struct TreeNode
{	
	string flag = "";
	Token* token = NULL;
	TreeNode* firstChild = NULL;
	TreeNode* nextSibling = NULL;
};

void input();
TreeNode* lexp();
TreeNode* atom();
TreeNode* list();
TreeNode* lexp_seq();
TreeNode* lexp_seq1();

TreeNode* match();
TreeNode* errorNode();

void printTree(TreeNode* head, int depth = 0, bool isFirst = false);

Token inputToken[1024];
int tokenNumber = 0;
int curPos = 0;
bool error = false;

int main() {
	input();
	curPos = 0;
	while (inputToken[curPos].tokenType != endInput && !error)
	{
		TreeNode* head = lexp();
		if (error)
			cout << "解析token失败，发生错误的结点如下所示：" << endl;
		printTree(head);
	}

	return 0;
}

//可将输入按实验一识别为Token字符串，但这里仅做简单判断(一个字符为一个Token)
void input() {
	cout << "请输入：";
	char ch;
	while ((ch = getchar()) != '\n') {
		inputToken[tokenNumber].value = ch;
		if (ch == '(')
			inputToken[tokenNumber].tokenType = leftBracket;
		else if (ch == ')')
			inputToken[tokenNumber].tokenType = rightBracket;
		else if (ch >= '0' && ch <= '9')
			inputToken[tokenNumber].tokenType = number;
		else if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
			inputToken[tokenNumber].tokenType = identifier;
		else
			inputToken[tokenNumber].tokenType = undefine;
		tokenNumber++;
	}
	inputToken[tokenNumber++].tokenType = endInput;
}

TreeNode* lexp() {
	TreeNode* node = new TreeNode;
	node->flag = "lexp";
	switch (inputToken[curPos].tokenType)
	{
	case number:
	case identifier:
		node->firstChild = atom();
		break;
	case leftBracket:
		node->firstChild = list();
		break;
	default:
		node = errorNode();
		error = true;
		break;
	}
	return node;
}

TreeNode* atom() {
	TreeNode* node = new TreeNode;
	node->flag = "atom";
	switch (inputToken[curPos].tokenType)
	{
	case number:
	case identifier:
		node->firstChild = match();
		break;
	default:
		node = errorNode();
		error = true;
		break;
	}
	return node;
}

TreeNode* list() {
	TreeNode* node = new TreeNode;
	node->flag = "list";
	switch (inputToken[curPos].tokenType)
	{
	case leftBracket: {
		TreeNode* tNode = node->firstChild = match();
		tNode = tNode->nextSibling = lexp_seq();
		if (error)
			return node;
		tNode = tNode->nextSibling = match();
		break;
	}
	default:
		node = errorNode();
		error = true;
		break;
	}
	return node;
}

TreeNode* lexp_seq() {
	TreeNode* node = new TreeNode;
	node->flag = "lexp_seq";
	switch (inputToken[curPos].tokenType)
	{
	case number:
	case identifier:
	case leftBracket: {
		TreeNode* tNode = node->firstChild = lexp();
		if (error)
			return node;
		tNode = tNode->nextSibling = lexp_seq1();
		break;
	}
	default:
		node = errorNode();
		error = true;
		break;
	}
	return node;
}

TreeNode* lexp_seq1() {
	TreeNode* node = new TreeNode;
	node->flag = "lexp_seq'";
	switch (inputToken[curPos].tokenType)
	{
	case number:
	case identifier:
	case leftBracket: {
		TreeNode* tNode = node->firstChild = lexp();
		if (error)
			return node;
		tNode = tNode->nextSibling = lexp_seq1();
		break;
	}
	case rightBracket:
		(node->firstChild = new TreeNode)->flag = "empty";
		break;
	default:
		node = errorNode();
		error = true;
		break;
	}
	return node;
}

TreeNode* match() {
	TreeNode* newNode = new TreeNode;
	newNode->flag = "match";
	newNode->firstChild = newNode->nextSibling = NULL;
	newNode->token = &(inputToken[curPos++]);

	return newNode;
}

TreeNode* errorNode() {
	TreeNode* errorNode = new TreeNode;
	errorNode->flag = "error";
	errorNode->firstChild = errorNode->nextSibling = NULL;
	errorNode->token = &(inputToken[curPos++]);

	return errorNode;
}

void printTree(TreeNode* head, int depth /*defalut=0*/, bool isFirst /*default=false*/) {
	if (head == NULL)
		return;
	int i;
	for (i = 0; i < depth - 1; i++)
		cout << "\t |";
	if (i < depth)
		cout << (isFirst ? "\t↖" : "\t |");
	if (head->flag == "match") {
		MyTokenType type = head->token->tokenType;
		string value = head->token->value;
		cout << typeName[type] << ':';
		//匹配，改变颜色为绿色
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
		cout << value << endl;
		//改回输出颜色
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	}
	else
	{
		//发生错误的结点，用红色输出
		if (head->flag == "error")
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
		cout << head->flag << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		printTree(head->firstChild, depth + 1, true);
	}
	printTree(head->nextSibling, depth);
}
