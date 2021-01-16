#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <climits>

using namespace std;

int n,m; // 한 변의 길이 , 남겨진 치킨집 개수  
int town[50][50];
vector<pair<int,int> > chicken;
vector<pair<int,int> > house;
int selection[13][2]; // 폐점되지 않은 치킨집의 좌표  
bool visit[50][50];
int copytown[50][50];
int ans = INT_MAX; 

typedef struct
{
	int y, x;
}dir;

dir moveDir[4] = {{0,1},{1,0},{0,-1},{-1,0}};

void cpyTown()
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			copytown[i][j] = 0;
			
	for(int i=0;i<m;i++)
	{
		int y = selection[i][0];
		int x = selection[i][1];
		
		copytown[y][x] = 2;
	}
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(town[i][j] != 2)
				copytown[i][j] = town[i][j];
	
}


void dfs(int idx, int cnt)
{
	if(cnt == m)
	{
		
		int result = 0;
		
		for(int i=0;i<house.size();i++)
		{
			int y = house[i].first;
			int x = house[i].second;
			
			int dist = INT_MAX;
			
			for(int i=0;i<m;i++)
			{
				int cy = selection[i][0];
				int cx = selection[i][1];
				
				dist = min(dist, abs(cy - y) + abs(cx - x));
			}			
			result += dist;
		}
		
		//cout << result <<"\n";
		
		ans = min(ans, result);	
		
		return;
	}
	
	for(int i=idx+1;i<chicken.size();i++) // 중복이되지 않도록 idx + 1을 해준다.  
	{
		selection[cnt][0] = chicken[i].first; // y값 
		selection[cnt][1] = chicken[i].second; // x 값  
		dfs(i,cnt+1);
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin >> town[i][j];
			if(town[i][j] == 1)
				house.push_back(make_pair(i,j)); // 집의 위치 저장. 
			
			if(town[i][j] == 2) 
				chicken.push_back(make_pair(i,j)); // 치킨집의 위치 저장. 
		} 	
	}
	
	dfs(-1,0);
	cout << ans <<"\n";
	return 0;
}
