#include <iostream>
#include <unordered_map>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	int fruits[200000];
	
	for(int i = 0; i < n; i++) {
		cin >> fruits[i];
	}
	
	int maxL = 0; // 탕후루의 최장 길이
	unordered_map<int, int> fruit_count; // 탕후루의 과일 종류
	int left = 0; // 왼쪽 포인터
	
	for(int right = 0; right < n; right++) { // 오른쪽 포인터를 증가해가며 검사
		fruit_count[fruits[right]]++; // 해당 과일의 개수 증가
		
		if(fruit_count.size() > 2) { // 과일 종류가 2를 초과한 경우
			fruit_count[fruits[left]]--; // 가장 왼쪽의 과일을 제거
			if(fruit_count[fruits[left]] == 0) { // 가장 왼쪽의 과일의 개수가 0개가 되면
				fruit_count.erase(fruits[left]); // 종류에서도 제거
			}
			left++; // 왼쪽 포인터 증가
		}
		
		maxL = max(maxL, right - left + 1); // 기존 최장 길이와 현재 길이 중 더 큰 값을 저장
	}
	
	cout << maxL;
}
