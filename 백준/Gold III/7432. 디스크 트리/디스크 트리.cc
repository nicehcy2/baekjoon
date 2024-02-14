#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int N;

class Trie {
private:
    map<string, Trie*> child;

public:
    void Insert(vector<string> &v, int idx) {

        if (v.size() == idx) {
            return;
        }

        if (child.find(v[idx]) == child.end()) {
            child[v[idx]] = new Trie;
        }

        child[v[idx]]->Insert(v, idx + 1);
    }

    void Output(int idx) {

        for (auto iter = child.begin(); iter != child.end(); iter++) {

            for (int i = 0; i < idx; i++) {
                cout << " ";
            }
            cout << iter->first << '\n';

            iter->second->Output(idx + 1);
        }
    }
};

void Solution() {

}

void Input() {
    cin >> N;
    string str, parse = "";

    Trie* root = new Trie;

    while (N--) {
        cin >> str;
        vector<string> v;

        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '\\') {
                v.push_back(parse);
                parse.clear();
            }
            else {
                parse += str[i];
            }
        }

        v.push_back(parse);
        parse.clear();

        root->Insert(v, 0);
    }

    root->Output(0);
}

int main() {
    Input();
    Solution();

    return 0;
}