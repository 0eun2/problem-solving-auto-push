import java.util.*;
import java.io.*;

public class Solution {
	static class Item {
		int v, c;

		public Item(int v, int c) {
			this.v = v;
			this.c = c;
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		int t = Integer.parseInt(br.readLine());

		for (int tc = 1; tc <= t; tc++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken());
			int k = Integer.parseInt(st.nextToken());
			Item[] items = new Item[n];

			for (int i = 0; i < n; i++) {
				st = new StringTokenizer(br.readLine());
				items[i] = new Item(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
			}

			// 입력 끝

			int[] dp = new int[k + 1];
			for (int i = 0; i < n; i++) {
				for (int j = k; j >= items[i].v; j--) {
					dp[j] = Math.max(dp[j], dp[j - items[i].v] + items[i].c);
				}
			}

			sb.append("#").append(tc).append(" ").append(dp[k]).append("\n");
		}

		System.out.println(sb);
	}

}
