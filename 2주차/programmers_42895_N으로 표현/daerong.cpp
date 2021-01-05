//Solution
//- 주어진 숫자 N과 사칙연산, 괄호, 등호로 수식을 만들어 최소 N으로 number를 만드는 수식을 찾는 문제
//- Failed 1 : Testcase #2 실패함.
//- 1. m[5]를 세팅하기 위해, (m[1], m[4]), (m[2], m[3]) 조합만 확인하는 과정에서 예외가 발생했다.
//- 2. (m[1], m[4]), (m[2], m[3], (m[3], m[2]), (m[4], m[1]) 전부를 확인하니 해결했다.
//- 이론은 다음과 같다.
//- 1. X개를 사용해 만들 수 있는 모든 숫자는 m[N]에 저장한다.
//- 2. m[X]은 i와 j(1 < i, j < X)의 원소의 사칙연산으로 구성할 수 있다.
//- 3. 단, X개의 숫자를 연속으로 구성한 NN...N은 사칙연산으로 구성할 수 없으므로 별도로 추가한다.
//- 4. X를 증가시키며 m[X]에서 number를 찾는다.
//- 풀이과정은 다음과 같다.
//1. 풀이에 필요한 값을 세팅한다.
//1.1. m[N] : N개의 숫자로 만들 수 있는 모든 숫자의 조합
//2. N == number인 경우, 1을 return한다.
//3. m[1]에 N을 저장
//3.1. m[1]의 원소는 N이 유일하다.
//4. cnt를 2~8까지 순서대로 증가시키며 다음을 수행한다.
//4.1. cnt개의 숫자를 연결한 N...N을 m[cnt]에 추가한다.
//4.2. i + j = cnt(1 < i, j < cnt)가 되는 모든 조합에 대해 다음을 수행한다.
//4.2.1. m[i][] + m[j][]를 m[cnt]에 추가한다. (m[i][], m[j][]는 m[i], m[j]각각의 원소를 의미)
//4.2.2. m[i][] - m[j][]를 m[cnt]에 추가한다.
//4.2.3. m[i][] * m[j][]를 m[cnt]에 추가한다.
//4.2.4. m[i][] / m[j][]를 m[cnt]에 추가한다.
//4.2.4.1. m[j][]가 0인 경우, 무시.
//4.3. m[cnt]에 number가 있다면 cnt를 return한다.
//5. 위 과정을 수행하여 number을 찾지 못하면 -1을 return한다.

#include <string>
#include <unordered_set>

using namespace std;

#define LAST 8

unordered_set<int> m[LAST + 1];

int solution(int N, int number) {
    if (N == number) return 1;
    int temp = N;
    m[1].insert(temp);
    for (int cnt = 2; cnt <= LAST; cnt++) {
        temp = temp * 10 + N;
        m[cnt].insert(temp);

        for (int i = 1; i < cnt; i++) {
            int j = cnt - i;
            for (unordered_set<int>::iterator it1 = m[i].begin(); it1 != m[i].end(); it1++) {
                for (unordered_set<int>::iterator it2 = m[j].begin(); it2 != m[j].end(); it2++) {
                    m[cnt].insert({ *it1 + *it2 });
                    m[cnt].insert({ *it1 - *it2 });
                    m[cnt].insert({ *it1 * *it2 });
                    if (*it2 != 0) m[cnt].insert(*it1 / *it2);
                }
            }
            if (m[cnt].find(number) != m[cnt].end()) return cnt;
        }
    }

    return -1;
}