#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long int a;
long long int b;
int mini = 10000;

void input() {
	cin >> a >> b;
}

void dfs(long long int a, int cnt) {
	if (a > b) {
		return;
	}

	if (a == b) {
		mini = min(mini, cnt);
	}
	dfs(2 * a, cnt + 1);
	dfs(10 * a + 1, cnt + 1);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();

	int cnt = 0;

	dfs(a, 1);
	if (mini == 10000) cout << -1;
	else cout << mini;
	

	return 0;
}