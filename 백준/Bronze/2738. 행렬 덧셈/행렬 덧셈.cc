#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N, M;
    vector<vector<int>> A, B, sum;
    cin >> N >> M;
    
    
    for(int i=0; i<N; i++){
        vector<int> v;
        for(int j=0; j<M; j++){
            int tmp;
            cin >> tmp;
            v.push_back({tmp});
        }
        A.push_back(v);
    }
    
    for(int i=0; i<N; i++){
        vector<int> v;
        for(int j=0; j<M; j++){
            int tmp;
            cin >> tmp;
            v.push_back({tmp});
        }
        B.push_back(v);
    }
    
    sum = A;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            sum[i][j] += B[i][j];
        }
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cout << sum[i][j] << " ";
        }
        cout << '\n';
    }
    
    return 0;
}