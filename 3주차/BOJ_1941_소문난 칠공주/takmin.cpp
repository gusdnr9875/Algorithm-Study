//문제:소문난 칠공주 (골드 3)
//알고리즘: 백트래킹
//푼날짜: 2021-01-13


//처음에 DFS로 접근했다가 십자가 같이 인접한경우는 탐색을 못하는 예외가생김
//25개중에 7개를 뽑는 경우의수를 모두구해야함
//그중에서 이다솜파가 임도연파보다 많아야하는경우와, 7개가 인접한경우를 구한다.

#include<iostream>
#include<map>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

char arr[5][5];
bool visited[25];
int ans;
vector<pair<int, int>>pick;
int dir[4][2] = {
	{-1,0},{0,1},{1,0},{0,-1} //북동남서
};

bool isInside(int a, int b) {
	return (a >= 0 && a < 5) && (b >= 0 && b < 5);
}

//선택한 7개가 인접해있는지 검사
bool check_near() {
	queue<pair<int, int>> q;
	bool flag[7] = { false, };
	q.push({ pick[0].first, pick[0].second });
	flag[0] = true;
	int cnt = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int k = 1; k < 7; k++) {
			if (flag[k]) continue;
			for (int i = 0; i < 4; i++) {
				int nx = x + dir[i][0];
				int ny = y + dir[i][1];
				if (nx == pick[k].first && ny == pick[k].second) {
					q.push({ nx,ny });
					flag[k] = true;
					cnt++;
				}
			}
		}

	}
	if (cnt == 7) return true;
	else return false;

	
}


void DFS(int idx, int lee, int lim) {
	//7개가 뽑혔다면 임다솜파가 더많은지+
	//인접한지를 검사한다.
	if (lee + lim == 7) {
		if (lim > lee) return;
		if (check_near()) ans++;
		return;
	}

	//7개를 뽑는 모든 경우의수를 구한다.
	for (int i = idx; i < 25; i++) {
		if (visited[i]) continue;

		pick.push_back({ i / 5,i % 5 });
		visited[i] = true;

		if (arr[i / 5][i % 5] == 'Y') DFS(i + 1, lee, lim + 1);
		else DFS(i + 1, lee + 1, lim);

		visited[i] = false;
		pick.pop_back();


		
	}
	
}

int main() {
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			cin >> arr[i][j];
	DFS(0, 0, 0);
	cout << ans;

	
	

}