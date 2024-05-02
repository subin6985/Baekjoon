#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> coordinates(n); // 좌표의 개수가 고정되어 있지 않으므로 vector 사용
	
	for(int i = 0; i < n; i++) {
		cin >> coordinates[i];
	}
  
	// 입력 받은 좌표를 정렬 후 중복값 제거
	vector<int> sorted(coordinates);
	sort(sorted.begin(), sorted.end());
	sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());

        // 원래 좌표값-압축 좌표값 쌍으로 저장
	map<int, int> order;
	for(int i = 0; i < sorted.size(); i++) {
		order[sorted[i]] = i;
	}
	
	for(int i = 0; i < n; i++) {
		cout << order[coordinates[i]] << " ";
	}
}
