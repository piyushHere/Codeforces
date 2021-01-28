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
		int n, q; cin >> n >> q;
		v32 arr(n);
		forn(i, n) {
			cin >> arr[i];
		}

		vector<int> fin;
		int flag = 0;

		if (n == 1) fin.push_back(0);
		else if (arr[0] > arr[1]) {
			fin.push_back(0);
			flag = 1;
		}

		for (int i = 1; i < n - 1; i++)
		{
			if (flag == 1) {
				if ((arr[i - 1] > arr[i]) and (arr[i] < arr[i + 1])) {
					fin.push_back(i);
					flag = 0;
				}
			}
			else {
				if ((arr[i - 1] < arr[i]) and (arr[i] > arr[i + 1])) {
					fin.push_back(i);
					flag = 1;
				}
			}
		}
		if (flag == 0) {
			if (arr[n - 1] > arr[n - 2])
				fin.push_back(n - 1);
		}


		else {
			if (arr[n - 1] < arr[n - 2])
				fin.push_back(n - 1);
		}
		long long ans = 0;
		int l = fin.size();
		if (l & 1) {
			forn(i, l) {
				if (i & 1) ans -= arr[fin[i]];
				else ans += arr[fin[i]];
			}
		}
		else {
			forn(i, l - 1) {
				if (i & 1) ans -= arr[fin[i]];
				else ans += arr[fin[i]];
			}
		}
		cout << ans << ln;

	}

}