#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, m;
int users[101][101]; // 사람들의 관계를 저장

int tmp = 5000; // 최소 케빈 베이컨의 수
int visited[101]; // 방문했는지 여부
int cnt[101]; // n까지 도달하는 단계 수를 cnt[n]에 저장
queue<int> friends; // bfs를 위한 큐

// 처음에는 bfs로 n*n의 모든 단계 수를 저장한 뒤 2중 for문으로 합을 구했는데 런타임 에러 발생
// 따라서 한 사람씩 bfs와 합 구하기를 진행
bool kevin(int x) {
	visited[x] = 1;
	friends.push(x);
	
	while(!friends.empty()) {
		int user = friends.front();
		friends.pop();
		
		for(int i = 1; i <= n; i++) {
			if(!visited[i] && users[user][i]) { // 방문하지 않았고, user와 관계가 있는 경우
				cnt[i] = cnt[user] + 1; // 단계 수 + 1
				visited[i] = 1;
				friends.push(i);
			}
		}
	}
	
	int sum = 0;
	for(int i = 1; i <= n; i++) sum += cnt[i]; // 모든 단계 수의 합
	
	if(sum < tmp) { // 합이 최소 케빈 베이컨 수보다 작은 경우
		tmp = sum; // 최소 케빈 베이컨 수를 변경하고
		return true; // true 반환
	} else return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	
	int a, b;
	for(int i = 0; i < m; i++) {
		cin >> a >> b;
		users[a][b] = 1; // 입력 받은 사람들의 관계를 1로 저장
		users[b][a] = 1;
	}
	
	int res;
	for(int i = 1; i <= n; i++) { // 한 사람씩 케빈 베이컨의 수 구하기
		if(kevin(i)) res = i; // 최소 케빈 베이컨 수가 변경되었다면 i를 결과로 저장
		memset(visited, false, sizeof(visited)); // visited, cnt 배열 리셋
		memset(cnt, 0, sizeof(cnt));
	}
	
	cout << res;
}
