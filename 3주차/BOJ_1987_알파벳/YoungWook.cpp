#include <iostream>


using namespace std;
int r, c;
char alphabet[20][20];
int board[20][20];
int visit[26];
int result;

typedef struct
{
	int y,x;
} dir;

dir moveDir[4] = {{0,1},{1,0},{0,-1},{-1,0}};

void dfs(int i, int j, int cnt)
{
	visit[board[i][j]] = 1;
	result = max(result, cnt);	
	
	for(int l=0;l<4;l++)
	{
		int nextY = i + moveDir[l].y;
		int nextX = j + moveDir[l].x;
		
		if(0<=nextY && nextY <r && 0<=nextX && nextX<c)
		{
			if(!visit[board[nextY][nextX]])
			{
				dfs(nextY, nextX,cnt+1);
				visit[board[nextY][nextX]] = 0;	
			}
			
		}
		
	}		
}



int main(){
	cin >> r >> c;
	
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
		{
			cin >> alphabet[i][j];	
			board[i][j] = alphabet[i][j] - 'A';
		}
	
	dfs(0,0,1);
	
	cout << result <<"\n";
	
	return 0;
}
