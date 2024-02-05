[메인으로 돌아가기](https://github.com/nicehcy2/baekjoon)

# 자주 틀리는 문법 정리

## 1. 개요

코딩 테스트 문제를 풀다가 반복적으로 틀리는 문법들이 있어 이를 정리하는 문서이다. 

단순히 어려운 문법보단 자주 헷갈렸던 문법을 C++ 위주로 작성했다. 

헷갈리거나 몰랐던 문법이 있을 때마다 추가할 예정이다. <br/><br/>

## 2. 정리

### priority_queue 
c++ STL에서 제공하는 priority_queue는 기본적으로 최대 힙(Max Heap)을 사용하므로 최소 힙을 이용하려면 추가의 문법이 필요하다.

- priority_queue 오름차순 (int, greater<T>)

```c++
  #include <queue>

  priority_queue<int, vector<int>, greater<int>> pq;
```

- priority_queue 오름차순 (int, Compare)

```c++
  #include <queue>

  struct Compare {
      bool operator()(int a, int b) {
          return a > b; // 최소 힙을 위해 '>'를 사용
      }
  };

  priority_queue<int, vector<int>, Compare> pq;
```

- priority_queue 오름차순 (pair<int, int>, greater<>)

```c++
  #include <queue>

  // 첫 번째(first) 원소를 기준으로 비교
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
```

- priority_queue 오름차순 (pair<int, int>, Compare)

```c++
  #include <queue>

  struct Compare {
      bool operator()(pair<int, int>& a, pair<int, int>& b) {
          return a.first > b.first; // second를 기준으로 비교하고 싶으면 first를 second로 변경
      }
  };

  priority_queue<int, vector<int>, Compare> pq;
```

- priority_queue (임의의 클래스)

```c++
  // z -> y -> x 순으로 비교
  struct cmp {
  	bool operator()(point a, point b) {
  		if (a.z == b.z) {
  			if (a.y == b.y) {
  				return a.x > b.x;
  			}
  			return a.y > b.y;
  		}
  		return a.z > b.z;
  	}
  };
```

- priority_queue 오름차순 (vector<vector<int>>, Compare)

```c++
  #include <queue>
  #include <vector>

  struct cmp {
    	bool operator()(vector<int> a, vector<int> b) {
    	  	return a[1] > b[1];
      };

  priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
```

<br/>

### sort()
- 오름차순 (greater<>())
```c++
  #include <algorithm>

  sort(v.begin(), v.end(), greater<>());
```

- 오름차순 (cmp)
```c++
  #include <algorithm>

  bool cmp(int i, int j) {
    return  i > j;
  }

  sort(v.begin(), v.end(), cmp);
```

<br/>

### 2차원 vector 초기화
```c++
  // 3 x 4 크기으ㅢ 2차원 벡터를 0으로 초기화
  vector<vector<int>> v(3, vector<int>(4, 0));
```
```c++
  // 3 x 4 크기으ㅢ 2차원 벡터를 0으로 초기화
  vector<vector<int>> v;

  for(int i=0; i<3; i++){
    vector<int> lv;
    for(int j=0; j<4; j++){
      lv.push_back(0);
    }
    v.push_back(lv);
  }
```

<br/>

### 2차원 배열 호출
```c++
  void func(int matrix[3][4]){
  }

  int matrix[3][4];
  func(matrix);
  
```
