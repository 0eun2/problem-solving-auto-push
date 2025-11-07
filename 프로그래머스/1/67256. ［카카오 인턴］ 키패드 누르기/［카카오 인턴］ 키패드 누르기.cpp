#include <iostream>
#include <vector>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int l_hand = 10, r_hand = 12;   // 왼손: *, 오른손: # 에서 시작
    
    for(int key: numbers){
        if(key == 1 || key == 4 || key == 7){ // 왼손
            l_hand = key;
            answer += 'L';
        }
        else if(key == 3 || key == 6 || key == 9){    // 오른손
            r_hand = key;
            answer += 'R';
        }
        else {  // 거리 계산
            if(key == 0){ // 0은 11로 계산
                key = 11;
            }
            
                            // 상하                   좌우
            int l_distance = abs(key - l_hand) / 3 + abs(key - l_hand) % 3;
            int r_distance = abs(key - r_hand) / 3 + abs(key - r_hand) % 3;
            
            if(l_distance < r_distance){    // 왼손이 더 가까움
                l_hand = key;
                answer += 'L';
            }
            else if(l_distance > r_distance){   // 오른손이 더 가까움
                r_hand = key;
                answer += 'R';
            }
            else {  // 왼손, 오른손 거리 같음
                if(hand == "right"){
                    r_hand = key;
                    answer += 'R';
                }
                else{
                    l_hand = key;
                    answer += 'L';
                }
            }   
        }
    }
    
    return answer;
}
