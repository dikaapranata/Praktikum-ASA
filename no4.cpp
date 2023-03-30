
#include <bits/stdc++.h>
using namespace std;


void solve(){
	/*
		3
		3 3
		1 2 4 
		2 2 3
		2 2 5
		
		2
		3 5
		1 1 3 3 4
		2 2 4 4 2
		1 4 4 5 5
		
		Time complexity O(n^2)
	*/
	int A,m,n;
	cin >> A >> m >> n;
	int arr[n][m];
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin >> arr[j][i];
			arr[j][i]*=A;
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cout << arr[j][i] << " ";
		}
		cout << "\n";
	}
	
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	solve();
	return 0;
}
