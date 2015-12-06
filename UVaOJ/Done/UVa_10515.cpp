#include <stdio.h>
#include <string.h>
char sm[200],sn[200];
struct BIGN
{
	int len,num[500],p;
	void Init(char s[])
	{
		p=1;
		len=strlen(s);
		for(int i=1; i<=len; i++)
			num[i]=s[len-i]-'0';
	}
}n;
int main()
{
	while(scanf("%s%s",sm,sn)&&(sm[0]!='0'||sn[0]!='0'))
	{
		int m=1,t=sm[strlen(sm)-1]-'0';
		n.Init(sn);
		while(n.len-n.p+1)
		{
			//printf("%d %d\n",n.len-n.p,t);
			for(int i=1; i<=n.num[n.p]; i++)
				m=(m*t)%10;
			int t1=t;
			for(int i=1; i<10; i++)
				t=(t1*t)%10;
			n.p++;
		}
		printf("%d\n",m);
	}
	return 0;
}
