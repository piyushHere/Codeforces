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

void printDivisors(int n)
{
	// Note that this loop runs till square root
	for (int i = 1; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			// If divisors are equal, print only one
			if (n / i == i)
				printf("%d ", i);

			else // Otherwise print both
				printf("%d %d ", i, n / i);
		}
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
		ll l, r, m; cin >> l >> r >> m;
		ll low = m - (r - l);
		ll high = m + (r - l);
		ll a = 0, b = 0, c = 0;
		bool ans = false;
		for (ll i = low; i <= m ; i++) {
			if (ans) break;
			for (ll j = 1; j <= sqrt(i); j++)
			{
				if (i % j == 0)
				{
					if (j <= r && j >= l) {
						a = j;
						b = l;
						c = m - i + l;
						ans = true;
						break;
					}
				}
			}
		}
		for (ll i = m; i <= high; i++) {
			if (ans) break;
			for (ll j = 1; j <= sqrt(i); j++)
			{
				if (i % j == 0)
				{
					if (j <= r && j >= l) {
						a = j;
						b = l;
						c = i - m + l;
						ans = true;
						break;
					}
				}
			}
		}
		cout << a << " " << b << " " << c << ln;
	}
}
