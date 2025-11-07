import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int[] arr = new int[n];

		for (int i = 0; i < n; i++) {
			arr[i] = i + 1;
		}

		while (m-- > 0) {
			st = new StringTokenizer(br.readLine());
			int i = Integer.parseInt(st.nextToken());
			int j = Integer.parseInt(st.nextToken());

			int[] copied = new int[j - i + 1];
			int idx = 0;
			for (int start = i - 1; start < j; start++) {
				copied[idx++] = arr[start];
			}

			idx = copied.length - 1;
			for (int start = i - 1; start < j; start++) {
				arr[start] = copied[idx--];
			}
		}

		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < n; i++) {
			sb.append(arr[i]).append(" ");
		}

		System.out.println(sb);
	}
}
