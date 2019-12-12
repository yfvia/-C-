#include<stdio.h>
#include<malloc.h>
#define INF 32767	//��������� 
#define MAXV 100	//��󶥵���� 
/*
����ע������ϰ 
*/ 
typedef char InfoType;	//������Ϣ����
//�����㡱���� 
typedef struct{
	int no;	//������ 
	InfoType info;	//������Ϣ 
}VertexType;

//���ڽӾ������� 
typedef struct{
	int edges[MAXV][MAXV];	//�ڽӾ������� 
	int n,e;	//�ڽӾ���Ķ�����n������e 
	VertexType vexs[MAXV];	//�������Ϣ 
}MatGraph;

//���ߡ����� 
typedef struct ANode{
	int adjvex;	//�ߵ��ڽӵ��� tip:���Ǹ�����ͼ������ڽӵ�����ͷ��ָ��ı�� 
	struct ANode *nextarc;	//ָ����һ���� 
	int weight;	//Ȩ�� 
}ArcNode;

//��ͷ��㡱���� 
//�൱�ڱ߹�����һ���������ArcNode 
typedef struct Vnode{
	InfoType info;	//ͷ�����Ϣ 
	int count;	//ͷ���Ķȣ� 
	ArcNode *firstarc;	//ָ���һ���ߣ�  
}VNode;

//���ڽӱ����� 
typedef struct{
	VNode adjlist[MAXV];	//�ڽӱ��ͷ������� 
	int n,e;	//�ڽӱ�Ķ�����n������e 
}AdjGraph;

//����ͼ�ġ��ڽӾ��� �� 
void CreateMat(MatGraph &g, int A[MAXV][MAXV], int n, int e){
	int i,j;
	//���涥���������� 
	g.n=n;
	g.e=e;
	//ͨ����������ʼ�������ڽӱ��Ӷ�ά����A�������� 
	for(i=0;i<g.n;i++)
		for(j=0;j<g.n;j++)
			g.edges[i][j]=A[i][j];
}

//���ͼ�ġ��ڽӾ��� �� 
void DispMat(MatGraph g){
	int i,j;
	//������ά�����������Ϣ 
	for(i=0;i<g.n;i++){
		for(j=0;j<g.n;j++)
			//������ݲ�������󣬾�ֱ���������������� 
			if(g.edges[i][j]!=INF)	printf("%4d",g.edges[i][j]);
			else printf("%4s","��");
		printf("\n");
	}
}

//�������ڽӱ� �� 
void CreateAdj(AdjGraph *&G,int A[MAXV][MAXV],int n,int e){
	int i,j;
	ArcNode *p;	//����һ���� 
	G = (AdjGraph *)malloc(sizeof(AdjGraph));	//���ڽӱ����ռ�
	//���ڽӱ�ÿ��ͷ���� ָ���һ���ߵ�ָ���� ��ʼ�� 
	for(i = 0;i<n;i++)
		G->adjlist[i].firstarc=NULL;
	//�����ڽӾ��� 
	for(i=0;i<n;i++)
		for(j=n-1;j>=0;j--)
			//�������һ���� 
			if(A[i][j]!=0&&A[i][j]!=INF){
				p=(ArcNode *)malloc(sizeof(ArcNode));	//��ǰ�洴���ı߷���ռ� 
				p->adjvex=j;	//�����ߵĽ��ı�� 
				p->weight=A[i][j];	//�ߵ�Ȩ�� 
				//ͷ�巨��first_arc����ͷ����next ��������ָ��ĵ�һ���� 
				//��һ��ʱ�����null����next_arc��֮�󣬶��ǽ�����������һ���߸���next_arc 
				p->nextarc=G->adjlist[i].firstarc;	
				G->adjlist[i].firstarc=p;	//����ͷ���ָ��ĵ�һ���� 
			}
	G->n=n;
	G->e=e;
}

//������ڽӱ� 
void DispAdj(AdjGraph *G){
	ArcNode *p;	//����һ����,��Ϊ���� 
	//�����ڽӱ��ͷ����б� 
	for(int i=0;i<G->n;i++){
		p=G->adjlist[i].firstarc;
		printf("%3d:",i);	//���ͷ����� 
		//����ÿһ���������� 
		while(p!=NULL){
			printf("%3d[%d]-->",p->adjvex,p->weight);
			p=p->nextarc;
		}
		//���ָ��null 
		printf("��\n");
	}
}

//���١��ڽӱ� �� 
void DestoryAdj(AdjGraph *&G){
	ArcNode *pre,*p;	//Ϊ�˱���������
	//���� 
	for(int i=0;i<G->n;i++){
		pre=G->adjlist[i].firstarc;	//ͷ��� 
		if(pre!=NULL){
			p=pre->nextarc;
			while(p!=NULL){
				free(pre);
				pre=p;
				p=p->nextarc;
			}
			//�������һ�� 
			free(pre);
		}	
	}
	//ͼ�Ľ�� 
	free(G);
}

