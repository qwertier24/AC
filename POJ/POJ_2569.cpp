#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
#include <string>
#include <math.h>
#include <iostream>
#include <iomanip>   
using namespace std;
struct FREQUENCY
{
	char chr1,chr2;
	int fre;
	bool operator<(const FREQUENCY& rhs)const
	{
		return fre>rhs.fre||(fre==rhs.fre&&(chr1<rhs.chr1||(chr1==rhs.chr1&&chr2<rhs.chr2)));
	}
}f[256][256];
char s[64*80+10];
int main()
{
	int n;
	cout << fixed << showpoint;   
	while(scanf("%d",&n)&&n)
	{
		memset(s,0,sizeof(s));
		memset(f,0,sizeof(f));
		getchar();
		for(int i=1; i<=n; i++)
		{
			gets(s+strlen(s));
			//printf("\n%d %s\n",i,s);
		}
		int len=strlen(s);
		len--;
		for(int i=1; i<=len; i++)
		{
			//printf("%c %c\n",s[i-1],s[i]);
			f[s[i-1]][s[i]].fre++;
			f[s[i-1]][s[i]].chr1=s[i-1];
			f[s[i-1]][s[i]].chr2=s[i];
		}
		sort(*f,*f+256*256);
		//printf("%d\n",f[0][0].fre);
		for(FREQUENCY* iter=*f; iter-*f<5; iter++)
		{
			printf("%c%c %d ",iter->chr1,iter->chr2,iter->fre);
			cout<<setprecision(6)<<iter->fre/(double)len<<endl;
		}
		printf("\n");
	}
	return 0;
}
