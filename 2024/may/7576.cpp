#include <iostream>
#include <queue>
using namespace std;

int m, n;
int tomato[1000][1000]; // 이 토마토가 익는 데 걸린 일수 저장
// 익은 토마토가 1로 입력되어 첫날을 1로 계산하므로 결과는 1 빼야 함
int checked[1000][1000]; // 토마토 확인 여부
int days = 0; // 다 익는 데 걸린 일수 (1 빼고 출력해야 함)

int count_of_tomatoes; // 총 토마토 수
int count_of_roated = 0; // 익은 토마토 수
bool done = false; // 모든 토마토가 다 익었는지 확인

queue<pair<int, int>> q; // bfs를 위한 큐

void bfs() {
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		bool day_count = false; // 이미 사방이 다 검사한 토마토거나, 토마토가 없을 땐 날짜를 증가하지 않기 위해
		
		if(x < m - 1 && tomato[y][x + 1] == 0 && checked[y][x + 1] == 0) { // 주위 토마토가 익지 않은 상태
			tomato[y][x + 1] = tomato[y][x] + 1; // 일수 + 1 하여 저장
			checked[y][x + 1] = 1;
			q.push(make_pair(x + 1, y)); // 큐에 푸시
			count_of_roated++; // 익은 토마토 수 + 1
			day_count = true; // 토마토가 익었으므로 유효한 날짜
		}
		if(x > 0 && tomato[y][x - 1] == 0 && checked[y][x - 1] == 0) {
			tomato[y][x - 1] = tomato[y][x] + 1;
			checked[y][x - 1] = 1;
			q.push(make_pair(x - 1, y));
			count_of_roated++;
			day_count = true;
		}
		if(y < n - 1 && tomato[y + 1][x] == 0 && checked[y + 1][x] == 0) {
			tomato[y + 1][x] = tomato[y][x] + 1;
			checked[y + 1][x] = 1;
			q.push(make_pair(x, y + 1));
			count_of_roated++;
			day_count = true;
		}
		if(y > 0 && tomato[y - 1][x] == 0 && checked[y - 1][x] == 0) {
			tomato[y - 1][x] = tomato[y][x] + 1;
			checked[y - 1][x] = 1;
			q.push(make_pair(x, y - 1));
			count_of_roated++;
			day_count = true;
		}
		
		if(day_count) days = tomato[y][x] + 1; // 유효한 날짜인 경우 최종 날짜 + 1
		
		if(count_of_tomatoes == count_of_roated) { // 익은 토마토 수와 익은 토마토 수가 같아진 경우
			done = true;
			break;
		}
	}
}

int main() {
	cin >> m >> n;
	
	count_of_tomatoes = m * n; // 총 토마토 수
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> tomato[i][j];
			if(tomato[i][j] == 1) count_of_roated++; // 익은 토마토를 입력 받으면 수 증가
			else if(tomato[i][j] == -1) count_of_tomatoes--; // 토마토가 없는 칸을 입력 받으면 수 감소
		}
	}
	
	if(count_of_tomatoes == count_of_roated) cout << 0; // 처음부터 같으면 0 출력
	else {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if(tomato[i][j] == 1 && checked[i][j] == 0) {
					checked[i][j] = 1;
					q.push(make_pair(j, i)); // 익은 토마토 큐에 push
				}
			}
		}
		
		bfs();
		if(!done) cout << -1; // bfs를 해도 수가 같아지지 않은 경우 -1 출력
		else cout << days - 1; // 최종 날짜 출력
	}
}
