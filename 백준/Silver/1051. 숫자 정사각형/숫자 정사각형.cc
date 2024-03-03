#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int N, M;
int arr[51][51];

void Solution() {

    int answer = 1;

    for (int t = 1; t < min(N, M); t++) {
        bool flag = false;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {

                if ((i + t < N) && (j + t < M)) {
                    if ((arr[i][j] == arr[i + t][j]) && (arr[i][j] == arr[i + t][j + t]) && (arr[i][j] == arr[i][j + t])) {
                        flag = true;
                    }
                }
            }
        }

        if (flag) {
            answer = t + 1;
        }
    }

    cout << pow(answer, 2) << '\n';
}

void Input() {
    
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;

        for (int j = 0; j < str.size(); j++) {
            arr[i][j] = str[j];
        }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Input();
    Solution();

    return 0;
}