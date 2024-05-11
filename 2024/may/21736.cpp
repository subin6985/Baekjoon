#include <iostream>
#include <queue>
using namespace std;

int n, m;
// 캠퍼스 정보
char campus[600][600];
// 방문한 위치는 1로 저장
int visited[600][600];
// 만난 인원수
int cnt = 0;

// bfs용 큐
queue<pair<int, int>> place;

void bfs() {
	while(!place.empty()) {
		int x = place.front().first;
		int y = place.front().second;
		place.pop();

                // x + 1이 가로 크기보다 작고, 벽이 아니며, 방문하지 않은 경우
		if(x < m - 1 && campus[y][x + 1] != 'X' && !visited[y][x + 1]) {
			visited[y][x + 1] = 1; // 방문 저장
			place.push(make_pair(x + 1, y)); // 큐에 푸시
			if(campus[y][x + 1] == 'P') cnt++; // 사람이면 인원수 증가
		}
		if(x > 0 && campus[y][x - 1] != 'X' && !visited[y][x - 1]) {
			visited[y][x - 1] = 1;
			place.push(make_pair(x - 1, y));
			if(campus[y][x - 1] == 'P') cnt++;
		}
		if(y < n - 1 && campus[y + 1][x] != 'X' && !visited[y + 1][x]) {
			visited[y + 1][x] = 1;
			place.push(make_pair(x, y + 1));
			if(campus[y + 1][x] == 'P') cnt++;
		}
		if(y > 0 && campus[y - 1][x] != 'X' && !visited[y - 1][x]) {
			visited[y - 1][x] = 1;
			place.push(make_pair(x, y - 1));
			if(campus[y - 1][x] == 'P') cnt++;
		}
	}
}

int main() {
	cin >> n >> m;

        // 도연이의 처음 위치
	int x, y;
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> campus[i][j];
			if(campus[i][j] == 'I') { // 도연이의 처음 위치 저장
				x = j;
				y = i;
			}
		}
	}
	
	place.push(make_pair(x, y));
	visited[y][x] = 1;
	bfs();
	
	if(cnt == 0) cout << "TT"; // 아무도 만나지 못한 경우
	else cout << cnt;
}
