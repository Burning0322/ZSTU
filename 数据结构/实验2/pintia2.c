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

    void createTree(Tree *T) {
        char c;
        scanf(" %c", &c);

        if (c == '#') {
            //树的分支
            *T = NULL;
        } else {
            //申请内存
            *T = (Tree)malloc(sizeof(TreeNode));
            //字符c存入新分配的内存的data
            (*T)->data = c;
            createTree(&(*T)->left);
            createTree(&(*T)->right);
        }
    }

    int findPath(Tree root, char target, char path[], int pathIndex) {
        //当前节点为空
        if (root == NULL) {
            return 0;
        }
        //如果当前节点不为空，将当前的节点的数据加入path
        path[pathIndex] = root->data;
        pathIndex++;

        //当前节点等于目标字符
        if (root->data == target) {
            // 输出路径
            for (int i = 0; i < pathIndex; i++) {
                printf("%c ", path[i]);
            }
            printf("\n");
            return 1;
        }

        if (findPath(root->left, target, path, pathIndex) || findPath(root->right, target, path, pathIndex)) {
            return 1;
        }

        return 0;
    }

    void freeTree(Tree root) {
        //当前节点为空
        if (root == NULL) {
            return;
        }

        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }

    int main() {
        Tree root = NULL;
        createTree(&root);

        char target;
        scanf(" %c", &target);

        char path[100]; // 假设路径不超过100个字符
        int pathIndex = 0;

        if (!findPath(root, target, path, pathIndex)) {
            printf("Node not found in the tree.\n");
        }

        freeTree(root);

        return 0;
    }
