#include<bits/stdc++.h>
#define ls rt*2,l,mid
#define rs rt*2+1,mid+1,r
#define fopen(FNAME) freopen(FNAME".in","r",stdin);freopen(FNAME".out","w",stdout);
using namespace std;
using ll=long long;
using PII=pair<int,int>;
using ve=vector<int>;
using PIL=pair<int,ll>;
using PLI=pair<ll,int>;
using PLL=pair<ll,ll>;
using AR3=array<int,3>;
const int N=5e4+9,mod=1e9+7;
int n,m,p,k;
int a[N],sum[N];
struct TREE{
	ll k;
	ll max_lazy=0;
}tr[N*4];
void push_down(int rt)
{
	if(tr[rt].max_lazy)
	{
		ll lazy=tr[rt].max_lazy;
		tr[rt*2].max_lazy=tr[rt*2+1].max_lazy=lazy;
		tr[rt*2].k=max(tr[rt*2].k,lazy);
		tr[rt*2+1].k=max(tr[rt*2+1].k,lazy);
	}
}
void build(int rt,int l,int r)
{
	if(l==r){tr[rt].k=0,tr[rt].max_lazy=0;return;}
	tr[rt].max_lazy=0;
	int mid=(l+r)/2;
	build(ls);
	build(rs);
}
void add(int rt,int l,int r,int kl,int kr,ll x)
{
	if(kl<=l&&r<=kr)
	{
		tr[rt].k+=x;
		tr[rt].max_lazy=max(tr[rt].max_lazy,x);
		return;
	}
	push_down(rt);
	int mid=(l+r)/2;
	if(kl<=mid)add(ls,kl,kr,x);
	if(mid<kr)add(rs,kl,kr,x);
}
ll ask(int rt,int l,int r,int kl,int kr)
{
	if(kl<=l&&r<=kr)
	{
		return tr[rt].k;
	}
	push_down(rt);
	ll res=-1;
	int mid=(l+r)/2;
	if(kl<=mid)res=max(res,ask(ls,kl,kr));
	if(mid<kr)res=max(res,ask(rs,kl,kr));
	return res;
}
ll ksm(ll a,ll b)
{
	ll re=1;
	for(;b;b=b/2,a=a*a)
	{
		if(b&1)re*=a;
	}
	return re;
}
void solve(int tcase)
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum[i]=a[i]+sum[i-1];
	}
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		int lenl,lenr;
		cin>>lenl>>lenr;
		build(1,1,n);
		for(int len=lenl;len<=lenr;len++)
		{
			for(int l=1;l+len-1<=n;l++)
			{
				int r=l+len-1;
				ll k_now=sum[r]-sum[l-1];
				add(1,1,n,l,r,k_now);
			}
		}
		ll ans=0;
		for(int i=1;i<=n;i++)
		{
//			cout<<ask(1,1,n,i,i)<<' ';
			ans=ans^(i*ask(1,1,n,i,i));
		}
//		cout<<'\n';
		cout<<ans<<'\n';
	}
//	cout<<ksm(2,63);
}
int T=1;
int main(	)
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	fopen("query");
//	cin>>T;
	for(int i=1;i<=T;i++)solve(i);
	return 0;
}
/*
我靠mod 2^64是什么鬼
1e19 完蛋啦

遗憾了 T2没写出来
再见了 我的奥林匹克信息学竞赛。
下辈子还当OI人
我想 总是别离惯的
AFOed 2025-11-19
*/