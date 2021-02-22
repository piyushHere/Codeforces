#include<bits/stdc++.h>
using namespace std;

#define int long long
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

struct custom_hash {
	static uint64_t splitmix64(uint64_t x) {
		// http://xorshift.di.unimi.it/splitmix64.c
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}

	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};

//int MAXN = 1 << 17;
int t[4 * (1 << 17)];
v32 a;
int n;

void build(int v, int tl, int tr, int flag) {
	// this condition is for leaf node a.k.a the actual element of array
	if (tl == tr) {
		t[v] = a[tl];
	} else {
		int tm = (tl + tr) / 2;
		build( v * 2, tl, tm, flag + 1);
		build( v * 2 + 1, tm + 1, tr, flag + 1);
		if ((n - flag) & 1) t[v] = t[v * 2] | t[v * 2 + 1];
		else t[v] = t[v * 2] ^ t[v * 2 + 1];
		/*t[v] = t[v*2] + t[v*2+1];*/
	}
}

void update(int v, int tl, int tr, int pos, int new_val, int flag) {
	if (tl == tr) {
		t[v] = new_val;
	} else {
		int tm = (tl + tr) / 2;
		if (pos <= tm)
			update(v * 2, tl, tm, pos, new_val, flag + 1);
		else
			update(v * 2 + 1, tm + 1, tr, pos, new_val, 1 + flag);
		if ((n - flag) & 1) t[v] = t[v * 2] | t[v * 2 + 1];
		else t[v] = t[v * 2] ^ t[v * 2 + 1];
	}
}

main() {
	fast_cin();
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int m;
	cin >> n >> m;
	int len = 1 << n;
	a = v32(len);
	forn(i, len) cin >> a[i];
	build(1, 0, len - 1, 0);
	//for (int i = 1; i <= 7; i++) cout << t[i] << " ";
	forn(i, m) {
		int p, val;
		cin >> p >> val;
		update(1, 0, len - 1, p - 1, val, 0);
		cout << t[1] << ln;
	}
}