#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>

using namespace std;

string typeName[7] = { "undefine","id","leftBracket","rightBracket","addop", "mulop","endInput" };
enum MyTokenType
{
	undefine, id, leftBracket, rightBracket, addop, mulop, endInput
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
TreeNode* E();
TreeNode* E1();
TreeNode* T();
TreeNode* T1();
TreeNode* F();

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
		TreeNode* head = E();
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
		else if (ch == '+')
			inputToken[tokenNumber].tokenType = addop;
		else if (ch == '*')
			inputToken[tokenNumber].tokenType = mulop;
		else if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
			inputToken[tokenNumber].tokenType = id;
		else
			inputToken[tokenNumber].tokenType = undefine;
		tokenNumber++;
	}
	inputToken[tokenNumber++].tokenType = endInput;
}

TreeNode* E() {
	TreeNode* node = new TreeNode;
	node->flag = "E";
	switch (inputToken[curPos].tokenType)
	{
	case id:
	case leftBracket: {
		TreeNode* tNode = node->firstChild = T();
		if (error)
			return node;
		tNode = tNode->nextSibling = E1();
		break;
	}
	default:
		node = errorNode();
		error = true;
		break;
	}
	return node;
}

TreeNode* E1() {
	TreeNode* node = new TreeNode;
	node->flag = "E'";
	switch (inputToken[curPos].tokenType)
	{
	case endInput:
	case rightBracket:
		(node->firstChild = new TreeNode)->flag = "empty";
		break;
	case addop: {
		TreeNode* tNode = node->firstChild = match();
		tNode = tNode->nextSibling = T();
		if (error)
			return node;
		tNode = tNode->nextSibling = E1();
		break;
	}
	default:
		node = errorNode();
		error = true;
		break;
	}
	return node;
}

TreeNode* T() {
	TreeNode* node = new TreeNode;
	node->flag = "T";
	switch (inputToken[curPos].tokenType)
	{
	case id:
	case leftBracket: {
		TreeNode* tNode = node->firstChild = F();
		if (error)
			return node;
		tNode = tNode->nextSibling = T1();
		break;
	}
	default:
		node = errorNode();
		error = true;
		break;
	}
	return node;
}

TreeNode* T1() {
	TreeNode* node = new TreeNode;
	node->flag = "T'";
	switch (inputToken[curPos].tokenType)
	{
	case endInput:
	case rightBracket:
	case addop:
		(node->firstChild = new TreeNode)->flag = "empty";
		break;
	case mulop: {
		TreeNode* tNode = node->firstChild = match();
		tNode = tNode->nextSibling = F();
		if (error)
			return node;
		tNode = tNode->nextSibling = T1();
		break;
	}
	default:
		node = errorNode();
		error = true;
		break;
	}
	return node;
}

TreeNode* F() {
	TreeNode* node = new TreeNode;
	node->flag = "F";
	switch (inputToken[curPos].tokenType)
	{
	case id:
		node->firstChild = match();
		break;
	case leftBracket: {
		TreeNode* tNode = node->firstChild = match();
		tNode = tNode->nextSibling = E();
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
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
		cout << value << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	}
	else
	{
		if (head->flag == "error")
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
		cout << head->flag << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		printTree(head->firstChild, depth + 1, true);
	}
	printTree(head->nextSibling, depth);
}
