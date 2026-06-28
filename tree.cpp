#include<bits/stdc++.h>
#define fopen(FNAME) freopen(FNAME".in","r",stdin);freopen(FNAME".out","w",stdout);
using namespace std;
using ll=long long;
using PII=pair<int,int>;
using ve=vector<int>;
using PIL=pair<int,ll>;
using PLI=pair<ll,int>;
using PLL=pair<ll,ll>;
using AR3=array<int,3>;
const int N=1e5+9,mod=1e9+7;
int n,m,p,k;
ve r[N];
void solve_sigma()
{
	ll anss=0;
	for(int i=1;i<=n;i++)
	{
		anss+=i;
	}
	cout<<anss<<'\n';
}
int a[N];
int ans[N];
void dfst(int now,int root)
{
//	set<int> se;
	if(a[now]==0)ans[now]=1;
	for(int to:r[now])
	{
		if(to==root)continue;
		dfst(to,now);
		ans[now]=max(ans[now],ans[to]);
	}
	if(a[now]==ans[now])ans[now]++;
}
ll final_ans=0;
void check()
{
	ll res=0;
	dfst(1,0);
	for(int i=1;i<=n;i++)
	{
		res+=ans[i];
	}
	final_ans=max(final_ans,res);
}
void dfs(int now)
{
	if(now==n+1)
	{
		check();
		return;
	}
	for(int i=0;i<=n;i++){
		ans[now]=0;
		a[now]=i;dfs(now+1);
	}
}
void solve(int tcase)
{
	final_ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		r[i].clear();
	}
	for(int u=2;u<=n;u++)
	{
		int v;cin>>v;
		r[u].push_back(v);
		r[v].push_back(u);
	}
//	solve_sigma();
	dfs(1);
	cout<<final_ans<<'\n';
}
int T=1;
int main(	)
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	fopen("tree");
	cin>>T;
	for(int i=1;i<=T;i++)solve(i);
	return 0;
}
/*
给的m应该是用来划分的 a[i]<2^m
*/