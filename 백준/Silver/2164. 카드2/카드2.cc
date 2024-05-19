#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <stack>
#include <queue>
#include <list>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	queue<int> card;

	cin >> n;

	for (int i = 1; i <= n; ++i) {
		card.push(i);
	}

	while (card.size() > 1) {
		card.pop();
		int temp = card.front();
		card.pop();
		card.push(temp);
	}

	cout << card.front() << '\n';

	return 0;
}