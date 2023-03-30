
#include <bits/stdc++.h>
using namespace std;

/*
	time complexity constant O(1)
*/

void solve(){
	
	int a,b,c,x;
	cin >> a >> b >> c >> x;
	long long ans = a*x*x + b*x + c;
	cout << ans;

}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	solve();
	return 0;
}
