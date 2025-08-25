import java.io.*;
import java.util.*;

public class Solution {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		int t = Integer.parseInt(br.readLine());

		for (int tc = 1; tc <= t; tc++) {
			int n = Integer.parseInt(br.readLine());
			int[] tree = new int[n];
			int maxTree = 0;

			StringTokenizer st = new StringTokenizer(br.readLine());
			for (int i = 0; i < n; i++) {
				tree[i] = Integer.parseInt(st.nextToken());
				maxTree = Math.max(maxTree, tree[i]);
			}

			int odd = 0, even = 0;
			for (int i : tree) {
				int diff = maxTree - i;
				odd += diff % 2;
				even += diff / 2;
			}

			if (even > odd) {
				while (Math.abs(even - odd) > 1) {
					odd += 2;
					even--;
				}
			}

			int ans = 0;
			if (even >= odd) {
				ans = even * 2;
			} else if (even < odd) {
				ans = odd * 2 - 1;
			}

			sb.append("#").append(tc).append(" ").append(ans).append("\n");
		}

		System.out.println(sb);
	}
}
