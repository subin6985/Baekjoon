#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int arr[1000];
	arr[1] = 1;  // l
	arr[2] = 2;  // ll, =
	arr[3] = 3;  // lll, =l, l=
	arr[4] = 5;  // llll, =ll, l=l, ll=, ==
  // arr[i-1] 타일 오른쪽에 1x2(l)을 붙이고, arr[i-2] 타일 오른쪽에 2x1(=)을 붙이면 arr[i]가 된다
  // 즉, arr[i] = arr[i - 1] + arr[i - 2]
	
	int n;
	cin >> n;
	
	if(n > 4) {
		int m = 5;
		while(m <= n) {
			arr[m] = (arr[m - 1] + arr[m - 2]) % 10007;  // 나머지 연산 해서 저장
			m++;
		}
	}
	
	cout << arr[n] % 10007;
}
