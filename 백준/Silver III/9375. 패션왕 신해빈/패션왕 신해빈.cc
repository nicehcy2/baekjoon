#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int T, N;

unordered_map<string, int> passion;

void Solution() {
    int ans = 1;

    for (auto p : passion) {
        ans *= p.second + 1;
    }

    cout << ans - 1 << '\n';
}

void Input() {
    cin >> T;

    while (T--) {
        cin >> N;
        passion.clear();

        for (int i = 0; i < N; i++) {
            string name, type;
            cin >> name >> type;

            passion[type]++;
        }

        Solution();
    }
}

int main() {
    Input();
    // Solution();

    return 0;
}