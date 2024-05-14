#include <iostream>
#include <queue>
using namespace std;

int n, m;

int arr[101][101]; // 입력 저장
int res[101][101]; // 이 칸에 도달하기 위해 지나야 하는 칸의 수 (0이면 방문 안함)

queue<pair<int, int>> q; // bfs 큐

void maze() {
	res[1][1] = 1; // 시작 칸도 포함하므로
	q.push(make_pair(1,1));

        // bfs 진행
	while(!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		int step = res[y][x] + 1; // 지나야 하는 칸의 수는 이전 칸 + 1
		
		if(x < m && arr[y][x + 1] && !res[y][x + 1]) {
			res[y][x + 1] = step;
			q.push(make_pair(x + 1, y));
		}
		if(x > 1 && arr[y][x - 1] && !res[y][x - 1]) {
			res[y][x - 1] = step;
			q.push(make_pair(x - 1, y));
		}
		if(y < n && arr[y + 1][x] && !res[y + 1][x]) {
			res[y + 1][x] = step;
			q.push(make_pair(x, y + 1));
		}
		if(y > 1 && arr[y - 1][x] && !res[y - 1][x]) {
			res[y - 1][x] = step;
			q.push(make_pair(x, y - 1));
		}
	}
}

int main() {
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
                        // 입력이 공백 없이 들어오므로 100의 자리수까지 들어올 수 있음
                        // 오버플로우가 발생하지 않도록 문자로 하나씩 입력받은 후, '0'을 뺀 값을 저장
			char c;
			cin >> c;
			arr[i][j] = c - '0';
		}
	}
	
	maze();
	
	cout << res[n][m]; // (n, m)에 저장된 정답을 출력
}
