#include <iostream>
using namespace std;

int main() {
	long side[100]; // int 범위를 초과함
	
	side[0] = 1;
	side[1] = 1;
	side[2] = 1;
	side[3] = 2;
	side[4] = 2;
	int cnt = 5; // 현재 배열이 어디까지 담겨있는지 표시
	
	int t, n;
	
	cin >> t;
	
	for(int i = 0; i < t; i++){
		cin >> n;
		if(n >= cnt) { // 배열 길이 이상이면 배열에 추가
			for(int j = cnt; j < n; j++) {
				side[j] = side[j - 5] + side[j - 1]; // p(6) = p(1) + p(5) = 3
			}
		}
		cout << side[n - 1] << endl;
	}
}
