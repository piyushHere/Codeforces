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
		string a, b; cin >> a >> b;
		int n = a.length();
		bool flag = false;
		int ans = 0;
		for (int i = 0; i < n; i += 2) {
			if (flag == 0 && a[i] != b[i]) {
				flag = 1;
				ans += 1;
			}
			else if (flag == 1 && a[i] == b[i]) {
				flag = 0;
			}
		}
		flag = 0;
		for (int i = 1; i < n; i += 2) {
			if (flag == 0 && a[i] != b[i]) {
				flag = 1;
				ans += 1;
			}
			else if (flag == 1 && a[i] == b[i]) {
				flag = 0;
			}
		}
		cout << ans << ln;
	}


}
