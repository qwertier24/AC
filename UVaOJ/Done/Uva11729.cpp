#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;
struct employee
{
	int b,j;
}Em[1001];
int cmp(const void* a, const void* b)
{
	return ((struct employee*)b)->j - ((struct employee*)a)->j;
}
int main()
{
	int n,c=0;
	while(true)
	{
		c++;
		int t=0;
		cin>>n;
		if(!n)
			return 0;
		for(int i=0; i<n; i++)
			cin>>Em[i].b>>Em[i].j;
		qsort(Em,n,sizeof(struct employee),cmp);
		int m=0;
		for (int i=0; i<n; i++)
		{
			m+=Em[i].b;
			t=t>(m+Em[i].j)?t:(m+Em[i].j);
		}
		cout<<"Case "<<c<<": "<<t<<"\n";
	}
	return 0;
}
