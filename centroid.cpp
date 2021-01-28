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
vector<vector<int> > g;
v32 cent;
v32 sz;
int n;

void dfs(int u, int prev) {
	sz[u] = 1;
	bool is_centroid = true;
	for (auto v : g[u]) if (v != prev) {
			dfs(v, u);
			sz[u] += sz[v];
			if (sz[v] > n / 2) is_centroid = false;
		}
	if (n - sz[u] > n / 2) is_centroid = false;
	if (is_centroid) cent.push_back(u);
};


int main() {
	fast_cin();
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t; cin >> t;
	while (t--) {
		cin >> n;
		g = vector<vector<int> >(n + 1);
		cent = v32();
		sz = v32(n + 1);
		forn(i, n - 1) {
			int u, v; cin >> u >> v;
			g[u].pb(v);
			g[v].pb(u);
		}
		dfs(1, -1);
		/*for (auto i : cent) cout << i << " ";
		cout << ln;*/
		if (cent.size() == 1) {
			int u = cent[0];
			int v = g[u][0];
			cout << u << " " << v << ln;
			cout << u << " " << v << ln;
		}
		else {
			int u = cent[0];
			for (int i = 1; i < cent.size(); i++) {
				int v;
				for (auto neigh : g[cent[i]]) {
					if (neigh != u) {
						v = neigh;
						break;
					}
				}
				cout << cent[i] << " " << v << ln;
				cout << u << " " << v << ln;
			}
		}
	}

}