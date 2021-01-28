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
		int n, x, p, q;
		cin >> n >> x >> p >> q;
		p -= 1;
		q -= 1;
		//cout << p << ln;
		v32 v(n);
		forn(i, n) cin >> v[i];
		sort(all(v));
		if (v[p] == x) {
			cout << 0 << ln;
			continue;
		}
		if (v[p] > x) {
			if (q < p) {
				cout << -1 << ln;
				continue;
			}
			int count = 0;
			int j = p;
			while (j >= 0 && v[j] > x) {
				count += 1;
				j--;
			}
			cout << count << ln;
			continue;
		}
		else {
			if (q > p) {
				cout << -1 << ln;
				continue;
			}
			int count = 0;
			int j = p;
			while (j < v.size() && v[j] < x) {
				count += 1;
				j++;
			}
			cout << count << ln;
			continue;
		}
	}

}