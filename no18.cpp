
#include <bits/stdc++.h>
using namespace std;

/*
	time complexity constant O(1)
*/

void solve(){
	
	string s;
	cin >> s;
	int a,b;
	cin >> a >> b;
	char temp = s[a-1];
	s[a-1]=s[b-1];
	s[b-1]=temp;
	cout << s;

}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	solve();
	return 0;
}
