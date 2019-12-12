#include "010--graph.cpp"
/*
图的遍历算法源码 
完善注释来复习~ 
*/ 
int visited[MAXV];	//标记已经访问过的顶点，全局变量，涉及递归 
//递归算法，深度遍历图 
//v代表开始遍历的顶点编号 
void DFS(AdjGraph *G, int v) {
	ArcNode *p;	//定义一条边 
	printf("%3d",v);visited[v]=1;	//输出开始遍历的那个顶点编号 ，并标记 
	p = G->adjlist[v].firstarc;	//边链的第一条边 
	//遍历边链 
	while(p!=NULL){
		//如果这条边指向的下一个顶点没有输出，就递归输出 
		if(visited[p->adjvex]==0)	DFS(G,p->adjvex);
		p=p->nextarc;
	}
}

//非递归算法，深度遍历图 
void DFS1(AdjGraph *G, int v){
	ArcNode *p;	//创建一条边 
	int St[MAXV];	//栈！ 
	int top=-1,w,x,i;	//top栈顶，w,x 
	//初始化标记数组，因为前面使用过，内容不是初始化的 
	for(i=0;i<G->n;i++)
		visited[i]=0;
	//输出开始的顶点编号 
	printf("%3d",v);
	visited[v]=1;	//标记已经输出的 
	top++;	//入栈！ 
	St[top]=v;	//入栈
	//如果栈不为空 
	while(top>-1){
		x=St[top];	//读取栈顶元素 
		p=G->adjlist[x].firstarc;	//第一条边 
		//遍历边链 
		while(p!=NULL){
			w=p->adjvex;	//边指向的顶点编号
			//如果没有输出 
			if(visited[w]==0){
				printf("%3d",w);
				visited[w]=1;
				//入栈 
				top++;
				St[top]=w;
				break;
			}
			//下一个 
			p=p->nextarc;
		}
		//遍历完了，出栈 
		if(p==NULL)	top--;
	}
	printf("\n");
}

void BFS(AdjGraph *G,int v){
	ArcNode *p;
	int queue[MAXV],front=0,rear=0;
	int visited[MAXV];
	int w,i;
	for(i=0;i<G->n;i++)
		visited[i]=0;
	printf("%3d",v);
	visited[v]=1;
	rear=(rear+1)%MAXV;
	queue[rear]=v;
	while(front!=rear){
		front=(front+1)%MAXV;
		w=queue[front];
		p=G->adjlist[w].firstarc;
		while(p!=NULL){
			if(visited[p->adjvex]==0){
				printf("%3d",p->adjvex);
				visited[p->adjvex]=1;
				rear=(rear+1)%MAXV;
				queue[rear]=p->adjvex;
			}
			p=p->nextarc;
		}
	}
	printf("\n");
}
