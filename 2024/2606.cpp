#include <iostream>
#include <queue>
using namespace std;


int n, m;
int cnt = 0; // 바이러스 감염된 컴퓨터 개수 (컴퓨터1 제외)
int arr[101][101]; // 컴퓨터들 간의 연결이 있으면 1 저장
bool checked[101] = {false, }; // 바이러스 컴퓨터 개수에 이미 반영한 컴퓨터면 true 저장
queue<int> virus; // 넓이 우선 탐색(bfs)을 위한 큐

void bfs(int x) { // bfs를 위한 함수
	checked[x] = true; // 컴퓨터1 반영
	virus.push(x); // virus: {1}
	
	while(!virus.empty()) { // 큐가 빌 때까지 반복
		x = virus.front(); // 탐색 기준 컴퓨터
		virus.pop(); // 기준 pop
		
		for(int i = 1; i <= n; i++) { // 컴퓨터 수만큼 반복
			if(arr[x][i] == 1 && !checked[i]) { // 기준 컴퓨터와 연결되어 있으며, 반영된 적 없는 경우
				virus.push(i); // 큐에 push
				checked[i] = true; // 반영
				cnt++; // 바이러스 컴퓨터 1 증가
			}
		}
	}
}

int main() {
	cin >> n >> m;
	
	int input1, input2;
	
	for(int i = 0; i < m; i++) {
		cin >> input1 >> input2;

    		// input1-input2가 연결되어 있음을 저장
		arr[input1][input2] = 1;
		arr[input2][input1] = 1;
	}
	
	bfs(1); // 1부터 bfs 수행
	
	cout << cnt;
}
