#include <string>
#include <iostream>
using namespace std;

bool sets[21] = { false };

bool check(int i) {
	if (sets[i] == true) return true;
	return false;
}

void all() {
	for (int i = 1; i < 21; i++) {
		sets[i] = true;
	}
}

void empty() {
	for (int i = 1; i < 21; i++) {
		sets[i] = false;
	}
}

void remove(int x) {
	sets[x] = false;
}

void add(int x) {
	sets[x] = true;
}

void toggle(int x) {
	sets[x] = !sets[x];
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int m = 0;
	cin >> m;

	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		if (s == "empty") {
			empty();
			continue;
		}
		if (s == "all") {
			all();
			continue;
		}

		int n = 0;
		cin >> n;
		if (s == "add") {
			add(n);
		}
		else if (s == "check") {
			cout << check(n) << "\n";
		}
		else if (s == "toggle") {
			toggle(n);
		}
		else if (s == "remove") {
			remove(n);
		}
	}

}