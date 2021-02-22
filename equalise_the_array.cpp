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

//unordered_map<long long, int, custom_hash> safe_map;
//gp_hash_table<long long, int, custom_hash> safe_hash_table;


main() {
	fast_cin();
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		unordered_map<int, int, custom_hash> m;
		v32 v;
		forn(i, n) {
			int x; cin >> x;
			m[x] += 1;
		}
		for (auto i : m) v.push_back(i.second);
		sort(all(v));
		unordered_map<int, int, custom_hash> last_index;
		unordered_map<int, int, custom_hash> pre_sum;
		unordered_map<int, int, custom_hash> post_sum;
		int last_element = -1;
		int cur_sum = 0;
		int sum = 0;
		forn(i, v.size()) {
			int curr_element = v[i];
			last_index[curr_element] = i;
			if (curr_element != last_element) {
				sum += cur_sum;
				pre_sum[curr_element] = sum;
				last_element = curr_element;
				cur_sum = 0;
			}
			cur_sum += curr_element;
		}
		/*for (auto i : v) cout << i << " ";
		cout << ln;*/
		last_element = -1;
		sum = 0;
		cur_sum = 0;
		for (int i = v.size() - 1; i >= 0; i--) {
			int curr_element = v[i];
			if (curr_element != last_element) {
				sum += cur_sum;
				post_sum[curr_element] = sum;
				last_element = curr_element;
				cur_sum = 0;
			}
			cur_sum += curr_element;
		}
		/*for (auto i : pre_sum) cout << i.first << "->" << i.second << ln;
		cout << ln;
		for (auto i : post_sum) cout << i.first << "->" << i.second << ln;
		cout << ln;
		for (auto i : last_index) cout << i.first << "->" << i.second << ln;*/
		int ans = INT_MAX;
		int l = v.size();
		for (auto k : pre_sum) {
			int i = k.first;
			ans = min(ans, pre_sum[i] + post_sum[i] - (l - (last_index[i] + 1)) * i);
			//cout << ans << ln;
		}
		cout << ans << ln;
	}

}