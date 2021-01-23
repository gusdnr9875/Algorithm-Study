#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct
{
	int y,x;
	bool check;
}val;

int n, m, h;
int result;
int arr[10][10];
val house;
vector<val> mint;

void dfs(int y, int x, int cur, int cnt, int hp)
{
	if(cnt > result)
	{
		if(abs(y-house.y) + abs(x - house.x) <= hp)
			result = cnt;
	}
	
	if(hp <= 0)
		return;
	for(int i=0;i<mint.size();i++)
	{
		int len = abs(mint[i].y - y) + abs(mint[i].x - x);
		if(len <= hp && mint[i].check == false)
		{
			mint[i].check = true;
			dfs(mint[i].y, mint[i].x, i+1, cnt+1, hp - len + h);
			mint[i].check = false;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> h;
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			int temp;
			cin >> temp;
			if(temp == 1)
			{
				house.y = i;
				house.x = j;
			}
			else if(temp == 2)
			{
				mint.push_back({i, j, 0});
			}
		}
	}
	dfs(house.y, house.x, 0,0, m);
	cout << result << "\n";
	return 0;
}
