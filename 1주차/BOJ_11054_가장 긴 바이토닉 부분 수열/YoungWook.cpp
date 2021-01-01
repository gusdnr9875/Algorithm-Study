#include <iostream>

using namespace std;

const int MAX = 1000;

int arr[MAX];
int leftdp[MAX];
int rightdp[MAX];
int n;


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> arr[i];
		
	// left
	int idx = 1;
	for(int i=0;i<n;i++)
	{
		int check = arr[i];
		for(int j=0;j<idx;j++)
		{
			if(arr[j] < check)
			{
				if( leftdp[i] < leftdp[j] + 1)
					leftdp[i] = leftdp[j] + 1;	
			}
					
		}
		idx++;
	}
	
	// right
	idx = n-1;
	for(int i=n-1;i>=0;i--)
	{
		int check = arr[i];
		for(int j=n-1;j>=idx;j--)
		{
			if(arr[j] < check)
			{
				if(rightdp[i] < rightdp[j] + 1)
					rightdp[i] = rightdp[j] + 1;	
			}
					
		}
		idx--;
	}
	
	int result = 0;
			
	for(int i=0;i<n;i++)
		if(result < rightdp[i] + leftdp[i])
			result = rightdp[i] + leftdp[i];
	
	/* 0부터 시작했고 한번 중복 */
	cout << result + 1 <<"\n";
	
	return 0;
}
