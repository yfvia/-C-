#include<stdio.h>
#include<malloc.h>
typedef char ElemType;	//元素类型
//链表类型 
typedef struct LNode{
	ElemType data;	//数据域 
	struct LNode *next;	//指向下一个结点的指针 
}LinkNode;

//头插法建立链表 
void CreateListF(LinkNode *&L,ElemType a[],int n){
	LinkNode *s;	//中继结点 
	L=(LinkNode *)malloc(sizeof(LinkNode));
	L->next=NULL;
	//头插法 
	for(int i=0;i<n;i++){
		s=(LinkNode *)malloc(sizeof(LinkNode));	//中继结点分配空间 
		s->data=a[i];	//赋值 
		s->next=L->next;	//挂载中继结点 
		L->next=s;	//完成使命 
	}
}

//尾插法建立链表 
void CreateListR(LinkNode *&L,ElemType a[],int n){
	LinkNode *s,*r;	//中继结点、尾结点 
	L=(LinkNode *)malloc(sizeof(LinkNode));	//中继结点分配空间 
	L->next=NULL;	// 
	r=L;	//当前，尾结点指向头结点
	//初始化 
	for(int i=0;i<n;i++){
		s=(LinkNode *)malloc(sizeof(LinkNode));	//中继结点分配空间 
		s->data=a[i];	//赋值 
		r->next=s;	//挂载到尾结点 
		s->next=NULL;	//完善 
		r=s;	//更新尾结点，s完成使命 
	}
}

//初始化空链表 
void InitList(LinkNode *&L){
	L=(LinkNode *)malloc(sizeof(LinkNode));	//给头结点分配空间 
	L->next=NULL;	//初始化 
}

//销毁链表 
void DestoryList(LinkNode *&L){
	LinkNode *pre=L,*p=L->next;	//pre，p兄弟 
	while(p!=NULL){	//执行条件 ：当前不为空 
		free(pre);	// 释放前一个 
		pre=p;	//更新前一个指针 
		p=p->next;	//更新当前指针 
	}
	free(pre);	//最后剩下的一个 
}

// 
bool ListEmpty(LinkNode *L){
	return L->next == NULL;
}

int ListLength(LinkNode *L){
	int length=0;
	LinkNode *p=L->next;
	while(p!=NULL){
		length++;
		p=p->next;
	}
	return length;
}

void DispList(LinkNode *L){
	LinkNode *p=L->next;
	while(p!=NULL){
		printf("%c ",p->data);
		p=p->next;
	}
	printf("\n");
}

bool GetElem(LinkNode *L,int i,ElemType &e){
	if(i<=0) return false;
	int j=0;
	LinkNode *p=L;
	while(j<i && p!=NULL){
		j++;
		p=p->next;
	}
	if(p==NULL)	return false;
	else {
		e=p->data;
		return true;
	}
}

int LocateElem(LinkNode *L,ElemType e){
	int i=1;
	LinkNode *p=L->next;
	while(p!=NULL && p->data!=e){
		p=p->next;
		i++;
	}
	if(p==NULL)	return 0;
	else  return i;
}

bool ListInsert(LinkNode *&L,int i,ElemType e){
	if(i<=0) false;
	LinkNode *p=L,*s;
	int j=0;
	while(j<i-1 && p!=NULL){
		p=p->next;
		j++;
	}
	if(p==NULL)	return false;
	else {
		s=(LinkNode *)malloc(sizeof(LinkNode));
		s->data=e;
		s->next=p->next;
		p->next=s;
		return true;
	}
}

bool ListDelete(LinkNode *&L,int i,ElemType &e){
	if(i<=0)	return false;
	int j=0;
	LinkNode *p=L,*q;
	while(j<i-1 && p!=NULL){
		p=p->next;
		j++;
	}
	if(p==NULL)	return false;
	else {
		q=p->next;
		if(q==NULL)	return false;
		e=q->data;
		p->next=q->next;
		free(q);
		return true;
	}
}
//合并两个链表 
void fun(LinkNode *&L,LinkNode *A,LinkNode *B){
	LinkNode *p=A->next,*q=B->next;
	LinkNode *t=L,*s;
	bool flag=true;
	while(p!=NULL && q!=NULL){
		if(flag==true){
			s=(LinkNode *)malloc(sizeof(LinkNode));
			s->data=p->data;
			s->next=NULL;
			t->next=s;
			t=s;
			p=p->next;
			flag=false;
		}else{
			s=(LinkNode *)malloc(sizeof(LinkNode));
			s->data=q->data;
			s->next=NULL;
			t->next=s;
			t=s;
			q=q->next;
			flag=true;
		}
	}
	if(p==NULL){
		while(q!=NULL){
			s=(LinkNode *)malloc(sizeof(LinkNode));
			s->data=q->data;
			s->next=NULL;
			t->next=s;
			t=s;
			q=q->next;
		}
	}else{
		s=(LinkNode *)malloc(sizeof(LinkNode));
			s->data=p->data;
			s->next=NULL;
			t->next=s;
			t=s;
			p=p->next;
	}
}
