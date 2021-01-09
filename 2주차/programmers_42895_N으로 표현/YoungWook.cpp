#include <string>

using namespace std;

int answer = 9;
    

void Solve(int n, int goal, int cnt, int sum)
{
    if(cnt > 8)
        return;
    
    if(sum == goal)
        if(answer > cnt)
            answer = cnt;
    
    int temp = 0;
    
    for(int i=1;i<=8;i++)
    {
        temp =(temp *10) + n;
        
        Solve(n, goal, cnt+i, sum + temp);
        Solve(n, goal, cnt+i, sum - temp);
        Solve(n, goal, cnt+i, sum / temp);
        Solve(n, goal, cnt+i, sum * temp);
        
    }
    
}

int solution(int N, int number) {
    Solve(N, number, 0, 0);
    if(answer == 9)
        answer = -1;

    return answer;
}
