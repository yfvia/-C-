#include "stdio.h"
#include "malloc.h"
#define MaxSize 50
/*
写注释来复习~~ 
*/ 
typedef char ElemType;	//元素类型

//“顺序表”类型 
typedef struct {
	ElemType data[MaxSize];	//存储元素的数组 
	int length;	//表长 
}SqList;

//初始化 空的“顺序表” 
void InitList(SqList *&L){
	L=(SqList *)malloc(sizeof(SqList));	//分配空间 
	L->length=0;	//初始化长度 
}

// 创建 有数据的“顺序表”，data from a 
void CreateList(SqList *&L,ElemType a[],int n){
	L=(SqList *)malloc(sizeof(SqList));	//分配空间 
	for(int i=0;i<n;i++){	//循环初始化元素 
		L->data[i]=a[i];
	}
	L->length=n;	//初始化长度 
}

//销毁“顺序表 ” 
bool DestroyList(SqList *&L){
	free(L);	//直接把指针的指向的空间销毁即可 
}

//判断 “顺序表”是否为空 
bool ListEmpty(SqList *L){
	return L->length == 0;
}

//得到“顺序表”的长度 
int ListLength(SqList *L){
	return L->length;
}

//输出“顺序表” 
bool DispList(SqList *L){
//	if(ListEmpty(L))	return false;
//	直接写是不是比较好，回去看看书 
	if(L->length == 0)	return false;	//	如果是个空表，就直接返回false
	//遍历整个表，输出 
	for(int i=0;i<ListLength(L);i++){
		printf("%c ",L->data[i]);
	}
	printf("\n");
	return true;	//别忘了返回值 
}

//得到指定位置的元素值 
bool GetElem(SqList *L,int i,ElemType &e){
	if(L->length == 0) return false;	//非空判断 
	if(i<1 || i>L->length)	return false;	//越界判断 
	e=L->data[i-1];	//随机访问，取值~ 
	return true;
}

//返回特定元素的位置 
int LocateElem(SqList *L,ElemType e){
	if(L->length == 0) return 0;	//非空判断 
	//遍历元素，注意，这里用的是下标 
	int i=0;
	while(i<L->length && L->data[i]!=e){
		i++;
	}
	return i+1;  //返回位置 
} 

//指定位置插入数据 
bool ListInsert(SqList *&L,int i,ElemType e){
	//长度存疑 
	if(i<1 || i>(L->length+1) || i>MaxSize)	return false;	//越界判断，这里可以插入到末尾 
	i--;	//转化为下标 
	//移动元素 
	for(int j=L->length;j>i;j--){
		L->data[j]=L->data[j-1];
	}
	L->data[i]=e;	//存值 
	L->length++;	//加一个长度 
	return true;
}

//删除特定位置的元素 
bool ListDelete(SqList *&L,int i,ElemType e){
	if(i<1 || i>L->length) return false;	//越界判断 
	i--;	//	转化为下标 
	e=L->data[i];	//取值
	//遍历删除 
	for(;i<L->length+1;i++){
		L->data[i]=L->data[i+1];
	}
	L->length--;	//减一个长度 
	return true;
}

//统计某元素在L中出现的次数 
int FindElem(SqList *L,ElemType x){
	int count=0;	//计数 
	//遍历 
	int i=0;
	while(i<L->length){
		if(L->data[i] == x)	count++;
		i++;
	}
	
	return count;
}
