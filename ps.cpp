#include<bits/stdc++.h>
using namespace std;

#define int long long
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

void dfs(unordered_map<int, vector<int> > &m, int s, long long &count, unordered_map<int, int> &vis) {
    vis[s] = 1;
    count++;
    for (auto neigh : m[s]) {
        if (!vis[neigh]) {
            dfs(m, neigh, count, vis);
        }
    }
}

vector<int> getTheGroups(int n, vector<string> queryType, vector<int> students1, vector<int> students2) {
    unordered_map<int, vector<int> > adj;
    vector<int> ans;
    for (int i = 0; i < queryType.size(); i++) {
        int v1 = students1[i];
        int v2 = students2[i];
        if (queryType[i] == "Friend") {
            adj[v1].push_back(v2);
            adj[v2].push_back(v1);
        }
        else {
            long long count1 = 0, count2 = 0;
            unordered_map<int, int> vis1;
            unordered_map<int, int> vis2;
            dfs(adj, v1, count1, vis1);
            if (!vis1[v2]) dfs(adj, v2, count2, vis1);
            ans.push_back(count1 + count2);
        }
    }
    return ans;
}


main() {
    fast_cin();
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<string> queryType;
    int n; cin >> n;
    int q; cin >> q;
    int total = 0;
    vector<int> students1, students2;
    forn(i, q) {
        string s; cin >> s;
        if (s == "Total") total++;
        queryType.push_back(s);
    }
    int k; cin >> k;
    forn(i, k) {
        int x; cin >> x;
        students1.push_back(x);
    }
    cin >> k;
    forn(i, k) {
        int x; cin >> x;
        students2.push_back(x);
    }
    vector<int> ans = getTheGroups(n, queryType, students1, students2);
    for (auto i : ans) cout << i << ln;
    //cout << students1[1] << " " << students2[1] << ln;
    // cout << total << ln;
}