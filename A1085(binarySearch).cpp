#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn=100010;
int n,p,a[maxn];

int binarySearch(int x,long y)
	//即在[i+1,n-1]范围内查找第一个大于y的数的位置
{
	if(a[n-1]<=y) return n;	
			//即y比所有数字都大(这是正整数数列,所以第一个不小于1,所以包含了所有的数字)
	int l=x+1,r=n-1,mid;
	while(l<r)
	{
		mid=(l+r)/2;		//在很大的数组中可以使用l+(r-l)/2
		if(a[mid]<=y)		//若a[mid]<=x,说明第一个大于x
			l=mid+1;
		else
			r=mid;
	}
	return l;				//结束的时候l=r,返回r和l都可以
}
int main()
{
	int i,j;
	int sum=1;				//意味着即使只有一个数的情况下,也应当是1,而不是j-i得出的0;
	scanf("%d %d",&n,&p);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a,a+n);			//注意要排序
	for(i=0;i<n;i++)
	{
		j=binarySearch(i,(long long)a[i]*p);		
						  //注意这里需要强制转换,不然最后一个就是错的,a[i]*p值可能超过int范围
		sum=max(sum,j-i);
	}
	printf("%d",sum);
	return 0;
}
