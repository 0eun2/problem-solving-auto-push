import java.io.*;
import java.util.*;

public class Solution {
	static class Edge {
		int n1, n2;
		long w;

		public Edge(int n1, int n2, long w) {
			this.n1 = n1;
			this.n2 = n2;
			this.w = w;
		}
	}

	static int[] parent;

	static int find(int a) {
		if (parent[a] < 0)
			return a;
		return parent[a] = find(parent[a]);
	}

	static boolean union(int a, int b) {
		int pa = find(a);
		int pb = find(b);

		if (pa == pb)
			return false;

		if (parent[pa] < parent[pb]) {
			parent[pa] += parent[pb];
			parent[pb] = pa;
		} else {
			parent[pb] += parent[pa];
			parent[pa] = pb;
		}

		return true;
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		int t = Integer.parseInt(br.readLine());

		for (int tc = 1; tc <= t; tc++) {
			int n = Integer.parseInt(br.readLine()); // 섬의 개수
			parent = new int[n + 1];
			long[] x = new long[n];
			long[] y = new long[n];

			StringTokenizer st = new StringTokenizer(br.readLine());
			for (int i = 0; i < n; i++) {
				x[i] = Long.parseLong(st.nextToken());
			}

			st = new StringTokenizer(br.readLine());
			for (int i = 0; i < n; i++) {
				y[i] = Long.parseLong(st.nextToken());
			}

			double e = Double.parseDouble(br.readLine());

			Arrays.fill(parent, -1);

			PriorityQueue<Edge> pq = new PriorityQueue<>((e1, e2) -> Long.compare(e1.w, e2.w));
			for (int i = 0; i < n - 1; i++) {
				for (int j = i + 1; j < n; j++) {
					pq.add(new Edge(i, j, (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j])));
				}
			}

			int cnt = 0;
			long ans = 0;
			while (!pq.isEmpty()) {
				Edge edge = pq.poll();
				if (!union(edge.n1, edge.n2))
					continue;
				ans += edge.w;
				if (++cnt == n - 1)
					break;
			}

			sb.append("#").append(tc).append(" ").append(Math.round(ans * e)).append("\n");
		}

		System.out.println(sb);
	}
}
