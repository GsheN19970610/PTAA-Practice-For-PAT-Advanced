#include<stdio.h>
#include<string.h>
int main()
{
	char number[10010];
	gets(number);
	int power=0,pos=0;
	if(number[0]=='-')
		printf("-");
	while(number[pos]!='E')					//’‚¿Ô”√while
		pos++;
	int i,j,len;
	len=strlen(number);
	for(i=pos+2;i<len;i++)
	{
		power=power*10+(number[i]-'0');
	}
	if(power==0)
	{
		for(i=1;i<pos;i++)
			printf("%c",number[i]);
	}
	else if(number[pos+1]=='-')
	{
		printf("0.");
		for(i=0;i<power-1;i++)
			printf("0");
		printf("%c",number[1]);
		for(j=3;j<pos;j++)
		{
			printf("%c",number[j]);
		}
	}
	else
	{
		for(i=1;i<pos;i++)
		{
			if(number[i]=='.')
				continue;
			printf("%c",number[i]);
			if(i==power+2 && pos-3!=power)
				printf(".");
		}
		for(i=0;i<power-(pos-3);i++)
		{
			printf("0");
		}
	}
	return 0;
}
