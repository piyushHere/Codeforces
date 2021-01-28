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
//==============================================================================================================================
// BITS/STDC++.H problem macOS : https://discuss.codechef.com/t/bits-stdc-h-does-not-work-in-mac-os/12587
//==============================================================================================================================

int main() {
	fast_cin();
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int c;
	cin >> c;
	setprecision(15);
	while (c--) {
		//cout<<"@"<<c<<ln;
		double t = 0;
		double l = 0, r;
		int count;
		cin >> count >> r;
		// vector<float> arr(10,0);
		deque<double> q;
		for (int i = 0; i < count; i++) {
			double temp;
			cin >> temp;
			q.push_back(temp);
		}
		double vl = 1, vr = 1;
		while (!q.empty()) {
			double a = ((q.front() - l) / vl);
			double b = ((r - q.back()) / vr);
			if (a < b) {
				t += a;
				vl += 1;
				l = q.front();
				q.pop_front();
				r -= (vr * a);
			}
			else if (b < a) {
				t += b;
				vr += 1;
				r = q.back();
				q.pop_back();
				l += (vl * b);
			}
			else {
				t += a;
				vr += 1;
				vl += 1;
				l = q.front();
				q.pop_front();
				r = q.back();
				if (!q.empty()) q.pop_back();
			}
		}
		t += ((r - l) / (vl + vr));
		cout << setprecision(16) << t << endl;
	}

	return 0;
}