#include<stdio.h>
#include<malloc.h>
typedef char ElemType;	//Ԫ������
//�������� 
typedef struct LNode{
	ElemType data;	//������ 
	struct LNode *next;	//ָ����һ������ָ�� 
}LinkNode;

//ͷ�巨�������� 
void CreateListF(LinkNode *&L,ElemType a[],int n){
	LinkNode *s;	//�м̽�� 
	L=(LinkNode *)malloc(sizeof(LinkNode));
	L->next=NULL;
	//ͷ�巨 
	for(int i=0;i<n;i++){
		s=(LinkNode *)malloc(sizeof(LinkNode));	//�м̽�����ռ� 
		s->data=a[i];	//��ֵ 
		s->next=L->next;	//�����м̽�� 
		L->next=s;	//���ʹ�� 
	}
}

//β�巨�������� 
void CreateListR(LinkNode *&L,ElemType a[],int n){
	LinkNode *s,*r;	//�м̽�㡢β��� 
	L=(LinkNode *)malloc(sizeof(LinkNode));	//�м̽�����ռ� 
	L->next=NULL;	// 
	r=L;	//��ǰ��β���ָ��ͷ���
	//��ʼ�� 
	for(int i=0;i<n;i++){
		s=(LinkNode *)malloc(sizeof(LinkNode));	//�м̽�����ռ� 
		s->data=a[i];	//��ֵ 
		r->next=s;	//���ص�β��� 
		s->next=NULL;	//���� 
		r=s;	//����β��㣬s���ʹ�� 
	}
}

//��ʼ�������� 
void InitList(LinkNode *&L){
	L=(LinkNode *)malloc(sizeof(LinkNode));	//��ͷ������ռ� 
	L->next=NULL;	//��ʼ�� 
}

//�������� 
void DestoryList(LinkNode *&L){
	LinkNode *pre=L,*p=L->next;	//pre��p�ֵ� 
	while(p!=NULL){	//ִ������ ����ǰ��Ϊ�� 
		free(pre);	// �ͷ�ǰһ�� 
		pre=p;	//����ǰһ��ָ�� 
		p=p->next;	//���µ�ǰָ�� 
	}
	free(pre);	//���ʣ�µ�һ�� 
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
//�ϲ��������� 
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
