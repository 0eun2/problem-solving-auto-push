import java.util.*;
import java.io.*;

public class Main {
	static int n, ans = Integer.MAX_VALUE;
	static int[][] arr;
	static boolean[] team;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());
		arr = new int[n][n];
		team = new boolean[n];

		for (int i = 0; i < n; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			for (int j = 0; j < n; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
			}
		} // 입력 끝

		dfs(0, 0);
		
		System.out.println(ans);
	}

	static void dfs(int idx, int cnt) {
		if (ans == 0)
			return;
		
		if (cnt == n / 2) {
			int start = 0, link = 0;
			for (int i = 0; i < n; i++) {
				if (team[i]) {
					start += calcSum(i);
				} else {
					link += calcSum(i);
				}
			}
			ans = Math.min(ans, Math.abs(start - link));
			return;
		}

		for (int i = idx; i < n; i++) {
			team[i] = true;
			dfs(i + 1, cnt + 1);
			team[i] = false;
		}
	}

	static int calcSum(int num) {
		int sum = 0;
		for (int i = 0; i < n; i++) {
			if (num == i)
				continue;
			if (team[num] == team[i])
				sum += arr[num][i];
		}
		return sum;
	}
}
