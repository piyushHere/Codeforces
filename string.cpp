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

int dirx[4] = { -1, 0, 1, 0};
int diry[4] = {0, -1, 0, 1};

string reachTheEnd(vector<string> grid, int maxTime) {
	int m = grid.size();
	int n = grid[0].length();
	if (n == 0) return "No";
	queue<pair<int, int> > q;
	vector<vector<int> > dis(m, vector<int> (n, INT_MAX));
	q.push(make_pair(0, 0));
	dis[0][0] = 0;
	//cout << 1 << ln;
	while (!q.empty()) {
		pair<int, int> node = q.front();
		int node_r = node.first;
		int node_c = node.second;
		q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int neigh_r = node_r + diry[dir];
			int neigh_c = node_c + dirx[dir];
			if (neigh_r >= 0 && neigh_r < m  && neigh_c >= 0 && neigh_c < n && grid[neigh_r][neigh_c] == '.' && dis[neigh_r][neigh_c] == INT_MAX) {
				q.push(make_pair(neigh_r, neigh_c));
				dis[neigh_r][neigh_c] = dis[node_r][node_c] + 1;
			}
		}
	}
	if (dis[m - 1][n - 1] <= maxTime) return "Yes";
	else return "No";

}


int main() {
	fast_cin();
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	vector<string> maze;
	maze.pb(".#");
	maze.pb("#.");
	cout << reachTheEnd(maze, 2);
}