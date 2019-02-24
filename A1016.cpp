#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int maxn=1010;
int toll[25];
struct record{
	char id[25];
	int mon,day,hour,min;
	bool status;
}rec[maxn],temp;

bool cmp(record a,record b)
{
	int s;	
	s=strcmp(a.id,b.id);
	if(s!=0)
		return s<0;
	else if(a.mon!=b.mon)	return a.mon<b.mon;
	else if(a.day!=b.day)	return a.day<b.day;
	else if(a.hour!=b.hour)	return a.hour<b.hour;
	else return a.min<b.min;
}

void get_ans(int on,int off,int& time,int& money)
{
	temp=rec[on];
	while(temp.day<rec[off].day || temp.hour<rec[off].hour || temp.min<rec[off].min)
	{
		time++;
		money+=toll[temp.hour];
		temp.min++;
		if(temp.min>=60)
		{
			temp.min=0;
			temp.hour++;
		}
		if(temp.hour>=24)
		{
			temp.hour=0;
			temp.day++;
		}
	}
}
int main()
{
	int i;
	for(i=0;i<24;i++)
		scanf("%d",&toll[i]);
	int n;
	scanf("%d",&n);
	char line[10];
	for(i=0;i<n;i++)
	{
		scanf("%s",rec[i].id);
		scanf("%d:%d:%d:%d",&rec[i].mon,&rec[i].day,&rec[i].hour,&rec[i].min);
		scanf("%s",line);
		if(strcmp(line,"on-line")==0)
			rec[i].status=true;
		else
			rec[i].status=false;
	}
	sort(rec,rec+n,cmp);
	int on=0,off,next;
	while(on<n)
	{
		int needprint=0;
		next=on;
		while(next<n && strcmp(rec[next].id,rec[on].id)==0)
		{
			if(needprint==0 && rec[next].status==true)
				needprint=1;
			else if(needprint==1 && rec[next].status==false)
				needprint=2;
			next++;						//直到next找到不同名字,即下一用户
		}	
		if(needprint<2)
		{
			on=next;
			continue;				//没有找到配对的同名online和offline
		}
		int allmoney=0;
		printf("%s %02d\n",rec[on].id,rec[on].mon);
		while(on<next)
		{
			while(on<next-1 && !(rec[on].status==true && rec[on+1].status==false))
			{
				on++;
			}
			off=on+1;
			if(off==next)
			{
				on=next;
				break;
			}
			printf("%02d:%02d:%02d ",rec[on].day,rec[on].hour,rec[on].min);
			printf("%02d:%02d:%02d ",rec[off].day,rec[off].hour,rec[off].min);
			int time=0,money=0;
			get_ans(on,off,time,money);
			allmoney+=money;
			printf("%d $%.2f\n",time,money/100.0);
			on=off+1;
		}
		printf("Total amount: $%.2f\n",allmoney/100.0);
	}
	return 0;
}