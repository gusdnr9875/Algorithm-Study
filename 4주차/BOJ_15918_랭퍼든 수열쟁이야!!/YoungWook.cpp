#include <iostream>

using namespace std;

bool checkN[13];
int arr[24];
int n, x, y;
int count;


void dfs(int idx)
{
	if(idx == 2*n - 1) 
	{
		count++;
		return;
	}	

	if(!arr[idx])
	{
		for(int i=1;i<=n;i++)
		{
			if(checkN[i] == 0 && idx + i + 1 <= 2*n-1 && !arr[idx+i+1])
			{
				checkN[i] = true;
				arr[idx] = i;
				arr[idx + i + 1] = i;
				dfs(idx + 1);
				checkN[i] = false;
				arr[idx] = 0;
				arr[idx + i + 1] = 0;
			}
		}
	}else
		dfs(idx+1);
		
	return;
	
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> x >> y;
	checkN[y-x-1] = true;
	arr[y-1] = y-x-1;
	arr[x-1] = y-x-1;
	
	dfs(0);
	
	cout << count <<"\n";
	
	return 0;
}
