#include "010--graph.cpp"
/*
ͼ�ı����㷨Դ�� 
����ע������ϰ~ 
*/ 
int visited[MAXV];	//����Ѿ����ʹ��Ķ��㣬ȫ�ֱ������漰�ݹ� 
//�ݹ��㷨����ȱ���ͼ 
//v����ʼ�����Ķ����� 
void DFS(AdjGraph *G, int v) {
	ArcNode *p;	//����һ���� 
	printf("%3d",v);visited[v]=1;	//�����ʼ�������Ǹ������� ������� 
	p = G->adjlist[v].firstarc;	//�����ĵ�һ���� 
	//�������� 
	while(p!=NULL){
		//���������ָ�����һ������û��������͵ݹ���� 
		if(visited[p->adjvex]==0)	DFS(G,p->adjvex);
		p=p->nextarc;
	}
}

//�ǵݹ��㷨����ȱ���ͼ 
void DFS1(AdjGraph *G, int v){
	ArcNode *p;	//����һ���� 
	int St[MAXV];	//ջ�� 
	int top=-1,w,x,i;	//topջ����w,x 
	//��ʼ��������飬��Ϊǰ��ʹ�ù������ݲ��ǳ�ʼ���� 
	for(i=0;i<G->n;i++)
		visited[i]=0;
	//�����ʼ�Ķ����� 
	printf("%3d",v);
	visited[v]=1;	//����Ѿ������ 
	top++;	//��ջ�� 
	St[top]=v;	//��ջ
	//���ջ��Ϊ�� 
	while(top>-1){
		x=St[top];	//��ȡջ��Ԫ�� 
		p=G->adjlist[x].firstarc;	//��һ���� 
		//�������� 
		while(p!=NULL){
			w=p->adjvex;	//��ָ��Ķ�����
			//���û����� 
			if(visited[w]==0){
				printf("%3d",w);
				visited[w]=1;
				//��ջ 
				top++;
				St[top]=w;
				break;
			}
			//��һ�� 
			p=p->nextarc;
		}
		//�������ˣ���ջ 
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
