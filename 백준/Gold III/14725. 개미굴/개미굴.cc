#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int N, K;

class Trie {
private:
    map<string, Trie*> child;

public:
    void insert(vector<string>& str, int idx) {
        if (str.size() == idx) {
            return;
        }

        if (child.find(str[idx]) == child.end()) {
            child.insert({ str[idx], new Trie });
        }

        child[str[idx]]->insert(str, idx + 1);
    }

    void Output(int idx) {
        for (auto iter = child.begin(); iter != child.end(); iter++) {

            for (int i = 0; i < idx; i++) {
                cout << "--";
            }
            cout << iter->first << '\n';
            iter->second->Output(idx + 1);
        }
    }
};

void Solution() {
    cin >> N;
    Trie* root = new Trie;

    for (int i = 0; i < N; i++) {
        cin >> K;

        vector<string> str;
        for (int j = 0; j < K; j++) {
            string tmp;
            cin >> tmp;

            str.push_back(tmp);
        }

        root->insert(str, 0);
    }

    root->Output(0);
}

void Input() {
}

int main() {
    Input();
    Solution();

    return 0;
}