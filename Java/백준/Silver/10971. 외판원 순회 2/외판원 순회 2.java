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
		visited = new boolean[n + 1];

		for (int i = 0; i < n; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			for (int j = 0; j < n; j++) {
				w[i][j] = Integer.parseInt(st.nextToken());
			}
		}

		for (int i = 0; i < n; i++) {
			dfs(i, i, 1, 0);
		}

		System.out.println(ans);
	}

	static void dfs(int first, int city, int cnt, int price) {
		if (cnt == n) {
            if (w[city][first] != 0)
			    ans = Math.min(ans, price + w[city][first]);
			return;
		}

		visited[city] = true;

		for (int next = 0; next < n; next++) {
			if (w[city][next] == 0 || visited[next])
				continue;

			visited[next] = true;
			dfs(first, next, cnt + 1, price + w[city][next]);
			visited[next] = false;
		}
	}
}
