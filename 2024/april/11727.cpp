#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	int arr[1001];
	arr[1] = 1;  // |
	arr[2] = 3;  // ||, =, ㅁ
  // arr[3]: |||, =|, ㅁ|, |=, |ㅁ
  // arr[i] = (arr[i - 1] 오른쪽에 |을 붙인 것) + (arr[i - 2] 오른쪽에 = or ㅁ을 붙인 것)
	
	if(n > 2) {
		int m = 3;
		while(m <= n) {
			arr[m] = (arr[m - 1] + arr[m - 2] * 2) % 10007;  // 나머지 연산
			m++;
		}
	}
	
	cout << arr[n];
}
