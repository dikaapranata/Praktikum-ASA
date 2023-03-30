
#include <bits/stdc++.h>
using namespace std;

/*
	time complexity constant O(1)
*/

void solve(){
	
	int t=0;
	int arr[3];
	while(t<3){
		int temp;
		cin >> temp;
		if(temp<0){
			cout << "Inputan sisi salah\n";
			return;
		}
		arr[t]=temp;
		t++;
	}
	sort(arr,arr+3);
	if(arr[0]*arr[0]+arr[1]*arr[1]==arr[2]*arr[2]){
		cout << "Segitiga siku-siku\n";
	}else{
		cout << "Bukan segitiga siku-siku\n";
	}
	

}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	solve();
	return 0;
}
