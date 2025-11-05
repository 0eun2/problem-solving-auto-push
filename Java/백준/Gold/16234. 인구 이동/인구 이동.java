import java.util.*;
import java.io.*;

public class Main {
	static class Point {
		int r, c;

		public Point(int r, int c) {
			this.r = r;
			this.c = c;
		}
	}

	static int n, left, right;
	static int[][] map;

	static int[] dr = { -1, 1, 0, 0 };
	static int[] dc = { 0, 0, -1, 1 };

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		n = Integer.parseInt(st.nextToken());
		left = Integer.parseInt(st.nextToken());
		right = Integer.parseInt(st.nextToken());

		map = new int[n][n];

		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < n; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		} // 입력 끝

		int ans = 0;

		while (true) {
			boolean moved = false;
			boolean[][] visited = new boolean[n][n];

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (visited[i][j])
						continue;

					List<Point> selected = new ArrayList<>();
					int sum = bfs(i, j, visited, selected);

					if (selected.size() > 1) {
						move(sum, selected);
						moved = true;
					}
				}
			}

			if (!moved)
				break;
			ans++;
		}

		System.out.println(ans);
	}

	static int bfs(int r, int c, boolean[][] visited, List<Point> selected) {
		Queue<Point> q = new ArrayDeque<>();

		q.add(new Point(r, c));
		visited[r][c] = true;
		selected.add(new Point(r, c));

		int sum = map[r][c];

		while (!q.isEmpty()) {
			Point cur = q.poll();

			for (int i = 0; i < 4; i++) {
				int nr = cur.r + dr[i];
				int nc = cur.c + dc[i];

				if (nr < 0 || nc < 0 || nr >= n || nc >= n || visited[nr][nc])
					continue;

				int diff = Math.abs(map[cur.r][cur.c] - map[nr][nc]);
				if (diff < left || diff > right)
					continue;

				sum += map[nr][nc];
				q.add(new Point(nr, nc));
				visited[nr][nc] = true;
				selected.add(new Point(nr, nc));
			}
		}

		return sum;
	}

	static void move(int sum, List<Point> selected) {
		int avg = sum / selected.size();

		for (Point cur : selected) {
			map[cur.r][cur.c] = avg;
		}
	}

}
