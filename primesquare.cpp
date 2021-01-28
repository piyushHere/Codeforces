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

bool isPrime(int n)
{
	// Corner case
	if (n <= 1)
		return false;

	// Check from 2 to n-1
	for (int i = 2; i < n; i++)
		if (n % i == 0)
			return false;

	return true;
}


int main() {
	fast_cin();
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t ; cin >> t;
	while (t--) {
		int n; cin >> n;
		bool p = isPrime(n);
		if (p) {
			forn(i, n) {
				forn(j, n) {
					cout << 1 << " ";
				}
				cout << ln;
			}
		}
		else {
			vector<vector<int> > v(n, vector<int> (n, 0));
			forn(i, n) {
				v[i][i] = 1;
				v[i][n - i - 1] = 1;
			}
			if (n & 1) {
				v[n / 2][0] = 1;
				v[n - 1][0] = 0;
				v[n - 1][n / 2] = 1;
			}
			forn(i, n) {
				forn(j, n) {
					cout << v[i][j] << " ";
				}
				cout << ln;
			}

		}
	}

}