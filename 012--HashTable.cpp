#include<stdio.h>
#define MaxSize 100	//��ϣ��������� 
#define NULLKEY -1	//�չؼ���ֵ 
#define DELKEY 	-2	//��ɾ���Ĺؼ���ֵ 
typedef int KeyType;	//�ؼ������� 
typedef char InfoType;	//������Ϣ
//����ϣ�� ������ 
typedef struct{
	KeyType key;	//�ؼ��� 
	InfoType data;	//������Ϣ 
	int count;		//̽����� 
}HashTable;
/*
nΪʵʱ��Ч�ؼ�������
mΪ��
pΪ��ϣ��������
k����һ����ͨ�Ĺؼ��� 
*/ 


//��k���뵽��ϣ�� 
void InsertHT(HashTable ha[],int &n,int m,int p,KeyType k){
	int i,adr;	//��ַ 
	adr=k%p;	//��ϣ���� 
	if(ha[adr].key==NULLKEY || ha[adr].key==DELKEY){	//�жϸõ�ַ�Ƿ����(Ϊ�ջ���Ԫ���ѱ�ɾ��) 
		ha[adr].key=k;	//����k 
		ha[adr].count=1;	//��¼̽����� 
	}
	else	//������ͻʱ������̽�ⷨ��� 
	{
		i=1;	//��ʼ����ֵ����¼��ͻ�Ĵ��� 
		//Ѱ�ҿ��õ�ַ 
		do{
			adr=(adr+1)%m;	//+1���� 
			i++;
		}while(ha[adr].key!=NULLKEY&&ha[adr].key!=DELKEY);	//������ʱ �����ﷴ����˼���������� 
		ha[adr].key=k;	//�ҵ����õ�ַ�󣬴洢 
		ha[adr].count=i;	//��¼̽����� 
	}
	n++;	//��¼Ԫ������ 
}

//������ϣ�� 
void CreateHT(HashTable ha[], KeyType x[], int n,int m,int p){
	int i,nl=0;	//nl��¼Ԫ������ 
	for(i=0;i<m;i++){	//��ʼ����ϣ�� 
		ha[i].key=NULLKEY;
		ha[i].count=0;
	}
	//������� 
	for(i=0;i<n;i++)
		InsertHT(ha,nl,m,p,x[i]);
}

//���ҹؼ���k 
int SearchHT(HashTable ha[], int m,int p,KeyType k){
//	int i=0,adr;	//���iû��...���� 
	int adr; 
	adr=k%p;	//��ϣ���� 
	while(ha[adr].key!=NULLKEY && ha[adr].key!=k){	//��Чֵ 
//		i++;	//
		adr=(adr+1)%m;
	}
	if(ha[adr].key==k)	return adr;	//�����ҵ��ĵ�ַ 
	else return -1;	//����ʧ�� 
}

//ɾ��kԪ�� 
int DeleteHT(HashTable ha[],int m,int p,int &n, int k){
	int adr;	//��ַ 
	adr = SearchHT(ha,m,p,k);	//��ȡk��Ӧ�ĵ�ַ 
	if(adr!=-1){	//��ȡ��ַ�ɹ� 
		ha[adr].key=DELKEY;	//���ɾ�� 
		n--;	//�������� 
		return 1;	//���سɹ� 
	}
	else return 0;	//����ʧ�� 
}

//�������ϣ�� �� 
void DispHT(HashTable ha[], int n, int m){
	float avg=0;	//Ϊ�˼���ASL 
	int i;	//���� 
	printf("    ��ϣ���ַ:  ");
	for(i=0;i<m;i++)	//������ַͷ 
		printf("%-4d",i);
	printf("\n");
	printf("    ��ϣ��ؼ���:");
	for(i=0;i<m;i++)	//�����ؼ��� 
		if(ha[i].key==NULLKEY || ha[i].key==DELKEY)	//�ж���Ч�ؼ��� 
			printf("    ");
		else	printf("% -4d",ha[i].key);	//�����Ч�ؼ��� 
	printf("\n");
	printf("    ̽�������    ");
	for(i=0;i<m;i++)	//���̽����� 
		if(ha[i].key==NULLKEY||ha[i].key==DELKEY)	//�ж���Ч�ؼ��� 
			printf("    ");
		else printf("%-4d",ha[i].count);	//����ؼ��ֶ�Ӧ��̽����� 
	printf("\n");
	for(i=0;i<m;i++)	//����ASL 
		if(ha[i].key!=NULLKEY && ha[i].key!=DELKEY)	//�ж���Ч�ؼ��� 
			avg=avg+ha[i].count;
	avg=avg/n;	//����ASL 
	printf("    ƽ�����ҳ���ASL(%d)=%g\n",n,avg);
}

int main()
{
	int x[]={16,74,60,43,54,90,46,31,29,88,77};
	int n=11,m=13,p=13,i,k=29;	//nΪʵʱ��Ч�ؼ���������mΪ����pΪ��ϣ����������k����һ����ͨ�Ĺؼ��� 
	HashTable ha[MaxSize];
	printf("(1)������ϣ��\n");
	CreateHT(ha,x,n,m,p);
	printf("(2)�����ϣ��:\n");
	DispHT(ha,n,m);
	printf("(3)���ҹؼ���Ϊ%d�ļ�¼λ��\n",k);
	i=SearchHT(ha,m,p,k);
	if(i!=-1)	printf("   ha[%d].key=%d\n",i,k);
	else printf("   ��ʾ��δ�ҵ�%d\n",k);
	k=77;
	printf("(4)ɾ���ؼ���%d\n",k);
	DeleteHT(ha,m,p,n,k);
	printf("(5)ɾ����Ĺ�ϣ��\n");
	DispHT(ha,n,m);
	printf("(6)���ҹؼ���Ϊ%d�ļ�¼λ��\n",k);
	i = SearchHT(ha,m,p,k);
	if(i!=-1)	printf("	ha[%d].key=%d\n",i,k);
	else printf("   ��ʾ�����ҵ�%d\n",k);
	printf("(7)����ؼ���%d\n",k);
	InsertHT(ha,n,m,p,k);
	printf("(8)�����Ĺ�ϣ��\n");
	DispHT(ha,n,m);
	return 0;
}
