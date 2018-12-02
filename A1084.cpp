#include<stdio.h>
#include<string.h>
int main()
{
	int i,j;
	char c1,c2;
	char str1[100];
	char str2[100];
	bool HashTable[128]={false};
	gets(str1);
	gets(str2);
	int len1=strlen(str1);
	int len2=strlen(str2);
	for(i=0;i<len1;i++)
	{
		for(j=0;j<len2;j++)
		{	
			c1=str1[i];
			c2=str2[j];
			if(c1>='a'&&c1<='z')	c1=c1-32;
			if(c2>='a'&&c2<='z')	c2=c2-32;
			if(c1==c2)	break;
		}
		if(j==len2 && HashTable[c1]==false)		
			//即前面的循环读到底,在str2中未出现c1字符 && c1字符未被输出
		{
			printf("%c",c1);
			HashTable[c1]=true;
		}
	}
	return 0;
}