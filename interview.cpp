// array : 1, 2, 3
// given sum: 10
// minimum coins to make the required sum

// 4 (3*3 + 1*1)
// dynamic programming
#include<bits/stdc++.h>
using namespace std;
/*unordered_map<vector<int>, bool> m;*/

int minimumCoins(vector<int> coins, int target_sum, vector<int> &curr, vector<vector<int> > &all_possible) {
	if (target_sum == 0) {
		all_possible.push_back(curr);
		return 0;
	}
	// iterate over my whole vector
	int ans = INT_MAX;
	for (int i = 0; i < coins.size(); i++) {
		int val = coins[i];
		// curr is the minimum coins after considering the curr coin
		if (val > target_sum) continue;
		// consider the curr element in the answer
		curr.push_back(val);
		int curr_val = minimumCoins(coins, target_sum - val, curr, all_possible);
		if (curr_val != INT_MAX && curr_val + 1 < ans) {
			ans = curr_val + 1;
		}
		curr.pop_back();
	}
	return ans;
}

int main() {
	int n; cin >> n;
	vector<int> coins(n);
	for (int i = 0; i < n; i++) {
		cin >> coins[i];
	}
	vector<int> curr;
	vector<vector<int> > all_possible;
	int sum;
	cin >> sum;
	int ans = minimumCoins(coins, sum, curr, all_possible);
	if (ans == INT_MAX) cout << "Not possible to make the given target sum";
	else {
		cout << "The minimum coins required are :" << ans << endl;
		cout << "Possible answers are" << endl;
		for (auto i : all_possible) {
			for (auto j : i) {
				cout << j << " ";
			}
			cout << endl;
		}
	}
}
