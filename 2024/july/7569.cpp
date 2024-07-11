// #7576 토마토와 유사
#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int m, n, h;
int tomato[100][100][100];

int days = 0;
int all_tomatoes;
int ripen_tomatoes = 0;

queue<tuple<int, int, int>> q; // 3개 넣으려면 pair가 아닌 tuple을 써야 함

void bfs() {
	while(!q.empty()) {
		tuple<int, int, int> t = q.front();
		q.pop();

                // tuple 값 차례대로 꺼내기
		int z = get<0>(t);
		int y = get<1>(t);
		int x = get<2>(t);
		
		bool day_count = false;
		
		if(x < m - 1 && tomato[z][y][x + 1] == 0) {
			tomato[z][y][x + 1] = tomato[z][y][x] + 1;
			q.push(make_tuple(z, y, x + 1));
			ripen_tomatoes++;
			day_count = true;
		}
		if(x > 0 && tomato[z][y][x - 1] == 0) {
			tomato[z][y][x - 1] = tomato[z][y][x] + 1;
			q.push(make_tuple(z, y, x - 1));
			ripen_tomatoes++;
			day_count = true;
		}
		if(y < n - 1 && tomato[z][y + 1][x] == 0) {
			tomato[z][y + 1][x] = tomato[z][y][x] + 1;
			q.push(make_tuple(z, y + 1, x));
			ripen_tomatoes++;
			day_count = true;
		}
		if(y > 0 && tomato[z][y - 1][x] == 0) {
			tomato[z][y - 1][x] = tomato[z][y][x] + 1;
			q.push(make_tuple(z, y - 1, x));
			ripen_tomatoes++;
			day_count = true;
		}
		if(z < h - 1 && tomato[z + 1][y][x] == 0) {
			tomato[z + 1][y][x] = tomato[z][y][x] + 1;
			q.push(make_tuple(z + 1, y, x));
			ripen_tomatoes++;
			day_count = true;
		}
		if(z > 0 && tomato[z - 1][y][x] == 0) {
			tomato[z - 1][y][x] = tomato[z][y][x] + 1;
			q.push(make_tuple(z - 1, y, x));
			ripen_tomatoes++;
			day_count = true;
		}
		
		if(day_count) days = tomato[z][y][x] + 1;
	}
}

int main() {
	cin >> m >> n >> h;
	
	all_tomatoes = m * n * h;
	
	for(int i = 0; i < h; i++) {
		for(int j = 0; j < n; j++) {
			for(int k = 0; k < m; k++) {
				cin >> tomato[i][j][k];
				if(tomato[i][j][k] == 1) {
					q.push(make_tuple(i, j, k));
					ripen_tomatoes++;
				}
				if(tomato[i][j][k] == -1) all_tomatoes--;
			}
		}
	}
	
	bfs();
		
	if(ripen_tomatoes == all_tomatoes) {
		if(days == 0) cout << days; // 처음부터 다 익어있을 경우, 0 출력
		else cout << days - 1;
	}
	else cout << -1;
}
