#include<bits/stdc++.h>
using namespace std;

#define int long long
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


main() {
	fast_cin();
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		v32 c(3);
		forn(i, n) {
			int x; cin >> x;
			if (x % 3 == 0) c[0] += 1;
			else if (x % 3 == 1) c[1] += 1;
			else c[2] += 1;
		}
		int val = n / 3;
		int ans = 0;
		forn(i, 3) {
			if (c[i] < val) {
				int req = val - c[i];
				int prev_i = (i + 2) % 3;
				int prev_can_give = c[prev_i] - val;
				if (prev_can_give >= req) {
					c[prev_i] -= req;
					c[i] += req;
					ans += req;
				}
				else {
					c[prev_i] = val;
					c[i] += prev_can_give;
					ans += prev_can_give;
					req -= prev_can_give;
					ans += 2 * req;
					c[(i + 1) % 3] -= req;
				}
			}
		}
		cout << ans << ln;

	}

}