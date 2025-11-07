import java.io.*;
import java.util.*;

public class Solution {

	static class Item {
		int t;
		int c;

		Item(int t, int c) {
			this.t = t;
			this.c = c;
		}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		int t = Integer.parseInt(br.readLine());

		for (int tc = 1; tc <= t; tc++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken());
			int l = Integer.parseInt(st.nextToken());
			Item[] arr = new Item[n];

			for (int i = 0; i < n; i++) {
				st = new StringTokenizer(br.readLine());
				arr[i] = new Item(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
			}
			// 입력 끝
			int[] dp = new int[l + 1];

			for (int i = 0; i < n; i++) {
				for (int j = l; j >= arr[i].c; j--) {
					dp[j] = Math.max(dp[j], dp[j - arr[i].c] + arr[i].t);
				}
			}

			sb.append("#").append(tc).append(" ").append(dp[l]).append("\n");
		}

		System.out.println(sb);
	}
}