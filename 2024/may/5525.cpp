#include <iostream>
#include <string>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	
	string s;
	cin >> s;
	
	int res = 0; // PN의 개수 (결과)
	int cnt = 0; // 'IOI' 패턴의 개수

        // 처음에는 bool을 이용해 I, O가 맞게 번갈아 나온 횟수를 센 뒤 수학적 규칙으로 PN의 개수를 계산했으나,
        // 그렇게 하면 패턴이 중간에 깨지는 모든 경우를 고려하지 못해 오답이 나왔음
        // 따라서 'IOI'를 묶어 하나로 세기로 함
	for(int i = 1; i < m - 1; i++) {
		if(s[i - 1] == 'I' && s[i] == 'O' && s[i + 1] == 'I') { // 'IOI' 패턴이 있는 경우
			cnt++;
			if(cnt == n) { // 'IOI' 패턴의 개수가 n과 같을 경우
				res++; // 결과를 1 증가시키고
				cnt--; // 패턴의 개수를 1 감소시킴
                                // n = 2일 때, 'IOIOI'(cnt = 2)의 경우
                                // 뒤에 'OI'가 연결되면 PN이 하나 더 있는 것이기 때문에, 앞의 'IO'만 지우는 방식
			}
			i++; // i를 2씩 증가시키기 위해
		} else { // 'IOI'패턴이 이어지지 않는 경우
			cnt = 0; // 패턴의 개수 초기화
		}
	}
	
	cout << res;
}
