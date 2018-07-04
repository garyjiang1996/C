#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define M 10
#define MAXQSIZE 10 	// 最大队列长度(对于循环队列，最大队列长度要减1) 
int visited[M];
typedef int QElemType;
typedef struct ArcNode{
	int adjvex;
	struct ArcNode *nextarc;
//	int info;
}ArcNode;  									//边结点类型
typedef struct VNode{
	char data;
	ArcNode *firstarc;
}VNode,AdjList[M]; 							//头结点  
typedef struct{
	AdjList vertices;  						//邻接表
	int vexnum,arcnum;
}ALGraph;
typedef struct{
	QElemType *base; 	//初始化的动态分配存储空间 
	int front; 			//头指针,若队列不空,指向队列头元素 
	int rear; 			//尾指针,若队列不空,指向队列尾元素的下一个位置 
}SqQueue;

int InitQueue(SqQueue *Q)
{ 	// 构造一个空队列Q 
	(*Q).base=(QElemType *)malloc(MAXQSIZE*sizeof(QElemType));
   	if(!(*Q).base) 							//存储分配失败 
   	{
   		printf("分配失败！！\n");
	   	exit(0);
   	}
   	(*Q).front=(*Q).rear=0;					//置空队列 
   	return OK;
}
int LocateVex(ALGraph G,char u)
{	//返回顶点 u 在图中的位置； 
	// 若原图不存在该顶点，输出Error，并返回控制； 
	int i;
	for (i=0;i<G.vexnum;i++)
    { 
		if(u==G.vertices[i].data) 
			return i; 						//返回顶点位置 
	}
	if (i==G.vexnum) 						//若原图不存在该顶点 
	{
		printf("Error u!\n");
		exit(1);
	}
	
	return 0;
} 
void CreateALGraph_adjlist(ALGraph *G)
{	//邻接表表示方法，构建一个有向图 
	int i,j,k,w; 
	char v1,v2;
	ArcNode *p;
	printf("Input vexnum & arcnum:");			//输入顶点个数和边条数 
	scanf("%d%d",&((*G).vexnum),&((*G).arcnum));
	printf("Input Vertices:"); 					//输入顶点信息 
	for (i=0;i<(*G).vexnum;i++)
    {	
    	getchar();								 
		scanf("%c",&((*G).vertices[i].data));
		(*G).vertices[i].firstarc=NULL;			//邻接表置空 
    }
  	printf("Input Arcs(v1,v2):\n");				//输入图中的所有边 
  	
  	for (k=0;k<(*G).arcnum;k++)
    {
		getchar();
		scanf("%c,%c",&v1,&v2);
		i=LocateVex(*G,v1);						//返回V1，V2的位置 
		j=LocateVex(*G,v2);
		p=(ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex=j;	
//		p->info = w;
		p->nextarc=(*G).vertices[i].firstarc;	//邻接表节点插入 
		(*G).vertices[i].firstarc=p;
	}	
}
void PrintALGraph_adjlist(ALGraph G)
{	//输出邻接表信息，检测图的邻接表是否创建成功 
	int i;
	ArcNode *p;
	printf("生成的邻接表为:\n");
	for(i=0;i<G.vexnum;i++)
	{
		printf("the %d adjlist is :  ",i);
		p=G.vertices[i].firstarc;			//指向该顶点的第一个邻接顶点 
		while(p)
		{
			printf("%d\t",p->adjvex);
			p=p->nextarc;					//指向该顶点的下一个邻接顶点 
		}
		printf("\n");
	}}
void DFS(ALGraph G, int v)
{ 	// 从第V个顶点遍历 
	ArcNode *p;
  	printf("%c  ",G.vertices[v].data);
   	visited[v]=1;							//当前顶点遍历后，visited标记 
    p=G.vertices[v].firstarc;
    while (p)
    {
		if (!visited[p->adjvex]) 
			DFS(G,p->adjvex);
		 p=p->nextarc;
	}
}
void DFSTraverse(ALGraph G)
{	//深度优先搜索对整个图进行遍历；
	//输出深度优先搜索序列； 
	int v;
	for (v=0;v<G.vexnum;++v)
		visited[v]=0;							//visited初始化 
	printf("深度优先搜索序列是:\n"); 
	for (v=0;v<G.vexnum;++v)
		if (!visited[v]) 
			DFS(G,v);							// 对当前节点进行DFS遍历 
	printf("\n");
}
void BFS(ALGraph G,int v)
  { // 从第V个顶点遍历 
  	ArcNode *p;	
	SqQueue Q;									//建立一个循环顺序队列 
    InitQueue(&Q);								//队列置空 
    printf("%c  ",G.vertices[v].data);
    visited[v]=1;							//当前顶点遍历后，visited标记  
   	Q.base[Q.rear]=v;							//顶点V入队 
  	Q.rear=(Q.rear+1)%MAXQSIZE;
   	while (Q.front!=Q.rear)						//队列非空时 
    {
	 	v=Q.base[Q.front];						//出队 
		Q.front=(Q.front+1)%MAXQSIZE;
		p=G.vertices[v].firstarc;
		while (p)
     	{	
		 	if (!visited[p->adjvex])
           	{ 
				printf("%c  ",G.vertices[p->adjvex].data);
	    		visited[p->adjvex]=1;
	    		Q.base[Q.rear]=p->adjvex;		//入队 
	    		Q.rear=(Q.rear+1)%MAXQSIZE;
	  		}
     		p=p->nextarc;
     	}
   	}
}
void BFSTraverse(ALGraph G)
{	//广度优先搜索方法对整个图进行遍历 
	int v;
	for (v=0;v<G.vexnum;++v) 					//visited初始化 
		visited[v]=0;					
	printf("广度优先搜索序列是:\n");
	for (v=0;v<G.vexnum;++v)
		if (!visited[v])
			 BFS(G,v);							//对当前节点进行BFS遍历 
	printf("\n");
}
int main()
{
	ALGraph G;
	
	CreateALGraph_adjlist(&G);					//邻接表表示方法，构建一个图 
	PrintALGraph_adjlist(G);					//输出图的邻接表表示信息 
	DFSTraverse(G);								//深度优先搜索 
	BFSTraverse(G);								//广度优先搜索 
	
	return 0;
}
