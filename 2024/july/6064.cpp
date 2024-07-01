#include <iostream>
using namespace std;

int gcd(int m, int n) { // 최대공약수 구하기
	while(n != 0) {
		int temp = n;
		n = m % n;
		m = temp;
	}
	return m;
}

int lcm(int m, int n) { // 최소공배수 구하기
	return (m / gcd(m, n)) * n;
}

int main() {
	int t;
	cin >> t;
	
	int m, n, x, y;
	
	for(int i = 0; i < t; i++) {
		cin >> m >> n >> x >> y;
		
		int max = lcm(m, n);
		int ans = 0;
		
		while(1) {
			if(x > max) {
				ans = -1;
				break;
			}
			if((x - 1) % n + 1 == y){
				ans = x;
				break;
			}
			x += m;
		}
		
		cout << ans << '\n';
	}
}
