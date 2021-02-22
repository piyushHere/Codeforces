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
		int x, y; cin >> x >> y;
		string s; cin >> s;
		v32 v(4);
		for (auto c : s) {
			if (c == 'U') v[0]++;
			if (c == 'D') v[1]++;
			if (c == 'L') v[2]++;
			if (c == 'R') v[3]++;
		}
		bool ans = true;
		if (x < 0 && v[2] < abs(x)) ans = false;
		if (x > 0 && v[3] < x) ans = false;
		if (y < 0 && v[1] < abs(y)) ans = false;
		if (y > 0 && v[0] < y) ans = false;
		if (ans) cout << "YES" << ln;
		else cout << "NO" << ln;
	}


}