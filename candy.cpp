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
using LLAR3=array<ll,3>;
const int N=1e5+9,mod=1e9+7;
int n,p,k;
ll m;
ll a[N],b[N];
ll pair_candy[N];
bool if_one_more=0;
PLL pair_candy_min={1e18,1e18};
ll calc(int cnt)
{
	ll an=pair_candy_min.first,bn=pair_candy_min.second;
	ll res=(cnt/2)*(an+bn);
	if(if_one_more)res+=(cnt%2)*an;
	else res+=(cnt%2)*bn;
	return res;
}
void solve(int tcase)
{
	cin>>n>>m;
	ll min_sum=1e18;
	int min_pos=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		pair_candy[i]=a[i]+b[i];
		if(pair_candy[i]<min_sum)
		{
			pair_candy_min={a[i],b[i]};
			min_sum=pair_candy[i];
			min_pos=i;
		}
		if(pair_candy[i]==min_sum&&a[i]>pair_candy_min.first)
		{
			pair_candy_min={a[i],b[i]};
			min_sum=pair_candy[i];
			min_pos=i;
		}
	}
	ll pair_cnt=(m/min_sum)*2;
	m=m%min_sum;
	if(m>=pair_candy_min.first){if_one_more=1,pair_cnt++,m-=pair_candy_min.first;}
	a[min_pos]=1e18;
	sort(a+1,a+n+1);
	ll sum_now=0;
	ll ans=pair_cnt;
//	cout<<if_one_more<<'\n';
	for(int i=1;i<=n;i++)
	{
		sum_now+=a[i];
		int l=0,r=pair_cnt;
		while(l<=r)
		{
			int mid=(l+r)/2;
			if(m+calc(mid)-sum_now<0)l=mid+1;
			else r=mid-1;
		}
//		cout<<m<<' '<<sum_now<<' '<<l<<' '<<calc(l)<<'\n';
		if(l<=pair_cnt&&m+calc(l)-sum_now>=0&&i-l>=0) ans=max(ans,pair_cnt+i-l);
//		else break;
	}
	cout<<ans<<'\n';
//	for(int i=1;i<=n;i++)cout<<ans_candy_rec[i]<<' ';
}
int T=1;
int main(	)
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	fopen("candy");
//	cin>>T;
	for(int i=1;i<=T;i++)solve(i);
	return 0;
}
/*
将两颗糖果捆绑
先两颗两颗的买
再买一颗的
那样如果先全部买一颗就不行了

*/
/*
8:40 初始化 A
8:48 B
9:08 CD好难 动手吧 
9:41 A大样例寄了 对拍
10:28 A感觉大问题 B
11:44 终于A样例通过 对拍 往死里写
A 10000组样例通过 爱你一万年~ 爱你经得起考验~
*/