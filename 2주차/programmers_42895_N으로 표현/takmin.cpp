//문제: N으로 표현(LV3)
//알고리즘:  DFS
//푼날짜: 2021-01-08						


#include<iostream>
#include<algorithm>
#include<limits.h>
#define MAX 9

using namespace std;
int n;
int num;
int ans=INT_MAX;
void DFS(int depth, int sum) {
	if (depth >= MAX) return;
	if (sum == num) {
		ans = min(ans, depth);
		return;
	}
	int operand = 0;
	//i는 깊이 즉, 숫자의개수
	for (int i = 1; i <= MAX; i++) {
		operand = operand * 10 + n;
		DFS(depth + i, sum + operand);
		DFS(depth + i, sum - operand);
		if (sum != 0) {
			DFS(depth + i, sum / operand);
			DFS(depth + i, sum * operand);
		}


	}
}

int solution(int N, int number) {
	n = N; 
	num = number;

	DFS(0, 0);
	if (ans >= MAX) return -1;
	return ans;

}
