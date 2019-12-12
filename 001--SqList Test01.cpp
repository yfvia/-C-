#include "001--SqList.cpp"
int main(void)
{
	SqList *L;
	ElemType e;
	printf("=========================Test the SqList====================\n");
	printf("01--InitList L\n");
	InitList(L);
	printf("02--Insert a.b.c.d.e Element\n");
	ListInsert(L,1,'a');
	ListInsert(L,2,'b');
	ListInsert(L,3,'c');
	ListInsert(L,4,'d');
	ListInsert(L,5,'e');
	printf("03--DisPlay the SqList L:");
	DispList(L);
	printf("04--The length of SqList: %d \n",ListLength(L));
	printf("05--SqList is %s\n",(ListEmpty(L)? "Empty" : "Not empty"));
	GetElem(L,3,e);
	printf("06--SqList's third element : %c\n",e);
	printf("07--The location of c is %d\n",LocateElem(L,'c'));
	printf("08--Insert f to the forth location of L\n");
	ListInsert(L,4,'f');
	printf("09--Display the SqList L:");
	DispList(L);
	printf("10--Delete the third element of the L\n");
	ListDelete(L,3,e);
	printf("11--Display the SqList L:");
	DispList(L);
	ListInsert(L,3,'e');
	DispList(L);
	int count=FindElem(L,'e'); //查找某元素出现的次数 
	printf("%d\n",count); 
	printf("12--Destroy the SqList of L\n");
	bool flag = DestroyList(L);
	if(flag) printf("True");
	else printf("False");
	
	printf("=========================Test Over!====================\n");
	return 0;
}
