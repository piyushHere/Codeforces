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
		unordered_map<int, int> m;
		int n; cin >> n;
		forn(i, n) {
			int x; cin >> x;
			m[x]++;
		}
		v32 val;
		for (auto i : m) val.pb(i.second);
		sort(all(val));
		int s = val.size();
		map<int, int> m2;
		map<int, int> count;
		vp32 p;
		for (auto i : val) {
			m2[i] += i;
			count[i] += 1;
		}
		for (auto i : m2) p.pb(make_pair(m2.first, m2.second));
		int ans = INT_MAX;
		int len = p.size();
		if (len == 1) {
			cout << 0 << ln;
			continue;
		}
		for (int i = 0; i < len; i++) {
			if (i == 0 ) {
				ans = min(ans, p[i + 1].second - p[i].first * count[p[i + 1].first]);
			}
			else {
				ans = min(ans, p[i - 1].second + p[i + 1])
			}
		}
	}

}