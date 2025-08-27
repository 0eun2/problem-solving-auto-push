import java.io.*;
import java.util.*;

public class Solution {
	static class Edge {
		int n;
		long w;

		public Edge(int n, long w) {
			this.n = n;
			this.w = w;
		}
	}

	static int n;
	static List<Edge>[] graph;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		int t = Integer.parseInt(br.readLine());

		for (int tc = 1; tc <= t; tc++) {
			n = Integer.parseInt(br.readLine());
			long[] x = new long[n];
			long[] y = new long[n];
			graph = new ArrayList[n];

			for (int i = 0; i < n; i++) {
				graph[i] = new ArrayList<>();
			}

			StringTokenizer st = new StringTokenizer(br.readLine());
			for (int i = 0; i < n; i++) {
				x[i] = Long.parseLong(st.nextToken());
			}

			st = new StringTokenizer(br.readLine());
			for (int i = 0; i < n; i++) {
				y[i] = Long.parseLong(st.nextToken());
			}

			double e = Double.parseDouble(br.readLine());

			for (int i = 0; i < n - 1; i++) {
				for (int j = i + 1; j < n; j++) {
					long cost = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
					graph[i].add(new Edge(j, cost));
					graph[j].add(new Edge(i, cost));
				}
			}

			sb.append("#").append(tc).append(" ").append(Math.round(prim(0) * e)).append("\n");
		}
		System.out.println(sb);
	}

	static long prim(int start) {
		int cnt = 0;
		long ans = 0;
		boolean[] visited = new boolean[n];
		long[] minEdge = new long[n];
		PriorityQueue<Edge> pq = new PriorityQueue<>((e1, e2) -> Long.compare(e1.w, e2.w));

		Arrays.fill(minEdge, Long.MAX_VALUE);
		pq.offer(new Edge(start, 0));
		minEdge[start] = 0;

		while (!pq.isEmpty()) {
			Edge cur = pq.poll();

			if (visited[cur.n])
				continue;

			visited[cur.n] = true;
			ans += cur.w;

			if (++cnt == n)
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