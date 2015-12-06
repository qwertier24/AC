#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
#include <string>
#include <math.h>
using namespace std;
int n=0,num[200];
char s[200];
int main()
{
	scanf("%s",s);
	for(int i=0; i<strlen(s); i+=2)
		num[n++]=s[i]-'0';
	sort(num,num+n);
	printf("%d",num[0]);
	for(int i=1; i<n; i++)
		printf("+%d",num[i]);
	return 0;
}
