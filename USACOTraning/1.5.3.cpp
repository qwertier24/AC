/*
ID: mayukun3
PROG: pprime
LANG: C++
*/
#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
bool prime(int a)
{
	int loop=floor(sqrt(a));
	for(int i=2; i<=loop; i++)
		if(a%i==0)
			return false;
	return true;
}
vector<int> v;
int main()
{
	int l,r;
	freopen("pprime.in","r",stdin);
	freopen("pprime.out","w",stdout);
	scanf("%d%d",&l,&r);
	v.push_back(2);v.push_back(3);v.push_back(5);v.push_back(7);
	for(int i=1; i<=9; i++)
		if(prime(i*10+i))
			v.push_back(i*10+i);
	for(int i=1; i<=9; i++)
		for(int j=0; j<=9; j++)
		{
			if(prime(i*100+j*10+i))
				v.push_back(i*100+j*10+i);
			if(prime(i*1000+j*100+j*10+i))
				v.push_back(i*1000+j*100+j*10+i);
		}
	for(int i=1; i<=9; i++)
		for(int j=0; j<=9; j++)
			for(int k=0; k<10; k++)
			{
				if(prime(i*10000+j*1000+k*100+j*10+i))
					v.push_back(i*10000+j*1000+k*100+j*10+i);
				if(prime(i*100001+j*10010+k*1100))
					v.push_back(i*100001+j*10010+k*1100);
			}
	for(int i=1; i<=9; i++)
		for(int j=0; j<10; j++)
			for(int k=0; k<10; k++)
				for(int l=0; l<10; l++)
				{
					if(prime(i*1000001+j*100010+k*10100+l*1000))
						v.push_back(i*1000001+j*100010+k*10100+l*1000);
					if(prime(i*10000001+j*1000010+k*100100+l*11000))
						v.push_back(i*1000001+j*100010+k*10100+l*1000);
				}
	sort(v.begin(),v.end());
	for(int i=0; i<v.size(); i++)
		if(v[i]>=l&&v[i]<=r)
		printf("%d\n",v[i]);
	return 0;
}
