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

int choose(vector<vector<int> > dispensers, int demand, int time) {
	int candidate_dispenser = -1;
	int candidate_wait = 9999;
	for (int i = 0; i < dispensers.size(); i++) {
		if (dispensers[i][1] >= demand + dispensers[i][0]) {
			int wait = max(dispensers[i][0] - time, 0);
			if (candidate_wait > wait) {
				if (wait == 0) return i;
				else {
					candidate_dispenser = i;
					candidate_wait = wait;
				}
			}
		}
	}
	return candidate_dispenser;
}

int solution(vector<int> a, int n, int x, int y, int z) {
	vector<vector<int> > dispensers;
	vector<int> v1; v1.push_back(0); v1.push_back(x);
	vector<int> v2; v2.push_back(0); v2.push_back(y);
	vector<int> v3; v3.push_back(0); v3.push_back(z);
	dispensers.push_back(v1);
	dispensers.push_back(v2);
	dispensers.push_back(v3);
	int curr_time = 0;
	for (auto car : a) {
		int choice = choose(dispensers, car, curr_time);
		if (choice == -1) return -1;
		if (dispensers[choice][0] > curr_time) {
			int wait = dispensers[choice][0] - curr_time;
			curr_time += wait;
		}
		vector<int> v; v.push_back(dispensers[choice][0] + car); v.push_back(dispensers[choice][1]);
		dispensers[choice] = v;
	}
	return curr_time;
}


int main() {
	fast_cin();
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int x = 3, y = 5, z = 7;
	vector<int> v;
	v.pb(1);
	v.pb(2);
	v.pb(3);
	v.pb(3);
	v.pb(2);
	v.pb(1);
	v.pb(3);
	cout << solution(v, 7, x, y, z);
}