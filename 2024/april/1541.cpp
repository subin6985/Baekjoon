#include <iostream>
#include <string>
using namespace std;

int main() {
	string input;
	cin >> input;
	
	int result = 0;
	string num;
	bool minus = false;
	
	for(int i = 0; i <= input.size(); i++) { // 끝나기 전 마지막 수도 연산해야 하기 때문에 식이 끝났는지 확인하기 위해 input.size()까지 반복
		if(input[i] != '+' && input[i] != '-' && i < input.size()) { // 부호가 아니거나 식이 끝나지 않았다면
			num += input[i]; // 수를 저장
		} else {
			if(!minus) result += stoi(num); // - 부호가 아직 안 나왔다면 저장한 수를 int형으로 변환해 덧셈
			else result -= stoi(num); // 나왔다면 뺄셈(- 뒤로 괄호를 치면 덧셈도 뺄셈 연산을 하고, 결과가 가장 작아지므로)
			num = "";
			
			if(input[i] == '-') {
				minus = true; // - 기호가 나옴
			}
		}
	}
	
	cout << result;
}
