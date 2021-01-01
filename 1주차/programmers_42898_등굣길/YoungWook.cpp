#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    /* 오른쪽과 아래쪽으로만 이동 */
    
    int dp[101][101] = {0};
    int Notgo[101][101] = {0};
    
    for(int i=0;i<puddles.size();i++)
    {
        int x = puddles[i][0];
        int y = puddles[i][1];
        
        Notgo[y][x] = -1; 
    }
    
    dp[0][1] = 1;
    
    for(int i=1;i<=n;i++)   
    {
        for(int j=1;j<=m;j++)
        {
           if(Notgo[i][j] == -1)
               dp[i][j] = 0;
            else
                dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % 1000000007;
            
        }
    }
    
    return dp[n][m];
}
