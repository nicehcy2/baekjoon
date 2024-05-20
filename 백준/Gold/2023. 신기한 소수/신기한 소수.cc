#include <iostream>
#include <string>

using namespace std;

int N;

bool findDecimal(int n) {

    if (n == 1) return false;
    else if (n == 2) return true;

    for (int i = 2; i <= n - 1; i++) {

        if (n % i == 0) return false;
    }

    return true;
}

void dfs(int n) {

    if (findDecimal(n)) {

        string str = to_string(n);
        if (str.size() == N) {

            cout << str << '\n';
            return;
        }
        
        n = 10 * n;
        for (int i = 0; i <= 9; i++) {
            dfs(n + i);
        }
    }
}

void Solution() {

    dfs(2);
    dfs(3);
    dfs(5);
    dfs(7);
}

void Input() {
    
    cin >> N;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    Input();
    Solution();

    return 0;
}