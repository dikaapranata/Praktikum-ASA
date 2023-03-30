
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
	
	10 10
	1 1
	10 10
	13
	4 1
	4 2
	7 3
	9 3
	10 3
	6 4
	1 5
	2 5
	4 6
	3 7
	7 7
	5 9
	5 10
*/

void BFS(){

	LL w,h,inx,iny,enx,eny,n;
	cin >> w >> h;
	/*titik awal*/
	cin >> inx >> iny;
	/*titik akhir*/
	cin >> enx >> eny;
	/*pembutan grid*/
	int grid[h][w],vis[h][w],cost[h][w];
	for(LL i=0;i<h;i++){
		for(LL j=0;j<w;j++){
			grid[i][j] = 0;
			vis[i][j] = 0;
			cost[i][j]=0;
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
	
	/*debug*/
	for(LL i=0;i<h;i++){
		for(LL j=0;j<w;j++){
			cout << cost[i][j] << " ";
		}
		cout << "\n";
	}
//	
//	cout << "\n";
//	for(auto j: parent){
//		cout  << "( "<< j.f.f << " , " << j.f.s << " ) : ( "<< j.s.f << " , " << j.s.s << " )\n";
//	}

}



int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	BFS();	
	return 0;
}
