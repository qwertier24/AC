#include <stdio.h>
#include <cstring>
#include <vector>
using namespace std;
char g[100][100],w[6]={'K','Q','R','B','N','P'},b[6]={'k','q','r','b','n','p'};
struct P
{
	char type;
	int x,y;
};
vector<P> ans_w,ans_b;
int main()
{
	for(int i=0; i<17; i++)
		scanf("%s",g[i]);
	for(int k=0; k<6; k++)            //white
	{
		for(int i=15; i>=0; i-=2)  
		{
			for(int j=2; j<33; j+=4)
			{
				//printf("%d %d %c",i,j,g[i][j]);
				if(g[i][j]==w[k])
					ans_w.push_back((P){g[i][j],(i+1)/2,(j+2)/4});
			}
			//printf("\n");
		}
	}
	for(int k=0; k<6; k++)            //white
	{
		for(int i=1; i<17; i+=2)  
		{
			for(int j=2; j<33; j+=4)
			{
				//printf("%d %d %c",i,j,g[i][j]);
				if(g[i][j]==b[k])
					ans_b.push_back((P){g[i][j],(i+1)/2,(j+2)/4});
			}
			//printf("\n");
		}
	}
	printf("White: ");
	for(int i=0; i<ans_w.size()-1; i++)
	{
		if(ans_w[i].type!='P')
			printf("%c",ans_w[i].type);
		printf("%c%d,",ans_w[i].y-1+'a',8-ans_w[i].x+1);
	}
	if(ans_w.size())
	{
		if(ans_w[ans_w.size()-1].type!='P')
			printf("%c",ans_w[ans_w.size()-1].type);
		printf("%c%d",ans_w[ans_w.size()-1].y-1+'a',8-ans_w[ans_w.size()-1].x+1);
	}
	printf("\n");
	printf("Black: ");
	for(int i=0; i<ans_b.size()-1; i++)
	{
		if(ans_b[i].type!='p')
			printf("%c",ans_b[i].type-'a'+'A');
		printf("%c%d,",ans_b[i].y-1+'a',8-ans_b[i].x+1);
	}
	if(ans_b.size())
	{
		if(ans_b[ans_b.size()-1].type!='p')
			printf("%c",ans_b[ans_b.size()-1].type-'a'+'A');
		printf("%c%d",ans_b[ans_b.size()-1].y-1+'a',8-ans_b[ans_b.size()-1].x+1);
	}
	return 0;
}
