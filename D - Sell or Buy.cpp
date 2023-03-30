
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

	LL n;
	cin >> n;
	vi num(n);
	for(LL i=0;i<n;i++)cin >> num[i];
	LL l=n-1,r=n-1;
	vector<ii> pos;
	LL maxv = 0;
	for(LL i=n-2;i>=0;i--){
		maxv = max(maxv,num[i+1]);
		if(num[i] < maxv){
			l--;
		}else{
			pos.pb(mp(l,r));
			l--;
			r=l;
		}
	}
	if(r>l)pos.pb(mp(l,r));
	LL res=0;
	for(LL i=0;i<pos.size();i++){
		LL cnt=0,tot=0;
		for(LL j=pos[i].f;j<pos[i].s;j++){
			tot+=num[j];
			cnt++;
		}
		res+=(cnt*num[pos[i].s]-tot);
	}
	
	cout << res;

	
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	solve();
	return 0;
}


