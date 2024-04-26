#include <iostream>
using namespace std;

int m, n, k;
int arr[50][50] = {0, }; // 배추 있는 곳은 1

bool checked[50][50] = {false, }; // 확인한 배추는 true
int cnt = 0; // 배추흰지렁이 마리 수

void search(int x, int y) {
	if(arr[x][y] == 1){ // 배추가 있을 경우
		if(!checked[x][y]) { // 이 배추를 확인한 적 없는 경우(먼저 확인한 배추와 연결되어있지 않은 경우)
			checked[x][y] = true; // 확인했음을 저장
			cnt++; // 마리 수 + 1
		}
		
		if(x > 0) { // x좌표가 0 초과일 경우(1을 빼도 괜찮음)
			if(arr[x - 1][y] == 1 && !checked[x - 1][y]) { // arr[x-1][y]에도 아직 확인하지 않은 배추가 심어져 있을 경우
				checked[x - 1][y] = true; // 확인했음을 저장(search 함수로 넘겨도 마리 수 증가 x)
				search(x - 1, y); // 탐색
			}
		}
		if(x < m - 1) { // x좌표가 m - 1 미만일 경우(1을 더해도 괜찮음)
			if(arr[x + 1][y] == 1 && !checked[x + 1][y]) {
				checked[x + 1][y] = true;
				search(x + 1, y);
			}
		}
		if(y > 0) { // y좌표가 0 초과일 경우(1을 빼도 괜찮음)
			if(arr[x][y - 1] == 1 && !checked[x][y - 1]) {
				checked[x][y - 1] = true;
				search(x, y - 1);
			}
		}
		if(y < n - 1) { // y좌표가 n - 1 미만일 경우(1을 더해도 괜찮음)
			if(arr[x][y + 1] == 1 && !checked[x][y + 1]) {
				checked[x][y + 1] = true;
				search(x, y + 1);
			}
		}
	}
}

int main() {
	int c, x, y;
	cin >> c;
	
	for(int i = 0; i < c; i++) {
		cin >> m >> n >> k;

                // 반복문이 돌 때 배추, 확인 배열 초기화
		for(int j = 0; j < m; j++) {
            for(int l = 0; l < n; l++) {
                arr[j][l] = 0;
                checked[j][l] = false;
            }
        }
		
		for(int j = 0; j < k; j++) {
			cin >> x >> y;
			arr[x][y] = 1;
		}
		
		for(int j = 0; j < m; j++) {
			for(int l = 0; l < n; l++) {
				search(j, l); // 한칸씩 탐색
			}
		}
		
		cout << cnt << '\n';
		cnt = 0; // 마리 수 초기화
	}
}
