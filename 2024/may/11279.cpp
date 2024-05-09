#include <iostream>
#include <queue>
using namespace std;

int main() {
        // 시간 초과 방지
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	
	priority_queue<int> pq; // 우선순위 큐 (내림차순 정렬)
	
	int x;
	for(int i = 0; i < n; i++) {
		cin >> x;
		if(x == 0) { // 입력값이 0인 경우
			if(pq.empty()) cout << 0 << '\n'; // 큐가 비어있으면 0 출력
			else {
				cout << pq.top() << '\n';
				pq.pop(); // 아니면 가장 큰 값 출력하고 꺼내기
			}
		} else pq.push(x); // 0이 아니면 큐에 넣기
	}
}
