#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef struct MyStruct
{
	int y;
	int x;
}chess;
int n = 0, result = 0;
int temp[11][11];
vector <chess> arr; //1인 곳
vector <chess> bitshop; // 비숍저장

void dfs(int cnt, int cur) {// 비숍개수, 현재 탐색 위치 순

	if (cnt > result) {
		result = cnt;
	}
	if (cur == arr.size())
		return;

	//1. 비숍가능한지 검사
	bool jud = true;
	for (int j = 0; j < bitshop.size(); j++) {
		if (abs(arr[cur].y - bitshop[j].y) == abs(arr[cur].x - bitshop[j].x)) {
			jud = false;
			break;
		}
	}
	if (jud == true) { //비숍이 가능하다면 
		bitshop.push_back({ arr[cur].y,arr[cur].x });
		dfs(cnt + 1, cur + 1);
		bitshop.pop_back();
	}
	dfs(cnt, cur + 1);

	return;

}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	int answer = 0;
	for(int i=1;i<=n;i++)
		for (int j = 1; j <= n; j++) {
			cin >> temp[i][j];
			if (temp[i][j] == 1 && (i+j)%2 == 0)
				arr.push_back({ i,j });
		}

	dfs(0, 0);
	answer += result;
	result = 0;
	arr.clear();


	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			if (temp[i][j] == 1 && (i + j) % 2 == 1)
				arr.push_back({ i,j });
		}
	dfs(0, 0);
	answer += result;
	cout << answer << endl;

	
	return 0;
}