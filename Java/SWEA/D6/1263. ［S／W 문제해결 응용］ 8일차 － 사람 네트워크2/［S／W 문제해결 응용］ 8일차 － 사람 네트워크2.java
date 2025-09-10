import java.util.*;
import java.io.*;

public class Solution {
	static int n;
	static int[][] graph;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		int t = Integer.parseInt(br.readLine());

		for (int tc = 1; tc <= t; tc++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			n = Integer.parseInt(st.nextToken());
			graph = new int[n][n];

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					graph[i][j] = Integer.parseInt(st.nextToken());
				}
			}
			// 입력 끝

			floydWarshall();

			sb.append("#").append(tc).append(" ").append(calcMin()).append("\n");
		}

		System.out.println(sb);
	}

	static void floydWarshall() {
		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (graph[i][j] == 1)
						continue;
					if (graph[i][k] != 0 && graph[k][j] != 0) {
						if (graph[i][j] == 0) {
							graph[i][j] = graph[i][k] + graph[k][j];
						} else {
							graph[i][j] = Math.min(graph[i][k] + graph[k][j], graph[i][j]);
						}
					}
				}
			}
		}
	}

	static int calcMin() {
		int[] sum = new int[n];
		int ans = Integer.MAX_VALUE;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j)
					continue;
				sum[i] += graph[i][j];
			}
			ans = Math.min(ans, sum[i]);
		}

		return ans;
	}

}
