#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 987654321;
int n,m;
int city[50][50];
int visit[50][50]; 
int chicken[13][2]; // 살아남은 치킨 집 
int result = INF;


void dfs(int y, int cnt)
{
	// 선택된 치킨집 
	if(cnt == m)
	{
		
		int temp = 0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(city[i][j] == 1)
				{
					int dist = INF;
					for(int k=0;k<cnt;k++)
					{
						int cy = chicken[k][0];
						int cx = chicken[k][1];
						
						int tdist = abs(cy - i) + abs(cx -j);
						
						if(tdist < dist)
							dist = tdist;
					}	
					
					temp += dist;
				}	
					
			}
		}
		
		if(temp < result)
			result = temp;
		
		return; 
	}
	
	
	
	for(int i = y;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(city[i][j] == 2 && !visit[i][j])
			{
				visit[i][j] = true;
				chicken[cnt][0] = i;
				chicken[cnt][1] = j;				
				dfs(i, cnt+1);
				visit[i][j] = false;
			}
		}
	}

}




int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin >> city[i][j];
			
	
	dfs(0,0);
	
	cout << result <<"\n";
	
	return 0;
}
