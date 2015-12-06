#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <map>
#define PROB "bbreeds"

using namespace std;

#define MOD 2012
char s[1010];
int d[1010][1010];
int main(){
	freopen(PROB".in","r",stdin);
	freopen(PROB".out","w",stdout);
	scanf("%s",s+1);
	int len=strlen(s+1);
	d[0][0]=1;
	int l=0;
	for(int i=1; i<=len; i++){
		if(s[i]=='(')l++;
		else l--;
		for(int j=0; j<=l; j++)
			if(s[i]==')')
				d[i][j]=(d[i-1][j+1]+d[i-1][j])%MOD;
			else
				d[i][j]=((j>0?d[i-1][j-1]:0)+d[i-1][j])%MOD;
	}
	printf("%d",!l?d[len][0]:0);
	return 0;
}

