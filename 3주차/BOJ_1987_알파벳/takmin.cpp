//문제: 알파벳 (골드4)
//알고리즘: 백트래킹
//푼날짜: 202-01-14

//map을 이용해 풀었지만 시간복잡도가 O(logN)이였고,
//배열을 통해 인덱스를 바로접근하는것보다 시간차이가 컸다
//로직은 똑같지만 1.맵을 이용하는방법, 2. 배열을 이용하는 방법으로 풀이를 두가지로 나누었다.

//1.맵을 이용하는방법
#include<iostream>
#include<map>
#include<algorithm>
#include<limits.h>
#include<unordered_map>
using namespace std;

map <char, bool> visited;
char arr[21][21];
int r, c;
int ans;
int dir[4][2] = {
	{-1,0}, {0,1} ,{1,0},{0,-1}
}; //북동남서

bool isInside(int a, int b) {
	return (a >= 0 && a < r) && (b >= 0 && b < c);
}
void DFS(int x, int y, int depth) {
	ans = max(ans, depth);

	for (int d = 0; d < 4; d++) {
		int nx = x + dir[d][0];
		int ny = y + dir[d][1];
		if (!isInside(nx, ny)) continue;
		if (!visited[arr[nx][ny]]) {
			visited[arr[nx][ny]] = true;
			DFS(nx, ny, depth + 1);
			visited[arr[nx][ny]] = false;
		}
	}
}
int main() {
	cin >> r >> c;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			cin >> arr[i][j];

	visited[arr[0][0]] = true;
	DFS(0, 0,1);

	cout << ans<<endl;
}


//2. 배열을 이용하는 방법
//참고: https://lmcoa15.tistory.com/30
#include <iostream>
#include <algorithm>
using namespace std;

int r, c;
int ans = 0;
char arr[21][21];
int alphabet[26] = { 0 }; //A~Z

int dir[4][2] = {
	{-1,0}, {0,1} ,{1,0},{0,-1}
}; //북동남서
bool isInside(int a, int b) {
	return (a >= 0 && a < r) && (b >= 0 && b < c);
}

void DFS(int x, int y, int depth) {

	ans = max(ans, depth);

	for (int d = 0; d < 4; d++) {
		int nx = x + dir[d][0];
		int ny = y + dir[d][1];

		if (!isInside(nx,ny))
			continue;

		//A:65 Z:90
		int k = (int)arr[nx][ny] - 65;
		if (alphabet[k])
			continue;

		alphabet[k]++;
		DFS(nx, ny, depth + 1);
		alphabet[k]--;

	}
}
int main() {

	cin >> r >> c;

	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++) {
			cin >> arr[i][j];
		}

	alphabet[(int)arr[0][0] - 65]++; //(0,0)지점 방문 체크
	DFS(0, 0, 1);

	cout << ans << endl;

}
