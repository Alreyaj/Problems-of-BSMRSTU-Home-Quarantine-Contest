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
#define matrix vector<vector<int> >
#define F first
#define S second
#define pb push_back
#define pq priority_queue
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define INT ini()
#define LONG inl()
#define M 10000007
#define N 100005

int ini(){int x;scanf("%d",&x);return x;}
ll inl(){ll x;scanf("%lld",&x);return x;}


void upd(matrix &tre, int i, int n, int v, int R)
{
	while(n < R)
	{
		tre[i][n] += v;
		n += (n & (-n));
	}
}

int qry(matrix &tre, int i, int n)
{
	int res = 0;
	while(n > 0)
	{
		res += tre[i][n];
		n -= (n & (-n));
	}
	return res;
}


int main()
{
	int n = INT, m = INT, q = INT, x = INT, y = INT;
	matrix t1(n + 5, vi(m + 5));
	matrix t2(m + 5, vi(n + 5));
	while(q--)
	{
		int t = INT;
		if(t == 1)
		{
			x = INT, y = INT;
		}
		else
		{
			int u = INT, v = INT, r = INT;
			upd(t1, u, max(1, v - r), 1, m + 2);
			upd(t1, u, min(m, v + r) + 1, -1, m + 2);
			upd(t2, v, max(1, u - r), 1, n + 2);
			upd(t2, v, min(n, u + r) + 1, -1, n + 2);
		}
		int ans = qry(t1, x, y);
		ans += qry(t2, y, x);
		if(ans) printf("Opps! I’m dead\n");
		else printf("I can’t be defeated\n");
	}
	return 0;
}
