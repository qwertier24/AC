/*
ID: mayukun3
PROG: namenum
LANG: C++
*/
#include <stdio.h>
#include <string.h>
char num_char[10]={0,0,'A','D','G','J','M','P','T','W'};
int char_num[30]={2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,-1,7,7,8,8,8,9,9,9,-1};
char s0[15];
int origin[15];
int n;
void getnum()
{
	scanf("%s",s0);
	n=strlen(s0);
	for(int i=0; i<n; i++)
	{
		origin[i]=s0[i]-'0';
	}
}
bool cmp(char s[])
{
	for(int i=0; i<n; i++)
		if(char_num[s[i]-'A']!=origin[i])
			return false;
	return true;
}
int main()
{
	bool none=true;
	char s[100];
	FILE* dict=fopen("dict.txt","r");
	freopen("namenum.in","r",stdin);
	freopen("namenum.out","w",stdout);
	getnum();
	while(fscanf(dict,"%s",s)!=EOF)
	{
		//printf("%s",s);
		if(strlen(s)==n)
		{
			if(cmp(s))
			{
				none=false;
				printf("%s\n",s);
			}
		}
	}
	if(none)printf("NONE\n");
}