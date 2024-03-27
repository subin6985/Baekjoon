#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	int stairs[300];
	
	for(int i = 0; i < n; i++) {
		cin >> stairs[i]; // 계단의 점수
	}
	
	
	int score[300];  // i칸을 오를 때의 최댓값 저장
	bool again = true;  // 연속된 칸을 밟아도 되는지
	score[0] = stairs[0];  // 0칸을 오를 때의 최댓값은 0번 칸의 점수
	if(n > 1) {  // 계단이 2칸 이상일 때
		score[1] = score[0] + stairs[1];  // 1칸을 오를 때의 최댓값은 0번 칸 + 1번 칸
		again = false;  // 연속된 칸을 또 밟을 수 없음
	}
	if(n > 2) {  // 계단이 3칸 이상일 때
		score[2] = stairs[0] + stairs[2];  // 0번 칸 + 2번 칸 저장
		again = true;  // 연속된 칸 밟을 수 있음
		if(score[2] < stairs[1] + stairs[2]) {  // 1번 칸 + 2번 칸이 더 큰 경우 (0번 칸 건너뜀)
			score[2] = stairs[1] + stairs[2];
			again = false;  // 연속된 칸을 또 밟을 수 없음
		}
	}
	
	for(int i = 3; i < n; i++) {  계단이 4칸 이상일 때
		score[i] = score[i - 2] + stairs[i];  // 2칸 전까지의 최댓값 + 밟을 칸 저장 (두 계단씩 오르기)
		
		if(again && score[i] < score[i - 1] + stairs[i]) {  // 연속된 칸을 오를 수 있고, 1칸 전까지의 최댓값 + 밟을 칸이 더 큰 경우
			score[i] = score[i - 1] + stairs[i];
			again = false;  // 연속된 칸을 또 밟을 수 없음
		} else if(score[i] < score[i - 3] + stairs[i - 1] + stairs[i]) {  // 3칸 전까지의 최댓값 + 1칸 전 + 밟을 칸이 더 큰 경우 (2칸 전의 계단 건너뜀)
			score[i] = score[i - 3] + stairs[i - 1] + stairs[i];
			again = false;  // 연속된 칸을 또 밟을 수 없음
		} else {
			again = true;  // 위의 조건문들에 해당되지 않는 경우이므로 연속된 칸을 밟을 수 있음
		}
	}
	
	cout << score[n - 1];  // (n - 1)까지 오를 때의 최댓값 출력
}
