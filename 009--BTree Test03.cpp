#include "007--BTree.cpp"
/*
二叉树的结点个数 、叶子结点数、某结点层次、二叉树宽度 
*/ 
int Nodes(BTNode *b)
{
	int num1,num2;
	if(b==NULL)	return 0;
	else if (b->lchild==NULL && b->rchild==NULL)	return 1;
	else {
		num1 = Nodes(b->lchild);
		num2 = Nodes(b->rchild);
		return (num1 + num2 + 1);
	}
}

int LeafNodes(BTNode *b)
{
	int num1, num2;
	if(b == NULL)	return 0;
	else if(b->lchild == NULL && b->rchild == NULL)	return 1;
	else{
		num1 = LeafNodes(b->lchild);
		num2 = LeafNodes(b->rchild);
		return num1 + num2;
	}
}

int Level(BTNode *b, ElemType x, int h)
{
	int l;
	if(b==NULL)	return 0;
	else if(b->data == x)	return h;
	else{
		l = Level(b->lchild, x, h+1);
		if(l!=0)	return l;
		else return(Level(b->rchild, x, h+1));
	}
	
}

int BTWidth(BTNode *b)
{
	struct{
		int lno;
		BTNode *p;
	}Qu[MaxSize];
	int front,rear;
	int lnum,max,i,n;
	front=rear=0;
	if(b!=NULL){
		rear++;
		Qu[rear].p=b;
		Qu[rear].lno = 1;
		while(rear!=front){
			front++;
			b=Qu[front].p;
			lnum = Qu[front].lno;
			if(b->lchild!=NULL){
				rear++,
				Qu[rear].p=b->lchild;
				Qu[rear].lno=lnum+1;
			}
			if(b->rchild!=NULL){
				rear++;
				Qu[rear].p=b->rchild;
				Qu[rear].lno=lnum+1;
			}
		}
		max = 0;
		lnum = 1;
		i = 1;
		while(i<=rear){
			n=0;
			while(i<=rear&&Qu[i].lno==lnum){
				n++;
				i++;
			}
			lnum=Qu[i].lno;
			if(n>max)	max=n;
		}
		return max;
	}
	else return 0;
}

int main(void)
{
	ElemType x = 'K';
	BTNode *b, *p, *lp, *rp;
	CreateBTree(b,"A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))");
	printf("输出二叉树b：");DispBTree(b);printf("\n");
	printf("二叉树b的结点个数：%d\n",Nodes(b));
	printf("二叉树b的叶子结点个数：%d\n",LeafNodes(b));
	printf("二叉树b中值为%c结点的层次：%d\n",x,Level(b,x,1));
	printf("二叉树b的宽度：%d\n",BTWidth(b));
//	printf("height:%d", BTHeight(b)) ;
	DestoryBTree(b);
	
	return 0;
}
