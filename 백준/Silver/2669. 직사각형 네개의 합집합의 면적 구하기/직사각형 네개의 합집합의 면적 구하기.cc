#include <iostream>

using namespace std;

bool arr[101][101];

void Solution() {
    int res = 0; 

    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 101; j++) {
            if (arr[i][j] == true) {
                res++;
            }
        }
    }

    cout << res << '\n';
}

void Input() {
    int cnt = 0;
    while (cnt < 4) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int i = y1; i < y2; i++) {
            for (int j = x1; j < x2; j++) {
                arr[i][j] = true;
            }
        }
        cnt++;
    }

}

int main() {
    Input();
    Solution();

    return 0;
}

