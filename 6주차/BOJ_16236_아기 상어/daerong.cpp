//Solution
//- 조건에 부합하는 가장 가까운 블럭을 찾아 이동하는 문제.
//- 해당 블럭의 조건은 다음과 같다. 
//- 1. baby_size보다 작다.
//- 2. 이동 거리 cnt 값이 최소
//- 3. cnt가 같은 경우, y값이 더 작은 값.
//- 4. y도 같은 경우, x값이 더 작은 값.
//- 이동 시에 지나갈 수 없는 블럭의 조건은 다음과 같다.
//- 1. baby_size보다 크다.
//- 위의 조건에 따라 bfs로 순회하며 이동이 종료되는 시점의 이동거리를 구한다.
//- 풀이과정은 다음과 같다.
//- 1. 주어진 값을 받아 map[y][x]을 세팅한다.
//- 2. fish.cnt 값을 999로 설정한다.		(이동할 블럭이 없는 경우, 999가 유지된다.)
//- 3. visited[y][x]를 false로 초기화한다. (distance_update()내의 bfs에서 재방문을 막는데 사용)
//- 4. distance_update(x, y, cnt)를 실행한다.
//- 4.1. 현재 상어의 위치{baby_x, baby_y}와 이동거리 0을 queue에 넣는다.
//- 4.2. 4.1을 시작으로 queue를 반복하며 bfs를 수행한다.
//- 4.3. queue의 front를 가져온다.
//- 4.4. 방문 여부에 따라 다음을 실행한다.
//- 4.4.1. 방문한 경우, 수행을 종료한다.
//- 4.4.2. 방문하지 않은 경우, visited[y][x]에 방문을 체크한다.
//- 4.5. map[y][x]가 0이 아니면서 baby_size보다 작으면 다음을 실행하며 fish를 업데이트 (FISH 구조체)
//- 4.5.1. 현재 이동거리를 확인하여 다음을 수행한다.
//- 4.5.1.1. fish.cnt보다 작은 경우, fish{x, y, cnt}를 업데이트 한다.
//- 4.5.1.2. fish.cnt와 같은 경우, y의 값에 따라 다음을 수행한다.
//- 4.5.1.2.1. fish.y보다 작은 경우, fish{ x, y, cnt }를 업데이트 한다.
//- 4.5.1.2.2. fish.y와 같은 경우, x의 값에 따라 다음을 수행한다.
//- 4.5.1.2.2.1. fish.x보다 작은 경우, fish{ x, y, cnt }를 업데이트 한다.
//- 4.6. 주변 네 방향에 대해 다음을 수행한다.
//- 4.6.1. map[y][x]의 범위를 벗어난 경우, 이후 과정을 생략한다.
//- 4.6.2. map[y][x]의 값이 baby_size보다 작거나 같은 경우 queue에 추가한다.
//- 4.6.3. 4.3으로 돌아가 반복 수행한다.
//- 5. fish.cnt 값에 따라 다음을 수행한다.
//- 5.1. fish.cnt == 999인 경우, 수행을 종료하고 총 이동거리 answer를 return한다.
//- 5.2. answer에 fish.cnt를 더하고{ baby_x, baby_y }를 fish의 위치로 이동한다.
//- 5.3. { baby_x, baby_y } 위치의 map[y][x]에 0을 넣는다.
//- 5.4. 2.로 돌아가 반복한다.



#include <iostream>
#include <queue>

using namespace std;

#define N_MAX 20

typedef struct FISH {
	int x;
	int y;
	int cnt;
} NEXT;

int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };

int answer = 0;
int N;
int map[N_MAX][N_MAX];
bool visited[N_MAX][N_MAX];
queue<FISH> q;
FISH fish;

int baby_x;
int baby_y;
int baby_size = 2;
int eat_cnt = 0;

void distance_update(int x, int y, int cnt) {
	q.push({ x, y, cnt });
	while (!q.empty()) {
		FISH temp = q.front();
		q.pop();

		if (visited[temp.y][temp.x]) continue;
		visited[temp.y][temp.x] = true;

		if (map[temp.y][temp.x] != 0 && map[temp.y][temp.x] < baby_size) {
			if (temp.cnt < fish.cnt) {
				fish.x = temp.x;
				fish.y = temp.y;
				fish.cnt = temp.cnt;
			}
			else if (temp.cnt == fish.cnt) {
				if (temp.y < fish.y) {
					fish.x = temp.x;
					fish.y = temp.y;
				}
				else if (temp.y == fish.y) {
					if (temp.x < fish.x) {
						fish.x = temp.x;
						fish.y = temp.y;
					}
				}
			}
		}

		for (int dir = 0; dir < 4; dir++) {
			int nx = temp.x + dx[dir];
			int ny = temp.y + dy[dir];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			if (map[ny][nx] > baby_size) continue;
			q.push({ nx, ny, temp.cnt + 1 });
		}
	}
}

void solution() {
	fish.cnt = 999;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			visited[y][x] = false;
		}
	}
	distance_update(baby_x, baby_y, 0);

	while (fish.cnt != 999) {
		answer += fish.cnt;
		baby_x = fish.x;
		baby_y = fish.y;
		map[baby_y][baby_x] = 0;
		eat_cnt++;
		if (baby_size == eat_cnt) {
			baby_size++;
			eat_cnt = 0;
		}

		fish.cnt = 999;
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				visited[y][x] = false;
			}
		}
		distance_update(baby_x, baby_y, 0);
	}

	cout << answer << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];
			if (map[y][x] == 9) {
				baby_x = x;
				baby_y = y;
				map[y][x] = 0;
			}
		}
	}

	solution();

	return 0;
}