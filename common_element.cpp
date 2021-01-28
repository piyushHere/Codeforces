#include<bits/stdc++.h>
using namespace std;


int common_element(vector<int> v1, vector<int> v2, vector<int> v3, int n1, int n2, int n3) {
	int i = 0, j = 0, k = 0;
	//cout << max(v1[i], max(v2[j], v3[k]));
	// 3 pointer approach
	while (i < n1 && j < n2 && k < n3) {
		int largest = max(v1[i], max(v2[j], v3[k]));
		//cout << largest << " " << endl;
		cout << v1[i] << " " << v2[j] << " " << v3[k] << endl;
		if (v1[i] == largest && v2[j] == largest && v3[k] == largest) {
			return largest;
		}
		if (v1[i] < largest) {
			i++;
		}
		if (v2[j] < largest) {
			j++;
		}
		if (v3[k] < largest) {
			k++;
		}
	}
	return -1;
}

int main() {
	int n1, n2, n3; cin >> n1 >> n2 >> n3;
	vector<int> arr1(n1);
	vector<int> arr2(n2);
	vector<int> arr3(n3);
	for (int i = 0; i < n1; i++) {
		cin >> arr1[i];
	}
	for (int i = 0; i < n2; i++) {
		cin >> arr2[i];
	}
	for (int i = 0; i < n3; i++) {
		cin >> arr3[i];
	}
	cout << common_element(arr1, arr2, arr3, n1, n2, n3);
}