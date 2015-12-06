#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;
struct Item
{
	int s,b;
	Item(int a,int c):s(a),b(c){}
	bool operator<(const Item& t) const{return s>t.s;}
};
void solve(int* A,int* B,int* C,int n)
{
	priority_queue<Item> pq;
	for(int i=1; i<=n; i++)
		pq.push(Item(A[i]+B[1],1));
	for(int i=1; i<=n; i++)
	{
		Item t=pq.top();
		C[i]=t.s;
		//printf("%d %d\n",t.s,t.b);
		pq.pop();
		if(t.b<n)
			pq.push(Item(t.s-B[t.b]+B[t.b+1],t.b+1));
	}
}
int main()
{
	int A[1000],B[1000],n;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=1; i<=n; i++)
			scanf("%d",&A[i]);
		sort(A+1,A+n+1);
		for(int i=2; i<=n; i++)
		{
			for(int j=1; j<=n; j++)
				scanf("%d",&B[j]);
			sort(B+1,B+n+1);
			solve(A,B,A,n);
		}
		printf("%d",A[1]);
		for(int i=2; i<=n; i++)
			printf(" %d",A[i]);
		printf("\n");
	}
	return 0;
}
