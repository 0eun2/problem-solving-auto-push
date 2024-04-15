#include <iostream>
#include <vector>

using namespace std;

//후위 순회
void postOrder(int left, int right, vector<int> &tree, vector<int> &result) {
    //종료 조건
    if (left > right) {
        return;
    }
    int root = tree[left];  //전위 순회에서 가장 먼저 순회하는 노드는 root 노드
    int tmp = left + 1; //root보다 큰 노드 중 첫 번째 인덱스(root 노드의 오른쪽 자식 노드)
    for (int i = left + 1; i <= right; i++) {
        if (tree[i] > root) {
            tmp = i;
            break;
        }
    }

    //후위 순회: left -> right -> root
    postOrder(left+1, tmp-1, tree, result);   //left 서브 트리 탐색
    postOrder(tmp, right, tree, result);    //right 서브 트리 탐색

    result.push_back(root); //root 입력
}

//전위 순회 결과 tree가 주어졌을 때 후위 순회한 결과 벡터 반환
vector<int> solution(vector<int> &tree) {
    vector<int> result;

    postOrder(0, tree.size() - 1, tree, result);
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num;
    vector<int> tree;   //트리를 전위 순회한 결과

    //입력
    while (cin >> num) {
        tree.push_back(num);
    }

    //연산
    vector<int> result = solution(tree);

    //출력
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << '\n';
    }

    return 0;
}