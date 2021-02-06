//문제: 스타트 택시
//알고리즘: 최단거리
//푼날짜 : 2021-02-01

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
#include<map>
#define MAX 20
using namespace std;

struct POINT {
	int x, y;
};
struct STATE {
	int x, y, gas;
};
bool operator<(STATE a, STATE b) {
	if (a.gas == b.gas) {
		if (a.x == b.x) {			
			return a.y > b.y;			
		}		
			return a.x > b.x;	
	}
	return a.gas < b.gas;
}
int n, m, gas;
int road[21][21];
map<pair<int, int>, pair<int, int>> start2Dest; //키: 출발 좌표, 값: 목적지 좌표
int dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };


bool isInside(int a, int b) {
	return (a >= 0 && a < n) && (b >= 0 && b < n);
}
bool func(pair<int,int> start) {
	pair<int, int> destination = start2Dest[start];
	queue<pair<STATE, int>>q;
	q.push({{ start.first,start.second,gas }, 0});

	bool visited[MAX][MAX] = { false, };
	visited[start.first][start.second] = true;

	while (!q.empty()) {
		int x = q.front().first.x;
		int y = q.front().first.y;
		int curGas = q.front().first.gas;
		int cnt = q.front().second;
		q.pop();

		if (curGas == -1) return false;
		if (x == destination.first && y == destination.second) {
			gas = curGas + cnt * 2;
			return true;
		}

		for (int d = 0; d < 4; d++) {
			int nx = x + dir[d][0];
			int ny = y + dir[d][1];
			if(!isInside(nx, ny)) continue;
			if (visited[nx][ny] || road[nx][ny]) continue;
			visited[nx][ny] = true;
			q.push({ { nx,ny,curGas - 1 }, cnt + 1 });
		}

	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m >> gas;

	//맵정보 입력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> road[i][j];
		}
	}
	pair<int, int>start;
	cin >> start.first >> start.second;
	start.first--, start.second--;

	for (int i = 0; i < m; i++) {
		int x, y, x2, y2;
		cin >> x >> y >> x2 >> y2;

		start2Dest[{x - 1, y - 1}] = { x2 - 1,y2 - 1 };
	}

	while (1) {

		priority_queue<STATE>pq;
		pq.push({ start.first,start.second,gas });

		bool visited[MAX][MAX] = { false, };
		visited[start.first][start.second] = true;

		bool flag = false;

		while (!pq.empty()) {
			int x = pq.top().x;
			int y = pq.top().y;
			int curGas = pq.top().gas;
			pq.pop();

			if (curGas == -1) {
				break;
			}

			//최단거리의 손님을 만났다면
			if (start2Dest.count({ x,y }) && start2Dest[{x, y}].first != -1) {
				start = { x,y };
				flag = true;
				gas = curGas;
				break;
			}

			for (int d = 0; d < 4; d++) {
				int nx = x + dir[d][0];
				int ny = y + dir[d][1];

				if (!isInside(nx, ny)) continue;
				if (visited[nx][ny] || road[nx][ny]) continue;
				visited[nx][ny] = true;
				pq.push({ nx,ny,curGas - 1 });
			}
		}

		//최단거리를 가지는 손님이 없었다면
		if (flag == false) {
			cout << -1 << "\n";
			return 0;
		}

		//목적지를 가다가 연료가 떨어졌다면
		if (func(start) == false) {
			cout << -1 << "\n";
			return 0;
		}

		if (--m==0) {
			cout << gas << "\n";
			return 0;
		}

		pair<int, int>temp = start;
		//손님을 목적지로 이동하게한 좌표가 현재 택시 좌표임
		start = start2Dest[{start.first, start.second}];
		//손님을 태운 목적지는 -1로 지정
		start2Dest[{temp.first, temp.second}] = { -1,-1 };

	}



}

