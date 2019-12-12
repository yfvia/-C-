#include "stdio.h"
#include "malloc.h"
#define MaxSize 50
/*
дע������ϰ~~ 
*/ 
typedef char ElemType;	//Ԫ������

//��˳������� 
typedef struct {
	ElemType data[MaxSize];	//�洢Ԫ�ص����� 
	int length;	//�� 
}SqList;

//��ʼ�� �յġ�˳��� 
void InitList(SqList *&L){
	L=(SqList *)malloc(sizeof(SqList));	//����ռ� 
	L->length=0;	//��ʼ������ 
}

// ���� �����ݵġ�˳�����data from a 
void CreateList(SqList *&L,ElemType a[],int n){
	L=(SqList *)malloc(sizeof(SqList));	//����ռ� 
	for(int i=0;i<n;i++){	//ѭ����ʼ��Ԫ�� 
		L->data[i]=a[i];
	}
	L->length=n;	//��ʼ������ 
}

//���١�˳��� �� 
bool DestroyList(SqList *&L){
	free(L);	//ֱ�Ӱ�ָ���ָ��Ŀռ����ټ��� 
}

//�ж� ��˳����Ƿ�Ϊ�� 
bool ListEmpty(SqList *L){
	return L->length == 0;
}

//�õ���˳����ĳ��� 
int ListLength(SqList *L){
	return L->length;
}

//�����˳��� 
bool DispList(SqList *L){
//	if(ListEmpty(L))	return false;
//	ֱ��д�ǲ��ǱȽϺã���ȥ������ 
	if(L->length == 0)	return false;	//	����Ǹ��ձ���ֱ�ӷ���false
	//������������� 
	for(int i=0;i<ListLength(L);i++){
		printf("%c ",L->data[i]);
	}
	printf("\n");
	return true;	//�����˷���ֵ 
}

//�õ�ָ��λ�õ�Ԫ��ֵ 
bool GetElem(SqList *L,int i,ElemType &e){
	if(L->length == 0) return false;	//�ǿ��ж� 
	if(i<1 || i>L->length)	return false;	//Խ���ж� 
	e=L->data[i-1];	//������ʣ�ȡֵ~ 
	return true;
}

//�����ض�Ԫ�ص�λ�� 
int LocateElem(SqList *L,ElemType e){
	if(L->length == 0) return 0;	//�ǿ��ж� 
	//����Ԫ�أ�ע�⣬�����õ����±� 
	int i=0;
	while(i<L->length && L->data[i]!=e){
		i++;
	}
	return i+1;  //����λ�� 
} 

//ָ��λ�ò������� 
bool ListInsert(SqList *&L,int i,ElemType e){
	//���ȴ��� 
	if(i<1 || i>(L->length+1) || i>MaxSize)	return false;	//Խ���жϣ�������Բ��뵽ĩβ 
	i--;	//ת��Ϊ�±� 
	//�ƶ�Ԫ�� 
	for(int j=L->length;j>i;j--){
		L->data[j]=L->data[j-1];
	}
	L->data[i]=e;	//��ֵ 
	L->length++;	//��һ������ 
	return true;
}

//ɾ���ض�λ�õ�Ԫ�� 
bool ListDelete(SqList *&L,int i,ElemType e){
	if(i<1 || i>L->length) return false;	//Խ���ж� 
	i--;	//	ת��Ϊ�±� 
	e=L->data[i];	//ȡֵ
	//����ɾ�� 
	for(;i<L->length+1;i++){
		L->data[i]=L->data[i+1];
	}
	L->length--;	//��һ������ 
	return true;
}

//ͳ��ĳԪ����L�г��ֵĴ��� 
int FindElem(SqList *L,ElemType x){
	int count=0;	//���� 
	//���� 
	int i=0;
	while(i<L->length){
		if(L->data[i] == x)	count++;
		i++;
	}
	
	return count;
}
