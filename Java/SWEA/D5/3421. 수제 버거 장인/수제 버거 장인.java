import java.io.*;
import java.util.*;

public class Solution {

	static int n, m, ans;
	static List<Integer>[] list;
	static boolean[] selected;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		int t = Integer.parseInt(br.readLine());

		for (int tc = 1; tc <= t; tc++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			n = Integer.parseInt(st.nextToken());
			m = Integer.parseInt(st.nextToken());
			list = new ArrayList[n + 1];
			selected = new boolean[n + 1];
			ans = 0;

			for (int i = 0; i <= n; i++) {
				list[i] = new ArrayList<>();
			}

			for (int i = 0; i < m; i++) {
				st = new StringTokenizer(br.readLine());
				int a = Integer.parseInt(st.nextToken());
				int b = Integer.parseInt(st.nextToken());

				list[a].add(b);
				list[b].add(a);
			}

			dfs(1);

			sb.append("#").append(tc).append(" ").append(ans).append("\n");
		}
		System.out.println(sb);
	}

	static boolean isPossible(int idx) {
		for (int i = 1; i <= n; i++) {
			if (selected[i] && list[i].contains(idx))
				return false;
		}
		return true;
	}

	static void dfs(int idx) {
		ans++;

		for (int i = idx; i <= n; i++) {
			if (selected[i] || !isPossible(i))
				continue;

			selected[i] = true;
			dfs(i + 1);
			selected[i] = false;
		}
	}
}