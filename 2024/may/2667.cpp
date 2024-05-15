#include <iostream>
#include <queue>
using namespace std;

int n;
int map[25][25]; // 입력을 저장하는 배열
int visited[25][25]; // 방문 여부를 저장하는 배열
queue<pair<int, int>> q; // bfs를 위한 큐

int village_num = 0; // 단지 수
priority_queue<int, vector<int>, greater<int>> house_nums; // 단지별 집의 수를 오름차순으로 저장하기 위한 우선순위 큐

void bfs() {
	int cnt = 0; // 집의 수
	while(!q.empty()) {
		int x = q.front().second;
		int y = q.front().first;
		q.pop();
		
		cnt++; // 큐에서 꺼낼 때마다 + 1
		
		if(x < n - 1 && map[y][x + 1] && !visited[y][x + 1]) {
			q.push(make_pair(y, x + 1));
			visited[y][x + 1] = 1;
		}
		if(x > 0 && map[y][x - 1] && !visited[y][x - 1]) {
			q.push(make_pair(y, x - 1));
			visited[y][x - 1] = 1;
		}
		if(y < n - 1 && map[y + 1][x] && !visited[y + 1][x]) {
			q.push(make_pair(y + 1, x));
			visited[y + 1][x] = 1;
		}
		if(y > 0 && map[y - 1][x] && !visited[y - 1][x]) {
			q.push(make_pair(y - 1, x));
			visited[y - 1][x] = 1;
		}
	}
	
	house_nums.push(cnt); // 집의 수를 우선순위 큐에 저장
}

int main() {
	cin >> n;
	
	char c;
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> c;
			map[i][j] = c - '0'; // 숫자가 붙어서 입력되므로 문자로 하나씩 받은 후 '0'을 빼서 저장
		}
	}
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(map[i][j] && !visited[i][j]) { // 집이 있고 방문되지 않은 경우
				q.push(make_pair(i, j));
				visited[i][j] = 1;
				bfs(); // bfs 진행
				village_num++; // 단지 수 + 1
			}
		}
	}
	
	cout << village_num << '\n'; // 단지 수 출력
	while(!house_nums.empty()) { // 집의 수 오름차순으로 출력
		cout << house_nums.top() << '\n';
		house_nums.pop();
	}
}
