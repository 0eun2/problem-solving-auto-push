import java.util.*;
import java.io.*;

class Solution {
	static int n, m;
	static int[][] arr;

	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		int t = Integer.parseInt(br.readLine());

		for (int tc = 1; tc <= t; tc++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			n = Integer.parseInt(st.nextToken());
			m = Integer.parseInt(st.nextToken());
			arr = new int[n][n];
			
			for (int i = 0; i < n; i++) {
				st = new StringTokenizer(br.readLine());
				for (int j = 0; j < n; j++) {
					arr[i][j] = Integer.parseInt(st.nextToken());
				}
			}

			int ans = 0;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					ans = Math.max(ans, solution(i, j));
				}
			}
			
			sb.append("#").append(tc).append(" ").append(ans).append("\n");
		}
		
		System.out.println(sb);
	}
	
	static int solution(int r, int c) {
		int sum = 0;
		
		for (int i = r; i < r + m; i++) {
			for (int j = c; j < c + m; j++) {
				if (i >= n || j >= n)
					continue;
				sum += arr[i][j];
			}
		}
		
		return sum;
	}
}