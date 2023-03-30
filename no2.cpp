
#include <bits/stdc++.h>
using namespace std;


void solve(){
	
	vector<int> num; // num[2,7,11,15]
	int target;
	
	// 2 7 11 15
	do{
		int temp;
		cin >> temp;
		num.push_back(temp);
	}while(cin.get()!='\n');
	
	cin >> target;
	/*algoritma inti */
	for(int i=0;i<num.size();i++){
		for(int j=0;j<num.size();j++){
			if(num[j]==target-num[i] && j!=i){
				cout << i << " " << j;
				return;
			}
		}
	}
}

int main(){
	solve();
	
	return 0;
}
