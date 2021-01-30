//문제: 트리의지름 (골드4)
//알고리즘: 트리+DFS
//푼날짜: 2021-01-25

//루트노드로부터 가장멀리있는 노드를((거리가 가장긴) 찾고
//그 가장멀리있는 노드에서 역으로 가장멀리있는노드(거리가가장긴)거리를 찾는다.

#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int n;
vector<pair<int, int>> graph[10000+1];
bool visited[10000 + 1];
int max_distance;
int futherNode;

void DFS(int node, int distance) {
	if (visited[node]) return;
	
	visited[node] = true;
	if (distance > max_distance) {
		max_distance = distance;
		futherNode = node;		
	}
	
	for (int i = 0; i < graph[node].size(); i++) {
		DFS(graph[node][i].first, distance + graph[node][i].second);
	}

}
int main() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		int from, to, weight;
		cin >> from >> to >> weight;
		graph[from].push_back(make_pair(to, weight));
		graph[to].push_back(make_pair(from, weight));
	}

	DFS(1, 0);
	max_distance = 0;
	memset(visited, false, sizeof(visited));
	DFS(futherNode, 0);
	cout << max_distance;


}
