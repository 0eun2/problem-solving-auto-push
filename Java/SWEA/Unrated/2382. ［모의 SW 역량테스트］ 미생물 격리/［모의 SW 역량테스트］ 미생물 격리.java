import java.io.*;
import java.util.*;

public class Solution {
	static class Micro {
		int r, c, cnt, dir;

		public Micro(int r, int c, int cnt, int dir) {
			this.r = r;
			this.c = c;
			this.cnt = cnt;
			this.dir = dir;
		}
	}

	static int n, m, k;
	static int[] dr = { -1, 1, 0, 0 };
	static int[] dc = { 0, 0, -1, 1 };
	static List<Micro> list;
	static Micro[][] map;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		int t = Integer.parseInt(br.readLine());

		for (int tc = 1; tc <= t; tc++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			n = Integer.parseInt(st.nextToken());
			m = Integer.parseInt(st.nextToken());
			k = Integer.parseInt(st.nextToken());
			list = new ArrayList<>();

			for (int i = 0; i < k; i++) {
				st = new StringTokenizer(br.readLine());

				list.add(new Micro(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()),
						Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()) - 1));
			}

			while (m-- > 0) {
				map = new Micro[n][n];
				move();
			}

			sb.append("#").append(tc).append(" ").append(count()).append("\n");
		}
		System.out.println(sb);
	}

	static void move() {
		list.sort((m1, m2) -> m2.cnt - m1.cnt);

		for (int i = 0; i < list.size(); i++) {
			Micro cur = list.get(i);

			int r = cur.r + dr[cur.dir];
			int c = cur.c + dc[cur.dir];

			cur.r = r;
			cur.c = c;

			if (r == 0 || r == n - 1 || c == 0 || c == n - 1) {
				if (cur.dir % 2 == 0)
					cur.dir++;
				else
					cur.dir--;
				cur.cnt /= 2;

				if (cur.cnt == 0) {
					list.remove(i);
					i--;
					continue;
				}
			}

			if (map[r][c] == null) {
				map[r][c] = cur;
			} else {
				map[r][c].cnt += cur.cnt;
				list.remove(i);
				i--;
			}
		}
	}

	static int count() {
		int sum = 0;

		for (Micro m : list) {
			sum += m.cnt;
		}

		return sum;
	}
}