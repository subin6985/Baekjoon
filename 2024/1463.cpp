#include <iostream>
using namespace std;

int main() {
	int x;
	cin >> x;
	
	int dp[1000000];
	dp[1] = 0; // 1은 0번만에 1로 만들 수 있음
	
	int cnt = 0;
	
	for(int i = 2; i <= x; i++) { // 2부터 x까지의 1을 만드는 연산의 최솟값 저장
		dp[i] = dp[i - 1] + 1; // i에서 1을 빼고 (i - 1)의 방법 따르기 (1을 뺐으니 +1)
		
		if(i % 2 == 0) {
			dp[i] = min(dp[i], dp[i / 2] + 1); // 위의 방법과 2를 나누고 (i / 2)의 방법을 따르는 것 중 연산이 더 적은 방법 선택
		}
		if(i % 3 == 0) {
			dp[i] = min(dp[i], dp[i / 3] + 1); // 위에서 선택된 방법과 i에서 3을 나누고 (i / 3)의 방법을 따르는 것 중 연산 더 적은 방법 선택
		}
	}
	
	cout << dp[x]; // x에서 1을 만드는 연산의 최솟값 출력
}
