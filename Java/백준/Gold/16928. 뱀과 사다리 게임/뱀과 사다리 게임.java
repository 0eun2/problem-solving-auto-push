import java.util.*;
import java.io.*;

public class Main {
	static class Point {
		int pos, cnt;

		public Point(int pos, int cnt) {
			this.pos = pos;
			this.cnt = cnt;
		}
	}

	static int[] map;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int n = Integer.parseInt(st.nextToken()); // 사다리
		int m = Integer.parseInt(st.nextToken()); // 뱀

		map = new int[101];

		while (n-- > 0) {
			st = new StringTokenizer(br.readLine());
			int s = Integer.parseInt(st.nextToken());
			int e = Integer.parseInt(st.nextToken());

			map[s] = e;
		}

		while (m-- > 0) {
			st = new StringTokenizer(br.readLine());
			int s = Integer.parseInt(st.nextToken());
			int e = Integer.parseInt(st.nextToken());

			map[s] = e;
		} // 입력 끝

		System.out.println(bfs());
	}

	static int bfs() {
		PriorityQueue<Point> pq = new PriorityQueue<>((p1, p2) -> p1.cnt - p2.cnt);
		boolean[] visited = new boolean[101];

		pq.offer(new Point(1, 0));
		visited[1] = true;

		while (!pq.isEmpty()) {
			Point cur = pq.poll();

			for (int i = 1; i <= 6; i++) {
				int npos = cur.pos + i;

				if (visited[npos])
					continue;

				if (npos == 100) {
					return cur.cnt + 1;
				}

				if (map[npos] != 0) {
					visited[npos] = true;
					npos = map[npos];
				}

				pq.offer(new Point(npos, cur.cnt + 1));
				visited[npos] = true;
			}
		}

		return 1;
	}
}
