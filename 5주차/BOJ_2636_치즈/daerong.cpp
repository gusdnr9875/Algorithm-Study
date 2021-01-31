//Solution
//- 사이의 빈공간 처리를 제외하면 BFS문제와 같다.
//- 이론적 접근은 다음과 같다.
//- 1. (0, 0)을 시작으로 bfs를 수행한다.
//- 1.1. 0을 만나면 queue에 넣고 확장한다.
//- 1.2. 1을 만나면 0으로 바꾼다.
//- 2. 총 1의 갯수를 관리하며 종료되는 시점을 관리한다.
//- 3. before에 이전 갯수를 저장한다.
//- 4. bfs 수행횟수를 t에 저장한다.
//- 5. before과 t를 출력한다.
//- 풀이는 다음과 같다.
//- 1. 풀이에 필요한 변수를 선언한다.
//- 1.1. map : 주어진 맵정보를 담을 배열
//- 1.2. v : 모든 요소가 false인 배열. 이후 visited 배열의 초기값으로 사용한다.
//- 1.2.1. visited : bfs() 함수에서 방문 체크
//- 1.4. num : 초기 map의 1의 갯수. 즉, 치즈의 갯수
//- 2. t를 1씩 증가시키며 다음을 수행한다.
//- 2.1. before에 num을 저장한다.
//- 2.2. bfs()를 수행한다.
//- 2.2.1. (0, 0)을 queue에 넣는다.
//- 2.2.2. queue에서 하나를 빼낸다.
//- 2.2.3. 방문했으면 2.2.2.로 돌아한다.
//- 2.2.4. 방문하지 않았으면, 방문체크를 한다.
//- 2.2.5. map[y][x]가 1이면 다음을 수행한다.
//- 2.2.5.1. map[y][x]를 0으로 바꾼다.
//- 2.2.5.2. num을 1감소시킨다.
//- 2.2.6. map[y][x]가 0이면 상하좌우 4방향을 queue에 추가한다.
//- 3. before과 t를 출력한다.

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct NODE {
	int x;
	int y;
} NODE;

int Y;
int X;
vector<vector<bool>> map;
vector<vector<bool>> v;
int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };
int num;

void init() {
	cin >> Y >> X;
	int temp;
	vector<bool> vec(X, false);
	for (int y = 0; y < Y; y++) {
		vector<bool> line;
		for (int x = 0; x < X; x++) {
			cin >> temp;
			line.push_back(temp);
			if (temp == 1) num++;
		}
		map.push_back(line);
		v.push_back(vec);
	}
}

void bfs(vector<vector<bool>> visited) {
	queue<NODE> q;
	q.push({ 0, 0 });
	while (!q.empty()) {
		NODE temp = q.front();
		q.pop();
		if (visited[temp.y][temp.x]) continue;
		visited[temp.y][temp.x] = true;
		if (map[temp.y][temp.x]) {
			map[temp.y][temp.x] = false;
			num--;
			continue;
		}

		for (int dir = 0; dir < 4; dir++) {
			int nx = temp.x + dx[dir];
			int ny = temp.y + dy[dir];
			if (nx < 0 || nx >= X || ny < 0 || ny >= Y) continue;
			q.push({ nx, ny });
		}
	}
}

void solution() {
	init();
	int before;
	int t = 0;
	while (num != 0) {
		t++;
		before = num;
		bfs(v);
	}
	cout << t << endl;
	cout << before << endl;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}