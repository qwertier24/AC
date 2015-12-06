#include <stdio.h>
#include <string>
#include <iostream>
const int MOD=(1<<30)/1000;
using namespace std;
bool exist(const string& s,char t)
{
	int len=s.size();
	for(int i=0; i<len; i++)
		if(s[i]==t)
			return true;
	return false;
}
void cpy(const string& s,char s1[])
{
	int len=s.size();
	for(int i=0; i<len; i++)
		s1[i]=s[i];
	s1[len]='\0';
}
int main()
{
	char t=getchar();
	int kase=0;
	while(t!='.')
	{
		bool ok=true;
		char s1[1000];
		int c,b,k,d,num[120]={0};
		string s;
		t=getchar();
		while((s.size()==0) || (t!='+' && t!='-' && t!=')'))
		{
			s+=t;
			t=getchar();
		}
		if(s[0]=='n')
			s.insert(0,"1");
		if(s[0]=='-'&&s[1]=='n')
			s.insert(1,"1");
		if(!exist(s,'^'))
		{
			if(!exist(s,'n'))
				s+="n^0";
			else
				s+="^1";
		}
		cpy(s,s1);
		sscanf(s1,"%dn^%d",&c,&b);
		k=b;
		for(int i=1; i<=k+1; i++)
		{
			int numt=1;
			for(int j=1; j<=b; j++)
				numt=(numt*i)%MOD;
			num[i]=(num[i]+c*numt)%MOD;
		}
		while(t!=')')
		{
			s.clear();
			while((s.size()==0) ||(t!='+'  && t!='-' && t!=')'))
			{
				s+=t;
				t=getchar();
			}
			if(s[1]=='n')
				s.insert(1,"1");
			if(!exist(s,'^'))
			{
				if(!exist(s,'n'))
					s+="n^0";
				else
					s+="^1";
			}
			cpy(s,s1);
			sscanf(s1,"%dn^%d",&c,&b);
			for(int i=1; i<=k+1; i++)
			{
				int numt=1;
				for(int j=1; j<=b; j++)
					numt=(numt*i)%MOD;
				num[i]=(num[i]+c*numt)%MOD;
			}
			//cout<<"S:"<<s<<"T:"<<t<<endl;
		}
		s.clear();
		t=getchar();
		t=getchar();
		while(t!='.' && t!='(')
		{
			s+=t;
			t=getchar();
		}
		cpy(s,s1);
		sscanf(s1,"%d",&d);
		for(int i=1; i<=k+1; i++)
			if(num[i]%d)
			{
				ok=false;
				break;
			}
		if(ok)
			printf("Case %d: Always an integer\n",++kase);
		else
			printf("Case %d: Not always an integer\n",++kase);

	}
	return 0;
}
