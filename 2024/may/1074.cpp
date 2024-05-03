#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

// 배열을 사용하면 메모리 초과가 발생해서 사용하지 않음
int N, r, c;

int num = 0; // 방문 순서

void divZ(int x, int y, int n) {
	if(n == 2) { // 분할한 한 변의 길이가 2일 때
		if(r == y) { // 행 값이 y값과 같을 경우
			if(c == x) cout << num; // 열 값과 x값도 같다면 num 그대로 출력
			else cout << num + 1; // 아니라면(c == x + 1) num + 1 출력
		} else { // (r == y + 1)일 경우
			if(c == x) cout << num + 2;
			else cout << num + 3; // (c == x + 1)일 경우
		}
	} else { // 분할한 한 변의 길이가 2보다 클 때
		int size = log2(n) - 1; // 분할했을 때 각 구역의 첫 번째 칸의 방문 순서는 4^(size)*(z 모양으로 방문하는 순서)임
		n /= 2; // 또 분할하기 위해 변의 길이를 2로 나누어 저장
		if(r >= y && r < y + n) { // 구하고자 하는 열 값이 상단에 있을 때
			if(c >= x && c < x + n) { // 구하고자 하는 행 값이 좌측에 있을 때
				divZ(x, y, n); // 좌측상단 구역은 첫 번째 칸의 방문 순서와 x, y 값에 변동 없음
			} else { // 행 값이 우측에 있을 때
				num += pow(4, size); // 우측상단 구역의 첫 번째 칸의 방문 순서 (좌측상단 구역에 먼저 방문하므로)
				divZ(x + n, y, n); // x값을 변의 길이만큼 증가
			}
		} else { // 열 값이 하단에 있을 때
			if(c >= x && c < x + n) {
				num += (pow(4, size) * 2); // 좌측하단 구역의 첫 번째 칸의 방문 순서 (좌측상단, 우측상단 구역에 먼저 방문하므로)
				divZ(x, y + n, n); // y값을 변의 길이만큼 증가
			} else {
				num += (pow(4, size) * 3); // 우측하단 구역의 첫 번째 칸의 방문 순서 (이 구역에 가장 마지막에 방문하므로)
				divZ(x + n, y + n, n); // x, y값을 변의 길이만큼씩 증가
			}
		}
	}
}

int main() {
	cin >> N >> r >> c;
	
	int size = pow(2, N); // 한 변의 크기
	
	divZ(0, 0, size); // 분할하지 않은 전체 상태에서 탐색 시작
}
