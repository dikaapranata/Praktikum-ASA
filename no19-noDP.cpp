
#include <bits/stdc++.h>
using namespace std;
#define LL long long

/*
	time complexity O(2^n)
*/

LL count(LL a,LL n){
	if(a==n)return 1;
	if(a>n)return 0;
	return count(a+1,n) + count(a+2,n);
}


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	LL n;
	cin >> n;
	cout << count(0,n);
	
	return 0;
}
