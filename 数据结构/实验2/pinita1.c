#include <stdio.h>
#include <stdlib.h>


//定义树节点结构定义
typedef struct TreeNode {
    //存储的节点
    char data;
    //左孩子
    struct TreeNode *left;
    //右孩子
    struct TreeNode *right;
} TreeNode, *Tree;

//计算叶子节点的个数
int leafCount = 0;

Tree createTree() {
    char c;
    scanf(" %c", &c);

    if (c == '#') {
        return NULL;
    } else {
        //动态分配内存
        Tree newNode = (Tree)malloc(sizeof(TreeNode));
        newNode->data = c;
        newNode->left = createTree();
        newNode->right = createTree();
        
        if (newNode->left == NULL && newNode->right == NULL) {
            leafCount++;
        }

        return newNode;
    }
}

void preOrderTraversal(Tree root) {
    if (root != NULL) {
        printf("%c", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

void inOrderTraversal(Tree root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%c", root->data);
        inOrderTraversal(root->right);
    }
}

void postOrderTraversal(Tree root) {
    if (root != NULL) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%c", root->data);
    }
}

int main() {
    Tree root = createTree();

    if (root != NULL) {
        preOrderTraversal(root);
        printf("\n");
        inOrderTraversal(root);
        printf("\n");
        postOrderTraversal(root);
        printf("\n");
        printf("%d\n", leafCount);
    } else {
        printf("0\n");
    }

    return 0;
}
