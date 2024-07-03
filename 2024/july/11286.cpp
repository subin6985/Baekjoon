#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

struct Compare { // 절댓값 오름차순 > 그냥 값 오름차순 정렬
	bool operator()(pair<int, int> const& p1, pair<int, int> const& p2) {
		if(abs(p1.first) == abs(p2.first)) { // 절댓값이 같다면
			return p1.second > p2.second; // 음수 먼저 정렬
		}
		
		return abs(p1.first) > abs(p2.first); // 절댓값이 작은 순으로 정렬
	}
};

int main() {
	int n;
	
	cin >> n;
	
	priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> numbers;
	
	int x;
	
	for(int i = 0; i < n; i++) {
		cin >> x;
		
		if(x == 0) { // 입력이 0일 때
			if(numbers.empty()) { // 큐가 비어있으면
				cout << 0 << '\n'; // 0 출력
			} else {
				if(numbers.top().second < 0) { // 그냥 값이 음수면
					cout << numbers.top().second << '\n'; // 음수 출력
				} else {
					cout << numbers.top().first << '\n';
				}
				numbers.pop();
			}
		} else {
			numbers.push(make_pair(abs(x), x)); // 첫 번째 값은 절댓값으로, 두 번째 값은 그냥 값으로 넣기
		}
	}
}
