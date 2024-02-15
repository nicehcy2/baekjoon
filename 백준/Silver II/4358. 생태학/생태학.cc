#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string, double> m;
int cnt;

void Solution() {
    cout << fixed;
    cout.precision(4);

    for (auto iter = m.begin(); iter != m.end(); iter++) {
        cout << iter->first << " ";
        cout << iter->second * 100 / cnt << "\n";
    }
}

void Input() {
    string str;

    while (getline(cin, str)) {

        cnt++;
        m[str] += 1;
    }
}

int main() {
    Input();
    Solution();

    return 0;
}