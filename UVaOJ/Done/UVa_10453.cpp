#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int d[1010][1010],len,ans,p;
char s1[1010],s2[1010],s3[3000];
void reserve(int len)
{
	for(int i=0; i<len; i++)
	s2[i]=s1[len-i-1];
	s2[len]='\0';
}
void push(char t)
{
	s3[p]=s3[len+ans-1-p]=t;
	p--;
}
int main()
{
	//freopen("prob.in","r",stdin);
	//freopen("prob.out","w",stdout);
	while(scanf("%s",s1)!=EOF)
	{
		len=strlen(s1);
		ans=len;
		int pos,odd;
		reserve(len);
		for(int i=0; i<len; i++)
			for(int j=0; j<len; j++)
			{
				if(i==0||j==0)
				{
					if(s1[i]==s2[j])d[i][j]=1;
					else d[i][j]=0,d[i][j]=d[i==0?0:i-1][j==0?0:j-1];
				}
				else
				{
					if(s1[i]==s2[j])
						d[i][j]=d[i-1][j-1]+1;
					else
						d[i][j]=max(d[i-1][j],d[i][j-1]);
				}
			}
		for(int i=0; i<len; i++)
			if(ans>len-1-(d[i][len-1-i]-1)*2)
				ans=len-1-(d[i][len-1-i]-1)*2,pos=i,odd=1;
		for(int i=0; i<len-1; i++)
			if(ans>len-2*(d[i][len-i-2]))
				ans=len-2*(d[i][len-i-2]),pos=i,odd=0;
		if(odd)
		{
			int l1=pos-1,r1=pos+1;
			s3[(len+ans+1)/2-1]=s1[pos];
			p=(len+ans+1)/2-2;
			for(int i=d[pos][len-1-pos]-1; i>=1; i--)
			{
				bool found=false;
				for(int l2=l1; l2>=0&&!found; l2--)
					for(int r2=r1; r2<len; r2++)
						if(d[l2][len-1-r2]==i&&s1[l2]==s1[r2])
						{
							for(int j=l1; j>=l2+1; j--)
								push(s1[j]);
							for(int j=r1; j<=r2-1; j++)
								push(s1[j]);
							push(s1[l2]);
							//printf("%d %d\n",l2,r2);
							l1=l2-1;
							r1=r2+1;
							found=true;
							break;
						}
			}
			//printf("%d %d\n",l1,r1);
			for(int i=l1; i>=0; i--)
				push(s1[i]);
			for(int i=r1; i<len; i++)
				push(s1[i]);
			s3[len+ans]='\0';
			printf("%d %s\n",ans,s3);
		}
		else
		{
			int l1=pos,r1=pos+1;
			//printf("%d %d\n",pos,ans);
			p=(len+ans)/2-1;
			for(int i=d[pos][len-1-pos]; i>=1; i--)
			{
				bool found=false;
				for(int l2=l1; l2>=0&&!found; l2--)
					for(int r2=r1; r2<len; r2++)
						if(d[l2][len-1-r2]==i&&s1[l2]==s1[r2])
						{
							for(int j=l1; j>=l2+1; j--)
								push(s1[j]);
							for(int j=r1; j<=r2-1; j++)
								push(s1[j]);
							push(s1[l2]);
							//printf("%d %d\n",l2,r2);
							l1=l2-1;
							r1=r2+1;
							found=true;
							break;
						}
			}
			//printf("%d %d\n",l1,r1);
			for(int i=l1; i>=0; i--)
				push(s1[i]);
			for(int i=r1; i<len; i++)
				push(s1[i]);
			s3[len+ans]='\0';
			printf("%d %s\n",ans,s3);
		}
	}
	return 0;
}
