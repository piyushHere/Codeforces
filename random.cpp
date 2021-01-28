#include<bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> array(n);
	unordered_map<int, int> freq;
	for (int i = 0; i < n; i++) {
		cin >> array[i];
		freq[array[i]]++;
	}
	for (auto ind : freq) {
		int element = ind.first;
		int count = ind.second;
		if (count > 1) {
			cout << element << " ";
		}
	}
}