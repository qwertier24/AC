/*
ID: mayukun3
PROG: gift1
LANG: C++
*/
#include <stdio.h>
#include <string>
#include <map>
#include <iostream>
#include <string.h>
using namespace std;
struct person
{
	string name;
	int money;
};
map<string,person> p;
string order[12];
int main()
{
	int n;
	string t;
	freopen("gift1.in","r",stdin);
	freopen("gift1.out","w",stdout);
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		cin>>order[i];
	for(int i=1; i<=n; i++)
	{
		int outcome,o;
		cin>>t;
		p[t].name=t;
		scanf("%d %d",&outcome,&o);
		p[t].money-=outcome;
		if(o)
			p[t].money+=outcome%o;
		for(int j=1; j<=o; j++)
		{
			cin>>t;
			p[t].money+=outcome/o;
		}
	}
	for(int i=1; i<=n; i++)
		cout<<p[order[i]].name<<' '<<p[order[i]].money<<endl;
	return 0;
}
