#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n;
    vector<int> clothes(n + 2, 1);  // 처음 학생이 가지고 있는 체육복 수: 1
    
    for(int i: reserve) {   // 여벌의 체육복이 있는 학생
        clothes[i]++;
    }
    for(int i: lost) {  // 체육복을 도난당한 학생
        clothes[i]--;
    }
    
    for(int i = 1; i <= n; i++) {
        if(clothes[i]){ // 체육복이 있음
            continue;
        }
        if(clothes[i - 1] == 2) {    // 왼쪽 학생에게 빌리기
            clothes[i - 1]--;
            clothes[i]++;
        } else if(clothes[i + 1] == 2) { // 오른쪽 학생에게 빌리기
            clothes[i + 1]--;
            clothes[i]++;
        }
    }
    
    for(int i = 1; i <= n; i++){
        if(!clothes[i]){
            answer--;
        }
    }
    
    
    return answer;
}