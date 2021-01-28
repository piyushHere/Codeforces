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

// n = 18
// den[] = {7,5,1}

int coin_change(int n, vector<int> den, int memo[]) {
	// Base case
	if (n == 0) {
		return 0;
	}
	// recursive step
	if (memo[n] != -1) return memo[n];
	int ans = INT_MAX;
	for (int i = 0; i < den.size(); i++) {
		if (n - den[i] >= 0) {
			int sub_ans = coin_change(n - den[i], den, memo);
			if (sub_ans != INT_MAX && sub_ans + 1 < ans) {
				ans = sub_ans + 1;
			}
		}
	}
	memo[n] = ans;
	return memo[n];
}


int main() {
	fast_cin();
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n = 18;
	vector<int> den;
	int memo[n + 1];
	memset(memo, -1, sizeof(memo));
	den.push_back(7);
	den.push_back(5);
	den.push_back(1);
	cout << coin_change(n, den, memo);

}