#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	priority_queue<int, vector<int>, greater<int>> qu; // 우선순위 큐, 오름차순 출력
	
	int n;
	cin >> n;
	
	int x;
	
	for(int i = 0; i < n; i++) {
		cin >> x;
		if(x == 0) {
			if(qu.empty()) cout << 0 << '\n'; // 입력이 0이고 큐가 비어있으면 0 출력
			else {
				cout << qu.top() << '\n'; // 아니면 가장 작은 값 출력
				qu.pop();
			}
		} else {
			qu.push(x); // 입력이 0이 아니면 큐에 삽입
		}
	}
}
