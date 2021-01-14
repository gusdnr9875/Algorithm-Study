//문제: 치킨배달(골드5)
//알고리즘: 백트래킹을통한 완전탐색
//푼날짜: 2021-01-11

#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;

struct POINT
{
	int x, y;
};
int n, m;
int arr[51][51];
int ans;
vector<POINT> house;
vector<POINT> chicken;
vector<POINT> pick;
void DFS(int pos) {
	if (pick.size() == m) {
		int temp=0;
		//집을기준으로 픽한 치킨집중에서 
		//가장 짧은 치킨집 거리 구하기
		for (int i = 0; i < house.size(); i++) {
			int minValue = INT_MAX;
			for (int j = 0; j < pick.size(); j++) {
				minValue=min(minValue,abs(house[i].x - pick[j].x) + abs(house[i].y - pick[j].y));
			}
			temp += minValue;
		}
		ans = min(ans, temp);
	}

	for (int i = pos; i < chicken.size(); i++) {
		pick.push_back(chicken[i]);
		DFS(i + 1);
		
		//백트래킹
		pick.pop_back();
	}
}
int main() {
	ans = INT_MAX;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1)  house.push_back({ i,j });
			else if (arr[i][j] == 2)  chicken.push_back({ i,j });
		}
	}

	DFS(0);
	cout << ans;

}
