//Solution
//- (0, 0)에서 (N, M)까지 낮은 숫자로만 이동하는 경로의 수를 구하는 문제
//- DFS, DP
//- 기본적인 이론은 다음과 같다.
//- 1. (X, Y)로 이동가능한 모든 경로의 합이 (X, Y)에 도착가능한 이동경로이다.
//- 2. 따라서 (N, M)을 시작으로 재귀함수를 구현하면 모든 패스에 대한 이동경로 합을 알 수 있다.
//- 3. 이 과정에서 기존에 구한 이동경로 합을 DP로 저장하는 경우 연산을 줄일 수 있다.
//- Failed 1 : dp배열을 0으로 초기화하여 시간초과가 발생.
//- 1. 기존 0을 집어넣는 방식의 경우,
//- 2. 이동 가능한 경로가 0이 될 수 있으므로
//- 3. dp[][]값이 0인 경우에 move()를 계속 수행한다.
//- 4. 이를 해결하기 위해 초기 dp[][]배열을 -1로 초기화한다.
//- 풀이 과정은 다음과 같다.
//- 1. 풀이를 위한 변수를 세팅한다.
//- 1.1. 상하좌우 4방향 연산을 위한 dx[], dy[] 배열
//- 1.2. 높이가 저장될 map[][] 배열
//- 1.3. 이동 경로 수를 저장할 dp[][] 배열
//- 2. move(x, y) 함수에 (N, M)을 넣어 경로 합을 구한다.
//- 2.1. (x, y)에 대한 경로 합 dp[y][x]가 존재할 경우 dp[y][x]를 리턴한다.
//- 2.2. 존재하지 않을 경우, 상하좌우 4방향에 대해 다음을 수행한다.
//- 2.2.1. 영역을 벗어나는 경우, 무시한다.
//- 2.2.2. 현재 영역보다 작거나 같은 경우, 이동불가능한 경로이므로 무시한다.
//- 2.2.3. 그 외의 경우 move(nx, ny)를 pathSum에 더한다.
//- 2.3. dp[y][x]에 pathSum을 저장하고 리턴한다.
//- 3. dp[M][N]의 값을 출력한다.


#include <iostream>

using namespace std;

#define MAP_MAX 501

int Y;		// M
int X;		// N
int map[MAP_MAX][MAP_MAX];
int dp[MAP_MAX][MAP_MAX];
int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };

void init() {
	cin >> Y >> X;
	for (int y = 1; y <= Y; y++) {
		for (int x = 1; x <= X; x++) {
			cin >> map[y][x];
			dp[y][x] = -1;
		}
	}

	dp[1][1] = 1;
}

int move(int x, int y) {
	if (dp[y][x] != -1) return dp[y][x];
	int pathSum = 0;
	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx <= 0 || nx > X || ny <= 0 || ny > Y) continue;
		if (map[y][x] >= map[ny][nx]) continue;
		pathSum += move(nx, ny);
	}

	return dp[y][x] = pathSum;
}

//void print_map() {
//	for (int y = 1; y <= Y; y++) {
//		for (int x = 1; x <= X; x++) {
//			cout << dp[y][x] << " ";
//		}
//		cout << endl;
//	}
//}

void solution() {
	init();
	move(X, Y);
	//print_map();
	cout << dp[Y][X] << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}