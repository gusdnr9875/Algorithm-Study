#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX = 1000;

typedef struct
{
	int y,x;
}dir;

dir moveDir[4] ={{0,1},{1,0},{0,-1},{-1,0}};

int n,m;
string maze[MAX];
bool visit[MAX][MAX];
pair<int,int> start;
vector<pair<int,int>> fire;

int bfs()
{
	queue<pair<int,int>> q;
	q.push(start);
	queue<pair<int,int>> flame;
	
	for(int i=0;i<fire.size();i++)
		flame.push(fire[i]); // 불 난 장소가 여러개 일 수도 있다. 
	
	int result = 0;
	while(!q.empty())
	{
		int flameSize = flame.size();
		for(int i=0;i<flameSize;i++)
		{
			int y = flame.front().first;
			int x = flame.front().second;
			flame.pop();
			
			for(int j=0;j<4;j++)
			{
				int ny = y + moveDir[j].y;
				int nx = x + moveDir[j].x;
				
				if(0<=ny && ny < n && 0<=nx && nx <m)
				{
					if(maze[ny][nx] == '.' || maze[ny][nx] == 'J')
					{
						maze[ny][nx] = 'F';
						flame.push(make_pair(ny,nx));
					}

				}
				
				
			}
				
		}
		
		int cursize = q.size();
		for(int i=0;i<cursize;i++)
		{
			int y = q.front().first;
			int x = q.front().second;
			q.pop();
			
			if(y == 0 || y == n-1 || x == 0|| x == m-1)
				return result+1;
				
			for(int j=0;j<4;j++)
			{
				int ny = y + moveDir[j].y;
				int nx = x + moveDir[j].x;
				
				if(0<=ny && ny <n && 0<=nx && nx<m && !visit[ny][nx])
				{
					if(maze[ny][nx] == '.')	
					{
						visit[ny][nx] =true;
						q.push(make_pair(ny, nx));
					}
				}		
				
			}
					
			
		}
		result++;		
	} 
	return -1;
}

int main(){
	ios_base::sync_with_stdio(0);

    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
	    cin >> maze[i];
	    for (int j = 0; j < maze[i].size(); j++)
	    { 
	        if (maze[i][j] == 'J')
            	start = { i, j };
            else if (maze[i][j] == 'F')
                fire.push_back({ i, j });
		}
    }

 

    int result = bfs();

    if (result == -1)
        cout << "IMPOSSIBLE\n";
    else
        cout << result << "\n";



	return 0;
}

