#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
#include <string>
#include <math.h>
#define MAXN 1000001
using namespace std;
int is_prime[MAXN+10],semi[MAXN+10];
vector<int> primes,semi_primes;
void get_primes()
{
	memset(is_prime,-1,sizeof(is_prime));
	for(int i=5; i*i<=MAXN; i+=4)
		if(is_prime[i])
			for(int j=i; i*j<=MAXN; j+=4)
				is_prime[i*j]=0;
	for(int i=1; i*4+1<=MAXN; i++)
		if(is_prime[i*4+1])
			primes.push_back(i*4+1);
}
int main()
{
	int h;
	get_primes();
	memset(semi,0,sizeof(semi));
	for(int i=0; i<primes.size(); i++)
		for(int j=0; primes[i]*primes[j]<=MAXN; j++)
			semi[primes[i]*primes[j]]=1;
	for(int i=5; i<=MAXN; i++)
		if(semi[i])
			semi_primes.push_back(i);
	//for(int i=0; i<10; i++)
		//printf("%d\n",primes[i]);
	//printf("%d",primes.size());
	while(scanf("%d",&h)&&h)
	{
		printf("%d %d\n",h,upper_bound(semi_primes.begin(),semi_primes.end(),h)-semi_primes.begin());
	}
	return 0;
}
