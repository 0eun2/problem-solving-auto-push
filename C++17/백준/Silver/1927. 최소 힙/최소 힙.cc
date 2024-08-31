#include<iostream>
#include<vector>

using namespace std;

bool isEmpty(vector<int> &heap) {
    return heap.size() == 1;
}

/*  1. 새로운 노드를 마지막 노드에 삽입
    2. 새로운 노드를 부모 노드들과 교환해서 힙의 성질 만족시키기 */
void push(vector<int> &heap, int x) {
    int idx = heap.size();
    heap.push_back(x);

    while (idx > 1 && heap[idx] < heap[idx / 2]) {
        swap(heap[idx], heap[idx / 2]);
        idx /= 2;
    }

    return;
}

/*  1. 루트 노드 삭제
    2. 삭제된 루트 노드에 힙의 마지막 노드를 가져옴
    3. 힙 재구성    */
int pop(vector<int> &heap) {
    int item = heap[1];
    heap[1] = heap[heap.size() - 1];
    heap.pop_back();

    int size = heap.size();
    int parent = 1, child = 2;

    while (child < size) {
        if (child + 1 < size && heap[child + 1] < heap[child])
            child += 1;

        if (heap[parent] > heap[child]) {
            swap(heap[parent], heap[child]);
            parent = child;
            child = parent * 2;
        } else {
            break;
        }
    }
    return item;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, x;
    vector<int> heap_vec;
    heap_vec.push_back(0);
    cin >> n;

    while (n--) {
        cin >> x;
        if (x == 0) { //출력
            if (isEmpty(heap_vec))
                cout << "0\n";
            else
                cout << pop(heap_vec) << '\n';
        } else { //추가
            push(heap_vec, x);
        }
    }


    return 0;
}