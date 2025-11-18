import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());

		long[] h = new long[n + 2];
		for (int i = 1; i <= n; i++) {
			h[i] = Long.parseLong(br.readLine());
		} // 입력 끝

		Stack<Integer> stack = new Stack<>();
		long ans = 0;
		stack.push(0);
		for (int i = 1; i <= n + 1; i++) {
			while (!stack.isEmpty() && h[i] < h[stack.peek()]) {
				ans = Math.max(ans, h[stack.pop()] * (i - stack.peek() - 1));
			}
			stack.push(i);
		}
		System.out.println(ans);
	}
}
