#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
#include <string>
#include <math.h>
using namespace std;
char s1[100010],s2[100010];
int len1,len2;
int main()
{
	while(scanf("%s%s",s1,s2)!=EOF)
	{
		int p1=0,p2=0;
		len1=strlen(s1);
		len2=strlen(s2);
		while(p1<len1&&p2<len2)
		{
			while(p2<len2&&s1[p1]!=s2[p2])
				p2++;
			if(p2!=len2)
			{
			p1++;
			p2++;
			}
		}
		if(p1==len1)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
