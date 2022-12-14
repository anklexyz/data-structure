//
// Created by 徐彬斌 on 2022/12/12.
//

#include "e6.h"

int LocateVex(MGraph G, VertexType u)
{ /* 初始条件:图G存在,u和G中顶点有相同特征 */
    /* 操作结果:若G中存在顶点u,则返回该顶点在图中位置;否则返回-1 */
    int i;
    for (i = 0; i < G.vexnum; ++i)
        if (strcmp(u, G.vexs[i]) == 0)
            return i;
    return -1;
}

Status CreateDN(MGraph *G)
{ /* 采用数组(邻接矩阵)表示法,构造有向网G */
    int i, j, k, w, IncInfo;
    char s[MAX_INFO], *info;
    VertexType va, vb;
    printf("请输入交通网络的城市个数,路线总数：");
    scanf("%d,%d", &(*G).vexnum, &(*G).arcnum);
    printf("请输入%d个城市名(<%d个汉字):\n", (*G).vexnum, MAX_NAME / 2);
    for (i = 0; i < (*G).vexnum; ++i) /* 构造顶点向量 */
        scanf("%s", (*G).vexs[i]);
    for (i = 0; i < (*G).vexnum; ++i) /* 初始化邻接矩阵 */
        for (j = 0; j < (*G).vexnum; ++j)
        {
            (*G).arcs[i][j].adj = INFINITY; /* 网 */
            (*G).arcs[i][j].info = NULL;
        }
    printf("请输入%d条路线的起点 终点 距离(以空格作为间隔): \n", (*G).arcnum);
    for (k = 0; k < (*G).arcnum; ++k)
    {
        scanf("%s%s%d%*c", va, vb, &w);  /* %*c吃掉回车符 */
        i = LocateVex(*G, va);
        j = LocateVex(*G, vb);
        (*G).arcs[i][j].adj = w; /* 有向网 */
        if (IncInfo)
        {
            printf("请输入该路线的相关信息: ");
            gets(s);
            w = strlen(s);
            if (w)
            {
                info = (char *) malloc((w + 1) * sizeof(char));
                strcpy(info, s);
                (*G).arcs[i][j].info = info; /* 有向 */
            }
        }
    }
    (*G).kind = DN;
    return OK;
}

void
ShortestPath_DIJ(MGraph G, int v0, PathMatrix *P, ShortPathTable *D)
{ /* 用Dijkstra算法求有向网G的v0顶点到其余顶点v的最短路径P[v]及带权长度 */
    /* D[v]。若P[v][w]为TRUE,则w是从v0到v当前求得最短路径上的顶点。 */
    /* final[v]为TRUE当且仅当v∈S,即已经求得从v0到v的最短路径 算法7.15 */
    int v, w, i, j, min;
    Status final[MAX_VERTEX_NUM];
    for (v = 0; v < G.vexnum; ++v)
    {
        final[v] = FALSE;
        (*D)[v] = G.arcs[v0][v].adj;
        for (w = 0; w < G.vexnum; ++w)
            (*P)[v][w] = FALSE; /* 设空路径 */
        if ((*D)[v] < INFINITY)
        {
            (*P)[v][v0] = TRUE;
            (*P)[v][v] = TRUE;
        }
    }
    (*D)[v0] = 0;
    final[v0] = TRUE; /* 初始化,v0顶点属于S集 */
    for (i = 1; i < G.vexnum; ++i) /* 其余G.vexnum-1个顶点 */
    { /* 开始主循环,每次求得v0到某个v顶点的最短路径,并加v到S集 */
        min = INFINITY; /* 当前所知离v0顶点的最近距离 */
        for (w = 0; w < G.vexnum; ++w)
            if (!final[w]) /* w顶点在V-S中 */
                if ((*D)[w] < min)
                {
                    v = w;
                    min = (*D)[w];
                } /* w顶点离v0顶点更近 */
        final[v] = TRUE; /* 离v0顶点最近的v加入S集 */
        for (w = 0; w < G.vexnum; ++w) /* 更新当前最短路径及距离 */
        {
            if (!final[w] && min < INFINITY && G.arcs[v][w].adj < INFINITY &&
                (min + G.arcs[v][w].adj < (*D)[w]))
            { /* 修改D[w]和P[w],w∈V-S */
                (*D)[w] = min + G.arcs[v][w].adj;
                for (j = 0; j < G.vexnum; ++j)
                    (*P)[w][j] = (*P)[v][j];
                (*P)[w][w] = TRUE;
            }
        }
    }
}

void main()
{
    int i, j, v0 = 0; /* v0为源点 */
    MGraph g;
    PathMatrix p;
    ShortPathTable d;
    CreateDN(&g);
    ShortestPath_DIJ(g, v0, &p, &d);
//   printf("最短路径数组p[i][j]如下:\n");
//   for(i=0;i<g.vexnum;++i)
//   {
//     for(j=0;j<g.vexnum;++j)
//       printf("%2d",p[i][j]);
//     printf("\n");
//   }
    printf("%s到各城市的最短路径长度为：\n", g.vexs[0]);
    for (i = 1; i < g.vexnum; ++i)
        printf("%s-%s:%d\n", g.vexs[0], g.vexs[i], d[i]);
}
