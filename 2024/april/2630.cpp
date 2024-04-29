#include <iostream>
using namespace std;

int arr[128][128];
int white = 0;
int blue = 0;

void div_cnt(int x, int y, int n) { // 분할 정복
	int cnt = 0;
	
	for(int i = x; i < x + n; i++) {
		for(int j = y; j < y + n; j++) {
			if(arr[i][j] == 1) cnt++;
		}
	}
	
	if(cnt == n * n) blue++; // 구역이 전부 1이면 파란색 + 1
	else if(cnt == 0) white++; // 전부 0이면 하얀색 + 1
	else { // 둘 다 아니면 다시 분할
		div_cnt(x, y, n / 2);
		div_cnt(x, y + n / 2, n / 2);
		div_cnt(x + n / 2, y, n / 2);
		div_cnt(x + n / 2, y + n / 2, n / 2);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> arr[j][i];
		}
	}
	
	div_cnt(0, 0, n);
	
	cout << white << '\n' << blue;
}
