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
		int n, x, y;
		cin >> n >> x >> y;
		int gap = y - x;
		int i = n - 1;
		while (gap % i != 0) {
			i -= 1;
		}
		int jump = gap / i;
		vector<int> ans;
		int s = 0;
		int j = x;
		while (j <= y && s < n) {
			ans.pb(j);
			j += jump;
			s += 1;
		}
		j = x - jump;
		while (j > 0 && s < n) {
			ans.push_back(j);
			s += 1;
			j -= jump;
		}
		j = y + jump;
		while (s < n) {
			ans.pb(j);
			j += jump;
			s++;
		}
		for (auto el : ans) cout << el << " ";
		cout << ln;
	}

}