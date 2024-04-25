#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	int arr[50001];
	arr[1] = 1;  // 1^1
	arr[2] = 2;  // 1^1 + 1^1 = arr[1] + arr[1]
	arr[3] = 3;  // 1^1 + 1^1 + 1^1 = arr[1] + arr[2]
	
	if(n > 3) {
		int m = 4;
		while(m <= n) {
			int l = (int)sqrt(m);  // 루트 m (소수점 이하 버림)
			if(m == l * l) {  // m이 제곱수인 경우
				arr[m] = 1;
			} else {  // 제곱수가 아닌 경우
				int res = 4;
				for(int i = l; i > 0; i--) {  // i = m으로 시작을 하면 제곱수가 아닌 경우까지 탐색하게 되므로 비효율적
					if(arr[i * i] + arr[m - i * i] < res) {  // arr[(m보다 작은 제곱수)] + arr[m - (제곱수)], 가장 작은 경우 찾기
						res = arr[i * i] + arr[m - i * i];
					}
				}
				arr[m] = res;
			}
			m++;
		}
	}
	
	cout << arr[n];
}
