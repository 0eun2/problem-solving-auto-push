import java.util.*;
import java.io.*;

public class Main {
	static int n, ans;
	static int[] cnt = {1, 2, 3};
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int t = Integer.parseInt(br.readLine()); 
		
		while (t-- > 0) {
			n = Integer.parseInt(br.readLine());
			ans = 0;
			
			backtracking(0, 0);
			
			sb.append(ans).append("\n");
		}
		
		System.out.println(sb);
	}
	
	static void backtracking(int idx, int sum) {
		if (sum == n) {
			ans++;
			return;
		}
		if (sum > n)
			return;
		
		for (int i = 0; i < 3; i++) {
			sum += cnt[i];
			backtracking(i, sum);
			sum -= cnt[i];
		}
	}
}
