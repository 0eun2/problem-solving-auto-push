#include <iostream>

using namespace std;

int k, ans;

void merge(int A[], int p, int q, int r) {
    int i = p, j = q + 1, t = 1;
    int *tmp = new int[r + 2];

    while (i <= q && j <= r) {
        if (A[i] <= A[j]) {
            tmp[t++] = A[i++];
        } else {
            tmp[t++] = A[j++];
        }
    }
    while (i <= q)  // 왼쪽 배열 부분이 남은 경우
        tmp[t++] = A[i++];
    while (j <= r)  // 오른쪽 배열 부분이 남은 경우
        tmp[t++] = A[j++];
    i = p;
    t = 1;
    while (i <= r) {  // 결과 저장
        A[i++] = tmp[t++];
        if (++ans == k) {
            cout << A[i - 1];
            break;
        }
    }
    delete[] tmp;
}

void merge_sort(int A[], int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;       // q는 p, r의 중간 지점
        merge_sort(A, p, q);      // 전반부 정렬
        merge_sort(A, q + 1, r);  // 후반부 정렬
        merge(A, p, q, r);        // 병합
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    ans = 0;

    cin >> n >> k;
    int *A = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    merge_sort(A, 0, n - 1);

    if (ans < k) cout << -1;
    delete[] A;

    return 0;
}