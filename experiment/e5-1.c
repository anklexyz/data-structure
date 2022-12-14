#include "e5-1.h"

void visitG(char *i)
{
    printf("%s ", i);
}

int LocateVex(ALGraph G, VertexType u)
{
    int i;
    for (i = 0; i < G.vexnum; ++i)
    {
        if (strcmp(u, G.vertices[i].data) == 0)
        {
            return i;
        }
    }
    return FALSE;
}

Status CreateGraph(ALGraph *G)
{
    int i, j, k;
    VertexType va, vb;
    ArcNode *p;
    (*G).vexnum = 10;
    (*G).arcnum = 20;
    printf("**请输入%d个顶点的值:", (*G).vexnum);
    for (i = 0; i < (*G).vexnum; ++i)
    {
        scanf("%s", (*G).vertices[i].data);
        (*G).vertices[i].firstarc = NULL;
    }

    printf("**请顺序输入%d条边的尾和头:\n", (*G).arcnum);
    for (k = 0; k < (*G).arcnum; ++k)
    {
        scanf("%s%s", va, vb);
        i = LocateVex(*G, va);
        j = LocateVex(*G, vb);
        p = (ArcNode *) malloc(sizeof(ArcNode));
        p->adjvex = j;
        p->info = NULL;
        p->nextarc = (*G).vertices[i].firstarc;
        (*G).vertices[i].firstarc = p;
    }
    return OK;
}

Status DestroyGraph(ALGraph *G)
{
    int i;
    ArcNode *p, *q;
    (*G).vexnum = 0;
    (*G).arcnum = 0;
    for (i = 0; i < (*G).vexnum; ++i)
    {
        p = (*G).vertices[i].firstarc;
        while (p)
        {
            q = p->nextarc;
            free(p);
            p = q;
        }
    }
    return OK;
}

VertexType *GetVex(ALGraph G, int v)
{
    if (v >= G.vexnum || v < 0)
    {
        return ERROR;
    }
    return &G.vertices[v].data;
}

int FirstAdjVex(ALGraph G, VertexType v)
{
    ArcNode *p;
    int v1;
    v1 = LocateVex(G, v);
    p = G.vertices[v1].firstarc;
    if (p)
    {
        return p->adjvex;
    } else
    {
        return -1;
    }
}

int NextAdjVex(ALGraph G, VertexType v, VertexType w)
{
    ArcNode *p;
    int v1, w1;
    v1 = LocateVex(G, v);
    w1 = LocateVex(G, w);
    p = G.vertices[v1].firstarc;
    while (p && p->adjvex != w1)
    {
        p = p->nextarc;
    }

    if (!p || !p->nextarc)
    {
        return -1;
    } else
    {
        return p->nextarc->adjvex;
    }
}

Boolean visited[MAX_VERTEX_NUM];

void (*VisitFunc)(char *v);

Status DFS(ALGraph G, int v)
{
    int w;
    VertexType v1, w1;
    strcpy(v1, *GetVex(G, v));
    visited[v] = TRUE;
    VisitFunc(G.vertices[v].data);
    for (w = FirstAdjVex(G, v1); w >= 0; w = NextAdjVex(G, v1, strcpy(w1, *GetVex(G, w))))
    {
        if (!visited[w])
        {
            DFS(G, w);
        }
    }
    return OK;
}

Status DFSTraverse(ALGraph G, void(*Visit)(char *))
{
    int v;
    VisitFunc = Visit;
    for (v = 0; v < G.vexnum; v++)
    {
        visited[v] = FALSE;
    }
    for (v = 0; v < G.vexnum; v++)
    {
        if (!visited[v])
        {
            DFS(G, v);
        }
    }
    printf("\n");
    return OK;
}

Status InitQueue(LinkQueue *Q)
{
    (*Q).front = (*Q).rear = (QueuePtr) malloc(sizeof(QNode));
    if (!(*Q).front)
    {
        return ERROR;
    }
    (*Q).front->next = NULL;
    return OK;
}

Status QueueEmpty(LinkQueue Q)
{
    if (Q.front == Q.rear)
    {
        return TRUE;
    } else
    {
        return FALSE;
    }
}

Status EnQueue(LinkQueue *Q, QElemType e)
{
    QueuePtr p = (QueuePtr) malloc(sizeof(QNode));
    if (!p)
    {
        return ERROR;
    }
    p->data = e;
    p->next = NULL;
    (*Q).rear->next = p;
    (*Q).rear = p;
    return OK;
}

Status DeQueue(LinkQueue *Q, QElemType *e)
{
    QueuePtr p;
    if ((*Q).front == (*Q).rear)
    {
        return ERROR;
    }
    p = (*Q).front->next;
    *e = p->data;
    (*Q).front->next = p->next;
    if ((*Q).rear == p)
    {
        (*Q).rear = (*Q).front;
    }
    free(p);
    return OK;
}

Status BFSTraverse(ALGraph G, void(*Visit)(char *))
{
    int v, u, w;
    VertexType u1, w1;
    LinkQueue Q;
    for (v = 0; v < G.vexnum; ++v)
    {
        visited[v] = FALSE;
    }
    InitQueue(&Q);
    for (v = 0; v < G.vexnum; v++)
    {
        if (!visited[v])
        {
            visited[v] = TRUE;
            Visit(G.vertices[v].data);
            EnQueue(&Q, v);
            while (!QueueEmpty(Q))
            {
                DeQueue(&Q, &u);
                strcpy(u1, *GetVex(G, u));
                for (w = FirstAdjVex(G, u1); w >= 0; w = NextAdjVex(G, u1, strcpy(w1, *GetVex(G, w))))
                {
                    if (!visited[w])
                    {
                        visited[w] = TRUE;
                        Visit(G.vertices[w].data);
                        EnQueue(&Q, w);
                    }
                }
            }
        }
    }
    printf("\n");
    return OK;
}

Status Display(ALGraph G)
{
    int i;
    ArcNode *p;
    printf("----------有向图构建完成!----------\n");
    printf("**%d个顶点：", G.vexnum);
    for (i = 0; i < G.vexnum; ++i)
    {
        printf("%s ", G.vertices[i].data);
    }
    printf("\n**%d条弧(边):\n", G.arcnum);
    for (i = 0; i < G.vexnum; i++)
    {
        p = G.vertices[i].firstarc;
        while (p)
        {
            printf("%s→%s ", G.vertices[i].data, G.vertices[p->adjvex].data);
            p = p->nextarc;
        }
        printf("\n");
    }
    printf("-----------------------------------\n");

    return OK;
}

int main()
{
    ALGraph g;
    CreateGraph(&g);
    Display(g);
    printf("**深度优先搜索:");
    DFSTraverse(g, visitG);
    printf("-----------------------------------\n");
    printf("**宽度优先搜索:");
    BFSTraverse(g, visitG);
    printf("-----------------------------------\n");
    DestroyGraph(&g);
    return 0;
}