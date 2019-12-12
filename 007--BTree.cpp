#include<stdio.h>
#include<malloc.h>
#define MaxSize 100
/*
写注释来复习 
*/ 
typedef char ElemType;
typedef struct node{
	ElemType data;
	struct node *lchild;
	struct node *rchild;
}BTNode;

void CreateBTree(BTNode *&b,char *str)
{
	BTNode *St[MaxSize],*p;	//栈储存括号，p为中继结点 
	int top=-1,k,j=0;
	char ch;
	b=NULL;	//初始化根节点！ 
	ch=str[j];	//第一个字符 
	while(ch!='\0'){	//执行条件：ch不是结束符 
		switch(ch){	//判别符号类型 
			case '(':top++;St[top]=p;k=1;break;	//接下来是 子树，此时栈顶为该子树的根节点
												//并标识左孩子 tip：此时，一定已经存在了根 
			case ')':top--;break;	//该子树储存结束，当前子树的根出栈！ 
			case ',':k=2;break;	//标识右孩子
			//如果是字母（结点） 
			default:p=(BTNode *)malloc(sizeof(BTNode));	//中继结点分配空间 
					p->data=ch;	//储存符号（结点） 
					p->lchild=p->rchild=NULL;	//初始化结点的左右孩子 
					if(b==NULL)	b=p;	//如果根节点为空，跟新根节点为p 
					else{	//根节点不为空 
						switch(k){	//分别处理左右孩子 
							case 1:St[top]->lchild=p;break;
							case 2:St[top]->rchild=p;break;
						}
					}
		} 
		j++;	//处理完当前符号后处理下一个 
		ch=str[j];	//更新ch 
	}
}

//递归销毁树 
void DestoryBTree(BTNode *&b)
{
	if(b!=NULL){
		DestoryBTree(b->lchild);
		DestoryBTree(b->rchild);
		free(b);
	}
} 

//返回元素值为x的结点 
BTNode * FindNode(BTNode *b,ElemType x)
{
	BTNode *p;
	if(b==NULL)	return NULL;	//判断空树 
	else if(b->data == x)	return b;	//树根 
	else {
		p=FindNode(b->lchild,x);	//递归，找左子树 
		if(p!=NULL)	return p;	//成立则说明左子树找到了 
		else return FindNode(b->rchild,x);	//不成立，递归，找右子树 
	}
}

//左孩子 
BTNode *LchildNode(BTNode *p)
{
	return p->lchild;
}

//右孩子 
BTNode *RchildNode(BTNode *p)
{
	return p->rchild;
}

//树的高度 
int BTHeight(BTNode *b)
{
	int lchildh,rchildh;	//记录左右树的高度 
	if(b==NULL) return (0);	//判断空树 |以及，叶子的子树 
	else{	//递归~！ 
		lchildh=BTHeight(b->lchild);	//左子树的高度 
		rchildh=BTHeight(b->rchild);	//右子树的高度 
		return (lchildh>rchildh)? (lchildh+1):(rchildh+1); //比较大小，返回算上当前层的高度 
	}
}

//输出二叉树 
void DispBTree(BTNode *b){
    if (b!=NULL)	//根非空才能输出 
    {
        printf("%c",b->data);	// 输出根的值 
        if (b->lchild!=NULL || b->rchild!=NULL)	//拥有左子树或者右子树 
        {
            printf("(");
            DispBTree(b->lchild);	//递归输出左子树，不存在也没关系 
            if (b->rchild!=NULL)	//右子树需要判断一下是否存在，因为可能要输出“，” 
            {
                printf(",");
            }
            DispBTree(b->rchild);	//递归输出右子树，不存在也没关系 
            printf(")");
        }
    }
}
