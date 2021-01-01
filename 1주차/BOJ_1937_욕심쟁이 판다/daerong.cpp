//Solution
//- 맵에서 크기가 큰 쪽으로만 이동할 때, 최대 이동칸 수를 구하는 문제
//- DP
//- 이론적 접근은 다음과 같다.
//- 1. 주변 셀의 값이 큰 경우에만 이동하므로 단방향으로만 패스가 그려진다.
//- 2. 임의의 셀에서 이동할 수 있는 최대 이동 칸수는 인근 셀의 최대 이동칸 수 + 1이다.
//- 3. 패스는 모든 셀로 연장되지 않으므로 모든 셀에 대해 확인한다.
//- 풀이는 다음과 같다.
//- 1. 필요한 변수를 세팅한다.
//- 1.1. map[][] : 주어진 맵 정보, 대나무의 수
//- 1.2. dp[][] : 이동가능한 최대 이동칸 수
//- 1.2.1. dp[][]는 -1로 초기화 한다.
//- 1.3. answer : map의 모든 공간에 대한 최대 이동칸 수
//- 1.4. dx[], dy[] : 상하좌우 이동을 위한 변수
//- 2. move()함수로 모든 셀에 대해 최대 이동칸 수를 구한다.
//- 2.1. dp[][]가 -1이 아닌 경우, dp[][] 값을 리턴한다.
//- 2.2. 상하좌우 4방향에 대해 다음을 수행한다.
//- 2.2.1. 맵을 벗어나면 해당 방향을 무시한다.
//- 2.2.2. 현재 셀보다 작거나 같은 경우, 해당 방향을 무시한다.
//- 2.2.3. 그 외의 경우, 해당 방향에 대한 move()를 구한다. (재귀사용)
//- 2.2.4. maxPath와 비교하여 4방향에 대한 최대값 maxPath에 저장한다.
//- 2.3. dp[y][x]을 2.2.3.에서 구한 maxPath에 1을 더한 maxPath + 1로 수정한다.
//- 2.4. dp[y][x]가 answer보다 큰 경우 answer을 수정한다.
//- 3. answer 값을 출력한다.


#include <iostream>
#include <algorithm>

using namespace std;

#define MAP_MAX 501

int N;
int map[MAP_MAX][MAP_MAX];
int dp[MAP_MAX][MAP_MAX];
int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };
int answer;

void init() {
	cin >> N;
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			cin >> map[y][x];
			dp[y][x] = -1;
		}
	}
}

int move(int x, int y) {
	if (dp[y][x] != -1) return dp[y][x];
	int maxPath = 0;
	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx <= 0 || nx > N || ny <= 0 || ny > N) continue;
		if (map[ny][nx] <= map[y][x]) continue;
		maxPath = max(maxPath, move(nx, ny));
	}

	dp[y][x] = maxPath + 1;
	answer = max(answer, dp[y][x]);

	return dp[y][x];
}

void solution() {
	init();
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			move(x, y);
		}
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