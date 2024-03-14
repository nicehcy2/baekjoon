#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> v;

vector<char> num, oper;
char dx[3] = { ' ', '+', '-' };
int N;

void Input() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		int num; cin >> num;
		v.push_back(num);
	}
}

void calc(int n) {

	string str = "";

	str += num[0];
	for (int i = 1; i < v[n]; i++) {

		str += oper[i - 1];
		str += num[i];
	}

	int res = 0;

	string tNum = "";
	vector<int> cNum, cOper;
	// str.erase(remove(str.begin(), str.end(), ' '), str.end());

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '+' || str[i] == '-') {
			
			cNum.push_back(stoi(tNum));
			cOper.push_back(str[i]);
			tNum = "";
		}
		else if (str[i] == ' ') {
			continue;
		}
		else {
			tNum += str[i];
		}
	}
	cNum.push_back(stoi(tNum));

	res = cNum[0];
	for (int i = 0; i < cOper.size(); i++) {

		if (cOper[i] == '+') {
			res += cNum[i + 1];
		}
		else if (cOper[i] == '-') {
			res -= cNum[i + 1];
		}
	}

	if (!res)
		cout << str << "\n";
}

void backtracking(int idx, int n) {

	if (idx == v[n] - 1) {

		calc(n);

		return;
	}

	for (int i = 0; i < 3; i++) {

		oper[idx] = dx[i];
		backtracking(idx + 1, n);
	}
}

void Solution() {

	for (int i = 0; i < N; i++) {

		num.clear(); oper.clear();
		for (int j = 0; j < v[i] - 1; j++) {
			oper.push_back('#');
		}

		for (int j = 1; j <= v[i]; j++) {
			num.push_back(j + '0');
		}
		
		backtracking(0, i);
		cout << '\n';
	}
}

int main() {
	
	ios::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);

	Input();
	Solution();

	return 0;
}