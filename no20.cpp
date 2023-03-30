
#include <bits/stdc++.h>
using namespace std;

/*
	time complexity constant O(len(s1)*len(s2))
	
	asdgbuyjfkr
	buy
	
	asdgbiyjfkr
	buy
*/

void solve(){
	
	string s1,s2;
	cin >> s1 >> s2;
	for(int i=0;i<=s1.length()-s2.length();i++){
		/*output kemungkinan*/
		for(int j=i;j<i+s2.length();j++){
			cout << s1[j];
		}
		cout << "\n";
		int len=0;
		/*bandingankan dengan string 2*/
		for(int j=i;j<i+s2.length();j++){
			if(s1[j]==s2[j-i])len++;
		}
		if(len==s2.length()){
			cout << "\nPattern ditemukan!!";
			return;
		}
	}
	cout << "\nPattern tidak ditemukan!!";

}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	solve();
	return 0;
}
