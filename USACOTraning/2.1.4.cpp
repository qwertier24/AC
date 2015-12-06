/*
ID: mayukun3
PROG: frac1
LANG: C++
*/
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
struct Pair
{
	int a,b;
	Pair(int x,int y):a(x),b(y){}
	bool operator< (const Pair& rhs) const
	{
		return (double)a/b < (double)rhs.a/rhs.b;
	}
};
bool huzhi(int a,int b)
{
	for(int i=2; i<=a; i++)
		if(a%i==0 && b%i==0)
			return false;
	return true;
}
int main()
{
	vector<Pair> v;
	int n;
	freopen("frac1.in","r",stdin);
	freopen("frac1.out","w",stdout);
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		for(int j=i; j<=n; j++)
			if(huzhi(i,j))
				v.push_back(Pair(i,j));
	sort(v.begin(),v.end());
	printf("0/1\n");
	for(int i=0; i<v.size(); i++)
		printf("%d/%d\n",v[i].a,v[i].b);
}