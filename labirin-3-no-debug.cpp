
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

/*
	test case : 
	5 5
	2 2
	4 4
	2
	3 3
	4 2
	
	5 5
	3 3
	5 5
	2
	3 3
	4 2
	
	3 3
	1 1
	3 3
	0
*/

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
	
	/*initialisasi array*/
	for(LL i=0;i<h;i++){
		for(LL j=0;j<w;j++){
			grid[i][j] = 0;
			vis[i][j]  = 0;
			cost[i][j] = 0;
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
	
	/*urutan : kanan -> bawah -> kiri -> atas */
	
	/*====== BFS ======*/
	LL path=0;
	ii init={inx,iny};
	vis[iny-1][inx-1]=1;
	queue<ii> que;
	que.push(init);
	while(que.size() > 0){
		ii curr = que.front();
		que.pop();
		vis[curr.s-1][curr.f-1]=1;
		
		/*cek nilai tujuan*/
		if(vis[eny-1][enx-1]==1)break;
		
		/*cek tetangga*/
		/*kanan*/
		if(curr.f-1+1 < w && curr.f-1+1 >=0){
			if(vis[curr.s-1][curr.f-1+1]==0 && grid[curr.s-1][curr.f-1+1]==0){
				cost[curr.s-1][curr.f-1+1]=cost[curr.s-1][curr.f-1]+1;
				vis[curr.s-1][curr.f-1+1]=1;
				/*menunjukan arah */
				dir[curr.s-1][curr.f-1+1]='r';
				/*nilai X lalu nilai Y*/
				que.push(mp(curr.f+1,curr.s));
				/*membuat parent*/
				ii temp = {curr.f+1,curr.s};
				parent[temp]={curr.f,curr.s};
				/*cek nilai tujuan*/
				if(vis[eny-1][enx-1]==1)break;
			}
		}
		/*bawah*/
		if(curr.s-1+1 < h && curr.s-1+1 >=0){
			if(vis[curr.s-1+1][curr.f-1]==0 && grid[curr.s-1+1][curr.f-1]==0){
				cost[curr.s-1+1][curr.f-1]=cost[curr.s-1][curr.f-1]+1;
				vis[curr.s-1+1][curr.f-1]=1;
				/*menunjukan arah */
				dir[curr.s-1+1][curr.f-1]='d';
				/*nilai X lalu nilai Y*/
				que.push(mp(curr.f,curr.s+1));
				/*membuat parent*/
				ii temp = {curr.f,curr.s+1};
				parent[temp]={curr.f,curr.s};
				/*cek nilai tujuan*/
				if(vis[eny-1][enx-1]==1)break;
			}
		}
		/*kiri*/
		if(curr.f-1-1 < w && curr.f-1-1 >=0){
			if(vis[curr.s-1][curr.f-1-1]==0 && grid[curr.s-1][curr.f-1-1]==0){
				cost[curr.s-1][curr.f-1-1]=cost[curr.s-1][curr.f-1]+1;
				vis[curr.s-1][curr.f-1-1]=1;
				/*menunjukan arah */
				dir[curr.s-1][curr.f-1-1]='l';
				/*nilai X lalu nilai Y*/
				que.push(mp(curr.f-1,curr.s));
				/*membuat parent*/
				ii temp = {curr.f-1,curr.s};
				parent[temp]={curr.f,curr.s};
				/*cek nilai tujuan*/
				if(vis[eny-1][enx-1]==1)break;
			}
		}
		/*atas*/
		if(curr.s-1-1 < h && curr.s-1-1 >=0){
			if(vis[curr.s-1-1][curr.f-1]==0 && grid[curr.s-1-1][curr.f-1]==0){
				cost[curr.s-1-1][curr.f-1]=cost[curr.s-1][curr.f-1]+1;
				vis[curr.s-1-1][curr.f-1]=1;
				/*menunjukan arah */
				dir[curr.s-1-1][curr.f-1]='u';
				/*nilai X lalu nilai Y*/
				que.push(mp(curr.f,curr.s-1));
				/*membuat parent*/
				ii temp = {curr.f,curr.s-1};
				parent[temp]={curr.f,curr.s};
				/*cek nilai tujuan*/
				if(vis[eny-1][enx-1]==1)break;
			}
		}
	}
	
	/*menghitung jumlah node yang sudah di kunjungi kecuali tujuan*/
	for(LL i=0;i<h;i++){
		for(LL j=0;j<w;j++){
			if(vis[i][j]==1)path++;
		}
	}
	
	/*cast dan path*/
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
	
	
	/*=====================================================================================*/
	
	/*inisialisasi untuk algo DFS*/
	/*pembutan grid*/
	for(LL i=0;i<h;i++){
		for(LL j=0;j<w;j++){
			vis[i][j]  = 0;
			cost[i][j] = 0;
		}
	}
	
	/*array arah gerak*/
	for(LL i=0;i<h;i++){
		for(LL j=0;j<w;j++){
			dir[i][j] = '*';
		}
	}	
	
	/*digunakan untuk backtracking*/
	parent.clear();
	
	
	
	/*====== DFS ======*/
	path=0;
	init={inx,iny};
	vis[iny-1][inx-1]=1;
	stack<ii> stk;
	stk.push(init);
	while(stk.size() > 0){
		ii curr = stk.top();
		stk.pop();
		vis[curr.s-1][curr.f-1]=1;
		
		/*cek nilai tujuan*/
		if(vis[eny-1][enx-1]==1)break;
		
		/*cek tetangga - urutan di balik karena merupakan stack*/
		/*atas*/
		if(curr.s-1-1 < h && curr.s-1-1 >=0){
			if(vis[curr.s-1-1][curr.f-1]==0 && grid[curr.s-1-1][curr.f-1]==0){
				cost[curr.s-1-1][curr.f-1]=cost[curr.s-1][curr.f-1]+1;
				/*menunjukan arah */
				dir[curr.s-1-1][curr.f-1]='u';
				/*nilai X lalu nilai Y*/
				stk.push(mp(curr.f,curr.s-1));
				/*membuat parent*/
				ii temp = {curr.f,curr.s-1};
				parent[temp]={curr.f,curr.s};
			}
		}
		/*kiri*/
		if(curr.f-1-1 < w && curr.f-1-1 >=0){
			if(vis[curr.s-1][curr.f-1-1]==0 && grid[curr.s-1][curr.f-1-1]==0){
				cost[curr.s-1][curr.f-1-1]=cost[curr.s-1][curr.f-1]+1;
				/*menunjukan arah */
				dir[curr.s-1][curr.f-1-1]='l';
				/*nilai X lalu nilai Y*/
				stk.push(mp(curr.f-1,curr.s));
				/*membuat parent*/
				ii temp = {curr.f-1,curr.s};
				parent[temp]={curr.f,curr.s};
			}
		}
		/*bawah*/
		if(curr.s-1+1 < h && curr.s-1+1 >=0){
			if(vis[curr.s-1+1][curr.f-1]==0 && grid[curr.s-1+1][curr.f-1]==0){
				cost[curr.s-1+1][curr.f-1]=cost[curr.s-1][curr.f-1]+1;
				/*menunjukan arah */
				dir[curr.s-1+1][curr.f-1]='d';
				/*nilai X lalu nilai Y*/
				stk.push(mp(curr.f,curr.s+1));
				/*membuat parent*/
				ii temp = {curr.f,curr.s+1};
				parent[temp]={curr.f,curr.s};
			}
		}
		/*kanan*/
		if(curr.f-1+1 < w && curr.f-1+1 >=0){
			if(vis[curr.s-1][curr.f-1+1]==0 && grid[curr.s-1][curr.f-1+1]==0){
				cost[curr.s-1][curr.f-1+1]=cost[curr.s-1][curr.f-1]+1;
				/*menunjukan arah */
				dir[curr.s-1][curr.f-1+1]='r';
				/*nilai X lalu nilai Y*/
				stk.push(mp(curr.f+1,curr.s));
				/*membuat parent*/
				ii temp = {curr.f+1,curr.s};
				parent[temp]={curr.f,curr.s};
			}
		}
		
		
		/*mengecek visited tetengga*/
		
		/*kanan*/
		if(curr.f-1+1 < w && curr.f-1+1 >=0){
			if(vis[curr.s-1][curr.f-1+1]==0 && grid[curr.s-1][curr.f-1+1]==0){
				vis[curr.s-1][curr.f-1+1]=1;
				/*cek nilai tujuan*/
				if(vis[eny-1][enx-1]==1)break;
				
			}
		}
		
		/*bawah*/
		if(curr.s-1+1 < h && curr.s-1+1 >=0){
			if(vis[curr.s-1+1][curr.f-1]==0 && grid[curr.s-1+1][curr.f-1]==0){
				vis[curr.s-1+1][curr.f-1]=1;
				/*cek nilai tujuan*/
				if(vis[eny-1][enx-1]==1)break;
			}
		}
		
		/*kiri*/
		if(curr.f-1-1 < w && curr.f-1-1 >=0){
			if(vis[curr.s-1][curr.f-1-1]==0 && grid[curr.s-1][curr.f-1-1]==0){
				vis[curr.s-1][curr.f-1-1]=1;
				/*cek nilai tujuan*/
				if(vis[eny-1][enx-1]==1)break;
			}
		}
		
		/*atas*/
		if(curr.s-1-1 < h && curr.s-1-1 >=0){
			if(vis[curr.s-1-1][curr.f-1]==0 && grid[curr.s-1-1][curr.f-1]==0){
				vis[curr.s-1-1][curr.f-1]=1;
				/*cek nilai tujuan*/
				if(vis[eny-1][enx-1]==1)break;
			}
		}
	}
	
	/*menghitung jumlah node yang sudah di kunjungi kecuali tujuan*/
	for(LL i=0;i<h;i++){
		for(LL j=0;j<w;j++){
			if(vis[i][j]==1)path++;
		}
	}
	
	/*cost dan path*/
	cout << cost[eny-1][enx-1] << " ";
	cout << path-1 << " ";
	
	/*backtracking*/
	node = {enx,eny};
	string temp2 = "";
	while(node.f!=inx || node.s!=iny){
		char mv = dir[node.s-1][node.f-1];
		temp2.pb(mv);
		node = parent[node];
	}
	reverse(temp2.begin(),temp2.end());
	cout << temp2 <<"\n";
	
	/*============================================================================================*/
	
	/*inisialisasi untuk algo A star*/
	/*pembutan grid*/
	for(LL i=0;i<h;i++){
		for(LL j=0;j<w;j++){
			vis[i][j]  = 0;
			cost[i][j] = 0;
		}
	}
	
	/*array arah gerak*/
	for(LL i=0;i<h;i++){
		for(LL j=0;j<w;j++){
			dir[i][j] = '*';
		}
	}	
	
	/*digunakan untuk backtracking*/
	parent.clear();
	
	/*====== A star ======*/
	
	/*array nilai heuristic*/
	int heur[h][w];
	/*manhattan distance*/
	for(LL i=0;i<h;i++){
		for(LL j=0;j<w;j++){
			heur[i][j] = abs(eny-i-1) + abs(enx-j-1);
		}
	}	
	
	/*urutan : kanan -> bawah -> kiri -> atas */
	
	/*A star*/
	init = {inx,iny};
	vis[iny-1][inx-1]=1;
	/*menghitung nilai total node awal*/
	totd[iny-1][inx-1]=heur[iny-1][inx-1];
	/*array tempat node yang akan di kunjungi*/
	vector<ii> plc;
	plc.pb(init);
	while(plc.size() > 0){
		/*mencari nilia terkecil*/
		ii curr;
		LL minv=INF;
		LL idx=0;
		/*di cari dari nilai akhir ke nilai awal karena di prioritaskan nilai yang paling kecil dan baru masuk ke array*/
		for(LL i=plc.size()-1;i>=0;i--){
			ii temp = plc[i];
			if(totd[temp.s-1][temp.f-1] < minv){
				minv = totd[temp.s-1][temp.f-1];
				curr = plc[i];
				idx=i;
			}
		}
		/*menghapus element*/
		plc.erase(plc.begin()+idx);
		
		vis[curr.s-1][curr.f-1]=1;
		/*cek apakah end goal sudah tercapai*/
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
				totd[curr.s-1][curr.f-1+1]=cost[curr.s-1][curr.f-1+1]+heur[curr.s-1][curr.f-1+1];
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
				totd[curr.s-1+1][curr.f-1]=cost[curr.s-1+1][curr.f-1]+heur[curr.s-1+1][curr.f-1];
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
				totd[curr.s-1][curr.f-1-1]=cost[curr.s-1][curr.f-1-1]+heur[curr.s-1][curr.f-1-1];
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
				totd[curr.s-1-1][curr.f-1]=cost[curr.s-1-1][curr.f-1]+heur[curr.s-1-1][curr.f-1];
				LL cntt=totd[curr.s-1-1][curr.f-1];
				neig.pb(mp(cntt,mp(curr.f,curr.s-1)));
				/*cek nilai tujuan*/
				if(vis[eny-1][enx-1]==1)break;
			}
		}
		
		/*masukkan node tetangga*/
		for(LL i=neig.size()-1;i>=0;i--){
			plc.pb(neig[i].s);
		}
		
	}
	
	path=0;
	/*menghitung jumlah node yang sudah di kunjungi*/
	for(LL i=0;i<h;i++){
		for(LL j=0;j<w;j++){
			if(vis[i][j])path++;
		}
	}
	
	/*cost dan path*/
	cout << cost[eny-1][enx-1] << " ";
	cout << path-1 << " ";
	
	/*backtracking*/
	node = {enx,eny};
	string temp3 = "";
	while(node.f!=inx || node.s!=iny){
		char mv = dir[node.s-1][node.f-1];
		temp3.pb(mv);
		node = parent[node];
	}
	reverse(temp3.begin(),temp3.end());
	cout << temp3 <<"\n";
	

}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	solve();
	return 0;
}

