#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int k;
vector <char> arr;
vector <int> val;
bool chk() {

	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] == '<') {
			if (val[i] > val[i + 1])
				return false;
		}
		else {
			if (val[i] < val[i + 1])
				return false;
		}
	}
	return true;
}


int main() {

	cin >> k;
	for (int i = 0; i < k; i++) {
		char temp;
		cin >> temp;
		arr.push_back(temp);
	}
	for (int j = 0, i = 9; j < k + 1; j++,i--) 
		val.push_back(i);
	while (1) {
		if (chk() == true)
			break;
		prev_permutation(val.begin(), val.end());
	}
	for (int i = 0; i < val.size(); i++)
		cout << val[i];
	cout << endl;

	val.clear();
	for (int i = 0; i < k + 1; i++)
		val.push_back(i);

	while (1) {
		if (chk() == true)
			break;

		next_permutation(val.begin(), val.end());
		
	}
	for (int i = 0; i < val.size(); i++)
		cout << val[i];
	cout << endl;
	return 0;

}
