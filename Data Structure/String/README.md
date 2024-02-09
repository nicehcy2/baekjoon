# string

## 1. 개요

C++ STL에서 제공하는 클래스로, 말 그대로 String(문자열)을 다루는 클래스이다. 

C에서는 char* 또는 char[]의 형태로 문자열을 다뤘다면, C++에서는 문자열을 하나의 변수 type처럼 사용하며, 문자열을 훨씬 다양하고 쉽게 다룰 수 있게 해준다.

char*, char[] 과 다르게 **문자열의 끝에 \n 문자가 들어가지 않으며, 문자열의 길이를 동적으로 변경 가능**하다. <br/><br/>

## 2. string 클래스의 입/출력

C++ 입출력 방식인 cin, cout으로 입출력이 가능하며, getline 함수도 이용할 수 있다. C에서의 scanf와 printf는 사용이 불가능하다.

```C++
string str; // 문자열 생성

cin >> str; // 공백(space) 이전까지 문자열을 입력받는다.

getline(cin, str); // '\n' 이전까지의 문자열, 즉 한 줄을 통째로 입력 받는다. (공백 포함)

getline(cin, str, 'a'); // 'a' 문자 이전까지의 문자열을 입력받는다.

cout << str; // 문자열을 출력한다.
```
<br/>

## 3. string 클래스 생성

string을 이용하기 위해서 <string> 헤더 파일을 추가해야 한다.

string을 생성하는 방법들은 다음과 같다.

```c++
string str; // 빈 문자열 str 생성

string str = "abcdef";

string str; str = "abcdef"; // "abcdef"로 선언된 str 생성

string str("abcdef"); // "abcdef"로 선언된 str 생성

string str2(str1); // str1 문자열을 복사한 str2 생성

char s[] = {'a', 'b', 'c', 'd', 'e', 'f'};
string str(s); // C에서의 문자열과 호환 가능

string *str = new string("abcdef"); // new를 이용한 동적할당
```
<br/>

## 4. string 클래스 연산자 활용

- 문자열 비교 (<, >, ==): 두 문자열의 사전 순서를 비교, 또는 동일 여부를 확인할 수 있다.
- 문자열 연결 (+): 두 문자열을 이어주는 역할을 한다.
<br/>

## 5. string 클래스의 멤버 함수

#### ▶ string의 특정 원소 접근

|함수|동작 기능|
|:---|:---|
|str.at(index)|index 위치의 문자 반환. 유효한 범위인지 체크 O|
|str[index]|index 위치의 문자 반환. 유효한 범위인지 체크 X. 따라서 at 함수보다 접근이 빠름|
|str.front()|문자열의 가장 앞 문자 반환|
|str.back()|문자열의 가장 뒤 문자 반환|

<br/>

#### ▶ string의 크기

|함수|동작 기능|
|:---|:---|
|str.length()|문자열의 길이 반환|
|str.size()|문자열의 길이 반환 (length와 동일)|
|str.capacity()|문자열이 사용 중인 메모리 크기 반환|
|str.resize(n)|string을 n의 크기로 만듦. 기존의 문자열 길이보다 n이 작다면 남은 부분은 삭제하고, n이 크다면 빈공간으로 채움|
|str.resize(n, 'a')|n이 string의 길이보다 더 크다면, 빈 공간을 'a'로 채움|
|str.shrink_to_fit()|stirng의 capacity가 실제 사용하는 메모리보다 큰 경우 낭비되는 메모리가 없도록 메모리를 줄여줌|
|str.reserve()|size=n 만큼의 메모리를 미리 할당해줌|
|str.empty()|str이 빈 문자열인지 확인|

<br/>

#### ▶ string에 삽입, 추가, 삭제

|함수|동작 기능|
|:---|:---|
