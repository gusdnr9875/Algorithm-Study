#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct a{
	int y;
	int x;
	bool checked;
}Chk;

vector <pair <int, int>> house;
vector <Chk> chicken;
int n = 0, m = 0;
int result = 2e9;

void dfs(int cnt, int current) {

	if (cnt == m) {
		int sum = 0;

		for (int i = 0; i < house.size(); i++) {
			int mined = 1000000000;
			for (int j = 0; j < chicken.size(); j++) {
				if (chicken[j].checked == false) continue;

				mined = min(mined, abs(house[i].first - chicken[j].y) + abs(house[i].second - chicken[j].x));
			}
			sum += mined;
		}

		if (result > sum)
			result = sum;

		return;
	}
	

	for (int i = current; i < chicken.size(); i++) {
		if (chicken[i].checked == false) {
			chicken[i].checked = true;
			dfs(cnt + 1, i);
			chicken[i].checked = false;
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	// 1.
	cin >> n >> m;
	int num = 0;
	for(int i=1;i<=n;i++)
		for (int j = 1; j <= n; j++) {
			cin >> num;
			if (num == 1)
				house.push_back(make_pair(i, j));
			else if (num == 2)
				chicken.push_back({ i,j,0 });
		}
	//2.
	dfs(0, 0);

	cout << result << endl;
	return 0;
}