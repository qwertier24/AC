#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <map>
#define PROB "alpha"
#define dbg if(0)
#define Rep(i) for(int i=n-1; i>=0; i--)
using namespace std;
int a_n[100],n_a[100],a[26],b[26],c[26],n;
bool found=false;
bool check_pos(int p){
	for(int i=p; i<n; i++){
		if(a_n[a[i]]==-1||a_n[b[i]]==-1||a_n[c[i]]==-1)continue;
		int A=a_n[a[i]],B=a_n[b[i]],C=a_n[c[i]];
		if((A+B)%n!=C&&(A+B+1)%n!=C)return false;
	}
	return true;
}
void search(int p,int plus){
	int A=a[p],B=b[p],C=c[p];
	if(!check_pos(p))return;	
	if(p==n){
		if(!plus){
			found=true;
			for(int i=0; i<n-1; i++)
				printf("%d ",a_n[i]);
			printf("%d\n",a_n[n-1]);
		}
		return;
	}
	if(a_n[A]!=-1&&a_n[B]!=-1){
		if(a_n[C]!=-1){
			if(a_n[C]!=(a_n[A]+a_n[B]+plus)%n)return;
			else search(p+1,(a_n[A]+a_n[B]+plus)/n);
		}else if(n_a[(a_n[A]+a_n[B]+plus)%n]==-1){
			n_a[(a_n[A]+a_n[B]+plus)%n]=C;
			a_n[C]=(a_n[A]+a_n[B]+plus)%n;
			search(p+1,(a_n[a[p]]+a_n[b[p]]+plus)/n);
			if(found)return;
			n_a[(a_n[A]+a_n[B]+plus)%n]=-1;
			a_n[C]=-1;
		}
	}else if(a_n[A]==-1&&a_n[B]==-1){
		if(a_n[C]==-1){
			Rep(i)
				if(n_a[i]==-1)
					Rep(j)
						if(((i==j&&A==B)||(i!=j&&A!=B))&&n_a[j]==-1&&n_a[(i+j+plus)%n]==-1){
							int rem=(i+j+plus)%n;
							n_a[i]=A;
							a_n[a[p]]=i;
							n_a[j]=B;
							a_n[b[p]]=j;
							n_a[rem]=C;
							a_n[C]=rem;
							search(p+1,(i+j+plus)/n);
							if(found)return;
							n_a[i]=-1;
							a_n[a[p]]=-1;
							n_a[j]=-1;
							a_n[b[p]]=-1;
							n_a[rem]=-1;
							a_n[c[p]]=-1;
						}
		}
		else{
			Rep(i)
				if(n_a[i]==-1)
					Rep(j){
						if(((i==j&&A==B)||(i!=j&&A!=B))&&n_a[j]==-1){
							int rem=(i+j+plus)%n;
							if(rem!=a_n[c[p]])continue;
							n_a[i]=a[p];
							a_n[a[p]]=i;
							n_a[j]=b[p];
							a_n[b[p]]=j;
							search(p+1,(i+j+plus)/n);
							if(found)return;
							n_a[i]=-1;
							a_n[a[p]]=-1;
							n_a[j]=-1;
							a_n[b[p]]=-1;
						}
					}
		}
	}else if(a_n[A]==-1){
		if(a_n[C]==-1){
			Rep(i)
				if(n_a[i]==-1){
					int rem=(i+a_n[b[p]]+plus)%n;
					if(n_a[rem]!=-1)continue;
					a_n[c[p]]=rem;
					n_a[rem]=c[p];
					a_n[a[p]]=i;
					n_a[i]=a[p];
					search(p+1,(i+a_n[b[p]]+plus)/n);
					if(found)return;
					a_n[C]=-1;
					n_a[rem]=-1;
					a_n[a[p]]=-1;
					n_a[i]=-1;
				}
		}else{
			Rep(i)
				if(n_a[i]==-1){
					int rem=(i+a_n[b[p]]+plus)%n;
					if(rem!=a_n[c[p]])continue;
					a_n[A]=i;
					n_a[i]=c[p];
							if(a_n[8]==13){
								printf("%d",p);
								exit(0);
							}
					search(p+1,(i+a_n[b[p]]+plus)/n);
					if(found)return;
					a_n[A]=-1;
					n_a[i]=-1;
				}
		}
	}else{
		if(a_n[C]==-1){
			Rep(i)
				if(n_a[i]==-1){
					int rem=(i+a_n[A]+plus)%n;
					if(n_a[rem]!=-1)continue;
					a_n[C]=rem;
					n_a[rem]=C;
					a_n[B]=i;
					n_a[i]=B;
							if(a_n[8]==13){
								printf("%d",p);
								exit(0);
							}
					search(p+1,(a_n[A]+a_n[B]+plus)/n);
					if(found)return;
					a_n[C]=-1;
					n_a[rem]=-1;
					a_n[B]=-1;
					n_a[i]=-1;
				}
		}else{
			Rep(i)
				if(n_a[i]==-1){
					int rem=(i+a_n[A]+plus)%n;
					if(a_n[C]!=rem)continue;
					a_n[B]=i;
					n_a[i]=B;
							if(a_n[8]==13){
								printf("%d",p);
								exit(0);
							}
					search(p+1,(a_n[A]+a_n[B]+plus)/n);
					if(found)return;
					a_n[B]=-1;
					n_a[i]=-1;
				}
		}
	}
}
int main(){
	freopen(PROB".in","r",stdin);
	freopen(PROB".out","w",stdout);
	memset(a_n,-1,sizeof(a_n));
	memset(n_a,-1,sizeof(n_a));
	
	char A[50],B[50],C[50];
	scanf("%d%s%s%s",&n,A,B,C);
	for(int i=0; i<n; i++){
		a[i]=A[n-i-1]-'A',b[i]=B[n-i-1]-'A',c[i]=C[n-i-1]-'A';
dbg		printf("%d %d %d\n",a[i],b[i],c[i]);
	}
	search(0,0);
	
	//for(int i=0; i<n-1; i++)
	//	printf("%d ",a_n[i]);
//	printf("%d\n",a_n[n-1]);
	return 0;
}

