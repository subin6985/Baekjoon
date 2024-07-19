#include <iostream>
using namespace std;

int main() {
	int n, t, p;
	int arr[6];
	
	cin >> n;
	
	for(int i = 0; i < 6; i++) {
		cin >> arr[i]; // 티셔츠의 사이즈별 신청자 수 저장
	}
	
	int tsum = 0; // 티셔츠 최소 묶음수
	
	cin >> t >> p;
	
	for(int i = 0; i < 6; i++) {
		if(arr[i] % t == 0) tsum += arr[i] / t; // 나누어떨어지면 (나눗셈 결과)를 더하고
		else tsum += (arr[i] / t) + 1; // 나누어떨어지지 않으면 (나눗셈 결과 + 1)을 더함
	}
	
	cout << tsum << '\n';
	
	int psum = n / p; // 펜 최소 묶음수
	
	cout << psum << ' ' << n - psum * p;
}
