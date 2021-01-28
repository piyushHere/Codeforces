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


int main() {
	fast_cin();
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t; cin >> t;
	while (t--) {
		int m, n; cin >> m >> n;
		vector<vector<int> > v(m, vector<int> (n));
		forn(i, m) {
			forn(j, n) {
				cin >> v[i][j];
			}
		}
		ll ans = 0;
		forn(i, m / 2) {
			forn(j, n / 2) {
				int a = v[i][j];
				int b = v[i][n - j - 1];
				int c = v[m - i - 1][j];
				int d = v[m - i - 1][n - j - 1];
				v32 vi; vi.pb(a); vi.pb(b); vi.pb(c); vi.pb(d);
				sort(all(vi));
				int med = vi[1];
				forn(i, 4) ans += abs(med - vi[i]);
			}
		}
		if (m & 1) {
			for (int i = 0; i < n / 2; i++) {
				ans += abs(v[m / 2][i] - v[m / 2][n - i - 1]);
			}
		}
		if (n & 1) {
			for (int i = 0; i < m / 2; i++) {
				ans += abs(v[i][n / 2] - v[m - i - 1][n / 2]);
			}
		}

		cout << ans << ln;
	}

}