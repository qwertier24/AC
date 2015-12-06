#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <ctype.h>
using namespace std;
char s[110];
bool check_minus(int p){
	return p>0&&s[p]=='-'&&((isalpha(s[p-1])&&isalpha(s[p+1])||(isdigit(s[p-1])&&isdigit(s[p+1]))));
}
int main(){
//#ifndef ONLINE_JUDGE
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
//#endif
	int p,k,rev;
	scanf("%d%d%d",&p,&k,&rev);
	if(rev==2)rev=-1;
	scanf("%s",s);
	int len=strlen(s);
	for(int i=0; i<len; i++){
		if(check_minus(i)){
			if(s[i-1]>=s[i+1])printf("%c",s[i]);
			else{
				char b=s[i-1]+1,e=s[i+1];
				if(rev==-1)b=s[i+1]-1,e=s[i-1];
				//printf("\n%c %c %d\n",b,e,i);
				if(isdigit(s[i-1])){
					if(p==3)
						for(char j=b; j!=e; j+=rev)
							for(int l=1; l<=k; l++)
								printf("*");
					else
						for(char j=b; j!=e; j+=rev)
							for(int l=1; l<=k; l++)
								printf("%c",j);
				}else{
					if(p==3)
						for(char j=b; j!=e; j+=rev)
							for(int l=1; l<=k; l++)
								printf("*");
					else if(p==1)
						for(char j=b; j!=e; j+=rev)
							for(int l=1; l<=k; l++)
								printf("%c",j);
					else
						for(char j=b; j!=e; j+=rev)
							for(int l=1; l<=k; l++)
								printf("%c",j-'a'+'A');
				}
			}
		}else printf("%c",s[i]);
	}
	return 0;
}
