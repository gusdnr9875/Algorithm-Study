#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n = 0;
bool visited[10001] = { 0, };
vector <pair<int, int>> arr[10001];

int result = 0;
int destination = 0;

void dfs(int cur, int len) {

	if (result < len) {
		result = len;
		destination = cur;
	}

	for (int i = 0; i < arr[cur].size(); i++) {
		if (visited[arr[cur][i].first] == 0) {
			visited[arr[cur][i].first] = 1;
			dfs(arr[cur][i].first, len + arr[cur][i].second);
		}
	}


}
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int s, e, v;
		cin >> s >> e >> v;
		arr[s].push_back(make_pair(e, v));
		arr[e].push_back(make_pair(s, v));
	}

	visited[1] = 1;
	dfs(1, 0); //목적지 구하고
	
	
	memset(visited, 0, sizeof(visited));
	result = 0;
	
	visited[destination] = 1;
	dfs(destination, 0);

	cout << result << endl;
	

}