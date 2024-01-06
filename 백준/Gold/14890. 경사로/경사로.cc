#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>

using namespace std;

int N, L, answer = 0;
int arr0[101][101];
int arr1[101][101];

bool CheckRoadBack(int i, int j, int arr[][101]) {
    int count = 0;

    while (true) {
        if (j - 1 >= 0) {
            if (arr[i][j - 1] == arr[i][j]) {
                count++;
                j--;
            }
            else {
                break;
            }
        }
        else {
            break;
        }
    }

    if (count + 1 >= L) return true;
    else return false;
}

bool CheckRoadForward(int i, int j, int arr[][101]) {
    int count = 0;

    while (true) {
        if (j + 1 < N) {
            if (arr[i][j + 1] == arr[i][j]) {
                count++;
                j++;
            }
            else {
                break;
            }
        }
        else {
            break;
        }
    }

    if (count + 1 >= L) return true;
    else return false;
}

void Solution(int arr[][101]) {
    for (int i = 0; i < N; i++) {
        bool possible = true;
        bool visited[101] = { false, };

        for (int j = 0; j < N - 1; j++) {
            // 경사로의 높이 차이가 1보다 클 경우
            if (abs(arr[i][j] - arr[i][j + 1]) > 1) {
                possible = false;
                break;
            }

            // 낮은 곳에서 높은 곳으로 경사로를 설치
            if (arr[i][j + 1] - arr[i][j] == 1) {
                if (CheckRoadBack(i, j, arr)) {
                    for (int k = 0; k < L; k++) {
                        if (!visited[j - k]) {
                            visited[j - k] = true;
                        }
                        else {
                            possible = false;
                            break;
                        }
                    }
                }
                else {
                    possible = false;
                    break;
                }
            }

            // 높은 곳에서 낮은 곳으로 경사로 설치
            if (arr[i][j] - arr[i][j + 1] == 1) {
                if (CheckRoadForward(i, j + 1, arr)) {
                    for (int k = 0; k < L; k++) {
                        if (!visited[j + 1 + k]) {
                            visited[j + 1 + k] = true;
                        }
                        else {
                            possible = false;
                            break;
                        }
                    }
                }
                else {
                    possible = false;
                    break;
                }
            }
        }


        if (possible) {
            answer++;
        }

    }
}

void Input() {
    cin >> N >> L;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr0[i][j]; // 가로
            arr1[j][i] = arr0[i][j];
        }
    }
}

int main() {
    Input();
    Solution(arr0);
    Solution(arr1);

    cout << answer << '\n';

    return 0;
}