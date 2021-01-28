#include <iostream>
#include <bits/stdc++.h>
#include <numeric> //For gcd()
#define ll long long int
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define fo(i, n) for (int i = 0; i < n; ++i)
#define foe(i, n) for (int i = 1; i <= n; ++i)
#define Fo(i, k, n) for (int i = k; i < n; ++i)
#define FOR(i, a, b) for (int i = (a); i < (b); ++(i))
#define vi vector<int>
#define vll vector<ll>
#define vvl vector<vector<ll>>
#define vpll vector<pair<ll, ll>>
#define MOD 998244353
#define MAX 1024
using namespace std;
using pi = pair<ll, ll>;
using namespace std;


/*void addEdge(int u, int v, bool bidir = false) {
	adjList[u].push_back(v);
	if (bidir) {
		adjList[v].push_back(u);
	}
}*/

map<int, bool> vis;

int dfs(int s, int d, vector<vector<int> > &input3, int bus) {
	if (s == d) return 0;
	int ans = INT_MAX;
	vis[s] = true;
	for (int i = 0; i < input3.size(); i++) {
		int curr = INT_MAX;
		if (input3[i][0] == s && !vis[input3[i][1]]) {
			if (bus == input3[i][2]) {
				int rec = dfs(input3[i][1], d, input3,  bus);
				rec == INT_MAX ? curr = INT_MAX : curr = 1 + rec;
			}
			else {
				if (bus != -1) {
					int rec = dfs(input3[i][1], d, input3, input3[i][2]);
					rec == INT_MAX ? curr = INT_MAX : curr = 2 + rec;
				}
				else {
					int rec = dfs(input3[i][1], d, input3, input3[i][2]);
					rec == INT_MAX ? curr = INT_MAX : curr = 1 + rec;
				}
			}
		}
		if (curr != INT_MAX) ans = min(ans, curr);
	}
	vis[s] = false;
	return ans;

}

int route(int input1, int input2, vector<vector<int> > input3) {
	return dfs(0, input1 - 1, input3,  -1);
}

/*int bfs(int src, int dest) {
	map<int, bool> visited;
	map<T, int> dist;
	for (auto i : adjList) {
		dist[i.first] = INT_MAX ;
	}
	dist[src] = 0;
	queue<int> q;
	q.push(src);
	visited[src] = true ;
	while (!q.empty()) {
		T node = q.front();
		// cout<<node<<" -> ";
		q.pop();
		for (auto neighbour : adjList[node]) {
			if (!visited[neighbour]) {
				q.push(neighbour);
				dist[neighbour] = dist[node] + 1;
				visited[neighbour] = true ;
			}
		}
	}
	if (dist[dest] == INT_MAX) return -1;
	else return dist[dest];
}*/

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t1, t2;
	cin >> t1 >> t2;
	vector<vector<int>  > v;
	//unordered_map<int,vector<int> > g;
	for (int i = 0; i < t2; i++) {
		vector<int> temp;
		int ans1, ans2, ans3;
		cin >> ans1 >> ans2 >> ans3;
		//g[ans1].push_back(ans2);
		temp.push_back(ans1);
		temp.push_back(ans2);
		temp.push_back(ans3);
		v.push_back(temp);
	}

	int result = route(t1, t2, v);
	if (result == INT_MAX) cout << -1 << endl;
	else
		cout << result << endl;
}