//Solution
//- 출발지에서 도착지로 승객들을 옮기는 시뮬레이션 문제.
//- Failed 1 : 출발지를 기준으로 승객 순서를 정렬해야하는데 도착지를 기준으로 정렬해버림.
//- 풀이는 다음과 같다.
//- 1. 주어진 정보로 문제에 필요한 값들을 세팅한다.
//- 1.1. N : N x N의 맵 크기
//- 1.2. M : 승객의 수
//- 1.3. E : (초기)연료량
//- 1.4. tx : 택시의 초기 위치
//- 1.5. ty : 택시의 초기 위치
//- 1.6. map : 맵 정보, N * N 크기의 배열. (1은 벽, 0은 길)
//- 1.7. visited : 모든 성분이 false인 N * N 크기의 배열
//- 1.8. man : 승객의 출발지-도착지 정보를 담은 벡터
//- 2. man의 모든 성분에 대해 다음을 반복한다.
//- 2.1. tx, ty와 승객 출발지 사이의 거리 get_dist() 값이 최소가 되는 승객을 찾는다.
//- 2.1.1. get_dist()함수는 bfs로 최단거리를 찾는다.
//- 2.1.2. 단, get_dist()의 값이 -1인 경우, 이동할 수 없는 위치에 승객이 있으므로 -1을 출력한다.
//- 2.2. tx, ty를 2.1.에서 찾은 승객의 출발지로 이동시킨다.
//- 2.2.1. E를 이동 칸 만큼 감소시킨다.
//- 2.2.2. E가 0보다 작은 경우 -1을 출력한다.
//- 2.3. tx, ty를 2.1.에서 찾은 승객의 도착지로 이동시킨다.
//- 2.3.1. tx, ty의 위치에서 2.1.에서 찾은 승객의 도착지까지의 거리를 구한다.
//- 2.3.2. E를 2.3.1.에서 구한 거리만큼 감소시킨다.
//- 2.3.3. E가 0보다 작은 경우 -1을 출력한다.
//- 2.4. man 벡터에서 이동시킨 승객을 제거한다.
//- 2.5. man 벡터가 빈 배열인 경우 남은 E를 출력한다.
//- 2.6. man 벡터가 비어있지 않은경우 2.로 돌아가 반복한다.

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define N_MAX 21
#define DIST_MAX 2000000000

typedef struct MAN {
	int sx;
	int sy;
	int ex;
	int ey;
} MAN;

typedef struct DIST {
	int x;
	int y;
	int cnt;
} DIST;

bool compare(MAN a, MAN b) {
	if (a.sy == b.sy) return a.sx < b.sx;
	else return a.sy < b.sy;
}

int dx[] = { 0, -1, 0, 1 };
int dy[] = { -1, 0, 1, 0 };
int N;
int M;
int E;		// 연료
vector<vector<int>> map;
vector<vector<bool>> visited;
int tx;
int ty;
vector<MAN> man;

void init() {
	cin >> N >> M >> E;
	int temp;
	for (int y = 0; y < N; y++) {
		vector<int> int_line;
		vector<bool> bool_line;
		for (int x = 0; x < N; x++) {
			cin >> temp;
			int_line.push_back(temp);
			bool_line.push_back(false);
		}
		map.push_back(int_line);
		visited.push_back(bool_line);
	}
	cin >> ty >> tx;
	tx -= 1;
	ty -= 1;
	int sx, sy, ex, ey;
	for (int i = 0; i < M; i++) {
		cin >> sy >> sx >> ey >> ex;
		man.push_back({ sx - 1, sy - 1, ex - 1, ey - 1 });
	}
	sort(man.begin(), man.end(), compare);
}

int get_dist(int x, int y, vector<vector<bool>> cp) {
	queue<DIST> q;
	q.push({ tx, ty, 0 });
	while (!q.empty()) {
		DIST temp = q.front();
		q.pop();
		if (cp[temp.y][temp.x]) continue;
		if (temp.x == x && temp.y == y) return temp.cnt;
		cp[temp.y][temp.x] = true;
		if (map[temp.y][temp.x] == 1) continue;
		for (int dir = 0; dir < 4; dir++) {
			int nx = temp.x + dx[dir];
			int ny = temp.y + dy[dir];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			q.push({ nx, ny, temp.cnt + 1 });
		}
	}

	return -1;
}

int solution() {
	while (!man.empty()) {
		vector<MAN>::iterator target;
		int min_dist = DIST_MAX;
		for (vector<MAN>::iterator iter = man.begin(); iter < man.end(); iter++) {
			int dist = get_dist(iter->sx, iter->sy, visited);
			if (dist == -1) return -1;
			if (dist < min_dist) {
				target = iter;
				min_dist = dist;
			}
		}

		if (E < min_dist) return -1;
		E -= min_dist;
		tx = target->sx;
		ty = target->sy;

		min_dist = get_dist(target->ex, target->ey, visited);
		if (min_dist == -1) return -1;

		if (E < min_dist) return -1;
		else {
			E += min_dist;
			tx = target->ex;
			ty = target->ey;
		}

		man.erase(target);
	}

	return E;
}

void solve() {
	init();
	int answer = solution();
	cout << answer << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}