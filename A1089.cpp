#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn=111;
int origin[maxn],tempOri[maxn],changed[maxn];
int n;
bool isSame(int a[],int b[])
{
	int i;
	for(i=0;i<n;i++)
	{
		if(a[i]!=b[i])			//只要有任何一个元素不相同,就不same
			return false;
	}
	return true;
}

bool showArray(int a[])			//输出数组
{
	int i;						
	for(i=0;i<n;i++)
	{
		printf("%d",a[i]);
		if(i<n-1)	
			printf(" ");
	}
	printf("\n");
}

bool insertSort()				//插入排序
{
	int i;
	bool flag=false;			
		//记录是否有任何一个中间量与changed相同
	for(i=1;i<n;i++)						//第一个作为主元,进行n-1次排序
	{
		if(i!=1 && isSame(tempOri,changed))
			flag=true;						//任何一个时刻中间量与changed相同就是true
		int temp=tempOri[i];
		int j=i;
		while(j>0 && temp<tempOri[j-1])		
			//temp作为定值,tempOri[j]作为随着j变化而变化的值,既将temp不断向前比较直至最小或者到头为止
		{
			tempOri[j]=tempOri[j-1];
			j--;
		}
		tempOri[j]=temp;
		if(flag==true)
			return true;			//每次循环都不断比较是否相等,既中间量相等时停止循环
	}
	return false;					//没有任何相等的时候,返回false
}

void mergeSort()					//归并排序,注意是void
{
	int i;
	bool flag=false;
	int step;
	for(step=2;step/2<n;step*=2)	//课本上P141写step/2小于等于n,这里会段错误
	{
		if(step!=2 && isSame(tempOri,changed))
			flag=true;				//任何一个时刻中间量与changed相同就是true
		for(i=0;i<n;i+=step)
		{
			sort(tempOri+i,tempOri+min(i+step,n));
		}
		if(flag==true)
		{
			showArray(tempOri);		//void是没有返回值的,所以这里要showArray
			return;
		}
	}
}

int main()
{
	int i;
	scanf("%d",&n);				//注意还有个n
	for(i=0;i<n;i++)			//输入起始数组origin
	{
		scanf("%d",&origin[i]);
		tempOri[i]=origin[i];	//tempOri
	}
	for(i=0;i<n;i++)
	{
		scanf("%d",&changed[i]);//输入目标数组changed
	}
	if(insertSort())			//if insertSort==true,就是插入排序
	{
		printf("Insertion Sort\n");
		showArray(tempOri);
	}
	else						//否则就是归并排序
	{
		printf("Merge Sort\n");
		for(i=0;i<n;i++)
		{
			tempOri[i]=origin[i];//还原tempOri数组
		}
		mergeSort();			//mergeSort中带有一个showArray了
	}
	return 0;
}