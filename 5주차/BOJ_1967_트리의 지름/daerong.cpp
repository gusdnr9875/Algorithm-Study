//Solution
//- 단말~단말을 연결할 때, 가장 큰 가중치를 가진 path를 찾는 문제.
//- 이론은 다음과 같다.
//- 1. 단말부터 단말까지의 가중치 합 중에 답이 있다.
//- 1.1.양쪽 끝으로 확장할 수 있는 경우, 최대가 될 수 없다.
//- 2. 단말에서 뻗어나갈 수 있는 방향의 수는 간선의 갯수이다.
//- 3. 모든 노드에 대해 DFS 확장을 시도하면 최대 가중치 합을 구할 수 있다.
//- Failed 1 : 이진트리로 가정하고 풀이했으나 틀렸다.
//- 1. 좌우 간선합이 큰쪽을 선택하며 확장시켜 시간복잡도는 낮지만 기본적으로 이진트리가 아니어서 사용불가.
//- 2. 간선의 제한이 없다고 하면 벡터로 선언하여 간선 갯수대로 확장시키면 된다.
//- 풀이는 다음과 같다.
//- 1. 풀이에 필요한 변수를 선언한다.
//- 1.1.node : N개의 노드에 대한 각각의 vector<>
//- 1.2.visited : 노드에 대한 방문여부를 체크할 배열
//- 1.3.answer : 간선 가중치 합의 최대값
//- 2. 모든 노드에 대해 다음을 수행한다.
//- 2.1. dfs() 함수로 node를 연결한다.
//- 2.2. 연결된 노드를 통해 dfs()를 확장한다.
//- 2.3. 더이상 연결할 수 없을 때, answer을 최대값으로 업데이트한다.
//- 3. answer를 출력한다.


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define N_MAX 10001

typedef struct NODE {
	int num;
	int wgt;
} NODE;

int N;
vector<NODE> node[N_MAX];
bool visited[N_MAX];
int answer;

void init() {
	cin >> N;
	int a, b, w;
	for (int i = 1; i < N; i++) {
		cin >> a >> b >> w;
		node[a].push_back({ b, w });
		node[b].push_back({ a, w });
	}
}

void dfs(int target, int sum) {
	visited[target] = true;
	for (int i = 0; i < node[target].size(); i++) {
		if (visited[node[target][i].num]) continue;
		dfs(node[target][i].num, sum + node[target][i].wgt);
	}
	answer = max(answer, sum);
	visited[target] = false;
}

void solution() {
	init();
	for (int i = 1; i <= N; i++) dfs(i, 0);
	cout << answer << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	solution();

	return 0;
}