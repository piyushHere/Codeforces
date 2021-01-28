#include<bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	int a, b, c;
	a = 0;
	b = 0;
	c = 1;
	int i = 0;
	do {
		cout << c << " ";
		a = b;
		b = c;
		c = a + b;
		i++;
	}
	while (i < n);
}