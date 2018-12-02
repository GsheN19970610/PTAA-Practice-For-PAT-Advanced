#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	int n,p,i,j;
	int a[100010];
	scanf("%d %d",&n,&p);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	int sum=1;
	for(i=0;i<n;i++)
	{
		j=upper_bound(a+i+1,a+n,(long long)a[i]*p)-a;   
		sum=max(sum,j-i);
	}
	printf("%d\n",sum);
	return 0;
}