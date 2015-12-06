#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int search_suffix(int o,int ql)
{
	int mid=(tree[o].left+tree[o].right)/2;
	if(ql==tree[o].left)return tree[o].suffix;
	if(ql>mid)return search_suffix(o*2+1,ql);
	int t=search_suffix(o*2,ql);
	if(sum(tree[o*2+1].suffix,tree[o].right)>sum(t,tree[o].right))
		return tree[o*2+1].suffix;
	else
		return t;
}
int search_sub(int o,int ql,int qr,int& subleft,int& subright)
{
	int tl1,tl2,tr1,tr2;
	int mid=(tree[o].left+tree[o].right)/2;
	if(ql==tree[o].left&&qr==tree[o].right)
	{
		subleft=tree[o].sub[0];
		subright=tree[o].sub[1];
		return;
	}
	if(qr<=mid)
	{
		search_sub(o*2,ql,qr,subleft,subright);
		return;
	}
	if(ql>mid)
	{
		search_sub(o*2+1,ql,qr,subleft,subright);
		return;
	}
	search_sub(o*2,ql,mid,tl1.tr1);
	search_sub(o*2+1,mid+1,qr,tl2,tr2);
	if(sum(tl1,tr1)<sum(tl2,tr2))
	{
		tl1=tl2;tr1=tr2;
	}
	tl2=search_suffix(o*2,ql);
	tr2=search_suffix(o*2+1,qr);
	if(sum(tl1,tr1)<sum(tl2,tr2))
	{
		tl1=tl2;tr1=tr2;
	}
	subleft=tl1;subright=tl2;
}
int main()
{
	int i,j;
	return 0;
}
