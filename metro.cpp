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

int minimizeCost(vector<int> numPeople, vector<int> x, vector<int> y) {
	int n = x.size();
	int x_m = INT_MIN;
	int y_m = INT_MIN;
	for (int i = 0; i < n; i++) {
		int xi = x[i];
		int yi = y[i];
		x_m = max(x_m, xi);
		y_m = max(y_m, yi);
	}
	cout << x_m << ln << y_m << ln;
	vector<vector<int> > dp(y_m, vector<int> (x_m));
	for ()
		return 0;
}


int main() {
	fast_cin();
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int cities; cin >> cities;
	v32 people(cities);
	forn(i, cities) cin >> people[i];
	v32 x(cities);
	v32 y(cities);
	forn(i, cities) {
		cin >> x[i];
	}
	forn(i, cities) {
		cin >> y[i];
	}
	cout << minimizeCost(people, x, y);

}