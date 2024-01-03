#include <iostream>
#include <vector>

using namespace std;

int N, gMax = 0;
int board[21][21];

vector<vector<int>> MoveUp(vector<vector<int>> lv) {
    for (int j = 0; j < N; j++) {
        for (int i = 0; i < N; i++) {
            if (lv[i][j] == 0) {
                for (int k = i + 1; k < N; k++) {
                    if (lv[k][j]) {
                        lv[i][j] = lv[k][j];
                        lv[k][j] = 0;
                        break;
                    }
                }
            }
        }

        for (int i = 1; i < N ; i++) {
            if (lv[i - 1][j] == lv[i][j]) {
                lv[i - 1][j] += lv[i][j];

                for (int k = i; k < N - 1; k++) {
                    if (lv[k + 1][j]) lv[k][j] = lv[k + 1][j];
                    else lv[k][j] = 0;
                }
                lv[N - 1][j] = 0;
            }
        }
    }

    return lv;
}

vector<vector<int>> MoveDown(vector<vector<int>> lv) {
    for (int j = 0; j < N; j++) {
        for (int i = N - 1; i >= 0; i--) {
            if (lv[i][j] == 0) {
                for (int k = i - 1; k >= 0; k--) {
                    if (lv[k][j]) {
                        lv[i][j] = lv[k][j];
                        lv[k][j] = 0;
                        break;
                    }
                }
            }
        }

        for (int i = N - 2; i >= 0; i--) {
            if (lv[i + 1][j] == lv[i][j]) {
                lv[i + 1][j] += lv[i][j];

                for (int k = i; k > 0; k--) {
                    if (lv[k - 1][j]) lv[k][j] = lv[k - 1][j];
                    else lv[k][j] = 0;
                }
                lv[0][j] = 0;
            }
        }
    }

    return lv;
}

vector<vector<int>> MoveLeft(vector<vector<int>> lv) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (lv[i][j] == 0) {
                for (int k = j + 1; k < N; k++) {
                    if (lv[i][k]) {
                        lv[i][j] = lv[i][k];
                        lv[i][k] = 0;
                        break;
                    }
                }
            }
        }

        for (int j = 1; j < N; j++) {
            if (lv[i][j - 1] == lv[i][j]) {
                lv[i][j - 1] += lv[i][j];
                for (int k = j; k < N - 1; k++) {
                    if (lv[i][j + 1]) lv[i][k] = lv[i][k + 1];
                    else lv[i][k] = 0;
                }
                lv[i][N - 1] = 0;
            }
        }
    }

    return lv;
}

vector<vector<int>> MoveRight(vector<vector<int>> lv) {
    for (int i = 0; i < N; i++) {
        for (int j = N - 1; j >= 0; j--) {
            if (lv[i][j] == 0) {
                for (int k = j - 1; k >= 0; k--) {
                    if (lv[i][k]) {
                        lv[i][j] = lv[i][k];
                        lv[i][k] = 0;
                        break;
                    }
                }
            }
        }

        for (int j = N - 2; j >= 0; j--) {
            if (lv[i][j + 1] == lv[i][j]) {
                lv[i][j + 1] += lv[i][j];
                for (int k = j; k > 0; k--) {
                    if (lv[i][j - 1]) lv[i][k] = lv[i][k - 1];
                    else lv[i][k] = 0;
                }
                lv[i][0] = 0;
            }
        }
    }

    return lv;
}

int FindMaxValue(vector<vector<int>> v) {
    int lMax = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (lMax < v[i][j]) {
                lMax = v[i][j];
            }
        }
    }

    return lMax;
}

void BackTracking(int cnt, vector<vector<int>> v) {
    if (cnt == 5) {
        int lMax = FindMaxValue(v);
        if (lMax > gMax) {
            gMax = lMax;
        }

        return;
    }

    vector<vector<int>> lv = v;
    // UP
    lv = MoveUp(lv);
    BackTracking(cnt + 1, lv); lv = v;

    // DOWN
    lv = MoveDown(lv);
    BackTracking(cnt + 1, lv); lv = v;

    // LEFT
    lv = MoveLeft(lv);
    BackTracking(cnt + 1, lv); lv = v;

    // RIGHT
    lv = MoveRight(lv);
    BackTracking(cnt + 1, lv); lv = v;
}

void Solution() {
    vector<vector<int>> v;

    for (int i = 0; i < N; i++) {
        vector<int> tmp;
        for (int j = 0; j < N; j++) {
            tmp.push_back(board[i][j]);
        }
        v.push_back(tmp);
    }

    BackTracking(0, v);
    /*
    vector<vector<int>> lv = v;
    lv = MoveRight(v);

    cout << '\n';
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << lv[i][j] << " ";
        }
        cout << '\n';
    }*/

    cout << gMax << '\n';
}

void Input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
}

int main() {
    Input();
    Solution();

    return 0;
}