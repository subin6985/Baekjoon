#include <iostream>
using namespace std;

int n, m;
int arr[1001][1001] = {0, };
int checked[1001] = {false, };

int cnt = 0;

void dfs(int x) { // 깊이 우선 탐색
	if(!checked[x]) {
		cnt++;
		checked[x] = true;
	}
	
	for(int i = 1; i <= n; i++) {
		if(arr[x][i] == 1 && !checked[i]) {
			checked[i] = true;
			dfs(i);
		}
	}
}

int main() {
	cin >> n >> m;
	
	int u, v;
	for(int i = 0; i < m; i++) {
		cin >> u >> v;
		arr[u][v] = 1;
		arr[v][u] = 1;
	}
	
	for(int i = 1; i <= n; i++){ // 1부터 노드들을 순회
		dfs(i);
	}
	
	cout << cnt;
}
