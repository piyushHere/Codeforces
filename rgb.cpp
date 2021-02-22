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
	v32 v(3); ; cin >> v[0] >> v[1] >> v[2];
	sort(all(v));
	int sum = v[0] + v[1] + v[2];
	int ans = 0;
	while (sum >= 3) {
		if (v[1] == 0) break;
		//cout << v[0] << " " << v[1] << " " << v[2] << ln;
		int l = v[1] - v[0];
		int r = v[2] - v[1];
		if (v[0] == 0) l -= 1;
		if (l == r) {
			ans += l + v[0];
			break;
		}
		else if (l < r) {
			v[1] = v[1] - (l + 1);
			v[2] = v[2] - 2 * (l + 1);
			ans += l + 1;

		}
		else {
			v[1] = v[1] - (r + 1);
			v[2] = v[2] - 2 * (r + 1);
			ans += r + 1;
		}
		sort(all(v));
		//cout << ans << ln;

		sum = v[0] + v[1] + v[2];
	}
	cout << ans;


}