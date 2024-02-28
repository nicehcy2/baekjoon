#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;
    
    sort(routes.begin(), routes.end());
    
    int stan = routes[0][1];
    
    for(int i=1; i<routes.size(); i++) {
        if (stan < routes[i][0]){
            stan = routes[i][1];
            answer++;
        }
        
        // 더 짧은 경우를 반영해줘야됨
        if (stan >= routes[i][1]) {
            stan = routes[i][1];
        }
    }
    
    
    return answer + 1;
}