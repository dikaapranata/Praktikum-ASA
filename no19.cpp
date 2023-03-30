
#include <bits/stdc++.h>
using namespace std;
#define LL long long

/*
	time complexity O(n)
*/

map<LL,LL> dp;
LL count(LL a,LL n){
	if(a==n)return 1;
	if(a>n)return 0;
	if(dp[a]!=0)return dp[a];
	LL val = count(a+1,n) + count(a+2,n);
	dp[a]=val;
	return dp[a];
}


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	LL n;
	cin >> n;
	cout << count(0,n);
	
	return 0;
}
