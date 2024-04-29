#include <iostream>
#include <queue>
using namespace std;

int n;
int arr[1001][1001] = {0, };
int checked[1001] = {false, };

queue<int> bfsQueue;

// 깊이 우선 탐색
void dfs(int x) {
	if(!checked[x]) {
		cout << x << " ";
		checked[x] = true;
		
		for(int i = 1; i <= n; i++) {
			if(arr[x][i] == 1) dfs(i);
		}
	}
}

// 너비 우선 탐색
void bfs(int x) {
	checked[x] = true;
	bfsQueue.push(x);
	
	while(!bfsQueue.empty()) {
		x = bfsQueue.front();
		cout << x << " ";
		bfsQueue.pop();
		
		for(int i = 1; i <= n; i++) {
			if(arr[x][i] == 1 && !checked[i]) {
				bfsQueue.push(i);
				checked[i] = true;
			}
		}
	}
}

int main() {
	int m, v;
	cin >> n >> m >> v;
	
	int a, b;
	for(int i = 0; i < m; i++) {
		cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}
	
	dfs(v);
	cout << '\n';

        // 깊이 우선 탐색 후, 확인한 정점 초기화
	for(int i = 1; i <= n; i++) {
		checked[i] = false;
	}
	
	bfs(v);
}
