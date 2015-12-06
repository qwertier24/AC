#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
#include <string>
#include <math.h>
using namespace std;
int pow10_mod[110][80000],is_prime[1000010];
char s[110];
int num[100],num_len;
vector<int> primes;
void get_primes()
{
	memset(is_prime,-1,sizeof(is_prime));
	for(int i=2; i<=1E3; i++)
		if(is_prime[i])
			for(int j=i*i; j<=1E6; j+=i)
				is_prime[j]=0;
	for(int i=2; i<=1E6; i++)
		if(is_prime[i])
			primes.push_back(i);
}
void reverse(int n)
{
	for(int i=0; i<n/2; i++)
		swap(s[i],s[n-i-1]);
}
int main()
{
	get_primes();
	//printf("%d\n",primes.size());
	int l;
	for(int i=0; i<primes.size(); i++)
		pow10_mod[0][i]=1;
	for(int i=1; i<=100; i++)
		for(int j=0; j<primes.size(); j++)
			pow10_mod[i][j]=(pow10_mod[i-1][j]*10)%primes[j];
	while(scanf("%s %d",s,&l)&&(s[0]!='0'||l))
	{
		int p=0;
		int len=strlen(s);
		reverse(len);
		//printf("%s\n",s);
		memset(num,0,sizeof(num));
		for(int i=0; i<=(len-1)/4; i++)
			for(int j=min((i+1)*4-1,len-1); j>=i*4; j--)
				num[i]=num[i]*10+s[j]-'0';
		num_len=(len-1)/4+1;
		//for(int i=0; i<num_len; i++)
		//	printf("%d \n",num[i]);
		bool bad=false;
		while(primes[p]<l&&p<primes.size())
		{
			//printf("%d\n",primes[p]);
			int mod=0;
			for(int i=0; i<num_len; i++)
				mod=(mod+(long long)pow10_mod[i*4][p]*num[i])%primes[p];
			if(!mod)
			{
				printf("BAD %d\n",primes[p]);
				bad=true;
				break;
			}
			p++;
		}
		if(!bad)
			printf("GOOD\n");
	}
	return 0;
}
