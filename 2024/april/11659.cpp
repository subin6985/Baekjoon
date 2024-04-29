#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);  // c 입출력(scanf, printf)을 사용하지 못하는 대신 입출력 속도 빨라짐
	cin.tie(NULL);  // cin과 cout을 묶어주는 작업 생략 -> 시간 절약
	cout.tie(NULL);
	
	int n, m;
	cin >> n >> m;
	
	int arr[100000];
	long sum[100000];
	sum[1] = 0;
	for(int i = 0; i < n; i++) {
		if(i != 0) sum[i + 1] = sum[i];
		cin >> arr[i];
		sum[i + 1] += arr[i];  // 1 ~ i번째 수의 합 저장
	}
	
	int a, b;
	for(int j = 0; j < m; j++) {
		cin >> a >> b;
		if(a == 1) {  // a가 1일 경우
			cout << sum[b] << "\n";  // 1 ~ b번째 수의 합 출력
		} else {
			cout << sum[b] - sum[a - 1] << "\n";  // (a ~ b번째 수의 합) = (b번째까지의 합) - (a - 1번째까지의 합)
		}
	}
}
