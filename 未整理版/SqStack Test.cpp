#include "SqStack.cpp"
int main(void)
{
	ElemType e;
	SqStack *s;
	printf("˳��ջs�Ļ����������£�\n");
	printf("01--��ʼ��ջs\n");
	InitStack(s);
	printf("02--ջΪ%s\n",(StackEmpty(s)? "��":"�ǿ�"));
	printf("03--���ν�ջԪ��a,b,c,d,e\n");
	Push(s,'a');
	Push(s,'b');
	Push(s,'c');
	Push(s,'d');
	Push(s,'e');
	printf("04--ջΪ%s\n",(StackEmpty(s)? "��":"�ǿ�"));
	
	printf("05--��ջ���У�");
	while(!StackEmpty(s)){
		Pop(s,e);
		printf("%c ",e);
	}
	printf("\n");
	printf("06--ջΪ%s\n",(StackEmpty(s)? "��":"�ǿ�"));
	printf("07--����ջ\n");
	DestoryStack(s);
	
	return 0;
}
