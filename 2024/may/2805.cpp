#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 나무의 최대 길이가 2,000,000,000이므로 모든 변수를 long long 타입으로 선언
int main() {
	long long n, m;
	cin >> n >> m;
	
	vector<long long> tree;
	
	long long a;
	for(long long i = 0; i < n; i++) {
		cin >> a;
		tree.push_back(a);
	}

        // 이분탐색을 위한 왼쪽과 오른쪽 수 (1과 나무의 최대 길이)
	long long left = 1;
	long long right = *max_element(tree.begin(), tree.end());
	
	long long res = 0;

        // 이분탐색
	while(left <= right) {
		long long std = (left + right) / 2; // 선언과 동시에 초기화를 해줘야 자료형이 제대로 지정됨
		long long sum = 0;
	
		for(long long height: tree) {
			if(height > std) sum += height - std; // 자른 나무의 길이 저장
		}

		if(sum < m) right = std - 1; // 자른 나무의 합이 원하는 길이보다 작다면 자를 길이를 더 낮게 해야 함
		else {
			res = std;
			left = std + 1; // 크거나 같다면 자를 길이를 더 높게 해서 확인
		}
	}
	
	cout << res;
}
