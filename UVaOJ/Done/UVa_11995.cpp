#include <stdio.h>
#include <stack>
#include <queue>
using namespace std;
bool guess[4];
char  s[4][20]={"","stack","queue","priority queue"};
int main()
{
	int T;
	while(scanf("%d",&T)!=EOF)
	{
		stack<int> st;
		queue<int> q;
		priority_queue<int> pq;
		for(int i=1; i<=3; i++)
			guess[i]=true;
		int opt,num;
		for(int i=1; i<=T; i++)
		{
			scanf("%d %d",&opt,&num);
			if(opt==1)
			{
				if(guess[1])
					st.push(num);
				if(guess[2])
					q.push(num);
				if(guess[3])
					pq.push(num);
			}
			else
			{
				if(st.empty()||st.top()!=num)
					guess[1]=false;
				else
					st.pop();
				if(pq.empty()||pq.top()!=num)
					guess[3]=false;
				else
					pq.pop();
				if(q.empty()||q.front()!=num)
					guess[2]=false;
				else
					q.pop();
			}
		}
		int count=0;
		for(int i=1; i<=3; i++)
			if(guess[i])
				count++;
		if(count==1)
		{
			for(int i=1; i<=3; i++)
				if(guess[i])
					printf("%s\n",s[i]);
		}
		else if(count==0)
			printf("impossible\n");
		else
			printf("not sure\n");
	}
	return 0;
}
