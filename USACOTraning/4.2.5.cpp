/*
ID: mayukun3
PROG: cowcycle
LANG: C++
*/
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>
#define ONLINE
using namespace std;
int front_n,back_n,front_l,front_r,back_l,back_r;
double min_var=1e30;
vector<vector<int> > lunzi[2];
vector<int> ans_f,ans_b;
double calc_var(vector<int>& front,vector<int>& back)
{
	double t[55],minus[55];
	int lt=0,lm=0;
	double ave=0,var=0;
	for(int i=0; i<front_n; i++)
		for(int j=0; j<back_n; j++)
			t[lt++]=front[i]/(double)back[j];
	sort(t,t+lt);
	for(int i=0; i<lt-1; i++)
		minus[lm++]=fabs(t[i]-t[i+1]);
	for(int i=0; i<lm; i++)
		ave+=minus[i];
	ave/=lm;
	for(int i=0; i<lm; i++)
		var+=(minus[i]*minus[i]-ave*ave);
	return var/lm;
}
bool check(int cur_l,int cur_r,int back)
{
	if(back)
		return cur_l*front_l*3<=cur_r*front_r;
	else
		return cur_l*back_l*3<=cur_r*back_r;
}
void print(vector<int> v)
{
	for(int i=0; i<v.size(); i++)
		printf("%d ",v[i]);
	printf("\n");
}
void search(int pos,int r,int rem,int back,vector<int>& v)
{
	//print(v);
	if(rem>r-pos+1)
		return;
	if(rem==0)
	{
		if(check(v[0],v[v.size()-1],back))
		{
			lunzi[back].push_back(v);
		}
		return;
	}
	for(int i=pos; i<=r; i++)
	{
		v.push_back(i);
		search(i+1,r,rem-1,back,v);
		v.pop_back();
	}
}
int main()
{
#ifdef ONLINE
	freopen("cowcycle.in","r",stdin);
	freopen("cowcycle.out","w",stdout);
#endif
	scanf("%d%d%d%d%d%d",&front_n,&back_n,&front_l,&front_r,&back_l,&back_r);
	for(int i=front_l; i<=front_r; i++)
		if(i*back_l*3<=front_r*back_r)
		{
			vector<int> v(0,10);
			search(i,front_r,front_n,0,v);
			break;
		}
	for(int i=back_l; i<=back_r; i++)
		if(i*front_l*3<=front_r*back_r)
		{
			vector<int> v(0,10);
			search(i,back_r,back_n,1,v);
			break;
		}
	vector<vector<int> >& front_s=lunzi[0];
	vector<vector<int> >& back_s=lunzi[1];
	for(int i=0; i<front_s.size(); i++)
	{
		vector<int>& front=front_s[i];
		for(int j=0; j<back_s.size(); j++)
		{
			vector<int>& back=back_s[j];
			if(front[0]*back[0]*3<=front[front.size()-1]*back[back.size()-1])
			{
				double var=calc_var(front,back);
				if(var<min_var)
				{
					min_var=var;
					ans_f=front;
					ans_b=back;
				}
			}
		}
	}
	//printf("%d",ans_f.size());
	for(int i=0; i<ans_f.size()-1; i++)
		printf("%d ",ans_f[i]);
	printf("%d\n",ans_f[front_n-1]);
	for(int i=0; i<ans_b.size()-1; i++)
		printf("%d ",ans_b[i]);
	printf("%d\n",ans_b[back_n-1]);
	return 0;
}
//fr*br>=3fl*bl
