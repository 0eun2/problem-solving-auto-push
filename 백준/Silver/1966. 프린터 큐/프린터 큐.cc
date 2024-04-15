#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, int m, vector<int> numbers) {
    int answer = 0;
    queue<int> q;

    //queue에 값 입력
    for (int num: numbers) {
        q.push(num);
    }

    //중요도 오름차순으로 정렬
    sort(numbers.begin(), numbers.end());

    while (true) {
        //queue의 맨 앞 원소가 중요도가 가장 높은 문서일 때
        if (q.front() == numbers[numbers.size() - 1]) {
            answer++;   //카운트 증가

            //queue와 vector에서 모두 해당 원소를 pop
            q.pop();
            numbers.pop_back();

            if (m == 0) { //원하는 원소가 큐의 가장 앞에 있을 때
                break;
            }
        }
            //중요도가 가장 높은 문서가 아닐 때
        else {   //원소를 queue의 가장 뒤에 재배치
            q.push(q.front());
            q.pop();
        }
        //원하는 원소의 위치가 0일 때 -> queue의 맨 뒤로, 0이 아닐 때 -> -1
        m = (m == 0) ? q.size() - 1 : m - 1;
    }
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //테스트 케이스 개수
    int tc;
    cin >> tc;

    for (int i = 0; i < tc; i++) {
        //문서의 개수, 몇 번째로 인쇄되었는지 궁금한 문서 인덱스
        int N, M;
        cin >> N >> M;

        //문서의 중요도
        vector<int> numbers(N);
        for (int j = 0; j < N; j++) {
            cin >> numbers[j];
        }

        cout << solution(N, M, numbers) << '\n';
    }

    return 0;
}