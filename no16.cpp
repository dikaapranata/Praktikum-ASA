
#include <bits/stdc++.h>
using namespace std;

/*
	inf*rm*t*k*
	oaia
	
	*acin**esar*l*sk*
	cgbaaa
	
	kra**ypa**y*do**ar
	bbtt5ll
	
	time Complexity linier O(n)
*/

void solve(){
	
	string s1,s2;
	cin >> s1 >> s2;
	int pos=0;
	for(int i=0;i<s1.length();i++){
		if(s1[i] == '*'){
			s1[i]=s2[pos];
			pos++;
		}
		cout << s1[i];
	}

}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	solve();
	return 0;
}
