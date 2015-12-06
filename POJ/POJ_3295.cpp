#include <stdio.h>
char opt[200];
int num[5];
int stage(char t)
{
	if(t=='p'||t=='q'||t=='r'||t=='s'||t=='t')return 0;
	else if(t=='N')return 1;
	else return 2;
}
int val(char t)
{
	if(t=='p')return num[0];
	else if(t=='q')return num[1];
	else if(t=='r')return num[2];
	else if(t=='s')return num[3];
	else return num[4];
}
int modify(char t,int a,int b)
{
	if(t=='K')return a&b;
	else if(t=='A')return a|b;
	else if(t=='C')return (a<=b);
	else return a==b;
}
int search(int p)
{
	//printf("%d\n",p);
	if(stage(opt[p])==0)
		return p*2+val(opt[p]);
	else if(stage(opt[p])==1)
		return search(p+1)^1;
	else
	{
		int t1=search(p+1);
		int t2=search(t1/2+1);
		//printf("%d %d %d %d %d\n",p,t1,t2,modify(opt[p],t1%2,t2%2), (t2/2)*2+modify(opt[p],t1%2,t2%2));
		return (t2/2)*2+modify(opt[p],t1%2,t2%2);
	}
}
int main()
{
	//freopen("prob.out","w",stdout);
	while(scanf("%s",opt)&&opt[0]!='0')
	{
		bool ok=true;
		for(int i=0; i<(1<<5); i++)
		{
			for(int j=0; j<5; j++)
				num[j]=(i>>j)&1;
			if(!(search(0)%2))
			{
				ok=false;
				break;
			}
		}
		if(ok)
			printf("tautology\n");
		else
			printf("not\n");
	}
	return 0;
}
