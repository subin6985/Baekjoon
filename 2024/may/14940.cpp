#include <iostream>
#include <queue>
using namespace std;

int n, m;
int arr[1000][1000]; // 입력 받은 좌표 저장
int res[1000][1000]; // 목표까지의 거리 저장

queue<pair<int, int>> q; // bfs를 위한 큐

void bfs() {
	while(!q.empty()) {
                // 현재 좌표 구하고 큐에서 pop
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

                // 현재 좌표에서 목표까지의 거리
		int cnt = res[y][x];
		
		if(x > 0) {
			if(arr[y][x - 1] == 1 && res[y][x - 1] == 0) { // 현재 좌표에서 (x - 1)이 가능하고 방문한 적이 없으면
				res[y][x - 1] = cnt + 1; // 현재 거리 + 1
				q.push(make_pair(x - 1, y)); // 큐에 push
			}
		}
		if(x < m - 1) {
			if(arr[y][x + 1] == 1 && res[y][x + 1] == 0) {
				res[y][x + 1] = cnt + 1;
				q.push(make_pair(x + 1, y));
			}
		}
		if(y > 0) {
			if(arr[y - 1][x] == 1 && res[y - 1][x] == 0) {
				res[y - 1][x] = cnt + 1;
				q.push(make_pair(x, y - 1));
			}
		}
		if(y < n - 1) {
			if(arr[y + 1][x] == 1 && res[y + 1][x] == 0) {
				res[y + 1][x] = cnt + 1;
				q.push(make_pair(x, y + 1));
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	
	int x, y;
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if(arr[i][j] == 2) { // 목표 지점
				x = j;
				y = i;
			}
		}
	}

        // 목표지점부터 bfs 시작
	q.push(make_pair(x, y));
	res[y][x] = 0;
	bfs();
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(res[i][j] == 0 && arr[i][j] == 1) { // 방문한 적이 없는데 갈 수 있는 땅인 경우
				res[i][j] = -1; // 목표에 도달할 수 없는 땅이므로 -1 저장
			}
			cout << res[i][j] << " ";
		}
		cout << "\n";
	}
}
