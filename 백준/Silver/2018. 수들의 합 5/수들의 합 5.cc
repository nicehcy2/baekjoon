#include <iostream>

using namespace std;

int n;

void Solution() {

    int sum = 1, ans = 1, start = 1, end = 1;

    while (end != n) {
        if (sum == n) {
            ans++;
            end++;
            sum += end;
        }
        else if (sum < n) {
            end++;
            sum += end;
        }
        else if (sum > n) {
            sum -= start;
            start++;
        }
    }

    cout << ans << '\n';
}

void Input() {

    cin >> n;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    Solution();

    return 0;
}