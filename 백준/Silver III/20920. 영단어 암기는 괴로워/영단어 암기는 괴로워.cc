#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
map<string, int> um;
vector<string> voca;

bool cmp(string a, string b) {
    if (a.size() == b.size() && um[a] == um[b]) {
        return a < b;
    }
    else if (um[a] == um[b]) {
        return a.size() > b.size();
    }

    return um[a] > um[b];
}

void Solution() {

    sort(voca.begin(), voca.end(), cmp);

    for (int i = 0; i < voca.size(); i++) {
        cout << voca[i] << '\n';
    }
}

void Input() {

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string word;

        cin >> word;

        if (word.size() >= M) {

            if (um.find(word) == um.end()) {
                voca.push_back(word);
                um[word]++;
            }

            else {
                um[word]++;
            }
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