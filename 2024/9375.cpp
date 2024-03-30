#include <iostream>
#include <map>
using namespace std;

int main() {
	int k, n;
	cin >> k;
	
	string str1, str2;
	
	for(int i = 0; i < k; i++) {
		map<string, int> clothes; // 옷 종류, 개수를 담을 맵
		int cnt = 1;
		
		cin >> n;
		
		for(int j = 0; j < n; j++) {
			cin >> str1 >> str2;
			clothes[str2]++; // 해당 옷 종류의 개수를 1 증가
		}
		
		for(auto iter = clothes.begin(); iter != clothes.end(); iter++) {
			cnt *= iter->second + 1; // 종류별 개수 + 1(해당 종류를 입지 않을 경우) 곱해줌
		}
		
		cout << cnt - 1 << endl; // 1(모든 종류의 옷을 입지 않을 경우) 빼줌
	}
}
