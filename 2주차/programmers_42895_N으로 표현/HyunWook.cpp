#include <string>
#include <vector>
using namespace std;

int result = 1000000000;
int n;
int number_s;
int arr[9] = { 0, };
void dfs(int cnt, int num) {
	if (result <= cnt)
		return;
	if (cnt > 8)
		return;
	if (num == number_s) {
		if (result > cnt)
			result = cnt;
		return;
	}
	for (int i = 1; i <= 8; i++) {
		dfs(cnt + i, num + arr[i]);
		dfs(cnt + i, num*arr[i]);
		dfs(cnt + i, num / arr[i]);
		dfs(cnt + i, num - arr[i]);
	}

	return;
}


int solution(int N, int number) {
	int answer = 0;
	n = N;
	number_s = number;

	for (int i = 1; i <= 8; i++) {
		arr[i] = arr[i - 1] * 10 + n;
	}

	dfs(0, 0);

	answer = result;
	if (result > 8)
		return -1;
	return answer;
}