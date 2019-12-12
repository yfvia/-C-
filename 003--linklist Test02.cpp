#include "002--linklist.cpp"
/*
将单链表按照基准划分 
*/ 
void Split(LinkNode *&L,ElemType x);
int main(void)
{
	LinkNode *L;
	ElemType a[]="abcdefgh" ;
	int n=8;
	CreateListR(L,a,n);
	printf("L:");
	DispList(L);
	ElemType x='d';
	printf("Splited by %c.\n",x);
	Split(L,x);
	printf("L:");
	DispList(L);
	DestoryList(L);
	
	return 0;
}
void Split(LinkNode *&L,ElemType x){
	LinkNode *p=L->next,*q,*r;
	L->next=NULL;
	r=L;
	while(p!=NULL){
		if(p->data<x){
			q=p->next;
			p->next=L->next;
			L->next=p;
			if(p->next==NULL){
				r=p;
			}
			p=q;
		}else{
			r->next=p;
			r=p;
			p=p->next;
		}
	}
	r->next=NULL;
	
};
