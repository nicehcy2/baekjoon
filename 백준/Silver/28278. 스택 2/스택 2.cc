#include <iostream>
#include <stack>

using namespace std;

int n;
stack<int> s;

void Input() {
	cin >> n;

	int num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		if (num == 1) {
			int integer;
			cin >> integer;
			s.push(integer);
		}
		else if (num == 2) {
			if (!s.empty()) {
				cout << s.top() << '\n';
				s.pop();
			}
			else {
				cout << "-1\n";
			}
		}
		else if (num == 3) {
			cout << s.size() << '\n';
		}
		else if (num == 4) {
			if (s.empty()) {
				cout << "1\n";
			}
			else {
				cout << "0\n";
			}
		}
		else {
			if (!s.empty()) {
				cout << s.top() << '\n';
			}
			else {
				cout << "-1\n";
			}
		}
	}
}

void Solution() {
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Input();
	Solution();

	return 0;
}