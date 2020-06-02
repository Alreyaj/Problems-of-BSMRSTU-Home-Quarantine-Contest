///----------------------///
///---Code Written by----///
///-----Al-Shahreyaj-----///
///----------------------///

///PRAGMA
//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")

#include<bits/stdc++.h>

///PBDS
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;

//PBDS_SET
//Index of Value - .order_of_key()
//Value at Index - .find_by_order()
//typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds_set; 
//typedef tree<int, null_type, lessorequal<int>, rb_tree_tag,tree_order_statistics_node_update> pbds_multiset; 

#define mem(a, x) memset(a, x, sizeof(a))
#define MP make_air
#define inf 1e8
#define INF 1e18
#define CP(x) printf("Case %d: ", x);
#define unq(v) v.erase(unique(all(v)),v.end())
#define one(x) __builtin_popcount(x)
#define onel(x) __builtin_popcountll(x)
#define ll long long
#define endl "\n"
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int,int>
#define pil pair<int,ll>
#define pll pair<ll,ll>
#define matrix vector<vector<ll> >
#define F first
#define S second
#define pb push_back
#define pq priority_queue
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define INT ini()
#define LONG inl()
#define M 10000007
#define N 10005

int ini(){int x;scanf("%d",&x);return x;}
ll inl(){ll x;scanf("%lld",&x);return x;}

int arr[N];
ll dp[1 << 21];

int main()
{
	int t = INT;
	while(t--){
		mem(dp, 0);
		int n = INT, m = INT, cn = 0;
		for(int i = 1; i <= n; i++)
		{
			int mask = 0;
			for(int j = 0; j < m; j++)
			{
				int x = INT;
				if(x) mask |= (1 << j);
			}
			if(!mask) cn++;
			arr[i] = mask;
		}
		int cn2 = 0;
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				if(i == j) continue;
				if(!arr[i] || !arr[j]) continue;
				if(one(arr[i]) + one(arr[j]) == one(arr[i] | arr[j]))
				{
					cn2++;
					if(!arr[i] || !arr[j]) continue;
					dp[(arr[i] | arr[j])]++;
				}
			}
		}
		for(int j = 0; j < m; j++)
		{
			for(int i = 1; i < (1 << m); i++)
			{
				if(i & (1 << j))
				{
					dp[i] += dp[i ^ (1 << j)];
				}
			}
		}
		ll ans = 0;
		for(int i = 1; i <= n; i++)
		{
			if(!arr[i]) continue;
			ans += dp[((1 << m) - 1) ^ arr[i]];
		}
		ans /= 6LL;
		ans += (1LL * cn * (1LL * cn2 / 2LL));
		ans += ((1LL * cn * (cn - 1) * (cn - 2)) / 6LL);
		ans += 1LL * cn * (cn - 1) / 2LL * (n - cn);
		cout << ans << endl;
	}
	return 0;
}



