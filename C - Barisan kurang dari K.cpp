
#include <bits/stdc++.h>
using namespace std;

#define LL long long 
#define ull unsigned long long
#define pb(x) push_back(x)
#define f first
#define s second
#define mp(x,y) make_pair(x,y)
#define fo(i, n) for (LL i = 0; i < n; i++)
#define INF 10e9+7
#define PI 3.14159265
#define bpl __builtin_popcountll
#define gcd __gcd 
typedef pair<LL,LL> ii;
typedef vector<LL> vi;

void solve(){

	LL n,k;
	cin >> n;
	vi num(n);
	for(LL i=0;i<n;i++)cin >> num[i];
	cin >> k;
	int grid[k+1][n+1];
	for(LL i=0;i<=k;i++){
		for(LL j=0;j<=n;j++){
			grid[i][j]=0;
		}
	}

	for(LL i=1;i<=k;i++){
		for(LL j=1;j<=n;j++){
			grid[i][j]=grid[i][j-1];
			if(num[j-1] <= i && num[j-1] > 0){
				grid[i][j] = grid[i][j] + grid[i/num[j-1]][j-1] + 1;
			}
		}
	}
	
	cout << grid[k][n];
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t=1;
	while(t--)solve();
	return 0;
}


