//Solution
//- (0, 0)에서 (M, N)까지 최단 경로의 갯수를 구하는 문제
//- 전형적인 DP문제
//- 이론적 접근은 다음과 같다.
//- 1. (x, y)점에서 이동가능한 경로정보는 (x-1, y) + (x, y+1)이다.
//- 2. 영역을 벗어나는 위치에서 들어오는 경로는 0개이다.
//- 3. wall로 연결된 영역에서 오는 경로는 0개이다.
//- 4. 위 과정을 반복했을 때, dp[M][N]의 값이 모든 이동경로의 합이다.
//- Failed 1 : dp[][]를 int형으로 선언.
//- 1. 범위 초과
//- 2. long long으로 교체
//- Failed 2 : (a, b), (c, d) 통과 불가하게 풀이
//- 1. 점의 이동에는 제한이 없고 선만 이동불가.
//- 1.1. 항상 점에 대한 처리에 문제가 생기는 것 같다. 조심하기
//- 2. 방향에 대한 이동불가를 처리하여 해결
//- 2.1. (x, y)에서 x-1와 y-1에 대한 각각의 이동 불가여부를 저장했다.
//- 2.2. 이 문제에서는 특정 방향으로만 이동하므로 2가지 방향에 대해서만 고려했다.
//- 풀이과정은 다음과 같다.
//- 1. 풀이에 필요한 변수를 세팅한다.
//- 1.1. dp[y][x] : (0, 0)에서 (x, y) 위치로의 최단 이동경로 수.
//- 1.2. x_wall[y][x] : (x, y)에서 (x-1, y)로의 이동이 불가능한 경우 true
//- 1.3. y_wall[y][x] : (x, y)에서 (x, y-1)로의 이동이 불가능한 경우 true
//- 2. (X, Y)를 시작으로 expand()를 수행하여 dp[][]를 채운다.
//- 2.1. 맵에서 벗어난 경우(x<0 또는 y<0) 0을 return한다.
//- 2.2. dp[][]의 초기값 -1이 아닌 경우, 해당 dp[][] 값을 return한다.
//- 2.3. dp[][] 값을 업데이트한다.
//- 2.3.1. 인접한 경로에 wall이 없는 경우, dp[y][x] = expand(x - 1, y) + expand(x, y - 1)이다.
//- 2.3.2. y방향에 wall이 있는 경우, dp[y][x] = expand(x - 1, y)
//- 2.3.3. x방향에 wall이 있는 경우, dp[y][x] = expand(x, y - 1)
//- 2.3.4. 양방향에 wall이 있는 경우, dp[y][x] = 0
//- 3. 업데이트가 완료된 dp[][]값을 return한다.
//- 4. dp[Y][X]의 값을 출력한다.

#include <iostream>
#include <algorithm>

using namespace std;

#define MAP_MAX 100

int X;
int Y;
long long dp[MAP_MAX + 1][MAP_MAX + 1];
long long x_wall[MAP_MAX + 1][MAP_MAX + 1];
long long y_wall[MAP_MAX + 1][MAP_MAX + 1];

void init() {
	cin >> X >> Y;
	for (int y = 0; y <= Y; y++) {
		for (int x = 0; x <= X; x++) {
			dp[y][x] = -1;
			x_wall[y][x] = false;
			y_wall[y][x] = false;
		}
	}

	int K;
	cin >> K;
	int x1, y1, x2, y2;
	for (int k = 0; k < K; k++) {
		cin >> x1 >> y1 >> x2 >> y2;
		int x = max(x1, x2);
		int y = max(y1, y2);
		if (x1 == x2) y_wall[y][x] = true;
		if (y1 == y2) x_wall[y][x] = true;
	}

	dp[0][0] = 1;
}

long long expand(int x, int y) {
	if (x < 0 || y < 0) return 0;
	if (dp[y][x] != -1) return dp[y][x];

	long long path_cnt = 0;
	if (y_wall[y][x] == false) path_cnt += expand(x, y - 1);
	if (x_wall[y][x] == false) path_cnt += expand(x - 1, y);

	return dp[y][x] = path_cnt;
}

void solution() {
	init();
	cout << expand(X, Y) << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}