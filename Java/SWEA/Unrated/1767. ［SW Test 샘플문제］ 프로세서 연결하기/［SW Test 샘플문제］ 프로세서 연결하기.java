import java.util.*;
import java.io.*;

public class Solution {
	static class Core {
		int r, c;

		public Core(int r, int c) {
			this.r = r;
			this.c = c;
		}
	}

	static int n, maxCore, minLength;
	static int[][] arr;
	static List<Core> core;
	static int[] dr = { -1, 1, 0, 0 };
	static int[] dc = { 0, 0, -1, 1 };

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		int t = Integer.parseInt(br.readLine());

		for (int tc = 1; tc <= t; tc++) {
			n = Integer.parseInt(br.readLine());
			maxCore = 0;
			minLength = Integer.MAX_VALUE;
			arr = new int[n][n];
			core = new ArrayList<>();

			for (int i = 0; i < n; i++) {
				StringTokenizer st = new StringTokenizer(br.readLine());
				for (int j = 0; j < n; j++) {
					arr[i][j] = Integer.parseInt(st.nextToken());
					if (arr[i][j] == 1 && i != 0 && i != n - 1 && j != 0 && j != n - 1) {
						core.add(new Core(i, j));
					}
				}
			}

			dfs(0, 0);

			sb.append("#").append(tc).append(" ").append(minLength).append("\n");
		}
		System.out.println(sb);

	}

	// core 선택
	static void dfs(int idx, int coreCnt) {
		if (idx == core.size()) {
			if (maxCore < coreCnt) {
				maxCore = coreCnt;
				minLength = getLength();
			} else if (maxCore == coreCnt) {
				minLength = Math.min(minLength, getLength());
			}
			return;
		}

		Core cur = core.get(idx);

		for (int dir = 0; dir < 4; dir++) {
			if (!isAvailable(cur, dir))
				continue;

			setStatus(cur, dir, 2);
			dfs(idx + 1, coreCnt + 1);
			setStatus(cur, dir, 0);
		}

		dfs(idx + 1, coreCnt); // 선택 안 함
	}

	static void setStatus(Core cur, int dir, int status) {
		int nr = cur.r;
		int nc = cur.c;

		while (true) {
			nr += dr[dir];
			nc += dc[dir];

			if (nr < 0 || nc < 0 || nr >= n || nc >= n) {
				break;
			}

			arr[nr][nc] = status;
		}
	}

	static boolean isAvailable(Core cur, int dir) {

		int nr = cur.r;
		int nc = cur.c;

		while (true) {
			nr += dr[dir];
			nc += dc[dir];

			if (nr < 0 || nc < 0 || nr >= n || nc >= n) {
				break;
			}

			if (arr[nr][nc] != 0) {
				return false;
			}
		}
		return true;
	}

	static int getLength() {
		int length = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j] == 2)
					length++;
			}
		}

		return length;
	}
}