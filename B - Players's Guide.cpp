
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

vector<ii> tbl;

/*
	7
	7500 264
	8800 130
	5600 205
	2200 155
	16500 270
	5000 192
	18000 250
	20000
	
	6
	100 60006
	250 153643
	300 127346
	500 177013
	850 211349
	50 40061
	1000
	
	6
	10 73738
	12 87497
	13 49793
	6 989947
	76 99894874
	20 847848
	1010
	
	3
	10 300
	21 800
	25 900
	40
	
*/

vi res;

LL val(LL n,LL budget){
	if(n<0||budget==0)
		return 0;
	else if(tbl[n].f > budget)
		return val(n-1,budget);
	else{
		LL temp1 = val(n-1,budget);
		LL temp2 = tbl[n].s + val(n-1,budget-tbl[n].f);
		LL result = max(temp1,temp2);
		res.pb(result);
		return result;
	}
}

void solve(){

	LL n,budget;
	cin >> n;
	fo(i,n){
		LL cost,val;
		cin >> cost >> val;
		tbl.pb(mp(cost,val));
	}
	cin >> budget;
	LL result = val(n-1,budget);
//	fo(i,res.size())cout << res[i] << " ";
	cout << result;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	solve();
	return 0;
}


