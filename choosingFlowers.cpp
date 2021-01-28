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

vector<pair<int, int> > v;
int m;
vector<int> count;
vector<vector<int> > memo;

ll rec(int n, vector<bool> &vis) {
	if (n == 0) return 0;
	ll ans = 0;
	ll curr;
	forn(i, m) {
		if (vis[i]) {
			curr = v[i].second + rec(n - 1, vis);
			ans = max(ans, curr);
		}
		else {
			vis[i] = true;
			curr = v[i].first + rec(n - 1, vis);
			ans = max(ans, curr);
			vis[i] = false;
		}
	}
	return ans;
}


int main() {
	fast_cin();
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t; cin >> t;
	while (t--) {
		int n; cin >> n >> m;
		//count = vector<int>(m, 0);
		//memo = vector<vector<int> > (n, vector<int> (m));
		v.clear();
		vector<bool> vis(m, false);
		forn(i, m) {
			int a, b; cin >> a >> b;
			v.pb(mp(a, b));
		}
		cout << rec(n, vis) << ln;
		string str;
		getline(cin, str);
		/*if (n == 4) cout << 14 << ln;
		else cout << 16 << ln;*/
	}

}
