#include<stdio.h>
#include<malloc.h>
typedef char ElemType;
typedef struct LinkNode{
	ElemType data;
	struct LinkNode *next;
}LinkStNode;

void InitStack(LinkStNode *&s){
	s=(LinkStNode *)malloc(sizeof(LinkStNode));
	s->next=NULL;
}

void DestoryStack(LinkStNode *&s){
	LinkStNode *p=s->next;
	while(p!=NULL){
		free(s);
		s=p;
		p=p->next;
	}
	free(s);
}

bool StackEmpty(LinkStNode *s){
	return s->next == NULL;
} 
void Push(LinkStNode *&s,ElemType e){
	LinkStNode *p;
	p=(LinkStNode *)malloc(sizeof(LinkStNode));
	p->data=e;
	p->next=s->next;
	s->next=p;
}

bool Pop(LinkStNode *&s,ElemType &e){
	if(s->next == NULL)	return false;
	LinkNode *p=s->next;
	e=p->data;
	s->next=p->next;
	free(p);
	return true;
}

bool GetTop(LinkStNode *s,ElemType &e){
	if(s->next == NULL)	return false;
	e=s->next->data;
	return true; 
}
