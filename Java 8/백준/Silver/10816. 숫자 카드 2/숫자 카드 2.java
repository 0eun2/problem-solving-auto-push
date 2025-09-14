import java.io.*;
import java.util.*;

public class Main {
	static int[] arr;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		int n = Integer.parseInt(br.readLine());
		arr = new int[n];

		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 0; i < n; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		Arrays.sort(arr);

		int m = Integer.parseInt(br.readLine());
		st = new StringTokenizer(br.readLine());
		while (m-- > 0) {
			int target = Integer.parseInt(st.nextToken());
			sb.append(searchUpperBound(target) - searchLowerBound(target)).append(" ");
		}

		System.out.println(sb);
	}

	static int searchLowerBound(int target) {
		int l = 0;
		int r = arr.length;
		int mid;

		while (l < r) {
			mid = (l + r) / 2;

			if (arr[mid] < target) {
				l = mid + 1;
			} else {
				r = mid;
			}
		}

		return l;
	}

	static int searchUpperBound(int target) {
		int l = 0;
		int r = arr.length;
		int mid;

		while (l < r) {
			mid = (l + r) / 2;

			if (arr[mid] <= target) {
				l = mid + 1;
			} else {
				r = mid;
			}
		}

		return l;
	}
}
