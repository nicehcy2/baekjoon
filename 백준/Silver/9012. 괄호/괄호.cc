#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
using namespace std;

string checkVPS(string input) //stack이 남아있으면 VPS가 아님
{
	stack<char> ps;
	for (int i = 0; i < input.size(); ++i) {
		if (input[i] == '(') {
			ps.push('(');
		}
		else {
			if (ps.empty()) return "NO";
			ps.pop();
		}
	}
	if (ps.empty()) {
		return "YES";
	}
	else {
		return "NO";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	string ps;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> ps;
		cout << checkVPS(ps) << '\n';
	}


	return 0;
}