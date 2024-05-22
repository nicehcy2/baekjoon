#include <iostream>
#include <string>

using namespace std;

int N;
int arr[65][65];

string recursive(int n, int y, int x) {
    
    if (n == 1) {
        if (arr[y][x]) return "(1)";
        else return "(0)";
    }

    else {
        
        int oneCnt = 0, zeroCnt = 0;

        for (int i = y; i < y + n; i++) {
            for (int j = x; j < x + n; j++) {
                if (arr[i][j]) oneCnt++;
                else zeroCnt++;
            }
        }
        if (oneCnt == n * n) return "1";
        else if (zeroCnt == n * n) return "0";

        string str = "(";

        oneCnt = 0, zeroCnt = 0;

        for (int i = y; i < y + n / 2; i++) {
            for (int j = x; j < x + n / 2; j++) {

                if (arr[i][j]) oneCnt++;
                else zeroCnt++;
            }
        }

        if (oneCnt == n * n / 4) str += "1";
        else if (zeroCnt == n * n / 4) str += "0";
        else str += recursive(n / 2, y, x);

        oneCnt = 0, zeroCnt = 0;

        for (int i = y; i < y + n / 2; i++) {
            for (int j = x + n / 2; j < x + n; j++) {

                if (arr[i][j]) oneCnt++;
                else zeroCnt++;
            }
        }

        if (oneCnt == n * n / 4) str += "1";
        else if (zeroCnt == n * n / 4) str += "0";
        else str += recursive(n / 2, y, x + n / 2);

        oneCnt = 0, zeroCnt = 0;

        for (int i = y + n / 2; i < y + n; i++) {
            for (int j = x; j < x + n / 2; j++) {

                if (arr[i][j]) oneCnt++;
                else zeroCnt++;
            }
        }

        if (oneCnt == n * n / 4) str += "1";
        else if (zeroCnt == n * n / 4) str += "0";
        else str += recursive(n / 2, y + n / 2, x);

        oneCnt = 0, zeroCnt = 0;

        for (int i = y + n / 2; i < y + n; i++) {
            for (int j = x + n / 2; j < x + n; j++) {

                if (arr[i][j]) oneCnt++;
                else zeroCnt++;
            }
        }

        if (oneCnt == n * n / 4) str += "1";
        else if (zeroCnt == n * n / 4) str += "0";
        else str += recursive(n / 2, y + n / 2, x + n / 2);

        str += ")";

        return str;
    }
}

void Solution() {

    if (N == 1) cout << arr[0][0];
    else cout << recursive(N, 0, 0);
}

void Input() {

    cin >> N;

    string s;

    for (int i = 0; i < N; i++) {

        cin >> s;
        for (int j = 0; j < N; j++) {

            arr[i][j] = s[j] - '0';
        }
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