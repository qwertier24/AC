#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;
char number[1010][1010]={"","one","two","three","four","five","six","seven","eight","nine","ten",
"eleven","twelve","thirteen","fourteen", "fifteen","sixteen", "seventeen", "eighteen", "nineteen"};
int n;
char ty[12][100]={"","ten","twenty", "thirty", "forty","fifty", "sixty", "seventy", "eighty", "ninety"};
char word[21][1010];
void add(char* s1,char* s2){
	int len1=strlen(s1),len2=strlen(s2);
	for(int i=len1; i<len1+len2; i++)
		s1[i]=s2[i-len1];
	s1[len1+len2]='\0';
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif
	int cnt=0;
	scanf("%d",&n);
	for(int i=1; i<=n; i++)scanf("%s",word[i]);
	for(int i=1; i<=n; i++)
		cnt+=strlen(word[i]);
	cnt--;
	int ans;
	for(int i=20; i<1000; i++){
		if(i>100){
			add(number[i],number[i/100]);
			add(number[i],"hundred");
		}
		int t=i;
		t%=100;
		if(t>=20){
			add(number[i],ty[t/10]);
			add(number[i],number[t%10]);
		}else
			add(number[i],number[t]);
	}
	for(int i=1; i<1000; i++)
		if(strlen(number[i])+cnt==i){
			ans=i;
			break;
		}
	for(int i=1; i<=n; i++){
		if(word[i][0]=='$')
			printf("%s ",number[ans]);
		else
			printf("%s ",word[i]);
	}
	return 0;
}
