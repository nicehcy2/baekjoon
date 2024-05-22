#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	vector<int> v1;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		int tmp;
		cin >> tmp;
		v1.push_back(tmp);
	}
	sort(v1.begin(), v1.end());
	cin >> m;
	for (int i = 0; i < m; ++i) {
		int tmp;
		cin >> tmp;
		if (binary_search(v1.begin(), v1.end(), tmp))
			cout << "1\n";
		else cout << "0\n";
	}


	return 0;
}