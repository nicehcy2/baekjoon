#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <stack>
#include <string>
#include <cstdlib>
#include <sstream>
#include <deque>
#pragma warning(disable:4996)
using namespace std;

deque<int> dq;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T, n, cnt = 0, tmp = 0, chk = 0, qIndex = 0;
	vector<int> v;
	string p, str;

	cin >> T;

	while (T > 0) {
		cin >> p >> n;
		cnt = 0;
		chk = 1;
		qIndex = 0;
		cin >> str;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] >= '0' && str[i] <= '9')
			{
				qIndex = qIndex * 10 + str[i] - '0';
			}
			else if (str[i] == ',')
			{
				dq.push_front(qIndex);
				qIndex = 0;
			}
			else if (str[i] == ']' && qIndex != 0)
			{
				dq.push_front(qIndex);
				qIndex = 0;
			}
		}

		for (int i = 0; i < p.length(); i++) {
			if (p[i] == 'R') {
				chk *= -1;
			}
			else if (p[i] == 'D') {
				if (dq.empty()) {
					cnt = -1;
					break;
				}
				else {
					if (chk < 0)
						dq.pop_front();
					else if (chk > 0)
						dq.pop_back();
				}
			}
		}

		if (cnt == -1) {
			cout << "error\n";
		}
		else {
			if (chk < 0) {
				if (dq.empty()) cout << "[]\n";
				else {
					cout << "[";
					while (dq.size() > 1) {
						cout << dq.front() << ',';
						dq.pop_front();
					}
					cout << dq.front() << ']' << '\n';
					dq.pop_front();
				}
			}
			else if (chk > 0) {
				if (dq.empty()) cout << "[]\n";
				else {
					cout << "[";
					while (dq.size() > 1) {
						cout << dq.back() << ',';
						dq.pop_back();
					}
					cout << dq.back() << ']' << '\n';
					dq.pop_back();
				}
			}
		}
		
		

		T--;
	}


	return 0;
}