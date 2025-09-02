import java.util.*;
import java.io.*;

public class Solution {
	static int n;
	static int[][] arr;
	static int[][] dist;
	static int[] dr = { -1, 1, 0, 0 };
	static int[] dc = { 0, 0, -1, 1 };

	static class Point {
		int r, c, w;

		public Point(int r, int c, int w) {
			this.r = r;
			this.c = c;
			this.w = w;
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		int t = Integer.parseInt(br.readLine());

		for (int tc = 1; tc <= t; tc++) {
			n = Integer.parseInt(br.readLine());
			arr = new int[n][n];
			dist = new int[n][n];

			for (int i = 0; i < n; i++) {
				Arrays.fill(dist[i], Integer.MAX_VALUE);
			}

			dist[0][0] = 0;

			for (int i = 0; i < n; i++) {
				String s = br.readLine();
				for (int j = 0; j < n; j++) {
					arr[i][j] = s.charAt(j) - '0';
				}
			}

			sb.append("#").append(tc).append(" ").append(dijkstra()).append("\n");
		}
		System.out.println(sb);

	}

	static int dijkstra() {
		PriorityQueue<Point> pq = new PriorityQueue<>((p1, p2) -> p1.w - p2.w);
		boolean[][] visited = new boolean[n][n];

		visited[0][0] = true;
		pq.add(new Point(0, 0, dist[0][0]));

		while (!pq.isEmpty()) {
			Point cur = pq.poll();

			if (cur.r == n - 1 && cur.c == n - 1)
				return cur.w;

			for (int i = 0; i < 4; i++) {
				int nr = cur.r + dr[i];
				int nc = cur.c + dc[i];

				if (nr < 0 || nc < 0 || nr >= n || nc >= n || visited[nr][nc] || dist[nr][nc] < cur.w + arr[nr][nc])
					continue;

				dist[nr][nc] = cur.w + arr[nr][nc];
				Point next = new Point(nr, nc, dist[nr][nc]);
				visited[next.r][next.c] = true;
				pq.add(next);
			}
		}

		return -1;
	}
}
