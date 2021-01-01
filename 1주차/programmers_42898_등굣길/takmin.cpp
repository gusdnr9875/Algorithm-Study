//프로그래머스 등굣길
//BFS+DP 문제인줄알았었다
//이중 for문으로 순차적으로 접근하면 최단거리를 구할필요가없다(이동방향이 문제에서 오른쪽 또는아래쪽)
//알고리즘: dp
#include <string>
#include <vector>
#include <queue>
#include<iostream>

using namespace std;

int dp[101][101]; //해당좌표에서 최단거리경로 개수
int map[101][101];




int solution(int m, int n, vector<vector<int>> puddles) {

	
	int answer = 0;
	for (int i = 0; i < puddles.size(); i++) {
		int x=puddles[i][1];
		int y = puddles[i][0];
		map[x][y] = -1;
	}
	
	dp[1][0] = 1;
	//1,1좌표부터 시작
	//현재 위치를 기준으로 왼쪽 위쪽의 값 확인후 더함
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j] == -1) dp[i][j] = 0;
			else dp[i][j]= (dp[i-1][j]+dp[i][j-1]) % 1000000007;
		}
	}

	return dp[n][m];
}

int main() {
	vector<vector<int>> in = { {2,2} };
	cout<<solution(4, 3, in);
}