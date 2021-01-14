//solution
//- 가로, 세로, 대각선이 겹치지 않게 배치하는 조합의 수를 구하는 문제.
//- 이론적 접근은 다음과 같다.
//- 1. 같은 행과 같은 열은 존재할 수 없으므로 행-열 쌍을 기록하여 체크한다.
//- 2. dfs로 가능한 조합을 찾는다.
//- 2.1. 단, 증가방향으로 체크하여 중복을 방지한다.
//- 3. 행의 중복은 불가하므로 다음을 추가로 체크해야 한다.
//- 3.1. 열의 중복을 체크한다.
//- 3.2. 대각여부를 체크한다.
//- 4. 3.에 해당하지 않는 조합의 수를 체크하여 출력한다.
//- 풀이는 다음과 같다.
//- 1. 풀이에 필요한 변수를 선언한다.
//- 1.1. vector<int> map : y에 대한 x를 저장한 배열
//- 1.2. answer : 답, 주어진 조건에 해당하는 조합의 수
//- 2. expand(map, y) 함수를 통해 bfs를 수행하며 조합을 찾아나간다.
//- 2.1. y에 해당하는 x를 선택하고 is_cross() 함수에서 중복여부를 체크한다.
//- 2.1.1. 0 ~ y-1까지 다음을 확인한다.
//- 2.1.2. map[]에서 map[y]의 값과 같은 값이 있는 지 확인한다.
//- 2.1.3. map[]에서 map[y]의 값과 대각을 이루는 지 확인한다.
//- 2.1.4. 2.1.2.와 2.1.3.에 해당한다면 규칙에 위반하므로 제외한다.
//- 3. 한 행당 하나의 queen을 선택하므로 y == n일 때, 다음을 확인한다.
//- 3.1. 2.1.4.에 해당하지 않는 조합이면 answer을 1 증가시킨다.
//- 4. answer을 출력한다.

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int answer;

bool is_cross(vector<int> map, int y) {
    for (int i = 0; i < y; i++) {
        if (map[i] == map[y]) return true;
        if (abs(map[i] - map[y]) == abs(i - y)) return true;
    }
    return false;
}

void expand(vector<int> map, int y) {
    if (y == map.size()) {
        answer++;
        return;
    }

    for (int x = 0; x < map.size(); x++) {
        map[y] = x;
        if (!is_cross(map, y)) {
            expand(map, y + 1);
        }
    }
}

int solution(int n) {
    vector<int> map(n);
    expand(map, 0);
    return answer;
}