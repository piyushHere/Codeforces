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
		int n; cin >> n;
		v32 v(n);
		int m = INT_MIN;
		forn(i, n) {
			cin >> v[i];
			m = max(m, v[i]);
		}
		sort(all(v));
		/*for (auto i : v) cout << i << " ";
		cout << ln;*/
		long long ans = 1;
		if (m == 0) {
			ans = 0;
		}
		else if (m < 0) {
			for (int i = n - 1; i >= n - 5; i--) {
				ans = ans * v[i];
			}
		}
		else if (m > 0) {
			int i = 0;
			int j = n - 1;
			int k = 5;
			ans = v[n - 1];
			k--;
			k >>= 1;
			j--;
			for (int itr = 0; itr < k; itr++) {
				int left_product = v[i] * v[i + 1];
				int right_product = v[j] * v[j - 1];
				if (left_product > right_product) {
					ans *= left_product;
					i += 2;
				}
				else {
					ans *= right_product;
					j -= 2;
				}
			}
		}
		cout << ans << ln;
	}

}
