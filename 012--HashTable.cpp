#include<stdio.h>
#define MaxSize 100	//哈希表最大容量 
#define NULLKEY -1	//空关键字值 
#define DELKEY 	-2	//被删除的关键字值 
typedef int KeyType;	//关键字类型 
typedef char InfoType;	//其他信息
//“哈希表 ”类型 
typedef struct{
	KeyType key;	//关键字 
	InfoType data;	//其他信息 
	int count;		//探测次数 
}HashTable;
/*
n为实时有效关键字数量
m为表长
p为哈希函数除数
k就是一个普通的关键字 
*/ 


//把k插入到哈希表 
void InsertHT(HashTable ha[],int &n,int m,int p,KeyType k){
	int i,adr;	//地址 
	adr=k%p;	//哈希函数 
	if(ha[adr].key==NULLKEY || ha[adr].key==DELKEY){	//判断该地址是否可用(为空或者元素已被删除) 
		ha[adr].key=k;	//储存k 
		ha[adr].count=1;	//记录探测次数 
	}
	else	//发生冲突时，线性探测法解决 
	{
		i=1;	//初始化的值，记录冲突的次数 
		//寻找可用地址 
		do{
			adr=(adr+1)%m;	//+1处理 
			i++;
		}while(ha[adr].key!=NULLKEY&&ha[adr].key!=DELKEY);	//不可用时 ，这里反过来思考就明白了 
		ha[adr].key=k;	//找到可用地址后，存储 
		ha[adr].count=i;	//记录探测次数 
	}
	n++;	//记录元素数量 
}

//创建哈希表 
void CreateHT(HashTable ha[], KeyType x[], int n,int m,int p){
	int i,nl=0;	//nl记录元素数量 
	for(i=0;i<m;i++){	//初始化哈希表 
		ha[i].key=NULLKEY;
		ha[i].count=0;
	}
	//逐个插入 
	for(i=0;i<n;i++)
		InsertHT(ha,nl,m,p,x[i]);
}

//查找关键字k 
int SearchHT(HashTable ha[], int m,int p,KeyType k){
//	int i=0,adr;	//这个i没用...垃圾 
	int adr; 
	adr=k%p;	//哈希函数 
	while(ha[adr].key!=NULLKEY && ha[adr].key!=k){	//有效值 
//		i++;	//
		adr=(adr+1)%m;
	}
	if(ha[adr].key==k)	return adr;	//返回找到的地址 
	else return -1;	//查找失败 
}

//删除k元素 
int DeleteHT(HashTable ha[],int m,int p,int &n, int k){
	int adr;	//地址 
	adr = SearchHT(ha,m,p,k);	//获取k对应的地址 
	if(adr!=-1){	//获取地址成功 
		ha[adr].key=DELKEY;	//标记删除 
		n--;	//更新数量 
		return 1;	//返回成功 
	}
	else return 0;	//返回失败 
}

//输出“哈希表 ” 
void DispHT(HashTable ha[], int n, int m){
	float avg=0;	//为了计算ASL 
	int i;	//辅助 
	printf("    哈希表地址:  ");
	for(i=0;i<m;i++)	//输出表地址头 
		printf("%-4d",i);
	printf("\n");
	printf("    哈希表关键字:");
	for(i=0;i<m;i++)	//输出表关键字 
		if(ha[i].key==NULLKEY || ha[i].key==DELKEY)	//判断有效关键字 
			printf("    ");
		else	printf("% -4d",ha[i].key);	//输出有效关键字 
	printf("\n");
	printf("    探测次数：    ");
	for(i=0;i<m;i++)	//输出探测次数 
		if(ha[i].key==NULLKEY||ha[i].key==DELKEY)	//判断有效关键字 
			printf("    ");
		else printf("%-4d",ha[i].count);	//输出关键字对应的探测次数 
	printf("\n");
	for(i=0;i<m;i++)	//计算ASL 
		if(ha[i].key!=NULLKEY && ha[i].key!=DELKEY)	//判断有效关键字 
			avg=avg+ha[i].count;
	avg=avg/n;	//计算ASL 
	printf("    平均查找长度ASL(%d)=%g\n",n,avg);
}

int main()
{
	int x[]={16,74,60,43,54,90,46,31,29,88,77};
	int n=11,m=13,p=13,i,k=29;	//n为实时有效关键字数量，m为表长，p为哈希函数除数，k就是一个普通的关键字 
	HashTable ha[MaxSize];
	printf("(1)创建哈希表\n");
	CreateHT(ha,x,n,m,p);
	printf("(2)输出哈希表:\n");
	DispHT(ha,n,m);
	printf("(3)查找关键字为%d的记录位置\n",k);
	i=SearchHT(ha,m,p,k);
	if(i!=-1)	printf("   ha[%d].key=%d\n",i,k);
	else printf("   提示：未找到%d\n",k);
	k=77;
	printf("(4)删除关键字%d\n",k);
	DeleteHT(ha,m,p,n,k);
	printf("(5)删除后的哈希表\n");
	DispHT(ha,n,m);
	printf("(6)查找关键字为%d的记录位置\n",k);
	i = SearchHT(ha,m,p,k);
	if(i!=-1)	printf("	ha[%d].key=%d\n",i,k);
	else printf("   提示：我找到%d\n",k);
	printf("(7)输入关键字%d\n",k);
	InsertHT(ha,n,m,p,k);
	printf("(8)插入后的哈希表\n");
	DispHT(ha,n,m);
	return 0;
}
