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
long long n;
vector<int> dp;

/*int rec(long long i, bool d) {
	if (i >= n) {
		//cout << i << ln;
		return 0;
	}
	if (memo[i] != -1) return memo[i];
	//cout << i << ln;
	if (d) memo[i] = rec(2 * i, true) + 1;
	else {
		memo[i] =  min(rec(i + 1, false), rec(2 * i, true)) + 1;
	}
	return memo[i];
}*/


int main() {
	fast_cin();
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int ans = INT_MAX;
		for (int i = 1; i <= sqrt(n); i++) {
			int curr = i - 1 + ceil((n - i) / (i * 1.0));
			//cout << curr << ln;
			ans = min(curr, ans);
		}
		cout << ans << ln;
	}
}