#include "listack.cpp"
int main(void)
{
	ElemType e;
	LinkStNode *s;
	printf("链栈s的基本运算如下：\n");
	printf("01--初始化栈s\n");
	InitStack(s);
	printf("02--栈为%s\n",(StackEmpty(s)? "空":"非空"));
	printf("03--依次进栈元素a,b,c,d,e\n");
	Push(s,'a');
	Push(s,'b');
	Push(s,'c');
	Push(s,'d');
	Push(s,'e');
	printf("04--栈为%s\n",(StackEmpty(s)? "空":"非空"));
	
	printf("05--出栈序列：");
	while(!StackEmpty(s)){
		Pop(s,e);
		printf("%c ",e);
	}
	printf("\n");
	printf("06--栈为%s\n",(StackEmpty(s)? "空":"非空"));
	printf("07--销毁栈\n");
	DestoryStack(s);
	
	return 0;
}
