//Solution
//- 올라갔다 내려가는 형태로 가장 긴 부분수열이 '바이토닉 수열'이다.
//- Failed 1 : 이중 for문에서 벗어나고자 BFS를 사용.
//- 1. 풀이 방식
//- 1.1. 한쪽 방향으로 큰 수들을 찾고 다시 재귀로 큰 수를 찾아가면서 dp[] 업데이트.
//- 1.2. 반대쪽에서 1.1.과 동일하게 수행.
//- 1.3. 양쪽방향의 dp[]합에 1을 더한 최대값 출력.
//- 2. 시간초과 발생
//- 2.1. 증가수열이나 감소수열에서 똑같이 O(N^2)임을 확인. if문만 늘어남.
//- 3. 이중 for문으로 풀이하니 시간초과 해결됨.
//- 3.1. 현재 값보다 작으며 작은 값들 중 가장 큰 값의 dp[] + 1을 하면 dp[]가 구해짐
//- 이론적인 접근은 다음과 같다.
//- 1. 증가하는 방향에 대해 최장 증가수열은 지나온 방향의 최장 길이 + 1이다.
//- 1.1. 자신보다 작은 값에 대해 최장 길이를 찾고 거기에 1을 더한다.
//- 2. 양쪽 방향에 대해 1.을 구한다.
//- 3. 특정 위치에서 양쪽 방향에 대한 최장 길이를 구한다.
//- 3.1. 양쪽 수열에서 시작 부분의 원소가 같으므로 한개를 제외한다.
//- 3.2. 따라서 왼쪽 최장길이 + 오른쪽 최장길이 - 1이 최대가 되는 값이 정답이다.
//- 풀이는 다음과 같다.
//- 1. 필요한 변수를 세팅.
//- 1.1. arr[] : 수열을 저장
//- 1.2. l_dp[] : 왼쪽 방향으로의 최장 감소 부분수열 길이, 왼쪽에서 시작할 때, 증가하는 부분수열 길이
//- 1.3. r_dp[] : 오른쪽 방향으로의 최장 감소 부분수열 길이, 오른쪽에서 시작할 때, 증가하는 부분수열 길이
//- 1.4. answer : 가장 긴 바이토닉 수열을 만드는 부분수열의 길이
//- 2. l_dp[]의 모든 원소에 대해 l_dp_update()를 수행한다.
//- 2.1. l_dp[]는 최소 1의 길이를 갖는다.
//- 2.2. 현재위치(target)보다 왼쪽의 원소(i)에 대해 다음을 수행한다.
//- 2.2.1. arr[target]보다 arr[i]가 크거나 같은 경우, 무시한다.
//- 2.2.2. l_dp[i] + 1이 l_dp[target] 보다 크면, l_dp[target]을 l_dp[i] + 1로 업데이트 한다.
//- 2.2.3. 위 과정을 반복해 현재 값보다 작으며 가장 큰 값을 찾을 수 있고 arr[target]에 해당 위치의 dp[] + 1이 저장된다.
//- 3. r_dp[]의 모든 원소에 대해 r_dp_update()를 수행한다.
//- 3.1. r_dp[]는 최소 1의 길이를 갖는다.
//- 3.2. 현재위치(target)보다 오른쪽의 원소(i)에 대해 다음을 수행한다.
//- 3.2.1. arr[target]보다 arr[i]가 크거나 같은 경우, 무시한다.
//- 3.2.2. r_dp[i] + 1이 r_dp[target] 보다 크면, r_dp[target]을 r_dp[i] + 1로 업데이트 한다.
//- 3.2.3. 위 과정을 반복해 현재 값보다 작으며 가장 큰 값을 찾을 수 있고 arr[target]에 해당 위치의 dp[] + 1이 저장된다.
//- 4. 2., 3.과정을 통해 얻은 dp[] 테이블로 최장 길이를 구한다.
//- 4.1. 양쪽 방향에 대해 교집합인 i를 제외해야한다.
//- 4.2. 따라서, r_dp[i] + l_dp[i] - 1이 최대가 되는 값을 출력하면 된다.

#include <iostream>
#include <algorithm>

using namespace std;

#define VOL_MAX 1000 + 1

int N;
int arr[VOL_MAX];
int l_dp[VOL_MAX];
int r_dp[VOL_MAX];
int answer;

void init() {
	cin >> N;
	for (int n = 0; n < N; n++) {
		cin >> arr[n];
	}
}

void l_dp_update(int target) {
	l_dp[target] = 1;
	for (int i = 0; i < target; i++) {
		if (arr[target] <= arr[i]) continue;
		if (l_dp[i] + 1 > l_dp[target]) {
			l_dp[target] = l_dp[i] + 1;
		}
	}
}
void r_dp_update(int target) {
	r_dp[target] = 1;
	for (int i = N - 1; i > target; i--) {
		if (arr[target] <= arr[i]) continue;
		if (r_dp[i] + 1 > r_dp[target]) {
			r_dp[target] = r_dp[i] + 1;
		}
	}
}

void solution() {
	init();
	for (int i = 0; i < N; i++) l_dp_update(i);
	for (int i = N - 1; i >= 0; i--) r_dp_update(i);

	for (int i = 0; i < N; i++) {
		answer = max(answer, l_dp[i] + r_dp[i] - 1);
	}

	cout << answer << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}