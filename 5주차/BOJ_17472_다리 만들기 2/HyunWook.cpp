#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int arr[10][10];
int island[10][10];
int p[7];
vector<pair<int, pair<int, int>>> vt;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int getParent(int a) {
	if (p[a] == a) return a;
	return p[a] = getParent(p[a]);
}


void unionSet(int a, int b) {
	int rootA = getParent(a);
	int rootB = getParent(b);
	p[rootA] = rootB;
}


//u번 섬에서 v번 섬으로 가는 직선 최단 거리를 구한다.
void makebridge(int u, int v) {
	queue < pair<int, int>> q;

	//u번 섬에 있는 칸들을 모두 큐에 넣는다.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (island[i][j] == u) {
				q.push(make_pair(i, j));
			}
		}
	}

	int mindist = 10;
	int x, y;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			int dist = 0;

			//한방향으로 계속 이동
			while (true) {
				//범위를 넘어간 경우
				if (nx < 0 || ny < 0 || nx >= n || ny >= m) break;
				//같은 섬인경우 더 탐색하지 않는다.
				if (island[nx][ny] == u) break;

				if (island[nx][ny] == v) {
					//v번섬인 경우 최소거리와 비교후 더 탐색하지 않는다.
					if (dist > 1 && mindist > dist) mindist = dist;
					break;
				}
				else if (island[nx][ny] == 0) {
					//바다인 경우 거리증가하고 이동
					dist++;
					nx += dx[k];
					ny += dy[k];
				}
				else {
					//다른 섬인 경우 더 탐색하지 않는다.
					break;
				}

			}
		}
	}

	//최소거리가 초기값이 아니라면 벡터에 최소거리와 섬의 번호를 넣는다.
	if (mindist != 10) vt.push_back(make_pair(mindist, make_pair(u, v)));
}


void bfs(int x, int y, int num) {
	queue<pair<int, int> > q;
	q.push(make_pair(x, y));
	island[x][y] = num;

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (arr[nx][ny] == 0) continue;
			if (island[nx][ny] != 0) continue;

			q.push(make_pair(nx, ny));
			island[nx][ny] = num;
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) 
			cin >> arr[i][j];
		

	//섬에 번호를 붙인다.
	int num = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			
			if (arr[i][j] == 0) continue;
			if (island[i][j] != 0) continue;
			bfs(i, j, ++num);
		}
	}


	//위에서 번호를 붙인 num이 섬의 개수
	//각 섬들간의 만들수 있는 다리를 모두 만든다.
	for (int i = 1; i <= num - 1; i++) {
		for (int j = i + 1; j <= num; j++) {
			makebridge(i, j);
		}
	}


	int size = vt.size();
	//거리를 기준으로 오름차순 정렬
	sort(vt.begin(), vt.end());
	//부모 배열 초기화(처음 부모는 자기 자신)
	for (int i = 1; i <= num; i++) p[i] = i;

	int sum = 0;
	int cnt = 0;
	int index = 0;

	int u, v, dist;
	//선택한 간선의 개수가 섬의개수 -1이 될때까지 간선을 선택한다.
	while (cnt < num - 1) {
		if (index == size) {
			//모든 섬을 연결하는 것이 불가능하다
			cout << -1 << "\n";
			return 0;
		}

		dist = vt[index].first;
		u = vt[index].second.first;
		v = vt[index].second.second;

		index++;
		if (getParent(u) == getParent(v)) {
			//이미 연결되어 있다.
			continue;
		}
		else {
			//연결되어 있지 않다면 합친다.
			unionSet(u, v);

			//연결된 간선의 수 증가
			cnt++;

			//다리 길이에 합쳐준다.
			sum += dist;
		}
	}

	cout << sum << '\n';

	return 0;
}
