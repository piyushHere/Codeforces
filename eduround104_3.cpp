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
		int matches = (n * (n - 1)) / 2;
		int max_score = matches * 3;
		int bucket = n * 3;
		v32 ans(n);
		if (max_score % bucket == 0) {
			int count = max_score / bucket;
			int val = count * 3;
			for (int i = 0; i < n; i++) {
				for (int j = i + 1; j < n; j++) {
					if (ans[i] < val) {
						cout << 1 << " ";
						ans[i] += 3;
					}
					else {
						cout << -1 << " ";
						ans[j] += 3;
					}
				}
			}
			cout << ln;
			for (auto i : ans) cout << i << " ";
		}
		else {
			int rounds = max_score / bucket;
			int val = rounds * 3;
			cout << val << ln;
			for (int i = 0; i < n; i++) {
				for (int j = i + 1; j < n; j++) {
					if (i == n - j - 1) {
						cout << 0 << " ";
						ans[i] += 1;
						ans[j] += 1;
					}
					else if (ans[i] < val) {
						cout << 1 << " ";
						ans[i] += 3;
					}
					else {
						cout << -1 << " ";
						ans[j] += 3;
					}
					cout << ln;
					for (auto i : ans) cout << i << " ";
				}
			}
		}
		cout << ln;
	}

}