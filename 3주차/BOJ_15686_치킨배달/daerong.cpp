//Solution
//- 주어진 치킨집 중 M개를 선택한 조합을 만들어 집과의 최단거리 합을 구하는 문제
//- 이론적 접근은 다음과 같다.
//- 1. 집과 치킨집의 거리를 최단거리 순서로 저장한다.
//- 1.1.집은 그대로, 치킨집만 조합으로 생성된다.
//- 1.2.집과 치킨집의 거리는 변하지 않는다.
//- 1.3.따라서 i번째 집에 대한 모든 치킨집의 거리를 오름차순으로 저장해 보관한다.
//- 2. 치킨집 M개의 부분집합(Combination)을 생성한다.
//- 2.1.index가 순차적으로 증가하는 함수를 이용하면 중복없이 생성이 가능하다.
//- 3. 1.에서 구한 최단거리순으로 확인한다.
//- 3.1.M개에 선택되지 못한 경우, 다음 최단거리을 확인한다.
//- 3.2.M개에 선택된 경우, 최단거리를 선택한다.
//- 3.3.모든 집에 대한 최단거리 합을 구한다.
//- 4. 모든 조합에 대해 3.3.의 최소값을 출력한다.
//- 풀이는 다음과 같다.
//- 1. 풀이에 필요한 값을 세팅한다.
//- 1.1.dist[i][j] : i번째 집을 기준으로 가까운 치킨 순서로 정렬된 치킨집 배열. (j가 0일 때, 가장 가까움)
//- 1.2.vector<LOCATE> house : 집의 x, y 위치가 기록된 배열
//- 1.3.vector<LOCATE> store : 치킨집의 x, y 위치가 기록된 배열
//- 1.4.answer : 치킨거리 합의 최소값
//- 2. combination(int target, int check, int cnt) 함수를 통해 M개의 원소를 갖는 치킨집 조합을 생성한다.
//- 2.1.cnt가 M인 경우, 다음을 수행한다.
//- 2.1.1.get_chicken_len() 함수로 치킨거리 합을 구한다.
//- 2.1.1.1.모든 집에 대해 다음을 수행한다.
//- 2.1.1.2.i번째 집에 대해 j를 0부터 증가시키며 최단 거리를 확인한다.
//- 2.1.1.2.1.j위치가 M개에 포함되는지는 check에 j번째 비트가 포함되었는 지 확인하면 된다.
//- 2.1.1.2.2.j는 0일 때 최소이며 후순으로 작은 값을 취한다.
//- 2.1.1.3.모든 집에대해 치킨집 최단거리의 합을 구한다.
//- 2.1.2. 2.1.1.에서 구한 치킨거리 합과 answer의 최소값을 answer에 저장한다.
//- 3. answer을 출력한다.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define N_MAX 50
#define M_MAX 13

typedef struct LOCATE {
	int x;
	int y;
} LOCATE;
typedef struct DIST {
	int store_id;
	int dist;
} DIST;
bool compare(DIST a, DIST b) {
	return a.dist < b.dist;
}

int N;
int M;
vector<vector<DIST>> dist;
vector<LOCATE> house;
vector<LOCATE> store;
int answer;

void init() {
	cin >> N >> M;
	int temp;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> temp;
			if (temp == 1) house.push_back({ x, y });
			else if (temp == 2) store.push_back({ x, y });
		}
	}

	answer = 2147483647;

	int len;
	for (int i = 0; i < house.size(); i++) {
		vector<DIST> line;
		for (int j = 0; j < store.size(); j++) {
			len = abs(house[i].x - store[j].x) + abs(house[i].y - store[j].y);
			line.push_back({ j, len });
		}
		sort(line.begin(), line.end(), compare);
		dist.push_back(line);
	}
}

int get_chicken_len(int check) {
	int sum = 0;
	for (int i = 0; i < dist.size(); i++) {
		for (int j = 0; j < dist[i].size(); j++) {
			if (check & (1 << dist[i][j].store_id)) {
				sum += dist[i][j].dist;
				break;
			}
		}
	}

	return sum;
}

void combination(int target, int check, int cnt) {
	if (cnt == M) {
		answer = min(answer, get_chicken_len(check));
		return;
	}

	if (target >= store.size()) return;

	combination(target + 1, check | (1 << target), cnt + 1);
	combination(target + 1, check, cnt);
}

void solution() {
	init();
	combination(0, 0, 0);
	cout << answer << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}