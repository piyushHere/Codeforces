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
unordered_map<int, bool> m;
vector<pair<int, int>> ans;
v32 v;
int n;

bool rec(int x, int k, int &count) {
	if (k == 0) return true;
	for (int i = 0; i < v.size() - 1; i++) {
		for (int j = i + 1; j < v.size(); j++) {
			if (!m[i] && !m[j] && (v[i] + v[j] == x || k == n)) {
				m[i] = true;
				m[j] = true;
				ans.push_back(make_pair(v[i], v[j]));
				if (k == n || v[i] + v[j] == x) {
					if (k == n) count = v[i] + v[j];
					bool sub = rec(max(v[i], v[j]), k - 1, count);
					if (sub) return true;
					else {
						m[i] = false;
						m[j] = false;
						ans.pop_back();
					}
				}
			}
		}
	}

	return false;
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
		v = v32(2 * n);
		forn(i, 2 * n) {
			cin >> v[i];
		}
		ans.clear();
		m.clear();
		int count = 0;
		/*bool flag = false;
		for (int i = 0; i < 2 * n - 1; i++) {
			for (int j = i + 1; j < 2 * n; j++) {
				int x = v[i] + v[j];
				if (rec(x, n)) {
					flag = true;
					cout << "YES" << ln << x << ln;
					break;
				}
			}
			if (flag) break;
		}
		if (flag) {
			for (auto p : ans) {
				cout << p.first << " " << p.second << ln;
			}
		}*/
		if (rec(0, n, count)) {
			cout << "YES" << ln << count << ln;
			for (auto p : ans) {
				cout << p.first << " " << p.second << ln;
			}
		}
		else cout << "NO" << ln;
	}

}