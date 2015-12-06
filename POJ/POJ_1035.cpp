#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
#include <string>
#include <math.h>
#include <iostream>
using namespace std;
map<string,int> mp;
bool cmp(const string& a,const string& b)
{
	return mp[a]<mp[b];
}
int main()
{
	//freopen("prob.out","w",stdout);
	string w;
	char s[100];
	while(scanf("%s",s)&&s[0]!='#')
	{
		w=(string)s;
		mp[w]=mp.size();
	}
	while(scanf("%s",s)&&s[0]!='#')
	{
		w=(string)s;
		vector<string> modified;
		if(mp.count(w))
		{
			cout<<w<<" is correct\n";
			continue;
		}
		cout<<w<<':';
		string t;
		for(int i=0; i<w.size(); i++)
		{
			t=w;
			t.erase(t.begin()+i);
			if(mp.count(t))
				modified.push_back(t);
			for(char j='a'; j<='z'; j++)
			{
				t=w;
				t.insert(t.begin()+i,j);
				if(mp.count(t))
					modified.push_back(t);
				t=w;
				t.erase(t.begin()+i);
				t.insert(t.begin()+i,j);
				if(mp.count(t))
					modified.push_back(t);
			}
		}
		for(char i='a'; i<='z'; i++)
		{
			t=w;
			t.insert(t.end(),i);
			if(mp.count(t))
				modified.push_back(t);
		}
		sort(modified.begin(),modified.end(),cmp);
		for(int i=0; i<modified.size(); i++)
			if(i==0||modified[i]!=modified[i-1])
				cout<<' '<<modified[i];
		cout<<endl;
	}
	return 0;
}
