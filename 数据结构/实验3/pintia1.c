#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX_NUM 100

typedef struct ArcNode {
    int adjvex;
    struct ArcNode* nextarc;
} ArcNode;

typedef struct {
    char data;
    ArcNode* firstarc;
} VertexNode;

typedef struct {
    VertexNode vertices[MAX_VERTEX_NUM];
    int vexnum, arcnum;
} ALGraph;

void CreateUDG(ALGraph *G) {
    int x, y;
    char c1, c2;
    scanf("%d %d", &G->vexnum, &G->arcnum);
    for (int i = 0; i < G->vexnum; i++) {
        scanf(" %c", &G->vertices[i].data);
        G->vertices[i].firstarc = NULL; // 初始化
    }
    for (int i = 0; i < G->arcnum; i++) {
        scanf(" %c %c", &c1, &c2);
        for (int j = 0; j < G->vexnum; j++) {
            if (G->vertices[j].data == c1)
                x = j;
            if (G->vertices[j].data == c2)
                y = j;
        }
        // 头插法
        ArcNode* p = (ArcNode*)malloc(sizeof(ArcNode));
        p->adjvex = y;
        p->nextarc = G->vertices[x].firstarc;
        G->vertices[x].firstarc = p;
        // 因为是无向图，所以要别忘了另一条边
        p = (ArcNode*)malloc(sizeof(ArcNode));
        p->adjvex = x;
        p->nextarc = G->vertices[y].firstarc;
        G->vertices[y].firstarc = p;
    }
}

int main() {
    ALGraph G;
    CreateUDG(&G);  
    int i , j,sum=0;
    ArcNode * p; 
    for(i = 0 ; i < G.vexnum ; ++i){
        sum=0;
        p=G.vertices[i].firstarc;
        for(; p!=NULL; p=p->nextarc){
                sum+=1;
        }
        if(i==0)
            printf("%d",sum);
        else
            printf(" %d",sum);
    }
    return 0;
}
