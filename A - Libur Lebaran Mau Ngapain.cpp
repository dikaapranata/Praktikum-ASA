
#include <bits/stdc++.h>
using namespace std;

#define LL long long 
#define ull unsigned long long
#define pb(x) push_back(x)
#define f first
#define s second
#define mp(x,y) make_pair(x,y)
#define fo(i, n) for (LL i = 0; i < n; i++)
#define INF 10e5+7
#define PI 3.14159265
#define bpl __builtin_popcountll
#define gcd __gcd 
typedef pair<LL,LL> ii;
typedef vector<LL> vi;

/*
	5
	A B C D E
	0 10 15 0 0
	10 0 0 20 35
	15 0 0 25 0
	0 20 25 0 10
	0 35 0 10 0
*/

void solve(){

	LL n;
	cin >> n;
	vector<char> let(n);
	/*input di petakan menjadi angka 0..n-1*/
	for(LL i=0;i<n;i++){
		cin >> let[i];
	}

	/*merupakan grid jarak*/
	int grid[n][n];

	/*node saat ini , jarak dengan tetangga , node tetangga*/
	map<LL,vector<ii>> tree;
	
	/*membuat hashmap koneksi antara node dengan tetangga*/
	for(LL i=0;i<n;i++){
		for(LL j=0;j<n;j++){
			LL dist;
			cin >> grid[i][j];
			dist = grid[i][j];
			if(dist>0){
				/*first merupakan node char dalam int*/
				/*nilai second merupakan jarak antara node saat ini*/
				ii v = {dist,j};
				tree[i].pb(v);
			}
		}
	}
	
	/*nilai sebelum nya*/
	int bef[n];
	
	/*buat nilai pertama dari distance 0*/
	int dis[n],vis[n];
	dis[0]=0;
	/*buat nilai yang lainnya INF*/
	for(LL i=1;i<n;i++)dis[i]=INF;
	for(LL i=0;i<n;i++){
		vis[i]=0;
	}
	/*node pertama*/
	LL init=0;
	queue<LL>que;
	que.push(init);
	while(que.size() > 0){
		LL cur=que.front();
		que.pop();
		vis[cur]=1;
		/*urutan tetangga dari jarak terpendek ke terjauh*/
		sort(tree[cur].begin(),tree[cur].end());
		for(LL i=0;i<tree[cur].size();i++){
			/*hitung jarak terpendek ke tetangga*/
			if(vis[tree[cur][i].s]==0){
				/*update jarak dan node sebelum*/
				if(dis[cur]+tree[cur][i].f < dis[tree[cur][i].s]){
					dis[tree[cur][i].s]=dis[cur]+tree[cur][i].f;
					bef[tree[cur][i].s]=cur;
				}
				que.push(tree[cur][i].s);
			}
		}
	}
	
	cout << "\n";
	for(LL i=0;i<n;i++){
		cout << "Simpul " << let[i] << "(Total Jarak = "<< dis[i] <<") ";
		/*backtrack jalur*/
		string path = "";
		LL node=i;
		while(node!=0){
			path+=let[node];
			node=bef[node];
		}
		path+=let[0];
		reverse(path.begin(),path.end());
		cout << "(Jalur = " << path << ")\n";
	}
	
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	solve();
	return 0;
}


