#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define M 10
#define MAXQSIZE 10 	// �����г���(����ѭ�����У������г���Ҫ��1) 
int visited[M];
typedef int QElemType;
typedef struct ArcNode{
	int adjvex;
	struct ArcNode *nextarc;
//	int info;
}ArcNode;  									//�߽������
typedef struct VNode{
	char data;
	ArcNode *firstarc;
}VNode,AdjList[M]; 							//ͷ���  
typedef struct{
	AdjList vertices;  						//�ڽӱ�
	int vexnum,arcnum;
}ALGraph;
typedef struct{
	QElemType *base; 	//��ʼ���Ķ�̬����洢�ռ� 
	int front; 			//ͷָ��,�����в���,ָ�����ͷԪ�� 
	int rear; 			//βָ��,�����в���,ָ�����βԪ�ص���һ��λ�� 
}SqQueue;

int InitQueue(SqQueue *Q)
{ 	// ����һ���ն���Q 
	(*Q).base=(QElemType *)malloc(MAXQSIZE*sizeof(QElemType));
   	if(!(*Q).base) 							//�洢����ʧ�� 
   	{
   		printf("����ʧ�ܣ���\n");
	   	exit(0);
   	}
   	(*Q).front=(*Q).rear=0;					//�ÿն��� 
   	return OK;
}
int LocateVex(ALGraph G,char u)
{	//���ض��� u ��ͼ�е�λ�ã� 
	// ��ԭͼ�����ڸö��㣬���Error�������ؿ��ƣ� 
	int i;
	for (i=0;i<G.vexnum;i++)
    { 
		if(u==G.vertices[i].data) 
			return i; 						//���ض���λ�� 
	}
	if (i==G.vexnum) 						//��ԭͼ�����ڸö��� 
	{
		printf("Error u!\n");
		exit(1);
	}
	
	return 0;
} 
void CreateALGraph_adjlist(ALGraph *G)
{	//�ڽӱ��ʾ����������һ������ͼ 
	int i,j,k,w; 
	char v1,v2;
	ArcNode *p;
	printf("Input vexnum & arcnum:");			//���붥������ͱ����� 
	scanf("%d%d",&((*G).vexnum),&((*G).arcnum));
	printf("Input Vertices:"); 					//���붥����Ϣ 
	for (i=0;i<(*G).vexnum;i++)
    {	
    	getchar();								 
		scanf("%c",&((*G).vertices[i].data));
		(*G).vertices[i].firstarc=NULL;			//�ڽӱ��ÿ� 
    }
  	printf("Input Arcs(v1,v2):\n");				//����ͼ�е����б� 
  	
  	for (k=0;k<(*G).arcnum;k++)
    {
		getchar();
		scanf("%c,%c",&v1,&v2);
		i=LocateVex(*G,v1);						//����V1��V2��λ�� 
		j=LocateVex(*G,v2);
		p=(ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex=j;	
//		p->info = w;
		p->nextarc=(*G).vertices[i].firstarc;	//�ڽӱ�ڵ���� 
		(*G).vertices[i].firstarc=p;
	}	
}
void PrintALGraph_adjlist(ALGraph G)
{	//����ڽӱ���Ϣ�����ͼ���ڽӱ��Ƿ񴴽��ɹ� 
	int i;
	ArcNode *p;
	printf("���ɵ��ڽӱ�Ϊ:\n");
	for(i=0;i<G.vexnum;i++)
	{
		printf("the %d adjlist is :  ",i);
		p=G.vertices[i].firstarc;			//ָ��ö���ĵ�һ���ڽӶ��� 
		while(p)
		{
			printf("%d\t",p->adjvex);
			p=p->nextarc;					//ָ��ö������һ���ڽӶ��� 
		}
		printf("\n");
	}}
void DFS(ALGraph G, int v)
{ 	// �ӵ�V��������� 
	ArcNode *p;
  	printf("%c  ",G.vertices[v].data);
   	visited[v]=1;							//��ǰ���������visited��� 
    p=G.vertices[v].firstarc;
    while (p)
    {
		if (!visited[p->adjvex]) 
			DFS(G,p->adjvex);
		 p=p->nextarc;
	}
}
void DFSTraverse(ALGraph G)
{	//�����������������ͼ���б�����
	//�����������������У� 
	int v;
	for (v=0;v<G.vexnum;++v)
		visited[v]=0;							//visited��ʼ�� 
	printf("�����������������:\n"); 
	for (v=0;v<G.vexnum;++v)
		if (!visited[v]) 
			DFS(G,v);							// �Ե�ǰ�ڵ����DFS���� 
	printf("\n");
}
void BFS(ALGraph G,int v)
  { // �ӵ�V��������� 
  	ArcNode *p;	
	SqQueue Q;									//����һ��ѭ��˳����� 
    InitQueue(&Q);								//�����ÿ� 
    printf("%c  ",G.vertices[v].data);
    visited[v]=1;							//��ǰ���������visited���  
   	Q.base[Q.rear]=v;							//����V��� 
  	Q.rear=(Q.rear+1)%MAXQSIZE;
   	while (Q.front!=Q.rear)						//���зǿ�ʱ 
    {
	 	v=Q.base[Q.front];						//���� 
		Q.front=(Q.front+1)%MAXQSIZE;
		p=G.vertices[v].firstarc;
		while (p)
     	{	
		 	if (!visited[p->adjvex])
           	{ 
				printf("%c  ",G.vertices[p->adjvex].data);
	    		visited[p->adjvex]=1;
	    		Q.base[Q.rear]=p->adjvex;		//��� 
	    		Q.rear=(Q.rear+1)%MAXQSIZE;
	  		}
     		p=p->nextarc;
     	}
   	}
}
void BFSTraverse(ALGraph G)
{	//���������������������ͼ���б��� 
	int v;
	for (v=0;v<G.vexnum;++v) 					//visited��ʼ�� 
		visited[v]=0;					
	printf("�����������������:\n");
	for (v=0;v<G.vexnum;++v)
		if (!visited[v])
			 BFS(G,v);							//�Ե�ǰ�ڵ����BFS���� 
	printf("\n");
}
int main()
{
	ALGraph G;
	
	CreateALGraph_adjlist(&G);					//�ڽӱ��ʾ����������һ��ͼ 
	PrintALGraph_adjlist(G);					//���ͼ���ڽӱ��ʾ��Ϣ 
	DFSTraverse(G);								//����������� 
	BFSTraverse(G);								//����������� 
	
	return 0;
}
