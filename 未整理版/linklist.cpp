#include<stdio.h>
#include<malloc.h>
typedef char ElemType;
typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LinkNode;

void CreateListF(LinkNode *&L,ElemType a[],int n){
	LinkNode *s;
	L=(LinkNode *)malloc(sizeof(LinkNode));
	L->next=NULL;
	for(int i=0;i<n;i++){
		s=(LinkNode *)malloc(sizeof(LinkNode));
		s->data=a[i];
		s->next=L->next;
		L->next=s;
	}
}

void CreateListR(LinkNode *&L,ElemType a[],int n){
	LinkNode *s,*r;
	L=(LinkNode *)malloc(sizeof(LinkNode));
	L->next=NULL;
	r=L;
	for(int i=0;i<n;i++){
		s=(LinkNode *)malloc(sizeof(LinkNode));
		s->data=a[i];
		r->next=s;
		s->next=NULL;
		r=s;
	}
}

void InitList(LinkNode *&L){
	L=(LinkNode *)malloc(sizeof(LinkNode));
	L->next=NULL;
}

void DestoryList(LinkNode *&L){
	LinkNode *pre=L,*p=L->next;
	while(p!=NULL){
		free(pre);
		pre=p;
		p=p->next;
	}
	free(pre);
}

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

void UnionList(LinkNode *&LA,LinkNode *&LB,LinkNode *&L){
	LinkNode *p=LA->next,*q=LB->next,*r;
	L=(LinkNode *)malloc(sizeof(LinkNode)) ;
	r=L;
	while(p!=NULL && q!=NULL){
		r->next=p;
		r=r->next;
		p=p->next;
		
		r->next=q;
		r=r->next;
		q=q->next;
	}
	if(p==NULL){
		r->next=q;
	}else if(q==NULL){
		r->next=p;
	}
}

void sort(LinkNode *&L) {
	LinkNode *p,*pre,*q;
	p=L->next->next;
	L->next->next=NULL;
	while(p!=NULL){
		q=p->next;
		pre=L;
		while(pre->next!=NULL && pre->next->data<p->data)
			pre=pre->next;
		p->next=pre->next;
		pre->next=p;
		p=q;
	}
}


void fun1(LinkNode *&L,LinkNode *A,LinkNode *B){
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
