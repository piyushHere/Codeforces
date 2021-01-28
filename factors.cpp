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

int x, y, l;

void printDivisors(int n)
{
	// Note that this loop runs till square root
	for (int i = 1; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			// If divisors are equal, print only one
			if (n / i == i) {
				l++;
				if (i % 2 == 0) x++;
				if (i % 3 == 0) y++;
			}

			else {
				int f = i;
				int s = n / i;
				if (f % 2 == 0) x++;
				if (f % 3 == 0) y++;
				l += 2;
			}
		}
	}
}


/*void primeFactors(int n)
{
	// Print the number of 2s that divide n
	while (n % 2 == 0)
	{
		//cout << 2 << " ";
		x++;
		l++;
		n = n / 2;
	}

	// n must be odd at this point. So we can skip
	// one element (Note i = i +2)
	for (int i = 3; i <= sqrt(n); i = i + 2)
	{
		// While i divides n, print i and divide n
		while (n % i == 0)
		{
			//cout << i << " ";
			if (i == 2) x++;
			else if (i == 3) y++;
			l++;
			n = n / i;
		}
	}

	// This condition is to handle the case when n
	// is a prime number greater than 2
	if (n > 2) {
		if (n % 2 == 0) x++;
		if (n % 3 == 0) y++;
		l++;
	}
}*/


int main() {
	fast_cin();
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		l = 0, x = 0, y = 0;
		primeFactors(n);
		//printDivisors(n);
		cout << l << ln;
		cout << x << " " << y << ln;
		if (x + y != l + 2 || x > y) cout << -1 << ln;
		else {
			cout << (y - x) + y << ln;
		}
	}

}