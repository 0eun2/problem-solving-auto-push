#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> pi;
const int INF = 2e5;

vector<int> dijkstra(int start, int v, vector<vector<pi>> &graph) {
    vector<int> dist(v + 1, INF);
    priority_queue<pi, vector<pi>, greater<>> pq; //first: 시작점으로부터의 거리(dist), second: 정점(node)

    dist[start] = 0;
    pq.emplace(0, start);
    while (!pq.empty()) {
        int weight = pq.top().first; //현재 정점까지의 경로값
        int node = pq.top().second; //현재 탐색하려는 정점
        pq.pop();

        if (weight > dist[node]) {
            continue;
        }
        for (int i = 0; i < graph[node].size(); i++) {
            int next_node = graph[node][i].first;
            int next_weight = weight + graph[node][i].second;
            if (next_weight < dist[next_node]) {
                dist[next_node] = next_weight;
                pq.emplace(next_weight, next_node);
            }
        }
    }
    return dist;
}

int main() {
    int v, e, k, a, b, w;

    //입력
    cin >> v >> e >> k;
    vector<vector<pi>> graph(v + 1, vector<pi>(0)); //인접 리스트
    while (e--) {
        cin >> a >> b >> w;
        graph[a].emplace_back(b, w);
    }

    //연산
    vector<int> dist = dijkstra(k, v, graph);

    //출력
    for (int i = 1; i <= v; i++) {
        if (dist[i] == INF)
            cout << "INF";
        else
            cout << dist[i];

        cout << '\n';
    }
    return 0;
}