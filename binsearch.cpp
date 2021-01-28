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
	int n, x, pos; cin >> n >> x >> pos;
	int l = 0;
	int r = n;
	int mid = (l + r) / 2;
	int lar = n - x;
	int sma = x - 1;
	int count = 1;
	long long ans = 1;
	//cout << lar << endl;
	while (l < r) {
		mid = (l + r) / 2;
		if (pos == mid) {
			break;
		}
		else if (pos < mid) {
			if (lar == 0) {
				cout << "lar" << ln;
				ans = 0;
				break;
			}
			ans *= lar;
			lar -= 1;
			ans = ans % 1000000007;
			count++;
			r = mid - 1;
		}
		else {
			if (sma == 0) {
				ans = 0;
				cout << "sma" << ln;
				break;
			}
			ans *= sma;
			sma -= 1;
			ans = ans % 1000000007;
			count++;
			l = mid + 1;
		}
	}
	ans = ans % 1000000007;
	cout << ans << ln;
	int rem = n - count;
	cout << rem << ln;
	ll s = 1;
	for (int i = rem; i >= 1; i--) {
		ans = ans % 1000000007;
		ans = ans * i;
	}
	cout << ans % 1000000007;

}