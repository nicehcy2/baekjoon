#include <iostream>
#include <string>

using namespace std;

string str;

void Solution() {
    int mCnt = 0;
    string max = "", min = "";

    // max 값 구하기
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == 'M') {
            mCnt++;
        }
        
        else if (str[i] == 'K') {
            max += "5";

            for (int j = 0; j < mCnt; j++) {
                max += "0";
            }

            mCnt = 0;
        }
    }
    // mCnt가 남아있다면?
    if (mCnt != 0) {
        for (int i = 0; i < mCnt; i++) {
            max += "1";
        }

        mCnt = 0;
    }
    mCnt = 0;

    // min 값 구하기
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == 'M') {
            mCnt++;
        }

        else if (str[i] == 'K') {
            if (mCnt != 0)
                min += "1";

            for (int j = 0; j < mCnt - 1; j++) {
                min += "0";
            }

            mCnt = 0;
            min += "5";
        }
    }
    // mCnt가 남아있다면?
    if (mCnt != 0) {
        min += "1";

        for (int i = 0; i < mCnt - 1; i++) {
            min += "0";
        }

        mCnt = 0;
    }


    cout << max << '\n' << min << '\n';
}

void Input() {
    cin >> str;
}

int main() {
    Input();
    Solution();

    return 0;
}