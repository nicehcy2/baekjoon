#include <iostream>

using namespace std;

#define EAST 1
#define WEST 2
#define NORTH 3
#define SOUTH 4

int N, M, X, Y, K;
int arr[21][21];
int dice[4][3];
int command[1001];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

bool CheckBound(int y, int x) {
    if (y >= 0 && y < N && x >= 0 && x < M) return true;
    else return false;
}

void RotateDice(int command) {
    if (command == EAST) {
        int temp = dice[1][1];
        dice[1][1] = dice[1][0];
        dice[1][0] = dice[3][1];
        dice[3][1] = dice[1][2];
        dice[1][2] = temp;
    }
    else if (command == WEST) {
        int temp = dice[1][1];
        dice[1][1] = dice[1][2];
        dice[1][2] = dice[3][1];
        dice[3][1] = dice[1][0];
        dice[1][0] = temp;
    }
    else if (command == NORTH) {
        int temp = dice[1][1];
        dice[1][1] = dice[0][1];
        dice[0][1] = dice[3][1];
        dice[3][1] = dice[2][1];
        dice[2][1] = temp;
    }
    else if (command == SOUTH) {
        int temp = dice[1][1];
        dice[1][1] = dice[2][1];
        dice[2][1] = dice[3][1];
        dice[3][1] = dice[0][1];
        dice[0][1] = temp;
    }
}

bool MoveNextArr(int command) {
    int tempY = Y;
    int tempX = X;
    tempY += dy[command - 1];
    tempX += dx[command - 1];

    // cout << "TEST: " << tempY << " " << tempX << '\n';

    if (CheckBound(tempY, tempX)) {
        X = tempX, Y = tempY;
        return true;
    }
    else return false;
}

void Solution() {
    for (int i = 0; i < K; i++) {
        if (!MoveNextArr(command[i])) continue;
        RotateDice(command[i]);

        if (arr[Y][X] == 0) {
            arr[Y][X] = dice[1][1];
        }
        else {
            dice[1][1] = arr[Y][X];
            arr[Y][X] = 0;
        }

        cout << dice[3][1] << '\n';
    }
}

void Input() {
    cin >> N >> M >> Y >> X >> K;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < K; i++) {
        cin >> command[i];
    }
}

int main() {
    Input();
    Solution();

    return 0;
}