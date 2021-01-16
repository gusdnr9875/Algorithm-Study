#include <string>
#include <vector>

using namespace std;

int chess[13];
int result;

bool possible(int y)
{
    for(int j=1;j<y;j++)
	{
		if(chess[j] == chess[y] || abs(chess[y]-chess[j]) == y - j )
			return false;
	}
	
	return true;	
}

void Queen (int n, int y)
{
    if(y == n+1)
    {
        result++;
        return;
    }
    for(int i=1;i<=n;i++)
	{
		chess[y] = i;
		if(possible(y))
			Queen(n, y+1);
	}
}


int solution(int n) 
{
    Queen(n,1);

    return result;
   
}
