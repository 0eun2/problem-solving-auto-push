import java.io.*;
import java.util.*;

public class Main {

	static int n, cnt, ans = Integer.MAX_VALUE;
	static int[][] w;
	static boolean[] visited;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		n = Integer.parseInt(br.readLine());
		w = new int[n][n];
		visited = new boolean[n];

		for (int i = 0; i < n; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			for (int j = 0; j < n; j++) {
				w[i][j] = Integer.parseInt(st.nextToken());
			}
		}

		// for (int i = 0; i < n; i++) {
		visited[0] = true;
		dfs(0, 1, 0);
		// visited[i] = false;
		// }

		System.out.println(ans);
	}

	static void dfs(int cur, int cnt, int sum) {
		if (cnt == n) {
			if (w[cur][0] != 0)
				ans = Math.min(ans, sum + w[cur][0]);
			return;
		}

		for (int next = 0; next < n; next++) {
			if (w[cur][next] == 0 || visited[next])
				continue;

			visited[next] = true;
			dfs(next, cnt + 1, sum + w[cur][next]);
			visited[next] = false;
		}
	}
}
