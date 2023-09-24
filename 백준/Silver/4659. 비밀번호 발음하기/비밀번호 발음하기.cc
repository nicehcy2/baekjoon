	#include <iostream>
#include <string>
#include <vector>
#include <utility>
using namespace std;
 
bool onemoreComp(string str) {
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
			return true;
		}
	}
	return false;
}
bool threeConti(string str) {
	int consonant = 0;	//자음
	int collection = 0;	//모음
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
			if (consonant != 0) { //자음 나오다가 모음 나온 경우 -> 자음 초기화
				consonant = 0;
			}
			collection += 1;
		}
		else {	//자음
			if (collection != 0) {	//모음 나오다가 자음 나온 경우 -> 모음 초기화
				collection = 0;
			}
			consonant += 1;
		}
 
		if (consonant >= 3 || collection >= 3) return false;
	}
	return true;
}
bool twoConti(string str) {
	for (int i = 0; i < str.length()-1; i++) {
		if (str[i] == str[i + 1]) {
			if (str[i] == 'e' || str[i] == 'o') continue;
			else return false;
		}
	}
	return true;
}
 
 
int main() {
 
	vector<pair<string, bool>> vec;
 
	while (1) {
 
		string str;
		cin >> str;
		if (str == "end") break;
 
		if (onemoreComp(str) == false || threeConti(str) == false || twoConti(str) == false) {
			vec.push_back(make_pair(str, false));
		}
		else vec.push_back(make_pair(str, true));
 
	}
	for (int i = 0; i < vec.size(); i++) {
		cout << "<" << vec[i].first << "> is ";
		if (vec[i].second == true) cout << "acceptable.\n";
		else cout << "not acceptable.\n";
	}
 
 
	return 0;
}