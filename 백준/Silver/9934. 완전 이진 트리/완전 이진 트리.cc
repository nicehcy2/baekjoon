#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> arr[10];
int ipt[1024];
int k;

void insertTree(int depth, int start, int end) {
	if (start >= end)
		return;

	int mid = (start + end) / 2;
	arr[depth].push_back(ipt[mid]);
	insertTree(depth + 1, start, mid);
	insertTree(depth + 1, mid+1, end);
}

int main(void)
{
	cin >> k;

	for (int i = 0; i < pow(2, k) - 1; i++) {
		cin >> ipt[i];
	}

	insertTree(0, 0, pow(2, k) - 1);

	for (int i = 0; i < k; i++) {
		for (auto o : arr[i]) {
			cout << o << ' ';
		}
		cout << "\n";
	}

	

	return 0;
}