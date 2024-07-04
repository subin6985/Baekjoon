#include <iostream>
using namespace std;

int n;
int arr[100][100];

int main() {
	cin >> n;
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if(arr[i][j] == 0) arr[i][j] = 10000; // 간선이 존재하지 않으면 비용을 높게 설정 (100*100 = 10000이라서)
		}
	}
	
	for(int i = 0; i < n; i++) { // 플로이드 워셜 알고리즘
		for(int j = 0; j < n; j++) {
			for(int k = 0; k < n; k++) {
				arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]); // 적은 비용 채택
			}
		}
	}
	
	int res;
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(arr[i][j] >= 10000) res = 0; // 비용이 10000 이상이면 간선 없는 것으로 간주, 0 출력
			else res = 1;
			
			cout << res << ' ';
		}
		cout << '\n';
	}
}
