#include"002--linklist.cpp"
int main(void)
{
	LinkNode *h;
	ElemType e;
	printf("=========================test of linklist=====================\n");
	printf("01--Init the linklist.\n");
	InitList(h);
	printf("02--Test insert a,b,c,d,e\n");
	ListInsert(h,1,'a');
	ListInsert(h,2,'b');
	ListInsert(h,3,'c');
	ListInsert(h,4,'d');
	ListInsert(h,5,'e');
	printf("03--Display the linklist h: ");
	DispList(h);
	printf("04--The length of linklist h: %d\n",ListLength(h));
	printf("05--The linklist is %s.\n",(ListEmpty(h)? "Empty":"not Empty"));
	GetElem(h,3,e);
	printf("06--The third element of the linklist is %c.\n",e);
	printf("07--The element a's location is %d.\n",LocateElem(h,'a'));
	printf("08--Insert f to the forth location. \n");
	ListInsert(h,4,'f');
	printf("09--Display the linklist h: ");
	DispList(h);
	printf("10--Delete the third element of h.\n");
	ListDelete(h,3,e);
	printf("11--Display the linklist h ");
	DispList(h);
	printf("12--Destory the linklist h,\n");
	DestoryList(h);
	printf("===========================test over==========================\n");
	
	return 0;
}
