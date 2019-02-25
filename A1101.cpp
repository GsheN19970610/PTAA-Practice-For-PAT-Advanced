#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn=100010;
const int inf=0x3fffffff;
int leftmax[maxn],rightmin[maxn];
int main()
{
	int n,i;
	int number[100010];
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&number[i]);
	leftmax[0]=0;
	for(i=1;i<n;i++)
	{
		if(number[i-1]>leftmax[i-1])
			leftmax[i]=number[i-1];
		else
			leftmax[i]=leftmax[i-1];
	}
	rightmin[n-1]=inf;						//这里要足够大
	for(i=n-2;i>=0;i--)
	{
		if(number[i+1]<rightmin[i+1])
			rightmin[i]=number[i+1];
		else
			rightmin[i]=rightmin[i+1];
	}
	int count=0,num[100010];
	for(i=0;i<n;i++)
	{
		if(number[i]>leftmax[i] && number[i]<rightmin[i])
			num[count++]=number[i];
	}
	printf("%d\n",count);
	for(i=0;i<count;i++)
	{
		printf("%d",num[i]);
		if(i<count-1)
			printf(" ");
	}
	printf("\n");
	return 0;
}
