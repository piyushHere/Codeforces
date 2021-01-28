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


int dis(map<int, vector<int> > &g, int source, int dest) {
	queue<int> q;
	q.push(source);
	int nodes = g.size();
	vector<int> dis(nodes + 1, INT_MAX);
	dis[source] = 0;
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		for (auto neigh : g[node]) {
			if (dis[neigh] == INT_MAX) {
				q.push(neigh);
				dis[neigh] = dis[node] + 1;
			}
		}
	}
	return dis[dest];
}


int main() {
	fast_cin();
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t; cin >> t;
	while (t--) {
		int n, a, b, da, db; cin >> n >> a >> b >> da >> db;
		map<int, vector<int> > g;
		forn(i, n - 1) {
			int u, v; cin >> u >> v;
			g[u].pb(v);
			g[v].pb(u);
		}
		int distance = dis(g, a, b);
		bool ans = false;
		if (distance <= da) ans = true;
		else {
			if (da >= db) ans = true;
			else ans = false;
		}
		if (ans) cout << "Alice" << ln;
		else cout << "Bob" << ln;
	}

}