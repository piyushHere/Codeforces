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
		int x0, x1, x2; cin >> x0 >> x1 >> x2;
		int y0, y1, y2; cin >> y0 >> y1 >> y2;
		int ans = 0;
		ans += min(x2, y1) * 2;
		int val = min(x2, y1);
		x2 -= val;
		y1 -= val;
		//int val2 = x2 + x0;
		/*int val1 = y1 + y0;
		if (val1 < x1) {
			ans -= max(0, x1 - val1 - x2) * 2;
		}*/
		/*else {
			ans -= (y2 - val2) * 2;
		}*/
		//x1 -= min(x1, y0 + y1);
		x1 -= min(x1, y1);
		//y2 -= min(y2, x0 + x2);
		y2 -= min(y2, x2);
		/*x1 -= min(x1, y0);
		y2 -= min(y2, x0);*/
		ans -= min(x1, y2) * 2;
		cout << ans << ln;
	}

}