#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> p32;
typedef pair<ll, ll> p64;
typedef pair<double, double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 1e9 + 7;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(int i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define INF 1e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

int isSubsetSum(vector<int> set, int n, int sum, int k)
{
	bool subset[sum + 1][n + 1];
	int count[sum + 1][n + 1];
	for (int i = 0; i <= n; i++)
	{
		subset[0][i] = true;
		count[0][i] = 0;
	}
	for (int i = 1; i <= k; i++)
	{
		subset[i][0] = false;
		count[i][0] = -1;
	}
	for (int i = 1; i <= k; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			subset[i][j] = subset[i][j - 1];
			count[i][j] = count[i][j - 1];
			if (i >= set[j - 1])
			{
				subset[i][j] = subset[i][j] ||
				               subset[i - set[j - 1]][j - 1];

				if (subset[i][j])
					count[i][j] = max(count[i][j - 1],
					                  count[i - set[j - 1]][j - 1] + 1);
			}
		}
	}

	return count[sum][n];
}


int main() {
	fast_cin();
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n; cin >> n;
	v32 v(n);
	forn(i, n) cin >> v[i];
	int m, k; cin >> m >> k;
	v32 memo(n);

}