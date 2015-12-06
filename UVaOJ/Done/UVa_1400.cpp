#include <stdio.h>
typedef long long LL;
inline LL max(const LL& a,const LL& b)
{
	return a>b?a:b;
}
inline LL max(const LL& a,const LL& b,const LL& c)
{
	return max(max(a,b),c);
}
inline LL extend_max(LL a,LL b,int c,int d,int& e)
{
	if(a>=b)
	{
		e=c;
		return a;
	}
	else
	{
		e=d;
		return b;
	}
}
inline LL extend_max(LL a,LL b,LL c,int a1,int a2,int b1,int b2,int c1,int c2,int& d, int& e)
{
	if(a==max(a,b,c))
	{
		d=a1,e=a2;
		return a;
	}
	else if(b==max(a,b,c))
	{
		d=b1,e=b2;
		return b;
	}
	else
	{
		d=c1,e=c2;
		return c;
	}
}
struct POINT
{
	LL prefix,suffix,sum,sub;
	int left,right,sub_left,prefix_right,suffix_left,sub_right;
}p[400010];
LL num[200001];
void BUILD(int o,int left,int right)
{
	POINT& t=p[o];
	t.left=left,t.right=right;
	if(left==right)
	{
		t.sum=t.prefix=t.suffix=t.sub=num[left];
		t.sub_left=t.suffix_left=t.sub_right=t.prefix_right=left;
		return;
	}
	int lc=o*2,rc=o*2+1;
	BUILD(lc,left,(left+right)/2);
	BUILD(rc,(left+right)/2+1,right);
	t.sum=p[lc].sum+p[rc].sum;
	t.prefix=extend_max(p[lc].prefix, p[lc].sum+p[rc].prefix, p[lc].prefix_right, p[rc].prefix_right,t.prefix_right);
	t.suffix=extend_max(p[lc].suffix+p[rc].sum, p[rc].suffix, p[lc].suffix_left, p[rc].suffix_left, t.suffix_left);
	t.sub=extend_max(p[lc].sub, p[lc].suffix+p[rc].prefix, p[rc].sub, p[lc].sub_left, p[lc].sub_right, p[lc].suffix_left, p[rc].prefix_right, p[rc].sub_left,p[rc].sub_right,p[o].sub_left,p[o].sub_right);
	return;
}
LL max_sub(int,int,int,int&,int&);
LL max_prefix(int,int,int&);
LL max_suffix(int,int,int&);
int main()
{
	int n,m,kase=1;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(int i=1; i<=n; i++)
			scanf("%lld",&num[i]);
		printf("Case %d:\n",kase++);
		BUILD(1,1,n);
		for(int i=1; i<=m; i++)
		{
			int l,r,ans_left,ans_right;
			scanf("%d %d",&l,&r);
			max_sub(l,r,1,ans_left,ans_right);
			printf("%d %d\n",ans_left,ans_right);
		}
	}
	return 0;
}
LL max_sub(int left,int right,int o,int& l,int& r)
{
	if(left==p[o].left&&right==p[o].right)
	{
		l=p[o].sub_left,r=p[o].sub_right;
		return p[o].sub;
	}
	int lc=o*2,rc=o*2+1,l1,l2,l3,r1,r2,r3,mid=(p[o].left+p[o].right)/2;
	LL s1,s2,s3;
	if(right<=mid)
		return max_sub(left,right,lc,l,r);
	if(left>mid)
		return max_sub(left,right,rc,l,r);
	s1=max_sub(left,mid,lc,l1,r1);
	s2=max_suffix(left,lc,l2)+max_prefix(right,rc,r2);
	s3=max_sub(mid+1,right,rc,l3,r3);
	return extend_max(s1,s2,s3,l1,r1,l2,r2,l3,r3,l,r);
	
}
LL max_suffix(int left,int o,int& l)
{
	if(left==p[o].left)
	{
		l=p[o].suffix_left;
		return p[o].suffix;
	}
	int lc=o*2,rc=o*2+1,mid=(p[o].left+p[o].right)/2,l1,l2;
	LL s1,s2;
	if(left>mid)
		return max_suffix(left,rc,l);
	s1=max_suffix(left,lc,l1)+p[rc].sum;
	s2=p[rc].suffix;
	l2=p[rc].suffix_left;
	return extend_max(s1,s2,l1,l2,l);
}
LL max_prefix(int right,int o,int& r)
{
	if(right==p[o].right)
	{
		r=p[o].prefix_right;
		return p[o].prefix;
	}
	int lc=o*2,rc=o*2+1,mid=(p[o].left+p[o].right)/2,r1,r2;
	LL s1,s2;
	if(right<=mid)
		return max_prefix(right,lc,r);
	s1=p[lc].prefix;
	r1=p[lc].prefix_right;
	s2=p[lc].sum+max_prefix(right,rc,r2);
	return extend_max(s1,s2,r1,r2,r);
}