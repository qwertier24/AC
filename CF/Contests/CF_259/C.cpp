#include <stdio.h>
#include <algorithm>
#include <cstring>

using namespace std;
char s[100010];
int main(){
	scanf("%s",s);
	int len=strlen(s);
	for(int i=0; i<len; i++)
		if(s[i]=='0'){
			for(int j=0; j<i; j++)
				printf("%c",s[j]);
			for(int j=i+1; j<len; j++)
				printf("%c",s[j]);
			return 0;
		}
	for(int i=1; i<len; i++)
		printf("%c",s[i]);
	return 0;
}
