import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int n = Integer.parseInt(br.readLine());
		String p = "";
		for (int i = 0; i < n; i++) {
			p += "IO";
		}
		p += "I";

		int m = Integer.parseInt(br.readLine());
		String s = br.readLine();

		int left = 0, right = n * 2, ans = 0;
		while (right++ < m) {
			if (s.substring(left, right).equals(p)) {
				ans++;
			}
			left++;
		}

		System.out.println(ans);
	}
}