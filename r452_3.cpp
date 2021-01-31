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
	ll n; cin >> n;
	if (n == 2) {
		cout << 1 << ln << 1 << " " << 1;
	}
	else if (n % 4 == 0) {
		cout << 0 << ln;
		cout << n / 2 << " ";
		forn(i, n / 4) cout << i + 1 << " " << n - i << " ";
	}
	else if (n & 1) {
		if ((n + 1) % 4 == 0) {
			cout << 0 << ln;
			cout << (n + 1) / 2 << " ";
			forn(i, (n + 1) / 4) cout << i + 1 << " " << n - i - 1 << " ";
		}
		else {
			cout << 1 << ln;
			cout << (n - 1) / 2 << " ";
			forn(i, (n - 1) / 4) cout << i + 2 << " " << n - i << " ";
		}
	}
	else {
		cout << 1 << ln;
		int k =  ((n * (n + 1)) / 2) / ((n - 1) * 2);
		cout << k * 2 << " ";
		forn(i, k) cout << i + 1 << " " << n - 2 - i << " ";
	}

}