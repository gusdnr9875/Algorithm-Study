//문제: 진우의 민트초코 우유
//알고리즘: 순열
//푼날짜: 2021-01-20
//
//풀이 1. 순열
//풀이 2. 백트래킹
//풀이 3. dfs백트래킹(실패)

//순열에대해서 공부할수있는 좋은기회의 문제였다.
//DFS로 4방향탐색과 백트래킹으로 집에서 하나하나 이동하면서 민트초코우유를찾았는데 시간초과가발생했다.
//1. 민트초코우유를 기준으로 순열로 모든경우의수를 구하고
//2. 조건을 만족하면서 가장 많이먹을수있는 민트초코 우유를 구한다.


//풀이1 .순열
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n, m, h; //마을크기, 진우의초기체력, 증가하는체력양
int home_x, home_y;
int cur_x, cur_y;
int ans; //먹은 민트초코의 최대개수
vector<pair<int, int>> milk;
//현재 위치에서 집까지 가는 거리구하기
int dstHome(int x, int y) {
	return abs(x - home_x) + abs(y - home_y);
}
//현재 위치에서 민트초코 우유까지 가는 거리 구하기
int dstMilk(int x, int y, int milk_x, int milk_y) {
	return abs(x - milk_x) + abs(y - milk_y);
}



int main() {
	cin >> n >> m >> h;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			int t; cin >> t;
			if (t == 1) home_x = i, home_y = j;
			else if (t == 2) milk.push_back({ i,j });
		}

	sort(milk.begin(), milk.end());

	do {
		//초깃값
		int hp = m;
		int now_x = home_x;
		int now_y = home_y;

		//민트초코우유 탐색
		for (int i = 0; i < milk.size(); i++) {
			int nowDistacne = dstMilk(now_x, now_y, milk[i].first, milk[i].second);

			//현재위치 갱신(민트초코를 먹은위치)
			now_x = milk[i].first;
			now_y = milk[i].second;
			int toHomeDistance = dstHome(now_x, now_y);

			//현재 체력보다 다음민트초코까지 가야할거리가 더큰경우
			if (hp < nowDistacne) break;
			//현재 민트초코만큼의거리를 걷고, 민트초코를 먹고 회복한 체력으로
			//집까지 갈수있을 체력이있다면
			if (hp - nowDistacne + h >= toHomeDistance) ans = max(ans, i + 1);

			//hp 민트초코거리만큼 소모, 민트초코먹고 회복
			hp -= nowDistacne; hp += h;


		}

		//순열로 모든 경우의수 갱신
	} while (next_permutation(milk.begin(), milk.end()));


	cout << ans;
}




//풀이2. 백트래킹
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef struct MyStruct
{
	int y;
	int x;
}val;

bool visited[10];
int n = 0, m = 0, h = 0;
int result = 0;
int arr[10][10] = { 0, };
val house;
vector <val> mint;

void dfs(int y, int x, int cnt, int hp) {
	if (cnt > result) {// 방문횟수가 더 많고
		//현재 위치에서 집으로 갈수있는 체력이있다면
		if (abs(y - house.y) + abs(x - house.x) <= hp)
			result = cnt;
	}
	//체력이 0아래로 떨어지면 종료
	if (hp <= 0)
		return;

	for (int i = 0; i < mint.size(); i++) {

		//현재위치에서 다음민트초코로 가는거리
		int dist = abs(mint[i].y - y) + abs(mint[i].x - x);

		//다음 민트초코로 갈수있는체력이있고, 이동할 민트초코 위치를 방문하지않았다면
		if (dist <= hp && !visited[i]) {
			visited[i] = true;
			dfs(mint[i].y, mint[i].x, cnt + 1, hp - dist + h);
			visited[i] = false;
		}

	}

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> h;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int temp = 0;
			cin >> temp;
			if (temp == 1)
				house.y = i, house.x = j;
			else if (temp == 2)
				mint.push_back({ i,j });
		}
	}

	dfs(house.y, house.x, 0, m);
	cout << result << endl;
	return 0;




//틀린코드(시간초과)
//dfs 백트래킹
#include<iostream>
#include<algorithm>
using namespace std;

int n, m, h; //마을크기, 진우의초기체력, 증가하는체력양
int map[11][11];
bool visited[11][11];
int start_x, start_y;
int ans; //먹은 민트초코의 최대개수
int dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1} }; //북동남서

bool isInside(int a, int b) {
	return (a >= 0 && a < n) && (b >= 0 && b < n);
}

bool isGoHome(int x, int y, int hp) {
	return abs(x - start_x) + abs(y - start_y) <= hp;
}
void DFS(int x, int y, int hp, int cnt) {
	if (isGoHome(x, y, hp)) {
		ans = max(ans, cnt);
	}
	else if (hp == 0) return;


	for (int i = 0; i < 4; i++) {
		int nx = x + dir[i][0];
		int ny = y + dir[i][1];
		if (!isInside(nx, ny)) continue;
		if (!visited[nx][ny]) {

			visited[nx][ny] = true;
			//민트초코가 있다면
			if (map[nx][ny] == 2) DFS(nx, ny, hp - 1 + h, cnt + 1);
			//민트초코가 없다면
			else if (map[nx][ny] == 0) DFS(nx, ny, hp - 1, cnt);
			visited[nx][ny] = false;


		}

	}
}

int main() {
	cin >> n >> m >> h;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1)
				start_x = i, start_y = j;
		}
	}
	visited[start_x][start_y] = true;
	DFS(start_x, start_y, m, 0);

	cout << ans;
}