#include <iostream>
#include <vector>

using namespace std;

const int MAX = 9;

int sudoku[MAX][MAX];
bool row[MAX][MAX+1];
bool col[MAX][MAX+1];
bool square[MAX][MAX+1];

int change2Squareidx(int y, int x)
{
	return (y/3) * 3 + x/3;
}

void dfs(int cnt)
{
	if(cnt == 81)
	{
		for(int i=0;i<MAX;i++)
		{
			for(int j=0;j<MAX;j++)
				cout << sudoku[i][j] << " ";
			cout <<"\n";
		}
	}
	int y = cnt/9;
	int x = cnt%9;
	
	if(sudoku[y][x])
		dfs(cnt+1);
	else
	{
		for(int k=1;k<=MAX;k++)
		{
			if(!col[x][k] && !row[y][k] && !square[change2Squareidx(y,x)][k])
			{
				sudoku[y][x] = k;
				col[x][k] = true;
				row[y][k] = true;
				square[change2Squareidx(y,x)][k] = true;
				dfs(cnt+1);
				sudoku[y][x] = 0;
				col[x][k] = false;
				row[y][k] = false;
				square[change2Squareidx(y,x)][k] = false;
				
				
			}
		}
	}
	
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	for(int i=0;i<MAX;i++)
	{
		for(int j=0;j<MAX;j++)
		{
			cin >> sudoku[i][j];
			if(sudoku[i][j])
			{
				col[j][sudoku[i][j]] =  true;
				row[i][sudoku[i][j]] = true;
				square[change2Squareidx(i,j)][sudoku[i][j]]	= true;
			}	
		}	
	
	}
	
	dfs(0);
		
	
	return 0;
}
