//Solution
//- 주어진 행렬의 순서는 유지한 채 곱셈의 우선순위만 바꿔서 곱셈 연산수가 최소가 되는 값을 구하는 문제
//- 이론적 접근은 다음과 같다.
//- 1. 주어진 행렬의 순서를 유지한 채, 잘게 분할한다.
//- 2. 분할한 범위에 대헤 곱셈 연산수가 최대가 되는 값을 구한다.
//- 3. 범위를 점차 넓혀가며 최종적인 결과를 얻는다.
//- 3.1. 2.에서 구한 작음 범위의 값을 이용해 큰 범위의 값을 구할 수 있다.
//- 3.2. (점화식)minSum[i][j] = minSum[i][k] + minSum[k + 1][j] + matrix[i] X matrix[j](X는 행렬곱)
//- 풀이는 다음과 같다.
//- 1. 풀이에 필요한 변수를 세팅한다.
//- 1.1. vector<> matrix : 행렬의 순서와 크기가 저장된 배열
//- 1.2. dp[i][j] : i번째 행렬부터 j번째 행렬 까지의 최소 곱셈 연산수 
//- 2. i와 j를 이동시킨다. 
//- 2.1. k를 i ~ j 범위에서 이동시키며 다음을 수행한다.
//- 2.1.1. 분할 범위 좌우의 dp[][]값을 이용해 최소가 되는 최소 곱셈 연산수를 구한다. (점화식 사용)
//- 3. 행렬의 모든 범위에 해당하는 dp[0][N-1]의 값을 출력한다.


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define NUM_MAX 2147483647
#define MAP_MAX 500 + 1

vector<pair<int, int>> matrix;
int dp[MAP_MAX][MAP_MAX];

void init() {
	int N;
	cin >> N;

	int r, c;
	for (int n = 0; n < N; n++) {
		cin >> r >> c;
		matrix.push_back(make_pair(r, c));
	}
}

void divide() {
	for (int i = matrix.size() - 1; i >= 0; i--) {
		for (int j = i + 1; j < matrix.size(); j++) {
			dp[i][j] = NUM_MAX;
			for (int k = i; k <= j; k++) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + matrix[i].first * matrix[k].second * matrix[j].second);
			}
		}
	}
}

void solve() {
	init();
	divide();
	cout << dp[0][matrix.size() - 1] << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}