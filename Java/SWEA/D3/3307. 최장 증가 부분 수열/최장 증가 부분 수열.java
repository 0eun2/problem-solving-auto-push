import java.util.*;
import java.io.*;

public class Solution {
	static int n;
	static boolean[][] graph;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		int t = Integer.parseInt(br.readLine());

		for (int tc = 1; tc <= t; tc++) {
			int n = Integer.parseInt(br.readLine());
			int[] arr = new int[n];

			StringTokenizer st = new StringTokenizer(br.readLine());
			for (int i = 0; i < n; i++) {
				arr[i] = Integer.parseInt(st.nextToken());
			}

			int[] dp = new int[n];
			int end = 0;
			for (int i = 0; i < n; i++) {
				int pos = lower_bound(dp, end, arr[i]);
				if (pos == end) {
					dp[end++] = arr[i];
					continue;
				}
				dp[pos] = arr[i];
			}

			sb.append("#").append(tc).append(" ").append(end).append("\n");
		}

		System.out.println(sb);
	}

	static int lower_bound(int[] dp, int end, int num) {
		int start = 0;

		while (start < end) {
			int mid = (start + end) / 2;

			if (dp[mid] < num) {
				start = mid + 1;
			} else {
				end = mid;
			}
		}

		return end;
	}
}
