#include<iostream>
#include<vector>
using namespace std;
const int INF = 1000000000;

int calculate(int mode, int op1, int op2){
    switch(mode){
        case 0: // +
            return op1 + op2;
        case 1: // -
            return op1 - op2;
        case 2: // *
            return op1 * op2;
        case 3: // /
            return op1 / op2;
    }       
}

//value: 계산 결과
void backtracking(int value, int index, int n, 
                  vector<int> &operand, vector<int> &operator_cnt, 
                  int &max_value, int &min_value){
    if(index == n){ //피연산자가 모두 사용됐을 경우
        max_value = max(max_value, value);  //최댓값 갱신
        min_value = min(min_value, value);  //최솟값 갱신
        return;
    }
    
    //피연산자가 모두 사용되지 않았을 경우
    for(int mode = 0; mode < 4; mode++){    
        if(operator_cnt[mode] <= 0){    //현재 선택한 연산자가 모두 사용됨
            continue;
        }
        operator_cnt[mode]--;   //연산자 감소
        int next_value = calculate(mode, value, operand[index]);
        backtracking(next_value, index + 1, n, operand, operator_cnt, max_value, min_value);
        operator_cnt[mode]++;
        
    }
}

pair<int, int> solution(int n, vector<int> operand, vector<int> operator_cnt){
    int max_value = -INF;
    int min_value = INF;
    
    backtracking(operand[0], 1, n, operand, operator_cnt, max_value, min_value);
    
    return {max_value, min_value};
}

int main(){
    //수의 개수
    int n;
    cin >> n;

    //수열(피연산자)
    vector<int> operand(n);
    for(int i=0; i<n; i++){
        cin >> operand[i];
    }

    //연산자
    vector<int> operator_cnt(4);
    for(int i=0; i<4; i++){
        cin >> operator_cnt[i];
    }

    pair<int, int> ans = solution(n, operand, operator_cnt);
    cout << ans.first << '\n' << ans.second;
    return 0;
}