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
#define M 1000000007
#define N 100005

int ini(){int x;scanf("%d",&x);return x;}
ll inl(){ll x;scanf("%lld",&x);return x;}

ll big_mod(ll a, ll p)
{
	if(p == 1LL) return a;
	ll res = big_mod(a, p / 2LL);
	res = (res * res) % M;
	if(p & 1LL) res = (res * a) % M;
	return res;
}

ll prob[N], m1[N], m2[N];

int main()
{
	int n = INT, m = INT;
	for(int i = 1; i <= n; i++) {
		prob[i] = 1LL;
		for(int j = 1; j <= m; j++)
		{
			ll x = LONG;
			x = (100LL - x);
			prob[i] = (prob[i] * x) % M;
		}
	}
	ll div = 1LL;
	for(int i = 1; i <= m; i++) div = (div * 100) % M;
	for(int i = 1; i <= n; i++) scanf("%lld", &m1[i]);
	for(int i = 1; i <= n; i++) scanf("%lld", &m2[i]);
	ll res = 0;
	for(int i = 1; i <= n; i++)
	{
		ll ans = 0LL;
		ans = ((((prob[i] % M) * m1[i]) % M) + ((((div - prob[i] + 10LL * M) % M) * m2[i]) % M)) % M;
		ans = (ans * big_mod(div % M, M - 2)) % M;
		res = (res + ans) % M;
	}
	printf("%lld\n", res);
	return 0;
}



