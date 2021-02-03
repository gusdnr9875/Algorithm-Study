//Solution
//- Union - Find의 전형적인 문제
//- 이론적 접근은 다음과 같다.
//- 1. a, b가 연결되어 있을 때, 작은 번호를 갖는 쪽에 연결한다.
//- 2. a, b가 다른 네트워크와 연결되어 있을 때, 부모의 번호를 비교하여 작은 번호를 갖는 쪽에 연결한다.
//- 3. 전체 네트워크 중 1의 번호를 갖는 컴퓨터의 수를 구한다.
//- 풀이는 다음과 같다.
//- 1. 풀이에 필요한 변수를 선언한다.
//- 1.1.parent[] : 최상단(네트워크 중 최소값을 갖는 컴퓨터 번호) 즉, 부모의 index를 저장할 배열.
//- 1.1.1.초기값은 parent[i] = i
//- 1.2.virus[] : 바이러스 연결을 담는 배열
//- 2. expand() 함수에서 union - find를 수행한다.
//- 2.1.parent(a), parent(b)를 비교한다.
//- 2.1.1.parent(a) < parent(b) 인 경우, parent[b] = a로 변경한다.
//- 2.1.2.parent(a) > parent(b) 인 경우, parent[a] = b로 변경한다.
//- 3. 2번 PC부터 확인하여 parent(n) == 1인 컴퓨터의 수를 구하여 출력한다.

#include <iostream>
#include <vector>
#include <queue>

	using namespace std;

#define N_MAX 101

int N;
int V;
int parent[N_MAX];
vector<vector<int>> virus;

void init() {
	cin >> N >> V;
	for (int i = 1; i <= N; i++) parent[i] = i;
	int a, b;
	for (int i = 0; i < V; i++) {
		cin >> a >> b;
		virus.push_back({ a, b });
	}
}

int get_parent(int target) {
	if (parent[target] == target) return target;
	return parent[target] = get_parent(parent[target]);
}

void expand() {
	for (int i = 0; i < virus.size(); i++) {
		int a = get_parent(virus[i][0]);
		int b = get_parent(virus[i][1]);
		if (a < b) {
			parent[b] = a;
			get_parent(virus[i][1]);
		}
		else if (a > b) {
			parent[a] = b;
			get_parent(virus[i][0]);
		}
	}
}

void solution() {
	init();
	expand();
	int answer = 0;
	for (int i = 2; i <= N; i++) {
		if (get_parent(i) == 1) answer++;
	}

	cout << answer << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}