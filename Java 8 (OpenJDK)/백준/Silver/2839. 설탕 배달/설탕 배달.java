import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int[] dp = new int[n + 1];

		dp[0] = dp[1] = dp[2] = -1;
		
		for (int i = 3; i <= n; i++) {
			if (i == 3 || i == 5)
				dp[i] = 1;
			else if (i == 4)
				dp[i] = -1;
			else {
				if (dp[i - 3] == -1 && dp[i - 5] == -1)
					dp[i] = -1;
				else if (dp[i - 3] == -1)
					dp[i] = dp[i - 5] + 1;
				else if (dp[i - 5] == -1)
					dp[i] = dp[i - 3] + 1;
				else {
					dp[i] = Math.min(dp[i - 3], dp[i - 5]) + 1;
				}
			}
		}

		System.out.println(dp[n]);
	}
}
