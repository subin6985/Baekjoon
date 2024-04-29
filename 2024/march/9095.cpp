#include <iostream>
using namespace std;

int main() {
	int t, n;
	cin >> t;
	
	int arr[12]; // 1~11을 만드는 가짓수를 배열에 저장
	arr[1] = 1; // 1
	arr[2] = 2; // 1+1, 2
	arr[3] = 4; // 1+1+1, 1+2, 2+1
	
	for(int i = 4; i < 12; i++) {
		arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3]; // (i - n)을 만드는 방법에서 n씩 더해주기만 하면 i가 됨 (1 <= n <= 3)
	}
	
	for(int i = 0; i < t; i++) {
		cin >> n;
		cout << arr[n] << endl;
	}
}
