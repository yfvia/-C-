#include<stdio.h>
#include<malloc.h>
#define MaxSize 100
/*
дע������ϰ 
*/ 
typedef char ElemType;
typedef struct node{
	ElemType data;
	struct node *lchild;
	struct node *rchild;
}BTNode;

void CreateBTree(BTNode *&b,char *str)
{
	BTNode *St[MaxSize],*p;	//ջ�������ţ�pΪ�м̽�� 
	int top=-1,k,j=0;
	char ch;
	b=NULL;	//��ʼ�����ڵ㣡 
	ch=str[j];	//��һ���ַ� 
	while(ch!='\0'){	//ִ��������ch���ǽ����� 
		switch(ch){	//�б�������� 
			case '(':top++;St[top]=p;k=1;break;	//�������� ��������ʱջ��Ϊ�������ĸ��ڵ�
												//����ʶ���� tip����ʱ��һ���Ѿ������˸� 
			case ')':top--;break;	//�����������������ǰ�����ĸ���ջ�� 
			case ',':k=2;break;	//��ʶ�Һ���
			//�������ĸ����㣩 
			default:p=(BTNode *)malloc(sizeof(BTNode));	//�м̽�����ռ� 
					p->data=ch;	//������ţ���㣩 
					p->lchild=p->rchild=NULL;	//��ʼ���������Һ��� 
					if(b==NULL)	b=p;	//������ڵ�Ϊ�գ����¸��ڵ�Ϊp 
					else{	//���ڵ㲻Ϊ�� 
						switch(k){	//�ֱ������Һ��� 
							case 1:St[top]->lchild=p;break;
							case 2:St[top]->rchild=p;break;
						}
					}
		} 
		j++;	//�����굱ǰ���ź�����һ�� 
		ch=str[j];	//����ch 
	}
}

//�ݹ������� 
void DestoryBTree(BTNode *&b)
{
	if(b!=NULL){
		DestoryBTree(b->lchild);
		DestoryBTree(b->rchild);
		free(b);
	}
} 

//����Ԫ��ֵΪx�Ľ�� 
BTNode * FindNode(BTNode *b,ElemType x)
{
	BTNode *p;
	if(b==NULL)	return NULL;	//�жϿ��� 
	else if(b->data == x)	return b;	//���� 
	else {
		p=FindNode(b->lchild,x);	//�ݹ飬�������� 
		if(p!=NULL)	return p;	//������˵���������ҵ��� 
		else return FindNode(b->rchild,x);	//���������ݹ飬�������� 
	}
}

//���� 
BTNode *LchildNode(BTNode *p)
{
	return p->lchild;
}

//�Һ��� 
BTNode *RchildNode(BTNode *p)
{
	return p->rchild;
}

//���ĸ߶� 
int BTHeight(BTNode *b)
{
	int lchildh,rchildh;	//��¼�������ĸ߶� 
	if(b==NULL) return (0);	//�жϿ��� |�Լ���Ҷ�ӵ����� 
	else{	//�ݹ�~�� 
		lchildh=BTHeight(b->lchild);	//�������ĸ߶� 
		rchildh=BTHeight(b->rchild);	//�������ĸ߶� 
		return (lchildh>rchildh)? (lchildh+1):(rchildh+1); //�Ƚϴ�С���������ϵ�ǰ��ĸ߶� 
	}
}

//��������� 
void DispBTree(BTNode *b){
    if (b!=NULL)	//���ǿղ������ 
    {
        printf("%c",b->data);	// �������ֵ 
        if (b->lchild!=NULL || b->rchild!=NULL)	//ӵ������������������ 
        {
            printf("(");
            DispBTree(b->lchild);	//�ݹ������������������Ҳû��ϵ 
            if (b->rchild!=NULL)	//��������Ҫ�ж�һ���Ƿ���ڣ���Ϊ����Ҫ��������� 
            {
                printf(",");
            }
            DispBTree(b->rchild);	//�ݹ������������������Ҳû��ϵ 
            printf(")");
        }
    }
}
