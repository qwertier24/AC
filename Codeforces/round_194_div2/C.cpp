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
int num[1000],len=0,cnt=0;
int main()
{
	long long n,ans=0;
	cin>>n;
	long long t=n;
	int flag=0;
	while(t)
	{
		num[++len]=t%3;
		if(num[len]&&!flag)
			flag=len;
		t/=3;
		cnt+=num[len];
	}
	t=1l;
	//cout<<flag<<endl;
	for(int i=flag+1; i<=len ;i++)
	{
		ans+=t*(long long)num[i];
		t*=3l;
	}
	cout<<ans+1;
	return 0;
}
