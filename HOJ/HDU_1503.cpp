#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;
char s1[200],s2[200],ans[500];
int d[200][200]={0},p;
void push(char t)
{
	ans[p--]=t;
	//printf("%d %c\n",p+1,t);
}
int main()
{
	int n1,n2,r1,r2,length;
	while(scanf("%s%s",s1+1,s2+1)!=EOF)
	{
		n1=strlen(s1+1),n2=strlen(s2+1);
		memset(d,0,sizeof(d));
		for(int i=1; i<=n1; i++)
			for(int j=1; j<=n2; j++)
				d[i][j]=(s1[i]==s2[j]?d[i-1][j-1]+1:max(d[i-1][j],d[i][j-1]));
		p=n1+n2-d[n1][n2];
		ans[p--]='\0';
		r1=n1,r2=n2;
		length=d[n1][n2];
		for(int length=d[n1][n2]; length; length--)
		{
			bool found=false;
			for(int l1=r1; l1>=1&&!found; l1--)
				for(int l2=r2; l2>=1; l2--)
						if(s1[l1]==s2[l2]&&d[l1][l2]==length)
						{
							//printf("%d %d %d\n",l1,l2,length);
							for(int i=r1; i>l1; i--)
								push(s1[i]);
							for(int i=r2; i>l2; i--)
								push(s2[i]);
							push(s1[l1]);
							r1=l1-1;
							r2=l2-1;
							found=true;
							break;
						}
		}
		for(int i=r1; i>=1; i--)
			push(s1[i]);
		for(int i=r2; i>=1; i--)
			push(s2[i]);
		printf("%s\n",ans);
	}
	return 0;
}
