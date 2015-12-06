#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <map>
#define PROB "clumsy"
using namespace std;
char s[100010];
int main(){
	freopen(PROB".in","r",stdin);
	freopen(PROB".out","w",stdout);
	int l=0;
	scanf("%s",s);
	int len=strlen(s),ans=0;
	for(int i=0; i<len; i++){
		if(s[i]=='(')
			l++;
		else{
			if(l)
				l--;
			else{
				ans++;
				l++;
			}
		}
	}
	printf("%d",ans+l/2);
	return 0;
}

