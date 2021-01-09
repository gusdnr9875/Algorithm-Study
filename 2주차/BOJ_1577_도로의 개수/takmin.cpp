//문제: 도로의개수
//알고리즘: dp
//푼날짜: 2021-01-06

//2방향만 체크하면됨
//최단거리이므로 아래쪽, 오른쪽으로 만 이동함
//check 변수를 두어서 특정 좌표에서 이동할수있는 방향을 bool값으로 두었음
//만약 특정좌표의 방향에서 공사중인 다리가있다면 해당방향은 false

#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

bool check[101][101][2];
long long dp[101][101];
int n, m, k;

int dir[2][2] = {
	{0,1},{1,0}
};

bool isInside(int a, int b) {
	return (a >= 0 && a <= m) && (b >= 0 && b <= n);
}
long long solve(int x, int y) {
	if (x == m && y == n) return 1;

	if (dp[x][y]) return dp[x][y];

	for (int d = 0; d < 2; d++) {
		int nx = x + dir[d][0];
		int ny = y + dir[d][1];
		
		if (isInside(nx, ny)) {
			//좌표 x,y에서 d방향으로 다른 좌표로이동하는데
			//공사중인 도로가 아니라면
			if(!check[x][y][d])
			dp[x][y]+=solve(nx, ny);
		}
	}
	return dp[x][y];
}
int main() {
	cin >> n >> m;
	cin >> k;

	for (int i = 0; i < k; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		int t = abs(a - c);

		//t가 0이면 1반환(아래쪽으로 공사길),
		//t가 1이면 0반환(오른쪽으로 공사길)
		//공사중인 도로 지정
		check[min(b, d)][min(a, c)][(t ? 0 : 1)] = true;
	}


	cout << solve(0, 0);
}