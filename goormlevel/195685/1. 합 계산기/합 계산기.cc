#include <iostream>

using namespace std;

int main() {
	
	int t, sum = 0;	// 식의 개수, 합 계산기 결과
	
	cin >> t;
	
	while(t--){
		int a, b, result;
		char op;
		
		cin >> a >> op >> b;
		
		switch(op){
			case '+':
				result = a + b;
				break;
			case '-':
				result = a - b;
				break;
			case '*':
				result = a * b;
				break;
			case '/':
				result = a / b;
				break;
		}
		
		sum += result;
	}
	
	cout << sum;
	return 0;
}