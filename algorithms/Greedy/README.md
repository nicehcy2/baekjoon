# GREEDY(탐욕 알고리즘)

## 1. 개요

<br/>

**그리디 알고리즘(탐욕법)** 은 최적의 값을 구해야 하는 상황에서 사용되는 근시안적인 방법론으로 **각 단계에서 최적이라고 생각되는 것을 선택** 해 나가는 방식으로 진행하여 최종적인 해답에 도달하는 알고리즘이다.

이때, **항상 최적의 값을 보장하는 것이 아니라 최적의 값이 근사한 값을 목표로** 하고 있다.

근시안적 방법론(단기적인 목표를 중심으로 한 전략적인 접근 방법), 근사 알고리즘(최적해에 근접한 값) <br/><br/>

## 2. 그리디 알고리즘을 쓰는 이유

<br/>

사실, 매 순간 최고의 선택을 하는 그리디 알고리즘은 항상 결과적으로 최적의 해를 보장하지 못한다. 그럼에도 그리디 알고리즘을 사용하는 이유는 최적해를 보장하는 문제에서 완전 탐색, 동적 계획법보다 수행 시간이 빠르기 때문이다. 최적해를 보장하지 못하는 경우에도 근사 알고리즘으로 사용이 가능하고, 대부분의 경우 속도가 매우 빠르기 때문에 실용적으로 사용할 수 있다.

특별한 구조가 있는 문제에 대해서는 탐욕 알고리즘이 언제나 최적해를 찾아낼 수 있고 이 구조를 **매트로이드**라 한다.
이러한 문제에 탐욕 알고리즘을 사용해서 빠른 계산 속도로 답을 구할 수 있다. <br/><br/>

## 3. 그리디 알고리즘 사용 조건

<br/>

#### 1. 탐욕 선택 속성(Greedy Choice Property)
   **각 단계에서 최선의 선택을 했을 때 전체 문제에 대한 최적해를 구할 수 있는 경우를 말한다.** 즉, 각 단계에서 가장 이상적인 선택을
   하는 것이 전체적으로 최적의 결과를 가져온다는 것이다. 현재의 선택이 미래의 선택에 영향을 주지 않기 때문에 가능하다.

#### 2. 최적 부분 구조(Optimal Substructure)
  **전체 문제의 최적해가 부분 문제의 최적해로 구성 될 수 있는 경우를 말한다.** 즉, 전체 문제를 작은 부분 문제로 나누어 각각의 부분 문제에서 최적의 해를 구한 후 이를 조합하여 전체 문제의 최적해를 구하는 것을 의미한다. <br/><br/>

## 4. 그리디 알고리즘 사용하기

<br/>

**그리디 알고리즘의 단계는 매 단계마다 최적이라고 생각되는 선택을 하면서 최종적으로 전체적으로 최적인 해답을 찾아내는 과정을 의미한다.** 어떻게 **정렬**해야 미래의 선택은 따져보지 않고 현재만 고려해도 최적해를 구할 수 있을지에 대한 답을 찾아야 한다.

<br/>

그리디 알고리즘의 단계
1. 문제의 최적해 구조를 결정한다.
2. 문제의 구조에 맞게 선택 절차를 정의한다: **선택절차(Selection Procedure)**
3. 선택 절차에 따라 선택을 수행한다.
4. 선택된 해가 문제의 조건을 만족하는지 검사한다: **적절성 검사(Feasibility Check)**
5. 조건을 만족하지 않으면 해당 해를 제외한다.
6. 모든 선택이 완료되며 해답을 검사한다: **해답 검사(Solution Check)**
7. 조건을 만족하지 않으면 해답으로 인정되지 않습니다.

<br/>

#### 1단계: 선택절차
- **이 단계에서는 현재 상태에서 최적인 선택을 한다.** 이 선택은 이후에 바뀌지 않는다. <br/><br/>

#### 2단계: 적정설 검사
- **이 단계에서는 선택한 항목이 문제의 조건을 만족시키는지 확인한다.** 조건을 만족시키지 않으면 해당 항목은 제외된다. <br/><br/>

#### 3단계: 해답 검사
- **이 단계에서는 모든 선택이 완료되면, 최종 선택이 문제의 조건을 만족 시키는지 확인한다.** 조건을 만족시키면 해답으로 인정된다. <br/><br/>

## 5. 그리디 알고리즘 예시

<br/>

#### 1. 거스름돈

문제 확인
- 거스름돈으로 1260원을 거슬러줘야 할 때 500원, 100원, 50원, 10원짜리 동전이 무한정 존재한다면, 가장 큰 동전부터 가능한 많이 사용하는 방식으로 거스름돈을 계산해 준다.

<br/>

그리디 알고리즘 적용
1. 선택 절차 : 거스름돈 문제에서 가장 가치가 큰 동전부터 선택을 한다.
2. 적절성 검사: 만약 선택된 동전의 가치가 거스름돈보다 크다면 다음으로 작은 동전을 선택한다.
3. 해답 검사 : 합이 일치하면 거스름돈 문제가 해결된다. <br/><br/>

## 6. 기타 내용

#### 그리디 알고리즘 vs 동적 계획법

<br/>

|분류|그리디 알고리즘|동적 계획법(DP)|
|:---|:----------|:----------|
|설명|각 단계에서 최적의 선택을 하는 <br/>방식으로 문제를 해결함|작은 문제의 해를 메모이제이션하여 <br/> 중복 계산을 피하고, 이를 이용하여 <br/>큰 문제를 해결함|
|성립 조건|1. 탐욕 선택 속성 <br/> 2. 최적 부분 구조|1. 중복 문제 <br/> 2. 최적 부분 구조|
|중복 부분 문제|중복 부분 문제를 해결하지 않음|중복 부분 문제를 해결할 수 있음|
|상황|- 각 단계에서 최적을 선택하여 최적의 경로를 구함 <br/> - 최적이 아니거나 풀리지 않을 수 있음|- 모든 상황을 계산하여 최적의 경로를 구할 수 있음 <br/> - 모든 상황을 계산하기에 시간이 오래 걸림|

<br/>

## 7. 다시 풀만한 문제
[문제 풀기](https://github.com/nicehcy2/baekjoon/blob/main/algorithms/Greedy/PROBLEM.md)

<br/>

[메인으로 돌아가기](https://github.com/nicehcy2/baekjoon)
