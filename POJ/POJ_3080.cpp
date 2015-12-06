#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
#include <string>
#include <math.h>
using namespace std;
bool cmp(const string& a,const string& b)
{
	return a.size()>b.size()||(a.size()==b.size()&&a<b);
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		vector<string> dna;
		vector<string> substr;
		bool ok[4001];
		for(int i=0; i<4000; i++)
			ok[i]=true;
		scanf("%d",&n);
		for(int i=1; i<=n; i++)
		{
			char s[70];
			scanf("%s",s);
			dna.push_back((string)s);
		}
		for(int i=3; i<=60; i++)
			for(int l=0; l+i-1<dna[0].size(); l++)
			{
				substr.push_back(dna[0].substr(l,i));
			}
		sort(substr.begin(),substr.end(),cmp);
		for(int i=1; i<dna.size(); i++)
			for(int k=0; k<substr.size(); k++)
				if(ok[k])
				{
					//printf("%d %d %d %s %s\n",i,j,k,dna[i].c_str(),substr[k].c_str());
					ok[k]=(dna[i].find(substr[k])!=string::npos);
				}
		bool found=false;
		for(int i=0; i<substr.size(); i++)
			if(ok[i])
			{
				printf("%s\n",substr[i].c_str());
				found=true;
				break;
			}
		if(!found)
			printf("no significant commonalities\n");
	}
	return 0;
}
