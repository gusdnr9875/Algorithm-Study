//Solution
//- 맵의 특정 포인트를 지나가는 경로의 수를 구하는 문제.
//- 다음의 특이사항이 있다.
//- 1. 특정 방향으로만 이동 가능해서 쉽다.
//- 2. 아이템을 모두 먹을 수 없는 예외케이스(ex> 이동 거리가 같은 블럭)는 없다.
//- 이론은 다음과 같다.
//- 1. 경로는 이동거리가 짧은 순서로 아이템을 먹는 순서이다.
//- 1.1. 모든 아이템을 먹어야 하므로 위 조건이 무조건 성립한다.
//- 2. n = 0(출발지)를 제외한 모든 지점에 대해 경로의 합을 구한다.
//- 2.1. n번째 위치에 대해 경로의 합은 n-1번째 위치에서 출발한 경로의 합이다.
//- 3. 최종적으로 (X = M, Y = N)위치의 경로 수를 구하면 된다.
//- 4. 형태는 아이템 성분에 대해 교집합을 갖는 박스의 밴다이어그램이다.
//- 4.1. 범위를 벗어나는 영역에 대해 경로를 구하지 않아 효율적이다.
//풀이는 다음과 같다.
//- 1. 풀이에 필요한 변수를 세팅한다.
//- 1.1. dp[][] : -1로 초기화 된 2차원 배열, 벽의 경우에는 0이 저장된다.
//- 1.2. items : 이동해야할 위치들의 집합. 정렬이 핵심이다.
//- 1.2.1. 출발 위치 (1 ,1) 저장.
//- 1.2.2. 각 아이템의 위치를 저장한 vector.
//- 1.2.3. 도착 위치 (X, Y) 저장
//- 1.2.4. 이동거리 x + y의 오름차순으로 정렬.
//- 2. 출발지(n = 0)를 제외한 모든 items 성분에 대해 expand() 함수를 수행한다.
//- 2.1. dp[y][x]가 -1이 아닌 경우에는 dp[y][x]를 즉시 리턴한다.
//- 2.1.1. 벽의 경우, 0이다. 이동이 불가하므로 그대로 리턴.
//- 2.1.2. 그 외의 경우, 이미 계산된 dp[][] 값이므로 그대로 사용한다.
//- 2.2. n-1번째 성분의 x, y와 n번째 성분의 x, y 범위를 넘어선 값은 0을 리턴한다.
//- 2.2.1. 범위를 벗어난 경로는 존재할 수 없다.
//- 2.3. dp[y][x] = dp[y-1][x] + dp[y][x-1]으로 값을 업데이트한다.
//- 2.3.1. 이는 expand()함수의 재귀로 구현했다.
//- 3. dp[Y][X]의 값을 리턴하여 답을 구한다.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAP_MAX 100 + 1

typedef struct LOCATE {
	int x;
	int y;
} LOCATE;
bool compare(LOCATE a, LOCATE b) {
	return a.x + a.y < b.x + b.y;
}

int Y;		// M
int X;		// N
int dp[MAP_MAX][MAP_MAX];		// wall : 0, defalut : -1
vector<LOCATE> items;

void init() {
	int A, B;
	cin >> Y >> X >> A >> B;

	for (int y = 1; y <= Y; y++) {
		for (int x = 1; x <= X; x++) {
			dp[y][x] = -1;
		}
	}

	int x = 1, y = 1;
	items.push_back({ x, y });
	for (int i = 1; i <= A; i++) {
		cin >> y >> x;
		items.push_back({ x, y });
	}
	items.push_back({ X, Y });
	sort(items.begin(), items.end(), compare);

	for (int i = 1; i <= B; i++) {
		cin >> y >> x;
		dp[y][x] = 0;
	}
	dp[1][1] = 1;
}

int expand(int x, int y, int end_x, int end_y) {
	if (dp[y][x] != -1) return dp[y][x];
	if (x < end_x || y < end_y) return 0;
	return dp[y][x] = expand(x - 1, y, end_x, end_y) + expand(x, y - 1, end_x, end_y);
}

void solution() {
	init();

	for (int i = 1; i < items.size(); i++) {
		expand(items[i].x, items[i].y, items[i - 1].x, items[i - 1].y);
	}

	cout << dp[Y][X] << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}