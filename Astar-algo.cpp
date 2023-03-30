
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

long long gcd(long long int a, long long int b){
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

long long lcm(int a, int b){
    return (a / gcd(a, b)) * b;
}

/*codeForce Round : # (Div. )*/

void solve(){

	LL w,h,inx,iny,enx,eny,n;
	/*lebar dan tinggi*/
	cin >> w >> h;
	/*titik awal*/
	cin >> inx >> iny;
	/*titik akhir*/
	cin >> enx >> eny;
	/*pembutan grid*/
	int grid[h][w],vis[h][w],cost[h][w],totd[h][w];
	for(LL i=0;i<h;i++){
		for(LL j=0;j<w;j++){
			grid[i][j] = 0;
			vis[i][j]  = 0;
			cost[i][j] = 0;
			totd[i][j] = 0;
		}
	}
	
	/*array arah gerak*/
	char dir[h][w];
	for(LL i=0;i<h;i++){
		for(LL j=0;j<w;j++){
			dir[i][j] = '*';
		}
	}	

	/*digunakan untuk backtracking*/
	map<ii,ii> parent;
	
	
	/*obstacle*/
	cin >> n;
	for(LL i=0;i<n;i++){
		LL temx,temy;
		cin >> temx >> temy;
		grid[temy-1][temx-1] = -1;
	}
	
	int heur[h][w];
	/*manhattan distance*/
	for(LL i=0;i<h;i++){
		for(LL j=0;j<w;j++){
			heur[i][j] = abs(eny-i-1) + abs(enx-j-1);
		}
	}	
	
	/*urutan : kanan -> bawah -> kiri -> atas */
	
	/*A star*/
	ii init = {inx,iny};
	vis[iny-1][inx-1]=1;
	totd[iny-1][inx-1]=heur[iny-1][inx-1];
	vector<ii> que;
	que.pb(init);
	while(que.size() > 0){
		/*mencari nilia terkecil*/
		ii curr;
		LL minv=INF;
		LL idx=0;
		for(LL i=que.size()-1;i>=0;i--){
			ii temp = que[i];
			if(totd[temp.s-1][temp.f-1] < minv){
				minv = totd[temp.s-1][temp.f-1];
				curr = que[i];
				idx=i;
			}
		}
		/*menghapus element*/
		que.erase(que.begin()+idx);
		
		vis[curr.s-1][curr.f-1]=1;
		if(vis[eny-1][enx-1]==1)break;
		
		/*nilai tetangga*/
		vector<pair<LL,ii>> neig;
		
		/*tetangga*/
		/*kanan*/
		if(curr.f-1+1 < w && curr.f-1+1 >=0){
			if(vis[curr.s-1][curr.f-1+1]==0 && grid[curr.s-1][curr.f-1+1]==0){
				/*nilai cost g(x)*/
				cost[curr.s-1][curr.f-1+1]=cost[curr.s-1][curr.f-1]+1;
				vis[curr.s-1][curr.f-1+1]=1;
				/*menunjukan arah */
				dir[curr.s-1][curr.f-1+1]='r';
				/*membuat parent*/
				ii temp = {curr.f+1,curr.s};
				parent[temp]={curr.f,curr.s};
				/*nilai total*/
				totd[curr.s-1][curr.f-1+1]=heur[curr.s-1][curr.f-1+1];
				LL cntt=totd[curr.s-1][curr.f-1+1];
				neig.pb(mp(cntt,mp(curr.f+1,curr.s)));
				/*cek nilai tujuan*/
				if(vis[eny-1][enx-1]==1)break;
				
			}
		}
		/*bawah*/
		if(curr.s-1+1 < h && curr.s-1+1 >=0){
			if(vis[curr.s-1+1][curr.f-1]==0 && grid[curr.s-1+1][curr.f-1]==0){
				/*nilai cost g(x)*/
				cost[curr.s-1+1][curr.f-1]=cost[curr.s-1][curr.f-1]+1;
				vis[curr.s-1+1][curr.f-1]=1;
				/*menunjukan arah */
				dir[curr.s-1+1][curr.f-1]='d';
				/*membuat parent*/
				ii temp = {curr.f,curr.s+1};
				parent[temp]={curr.f,curr.s};
				/*nilai total*/
				totd[curr.s-1+1][curr.f-1]=heur[curr.s-1+1][curr.f-1];
				LL cntt=totd[curr.s-1+1][curr.f-1];
				neig.pb(mp(cntt,mp(curr.f,curr.s+1)));
				/*cek nilai tujuan*/
				if(vis[eny-1][enx-1]==1)break;
			}
		}
		/*kiri*/
		if(curr.f-1-1 < w && curr.f-1-1 >=0){
			if(vis[curr.s-1][curr.f-1-1]==0 && grid[curr.s-1][curr.f-1-1]==0){
				/*nilai cost g(x)*/
				cost[curr.s-1][curr.f-1-1]=cost[curr.s-1][curr.f-1]+1;
				vis[curr.s-1][curr.f-1-1]=1;
				/*menunjukan arah */
				dir[curr.s-1][curr.f-1-1]='l';
				/*membuat parent*/
				ii temp = {curr.f-1,curr.s};
				parent[temp]={curr.f,curr.s};
				/*nilai total*/
				totd[curr.s-1][curr.f-1-1]=heur[curr.s-1][curr.f-1-1];
				LL cntt=totd[curr.s-1][curr.f-1-1];
				neig.pb(mp(cntt,mp(curr.f-1,curr.s)));
				/*cek nilai tujuan*/
				if(vis[eny-1][enx-1]==1)break;
			}
		}
		/*atas*/
		if(curr.s-1-1 < h && curr.s-1-1 >=0){
			if(vis[curr.s-1-1][curr.f-1]==0 && grid[curr.s-1-1][curr.f-1]==0){
				/*nilai cost g(x)*/
				cost[curr.s-1-1][curr.f-1]=cost[curr.s-1][curr.f-1]+1;
				vis[curr.s-1-1][curr.f-1]=1;
				/*menunjukan arah */
				dir[curr.s-1-1][curr.f-1]='u';
				/*membuat parent*/
				ii temp = {curr.f,curr.s-1};
				parent[temp]={curr.f,curr.s};
				/*nilai total*/
				totd[curr.s-1-1][curr.f-1]=heur[curr.s-1-1][curr.f-1];
				LL cntt=totd[curr.s-1-1][curr.f-1];
				neig.pb(mp(cntt,mp(curr.f,curr.s-1)));
				/*cek nilai tujuan*/
				if(vis[eny-1][enx-1]==1)break;
			}
		}
		
//		cout << "hi";
		/*push to queue*/
//		sort(neig.begin(),neig.end());
		for(LL i=neig.size()-1;i>=0;i--){
			que.pb(neig[i].s);
		}
		
	}
	
	LL path=0;
	for(LL i=0;i<h;i++){
		for(LL j=0;j<w;j++){
			if(vis[i][j])path++;
		}
	}
	
	cout << cost[eny-1][enx-1] << " ";
	cout << path-1 << " ";
	/*backtracking*/
	ii node = {enx,eny};
	string temp = "";
	while(node.f!=inx || node.s!=iny){
		char mv = dir[node.s-1][node.f-1];
		temp.pb(mv);
		node = parent[node];
	}
	reverse(temp.begin(),temp.end());
	cout << temp <<"\n";
	
	
	
	/*debug*/
	for(LL i=0;i<h;i++){
		for(LL j=0;j<w;j++){
			cout << vis[i][j] << " ";
		}
		cout << "\n";
	}
	
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	solve();
	return 0;
}


