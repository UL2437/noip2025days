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
const int N=5e3+9,mod=998244353;
int n,m,p,k;
int Testcase;
int a[N];
bool cmp(PII x,PII y)
{
	if((2/x.first)*a[x.second]!=(2/y.first)*a[y.second])return (2/x.first)*a[x.second]>(2/y.first)*a[y.second];
	if(a[x.second]!=a[y.second])return a[x.second]>a[y.second];
	return x.second<y.second;
}
ll dfs_ans=0;
vector<PII> v;
void dfs(int now,int w_now,ll asum)
{
	int w=v[now].first,i=v[now].second;
	if(now==n)
	{
		dfs_ans=max(dfs_ans,asum);
		return;
	}
	if(w_now+w<=m)dfs(now+1,w_now+w,asum+a[i]);
	dfs(now+1,w_now,asum);
}
void solve_pow()
{
	ll ansp=1;
	for(int i=1;i<=n;i++)
	{
		ansp=ansp*2;
		ansp%=mod;
	}
	cout<<ansp<<'\n';
}
void solve(int tcase)
{
	cin>>n>>m;
	bool if_a_egs=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i!=1&&a[i]!=a[i-1])if_a_egs=0;
	}
	if(if_a_egs)
	{
		solve_pow();
		return;
	}
	ll ans=0;
	for(int cr=0;cr<(1<<n);cr++)
	{
		v.clear();
		for(int i=1;i<=n;i++)
		{
			if((1<<(i-1))&cr)
			{//w=1
				v.push_back({1,i});
			}
			else
			{//w=2
				v.push_back({2,i});
			}
		}
		sort(v.begin(),v.end(),cmp);
		
		int sum=0;ll sum_w=0;
		for(PII x:v)
		{
			int w=x.first,now=x.second;
			if(sum+w<=m)sum+=w;
			else continue;
			sum_w+=a[now];
//			cout<<w<<' '<<a[now]<<'\n';
		}
		dfs_ans=0;
		dfs(0,0,0);
		if(dfs_ans==sum_w)
		{
			ans++;
		}
		else
		{
//			cout<<'\n';
//			for(PII x:v)
//			{
//				int w=x.first,now=x.second;
//				cout<<w<<' '<<a[now]<<'\n';
//			}
		}
//		cout<<'\n';
	}
//	cout<<"\n\n";
	cout<<ans<<'\n';
}
int T=1;
int main(	)
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	fopen("sale");
	cin>>Testcase>>T;
	for(int i=1;i<=T;i++)solve(i);
	return 0;
}
/*

*/