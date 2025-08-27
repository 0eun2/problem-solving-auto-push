import java.io.*;
import java.util.*;

public class Solution {
	static class Edge {
		int n, w;

		public Edge(int n, int w) {
			this.n = n;
			this.w = w;
		}
	}

	static int v;
	static List<Edge>[] graph;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		int t = Integer.parseInt(br.readLine());

		for (int tc = 1; tc <= t; tc++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			v = Integer.parseInt(st.nextToken());
			int e = Integer.parseInt(st.nextToken());
			graph = new ArrayList[v + 1];

			for (int i = 0; i <= v; i++) {
				graph[i] = new ArrayList<>();
			}

			while (e-- > 0) {
				st = new StringTokenizer(br.readLine());
				int n1 = Integer.parseInt(st.nextToken());
				int n2 = Integer.parseInt(st.nextToken());
				int w = Integer.parseInt(st.nextToken());
				graph[n1].add(new Edge(n2, w));
				graph[n2].add(new Edge(n1, w));
			}

			sb.append("#").append(tc).append(" ").append(prim(1)).append("\n");
		}
		System.out.println(sb);
	}

	static long prim(int start) {
		int cnt = 0;
        long ans = 0;
		boolean[] visited = new boolean[v + 1];
		int[] minEdge = new int[v + 1];
		PriorityQueue<Edge> pq = new PriorityQueue<>((e1, e2) -> e1.w - e2.w);

		Arrays.fill(minEdge, Integer.MAX_VALUE);
		pq.offer(new Edge(start, 0));
		minEdge[start] = 0;

		while (!pq.isEmpty()) {
			Edge cur = pq.poll();

			if (visited[cur.n])
				continue;

			visited[cur.n] = true;
			ans += cur.w;
            
            if (++cnt == v)
                break;

			for (Edge next : graph[cur.n]) {
				if (!visited[next.n] && minEdge[next.n] > next.w) {
					minEdge[next.n] = next.w;
					pq.add(next);
				}

			}
		}

		return ans;
	}
}