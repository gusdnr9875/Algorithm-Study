#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <cmath>
int N, result = 0;
int row[13] = { 0, }; //열값을 넣어줄 예정

bool checked(int r) {

	for (int i = 0; i < r; i++) {
		if (row[i] == row[r])
			return false;
		else if (abs(row[i] - row[r]) == r - i)
			return false;
	}
	return true;
}

void dfs(int r) {
	if (N == r) {
		result++;
		return;
	}

	for (int i = 0; i < N; i++) { //0열부터 n-1열까지 검사
		row[r] = i;
		if (checked(r)) {
			dfs(r + 1);
		}
		row[r] = 0;
	}
	return;
}

int solution(int n) {
	int answer = 0;
	N = n;
	dfs(0);
	answer = result;
	return answer;
}

int main() {

	printf("%d\n", solution(4));
}