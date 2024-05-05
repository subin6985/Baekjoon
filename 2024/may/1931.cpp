#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	
	vector<pair<int, int>> meeting;
	
	int start, end;
	
	for(int i = 0; i < N; i++) {
		cin >> start >> end;
		meeting.push_back(make_pair(end, start)); // 일찍 끝나는 순으로 정렬해야 하므로 end가 앞
	}
	
	sort(meeting.begin(), meeting.end());
	
	int end_time = meeting[0].first; // 앞 회의의 끝나는 시간 저장
	int cnt = 1; // 회의 횟수
	
	for(int i = 1; i < N; i++) {
		if(meeting[i].second >= end_time) { // 시작하는 시간이 앞 회의의 끝나는 시간 이상이면 다음 회의가 됨
			cnt++; // 횟수 증가
			end_time = meeting[i].first; // 끝나는 시간 변경
		}
	}
	
	cout << cnt;
}
