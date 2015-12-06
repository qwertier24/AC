/*
ID: mayukun3
PROG: calfflac
LANG: C++
*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <algorithm>
using namespace std;
char change(char a)
{
     if(isupper(a))
                   return a-'A'+'a';
     else
         return a;
}
char s0[20010],s1[20010];
int p1_p0[20010];
int main()
{
	FILE* fin=fopen("calfflac.in","r");
	freopen("calfflac.out","w",stdout);
    int m=-1,ans=0,l=0,r=0;
    s0[0]='\0';
    while(fgets(s0+strlen(s0),90,fin)!=NULL)
    {}
    for(int i=0; i<strlen(s0); i++)
    {
           // printf("%c",s0[i]);
            if(isalpha(s0[i]))
            {
              s1[++m]=change(s0[i]);
               p1_p0[m]=i;         
            }
    }
    for(int i=0; i<=m; i++)
    {
            for(int j=0; j<=min(i,m-i); j++)
            {
                    if(s1[i+j]!=s1[i-j])
                    {
                     if(ans<j*2-1)
                     {
                         l=i-j+1;
                         r=i+j-1;
                         ans=(j-1)*2+1;
                     }
                     break;
                    }
                    else if(j==min(i,m-i) && ans<j*2+1)
                    {
                         ans=j*2+1;
                         l=i-j;
                         r=i+j;
                    }
            }
            for(int j=0; j<=min(m-1-i,i); j++)
            {
                    if(s1[i-j]!=s1[i+j+1])
                    {
                     if(ans<j*2)
                     {
                      l=i-j+1;
                      r=i+j;
                      ans=j*2;
                     }
                     break;
                    }
                    else if(j==min(m-1-i,i) && ans<(j+1)*2)
                    {
                         l=i-j;
                         r=i+j+1;
                         ans=(j+1)*2;
                    }
            }
    }
    printf("%d\n",ans);
    for(int i=p1_p0[l]; i<=p1_p0[r]; i++)
    printf("%c",s0[i]);
    printf("\n");
    return 0;
}
