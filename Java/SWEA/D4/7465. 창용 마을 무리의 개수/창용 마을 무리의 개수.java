import java.io.*;
import java.util.*;

public class Solution {
	static int[] p;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		int t = Integer.parseInt(br.readLine());

		for (int tc = 1; tc <= t; tc++) {
			StringTokenizer st = new StringTokenizer(br.readLine());

			int n = Integer.parseInt(st.nextToken());
			int m = Integer.parseInt(st.nextToken());
			p = new int[n + 1];

			Arrays.fill(p, -1); // 루트: 자기자신

			for (int i = 0; i < m; i++) {
				st = new StringTokenizer(br.readLine());
				int a = Integer.parseInt(st.nextToken());
				int b = Integer.parseInt(st.nextToken());
				union(a, b);
			}

			int ans = 0;
			for (int i = 1; i <= n; i++) {
				if (p[i] < 0) {
					ans++;
				}
			}

			sb.append("#").append(tc).append(" ").append(ans).append("\n");
		}

		System.out.println(sb);
	}

	static void union(int a, int b) {
		int ap = find(a);
		int bp = find(b);

		if (ap == bp)
			return;

		if (p[ap] < p[bp]) { // a 집합이 더 큼
			p[ap] += p[bp];
			p[bp] = ap;
		} else {
			p[bp] += p[ap];
			p[ap] = bp;
		}
	}

	static int find(int node) {
		if (p[node] < 0) {
			return node;
		}
		return p[node] = find(p[node]);
	}

}
