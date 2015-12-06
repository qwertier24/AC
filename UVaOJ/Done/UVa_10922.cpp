#include <stdio.h>
#include <string.h>
char s[2000],num[2000];
void search(int cur,int deep)
{
	if(cur==9)
	{
		printf("%s is a multiple of 9 and has 9-degree %d.\n",s,deep);
		return;
	}
	int t=0;
	while(cur)
	{
		t+=cur%10;
		cur/=10;
	}
	search(t,deep+1);
}
int main()
{
	while(scanf("%s",s)&&s[0]!='0')
	{
		int t=0;
		for(int i=0; i<strlen(s); i++)
			t+=s[i]-'0';
		if(t%9)
			printf("%s is not a multiple of 9.\n",s);
		else
			search(t,1);
	}
	return 0;
}
