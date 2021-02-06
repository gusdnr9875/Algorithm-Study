//문제: 아기상어 (골드4)
//알고리즘: bfs(최단거리)
//https://na982.tistory.com/101 
//다시풀기-> 실패

#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;

struct Shark {
	int x, y, time;
};
Shark shark;
int n;
int map[21][21];
int dir[4][2] = { {0,-1},{0,1},{-1,0},{1,0} };
int sharkSize;
int sharkAte;


bool isInside(int a, int b) {
	return (a >= 0 && a < n) && (b >= 0 && b < n);
}
void bfs() {
	bool isupdate = true;
	//상어가 물고기를먹었다면 while문 반복
	while (isupdate) {
		isupdate = false; //상어가 먹이를 먹었는지 확인하는 변수		
		bool visited[21][21] = { false, }; //상어의 방문여부 초기화
		queue <Shark> q; //최단거리를 탐색하기위한 큐
		visited[shark.x][shark.y] = true;
		q.push(shark); //현재 상어의 위치를 push



		//최단거리를 구하기위한 구조체 초기화(최솟값 비교를위함)
		Shark candi;
		candi.x = 20;
		candi.time = -1;

		//탐색
		while (!q.empty()) {
			Shark cur = q.front();
			q.pop();
			//최단거리를위한 최솟값비교
			if (candi.time != -1 && candi.time < cur.time)
				break;

			//현재좌표가 물고기가있고, 물고기가 상어크기보다 작다면
			if (map[cur.x][cur.y] < sharkSize && map[cur.x][cur.y] != 0) {
				//먹이를먹는다.
				isupdate = true;
				//가장위쪽이나, 위쪽중에서도 왼쪽일때, 갱신(문제의 조건)
				if (candi.x > cur.x || (candi.x == cur.x && candi.y > cur.y))
					candi = cur;
			}


			for (int i = 0; i < 4; i++) {
				Shark next;
				next.x = cur.x + dir[i][0];
				next.y = cur.y + dir[i][1];
				next.time = cur.time + 1;
				//상어 이동
				if (!isInside(next.x, next.y)) continue;
				if (!visited[next.x][next.y] && map[next.x][next.y] <= sharkSize) {
					visited[next.x][next.y] = true;
					q.push(next);
				}

			}
		}

		//탐색이 끝나고
		//먹이를 먹었다면
		if (isupdate) {
			shark = candi;
			sharkAte++;
			//상어의크기만큼 물고기를먹었다면 상어의 크기증가
			if (sharkAte == sharkSize) {
				sharkSize++;
				sharkAte = 0;
			}
			//먹이를먹었으니 0으로 초기화
			map[shark.x][shark.y] = 0;
		}
	}
}


int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				shark.x = i, shark.y = j, shark.time = 0;
				sharkSize = 2, sharkAte = 0;
				map[i][j] = 0;
			}
		}
	}
	bfs();
	cout << shark.time;
}