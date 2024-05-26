#include <iostream>
#include <vector>

using namespace std;

int calcDistance(int key, int hand){
    int diff = abs(key - hand);
    switch(diff){
        case 1:
        case 3:
            return 1;
        case 2:
        case 4:
        case 6:
            return 2;
        case 5:
        case 7:
        case 9:
            return 3;
        case 8:
        case 10:
            return 4;
    }
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int l_hand = 10, r_hand = 12;
    
    for(int key: numbers){
        cout << "left: " << l_hand << '\n' << "right: " << r_hand << '\n';
        if(key == 1 || key == 4 || key == 7){ // 왼손
            l_hand = key;
            answer += 'L';
        }
        else if(key == 3 || key == 6 || key == 9){    // 오른손
            r_hand = key;
            answer += 'R';
        }
        else if(key == 2 || key == 5 || key == 8 || key == 0){  // 거리 계산
            if(key == 0){ // 0은 11로 계산
                key = 11;
            }
            
            int l_distance = calcDistance(key, l_hand);
            int r_distance = calcDistance(key, r_hand);
            
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