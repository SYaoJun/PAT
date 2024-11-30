/*
1. 时间复杂度
2. 空间复杂度
3. 实现思路: Dijkstra + DFS
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>

const int N = 505;
const int INF = 0x3f3f3f3f;
int m, n, s, D, cntPath = 0, optN = 0;

int G[N][N];
int c[N], d[N], vis[N];
std::vector<int> pre[N], path, optPath;
void Dijkstra(){
	memset(d, 0x3f, sizeof(d)); //最短距离置为无穷大 
	memset(vis, 0, sizeof(vis));
	d[s] = 0;
	for(int i = 0; i < n; i++){ //循环N次 
		int t = -1;
		for(int j = 0; j < n; j++){
			if(!vis[j] &&(t==-1 || d[t] > d[j])){
				t = j;
			}
		}
		if(t == -1) return;
		vis[t] = 1;
		for(int j = 0; j < n; j++){
			if(!vis[j]){
				if(d[t] + G[t][j] < d[j]){
					pre[j].clear(); 
					d[j] = d[t] + G[t][j];
					pre[j].push_back(t);
				}else if(d[t] + G[t][j] == d[j]){
					pre[j].push_back(t);
				} 
			}
		}
	} 
}
void dfs(int u){
	if(u == s){
		cntPath++;
		path.push_back(u);
		int tmpN = 0;
		for(int j = 0; j < path.size(); j++){
			int v = path[j];
			tmpN += c[v];
		}
		if(tmpN > optN){
			optN = tmpN;
			optPath = path;
		}
		path.pop_back();
		return;
	}
	path.push_back(u);
	for(int j = 0; j < pre[u].size(); j++){
		int v = pre[u][j];
		dfs(v);
	}
	path.pop_back();
}
int main() {
	int x, u, v, w;
	memset(G, 0x3f, sizeof G);
	scanf("%d%d%d%d", &n, &m, &s, &D);
	for(int i = 0; i < n; i++){
		scanf("%d", &c[i]);
	}
	
	for(int i = 0; i < m; i++){
		scanf("%d%d%d", &u, &v, &w); //读入边的时候需要注意 
		G[v][u] = G[u][v] = w; //是无向图 
	}
	Dijkstra();
	dfs(D);
	printf("%d %d\n", cntPath, optN);
	for(int j = optPath.size()-1; j >= 0 ; j--){
		printf("%d", optPath[j]);
		if(j) printf(" ");
	}
	return 0;
}