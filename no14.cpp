
#include <bits/stdc++.h>
using namespace std;

/*fungsi untuk mengecek apakah angka merupakan bilangan prima atau bukan*/
bool cekPrima(int n){
	for(int i=2;i<n;i++){
		if(n%i==0)return false;
	}
	return true;
}

void solve(){
	
	int n,m;
	cin >> n >> m;
	/*menciptakan grid dengan ukuran m x n*/
	char grid[m+1][n+1];
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			/*cek tiap koordinat lalu jumlah dan cek apakah merupakan bilangan prima*/
			if(cekPrima(i+j))grid[i][j] = 'O';
			else grid[i][j] = 'X';
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cout << grid[i][j] << " ";
		}
		cout << "\n";
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	solve();
	return 0;
}
