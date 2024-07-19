#include <iostream>
#include <queue>
using namespace std;

int arr[101]; // 해당 칸의 뱀, 사다리가 향하는 위치 저장
int cnt[101]; // 각 칸으로 가기 위해 주사위를 굴려야 하는 최수 횟수

queue<int> num;

void bfs() {
	while(!num.empty()) { // 큐가 빌 때까지
		int x = num.front();
		num.pop();
		
		if(arr[x] != 0) { // 뱀이나 사다리가 있는 칸일 경우
                        // 연결된 칸은 주사위를 굴릴 필요가 없으므로, 처음 확인하거나 최수 횟수인 경우 현재 칸의 횟수를 저장
			if(cnt[arr[x]] == 0 || cnt[x] < cnt[arr[x]]) cnt[arr[x]] = cnt[x];
			num.push(arr[x]);
		} else { // 없는 경우
			for(int i = 1; i <= 6; i++) { // 주사위를 굴려 갈 수 있는 칸(1~6칸 뒤)의 횟수를 '현재 칸 + 1'로 저장
				if(x + i < 101) {
					if(cnt[x + i] == 0 || cnt[x] + 1 < cnt[x + i]) {
						cnt[x + i] = cnt[x] + 1;
						num.push(x + i);
					}
				}
			}
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	
	int x;
	for(int i = 0; i < n; i++) {
		cin >> x;
		cin >> arr[x];
	}
	
	for(int i = 0; i < m; i++) {
		cin >> x;
		cin >> arr[x];
	}
	
	cnt[1] = 0; // 첫 번째 칸은 주사위를 굴릴 필요가 없음
	num.push(1);
	
	bfs();
	
	cout << cnt[100];
}
