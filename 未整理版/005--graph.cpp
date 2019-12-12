#include<stdio.h>
#include<malloc.h>
#define INF 32767	//定义无穷大 
#define MAXV 100	//最大顶点个数 
/*
完善注释来复习 
*/ 
typedef char InfoType;	//定义信息类型
//“顶点”类型 
typedef struct{
	int no;	//顶点编号 
	InfoType info;	//顶点信息 
}VertexType;

//“邻接矩阵”类型 
typedef struct{
	int edges[MAXV][MAXV];	//邻接矩阵数组 
	int n,e;	//邻接矩阵的顶点数n，边数e 
	VertexType vexs[MAXV];	//顶点的信息 
}MatGraph;

//“边”类型 
typedef struct ANode{
	int adjvex;	//边的邻接点编号 tip:这是个有向图，这个邻接点代表箭头所指向的编号 
	struct ANode *nextarc;	//指向下一条边 
	int weight;	//权重 
}ArcNode;

//“头结点”类型 
//相当于边构成了一个链表，结合ArcNode 
typedef struct Vnode{
	InfoType info;	//头结点信息 
	int count;	//头结点的度！ 
	ArcNode *firstarc;	//指向第一条边！  
}VNode;

//“邻接表”类型 
typedef struct{
	VNode adjlist[MAXV];	//邻接表的头结点数组 
	int n,e;	//邻接表的顶点数n，边数e 
}AdjGraph;

//创建图的“邻接矩阵 ” 
void CreateMat(MatGraph &g, int A[MAXV][MAXV], int n, int e){
	int i,j;
	//储存顶点数、边数 
	g.n=n;
	g.e=e;
	//通过遍历来初始化整个邻接表，从二维数组A传入数据 
	for(i=0;i<g.n;i++)
		for(j=0;j<g.n;j++)
			g.edges[i][j]=A[i][j];
}

//输出图的“邻接矩阵 ” 
void DispMat(MatGraph g){
	int i,j;
	//遍历二维数组来输出信息 
	for(i=0;i<g.n;i++){
		for(j=0;j<g.n;j++)
			//如果内容不是无穷大，就直接输出，否则输出∞ 
			if(g.edges[i][j]!=INF)	printf("%4d",g.edges[i][j]);
			else printf("%4s","∞");
		printf("\n");
	}
}

//创建“邻接表 ” 
void CreateAdj(AdjGraph *&G,int A[MAXV][MAXV],int n,int e){
	int i,j;
	ArcNode *p;	//创建一个边 
	G = (AdjGraph *)malloc(sizeof(AdjGraph));	//给邻接表分配空间
	//给邻接表每个头结点的 指向第一条边的指针域 初始化 
	for(i = 0;i<n;i++)
		G->adjlist[i].firstarc=NULL;
	//遍历邻接矩阵 
	for(i=0;i<n;i++)
		for(j=n-1;j>=0;j--)
			//如果存在一条边 
			if(A[i][j]!=0&&A[i][j]!=INF){
				p=(ArcNode *)malloc(sizeof(ArcNode));	//给前面创建的边分配空间 
				p->adjvex=j;	//这条边的结点的编号 
				p->weight=A[i][j];	//边的权重 
				//头插法，first_arc就是头结点的next ，这里是指向的第一条边 
				//第一次时，会把null赋给next_arc，之后，都是将这个顶点的下一条边赋给next_arc 
				p->nextarc=G->adjlist[i].firstarc;	
				G->adjlist[i].firstarc=p;	//更新头结点指向的第一条边 
			}
	G->n=n;
	G->e=e;
}

//输出“邻接表” 
void DispAdj(AdjGraph *G){
	ArcNode *p;	//创建一条边,作为载体 
	//遍历邻接表的头结点列表 
	for(int i=0;i<G->n;i++){
		p=G->adjlist[i].firstarc;
		printf("%3d:",i);	//输出头结点编号 
		//遍历每一条顶点链！ 
		while(p!=NULL){
			printf("%3d[%d]-->",p->adjvex,p->weight);
			p=p->nextarc;
		}
		//最后指向null 
		printf("∧\n");
	}
}

//销毁“邻接表 ” 
void DestoryAdj(AdjGraph *&G){
	ArcNode *pre,*p;	//为了遍历边链表
	//遍历 
	for(int i=0;i<G->n;i++){
		pre=G->adjlist[i].firstarc;	//头结点 
		if(pre!=NULL){
			p=pre->nextarc;
			while(p!=NULL){
				free(pre);
				pre=p;
				p=p->nextarc;
			}
			//最后留的一个 
			free(pre);
		}	
	}
	//图的结点 
	free(G);
}

