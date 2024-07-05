#include <iostream>
#include <cstring>
using namespace std;

int n;
char arr[101][101];
bool checked[101][101] = {false, };

void dfs(int x, int y) { // 깊이 우선 탐색
	checked[x][y] = true;

        // 상하좌우 검사
	if(x > 0) {
		if((arr[x][y] == arr[x - 1][y]) && !checked[x - 1][y]) dfs(x - 1, y);
	}
	if(x < n - 1) {
		if((arr[x][y] == arr[x + 1][y]) && !checked[x + 1][y]) dfs(x + 1, y);
	}
	if(y > 0) {
		if((arr[x][y] == arr[x][y - 1]) && !checked[x][y - 1]) dfs(x, y - 1);
	}
	if(y < n - 1) {
		if((arr[x][y] == arr[x][y + 1]) && !checked[x][y + 1]) dfs(x, y + 1);
	}
}

int main() {
	cin >> n;
	
	string tmp;
	
	for(int i = 0; i < n; i++) {
		cin >> tmp; // 문자열을 입력받고
		for(int j = 0; j < n; j++) {
			arr[i][j] = tmp[j]; // 문자로 저장
		}
	}
	
	int cnt = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(!checked[i][j]) { // 방문하지 않았으면
				dfs(i, j); // 탐색 시작
				cnt++; // 같은 색끼리 인접해있는 구역을 모두 방문했으므로 개수 + 1
			}
		}
	}
	
	cout << cnt << ' '; // 색약이 아닌 사람의 결과 출력
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			checked[i][j] = false; // 방문 배열 초기화
			if(arr[i][j] == 'G') arr[i][j] = 'R'; // 녹색이면 적색으로 변환
		}
	}
	
	cnt = 0; // 개수 초기화
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(!checked[i][j]) {
				dfs(i, j);
				cnt++;
			}
		}
	}
	
	cout << cnt; // 색약자의 결과 출력
}
