#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int N, M;
unordered_map<string, string> m;

void Solution() {
    for (int i = 0; i < M; i++) {
        string site;
        cin >> site;

        cout << m[site] << '\n';
    }
}

void Input() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string site, pass;
        cin >> site >> pass;

        m[site] = pass;
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Input();
    Solution();

    return 0;
}