
#include <bits/stdc++.h>
using namespace std;

/*
	time Complexity linier O(n)
*/

void solve(){
	
	int n;
	cin >> n;
	set<int> num;
	for(int i=0;i<n;i++){
		int temp;
		cin >> temp;
		num.insert(temp);
	}
	set<int>::iterator itr;
	for (itr = num.begin(); itr != num.end(); itr++){
    	cout << *itr << " ";
    }
	
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	solve();
	return 0;
}
