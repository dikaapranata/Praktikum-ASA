
#include <bits/stdc++.h>
using namespace std;

/*
	time complexity constant O(1)
*/

void solve(){
	
	int n;
	cin >> n;
	if(n==4){
		cout << "MEMAKAN, SAHUR";
	}else if(n==18){
		cout << "MEMAKAN, BERBUKA";
	}else if(n>4 && n<18){
		cout << "TIDAK MEMAKAN";
	}else{
		cout << "MEMAKAN, AMAN";
	}

}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	solve();
	return 0;
}
