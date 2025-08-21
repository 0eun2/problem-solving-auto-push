import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int m = Integer.parseInt(br.readLine());
		int s = 0;

		for (int i = 0; i < m; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			String op = st.nextToken();
			int x = 0;
			if (!op.equals("all") && !op.equals("empty")) {
				x = Integer.parseInt(st.nextToken());
			}

			switch (op) {
			case "add":
				s |= (1 << (x - 1));
				break;
			case "remove":
				s &= ~(1 << (x - 1));
				break;
			case "check":
				sb.append((s & (1 << (x - 1))) != 0 ? "1" : "0").append("\n");
				break;
			case "toggle":
				s ^= (1 << (x - 1));
				break;
			case "all":
				s = (1 << 20) - 1;
				break;
			case "empty":
				s = 0;
				break;
			}
		}

		System.out.print(sb);
	}
}
