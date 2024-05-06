#include <iostream>
#include <queue>
using namespace std;

int n, k;
int visit[100001];
// 재귀호출 하면 런타임 초과 돼서 위치와 시간을 함께 담는 큐 이용
// 같은 위치에 또 방문하는 경우는 +1, -1, *2를 하는 경우(1초)보다 오래 걸리므로 신경쓰지 않아도 됨
queue<pair<int, int>> q;

void search(int n) {
	q.push(make_pair(n, 0));
	visit[n] = 1;
	
	while(!q.empty()){
		int x = q.front().first;
		int sec = q.front().second;
		q.pop();
		
		if(x == k) { // 동생을 찾은 경우
			cout << sec;
			break;
		}
		if(x < 100000 && !visit[x + 1]) { // (x + 1)을 방문하지 않은 경우, 큐에 넣고 방문했다고 저장
			q.push(make_pair(x + 1, sec + 1));
			visit[x + 1] = 1;
		}
		if(x > 0 && !visit[x - 1]) {
			q.push(make_pair(x - 1, sec + 1));
			visit[x - 1] = 1;
		}
		if(x * 2 < 100001 && !visit[x * 2]) {
			q.push(make_pair(x * 2, sec + 1));
			visit[x * 2] = 1;
		}
	}
}

int main() {
	cin >> n >> k;
	
	search(n);
}
