#include <iostream>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = skill_trees.size();
    string s = "";
    
    for(string skill_tree: skill_trees){
        for(char c: skill_tree){
            // skill에 skill_tree와 같은 값이 있으면 저장
            if(skill.find(c) != string::npos){  
                s.push_back(c);
            }
        }
        
        for(int i = 0; i < s.length(); i++){
            if(skill[i] != s[i]){   // 순서가 다르면 불가능한 스킬트리
                answer--;
                break;
            }
        }
        
        s = ""; // 초기화
    }
    
    return answer;
}