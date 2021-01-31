#include <iostream>
#include <climits>

using namespace std;

const int MAX = 10;


char board[MAX][MAX];
int	hy, hx; 
int n,m;
int result = INT_MAX;

typedef struct
{
	int y,x;
}Dir;

Dir moveDir[4] = {{0,1},{1,0},{0,-1},{-1,0}}; // 오른, 아래, 왼, 위  

void dfs(int by, int bx, int ry, int rx, int cnt, int dir)
{
	
	if(cnt > 10)
		return;
	
	
	//cout << by << bx << ry << rx <<"\n";
	
	int copyboard[MAX][MAX];
	
	// 방향 별 기울이기
	int bny = by + moveDir[dir].y;
	int bnx = bx + moveDir[dir].x;
		
	int rny = ry + moveDir[dir].y;
	int rnx = rx + moveDir[dir].x; 
	
	
	
	switch(dir)
	{
			
		case 0: // 오른쪽 
		{
		 	int bcnt = 0;
			int rcnt = 0;
			while(board[bny][bnx] == '.')
			{
				bny += moveDir[dir].y;
				bnx += moveDir[dir].x;	
				bcnt++;
			} 
		 	
		 	while(board[rny][rnx] == '.')
			{
				rny += moveDir[dir].y;
				rnx += moveDir[dir].x;	
				rcnt++;
			} 
		 	
		 	
		 	// 같은 위치 이면  
		 	if(bny == rny && bnx == rnx)
		 	{
		 		if(board[bny][bnx] == 'O')
		 			return;
				else
				{
					if(bcnt < rcnt)
					{
						rnx -= 2;
						bnx -= 1;
					}
					else
					{
						rnx -= 1;
						bnx -= 2;
					}
				
				}
				 	
			}
			// 같은 위치 아니면  
			else
			{
				if(board[bny][bnx] == 'O')
					return;
				
				if(board[rny][rnx] == 'O')
				{
					result = min(result, cnt);
					return;
				}
				
				rnx--;
				bnx--;
							
			}
		 	
		 			
			break;
		}
		case 1: // 아래쪽 
		{
			int bcnt = 0;
			int rcnt = 0;
			while(board[bny][bnx] == '.')
			{
				bny += moveDir[dir].y;
				bnx += moveDir[dir].x;	
				bcnt++;
			} 
		 	
		 	while(board[rny][rnx] == '.')
			{
				rny += moveDir[dir].y;
				rnx += moveDir[dir].x;	
				rcnt++;
			} 
		 	
		 	
		 	// 같은 위치 이면  
		 	if(bny == rny && bnx == rnx)
		 	{
		 		if(board[bny][bnx] == 'O')
		 			return;
				else
				{
					if(bcnt < rcnt)
					{
						rny -= 2;
						bny -= 1;
					}
					else
					{
						rny -= 1;
						bny -= 2;
					}
				
				}
				 	
			}
			else
			{
				if(board[bny][bnx] == 'O')
					return;
				
				if(board[rny][rnx] == 'O')
				{
					result = min(result, cnt);
					return;
				}
				
				rny--;
				bny--;
							
			}
			
			
			
			break;
		}
		case 2: // 왼쪽 
		{
			int bcnt = 0;
			int rcnt = 0;
			while(board[bny][bnx] == '.')
			{
				bny += moveDir[dir].y;
				bnx += moveDir[dir].x;	
				bcnt++;
			} 
		 	
		 	while(board[rny][rnx] == '.')
			{
				rny += moveDir[dir].y;
				rnx += moveDir[dir].x;	
				rcnt++;
			} 
		 	
		 	
		 	// 같은 위치 이면  
		 	if(bny == rny && bnx == rnx)
		 	{
		 		if(board[bny][bnx] == 'O')
		 			return;
				else
				{
					if(bcnt < rcnt)
					{
						rnx += 2;
						bnx += 1;
					}
					else
					{
						rnx += 1;
						bnx += 2;
					}
				
				}
				 	
			}
			else
			{
				if(board[bny][bnx] == 'O')
					return;
				
				if(board[rny][rnx] == 'O')
				{
					result = min(result, cnt);
					return;
				}
				
				rnx++;
				bnx++;
							
			}
			break;
		} 
		case 3: // 위쪽 
 		{
 			int bcnt = 0;
			int rcnt = 0;
			while(board[bny][bnx] == '.')
			{
				bny += moveDir[dir].y;
				bnx += moveDir[dir].x;	
				bcnt++;
			} 
		 	
		 	while(board[rny][rnx] == '.')
			{
				rny += moveDir[dir].y;
				rnx += moveDir[dir].x;	
				rcnt++;
			} 
		 	
		 	
		 	// 같은 위치 이면  
		 	if(bny == rny && bnx == rnx)
		 	{
		 		if(board[bny][bnx] == 'O')
		 			return;
				else
				{
					if(bcnt < rcnt)
					{
						rny += 2;
						bny += 1;
					}
					else
					{
						rny += 1;
						bny += 2;
					}
				
				}
				 	
			}
			else
			{
				if(board[bny][bnx] == 'O')
					return;
				
				if(board[rny][rnx] == 'O')
				{
					result = min(result, cnt);
					return;
				}
				
				rny++;
				bny++;
							
			}
			
			break;
		}		
	} 
	
	
	
	for(int i=0;i<4;i++)
		dfs(bny, bnx, rny, rnx ,cnt+1,i);
	
	
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int by, bx, ry, rx; // 초기 red, blue 위치  
	cin >> n >> m ;
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin >> board[i][j];
			if(board[i][j] == 'B')
			{
				by = i;
				bx = j;	
				board[i][j] = '.';
			}	
			
			if(board[i][j] == 'R')
			{
				ry = i;
				rx = j;
				board[i][j] = '.';
			}
			
			if(board[i][j] == 'O')
			{
				hy = i;
				hx = j;
			}
		}
	}
	
	for(int i=0;i<4;i++)
	{
		dfs(by, bx, ry, rx, 1,i);
	}
	
	if(result == INT_MAX)
	{
		cout << 0 << "\n";
		return 0;
	}
	cout << 1 <<"\n";
	
	return 0;
}
