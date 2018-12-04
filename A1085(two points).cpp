#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn=100010;
int main()
{
	int a[maxn];
	int n,p;
	int i,j;
	scanf("%d %d",&n,&p);
	int ans=1;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	i=0;								
	//这里很重要的一点就是i要重新归零,因为在上面的运算中i被加到了n
	j=0;
	while(i<n && j<n)
	{
		while(j<n && a[j]<=(long)a[i]*p)
		{
			ans=max(ans,j-i+1);			//j-i+1
			j++;
		}
		i++;
	}
	printf("%d",ans);
	return 0; 
}