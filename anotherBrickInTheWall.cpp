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

vector<vector<int> > vis;
vector<vector<char> > v;
int n;
int dirx[4] = { -1, 0, 1, 0};
int diry[4] = {0, -1, 0, 1};

void dfs(int i, int j, int k) {
	if (i < 0 || i >= n || j < 0 || j >= n || v[i][j] - '0' != k || vis[i][j] != -1) return;
	vis[i][j] = k;
	for (int dir = 0; dir < 4; dir++) {
		dfs(i + diry[dir], j + dirx[dir], k);
	}
}


int main() {
	fast_cin();
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t; cin >> t;
	while (t--) {
		cin >> n;
		v = vector<vector<char> >(n, vector<char> (n));
		forn(i, n) {
			forn(j, n) {
				cin >> v[i][j];
			}
		}
		vis = vector<vector<int> >(n, vector<int> (n, -1));
		dfs(0, 1, 0);
		dfs(0, 1, 1);
		dfs(1, 0, 0);
		dfs(1, 0, 1);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << vis[i][j] << " ";
			}
			cout << ln;
		}
		if (vis[n - 2][n - 1] == -1 && vis[n - 1][n - 2] == -1) cout << 0 << ln;
		else {
			if (vis[n - 2][n - 1] == -1) {
				cout << 1 << ln;
				cout << n - 1 + 1 << " " << n - 2 + 1 << ln;
			}
			else if (vis[n - 1][n - 2] == -1) {
				cout << 1 << ln;
				cout << n - 2 + 1 << " " << n - 1 + 1 << ln;
			}
			else {
				cout << 2 << ln;
				cout << n - 1 + 1 << " " << n - 2 + 1 << ln;
				cout << n - 2 + 1 << " " << n - 1 + 1 << ln;
			}
		}
	}

}