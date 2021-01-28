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


/*int deleteProducts(vector<int> ids, int m) {
	priority_queue<pi, vector<pi>, greater<pi> > q;
	unordered_map<int, int> freq;
	for (auto i : ids) {
		freq[i]++;
	}
	for (auto i : freq) {
		int f = i.first;
		int s = i.second;
		cout << f << " " << s << ln;
		q.push(make_pair(s, f));
	}
	int i = 0;
	/*while (!q.empty() && i < m) {
		pi x = q.top();
		q.pop();
		x.first -= 1;
		i++;
		if (x.first != 0) {
			q.push(x);
		}
	}*/
/*int ans = 0;
return ans;*/



int main() {
	fast_cin();
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n; cin >> n;
	forn(i, n)
	//cout << deleteProducts(v, m);
}