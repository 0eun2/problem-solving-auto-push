import java.util.*;
import java.io.*;

public class Main {
	static class Pair {
		int num, cnt;

		public Pair(int num, int cnt) {
			this.num = num;
			this.cnt = cnt;
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int a = Integer.parseInt(st.nextToken());
		int b = Integer.parseInt(st.nextToken());

		System.out.println(bfs(a, b));
	}

	static int bfs(int a, int b) {
		if (a == b)
			return 1;

		if (b % 2 != 0 && b % 10 != 1)
			return -1;

		PriorityQueue<Pair> pq = new PriorityQueue<>((p1, p2) -> Integer.compare(p1.cnt, p2.cnt));

		pq.add(new Pair(b, 1)); // 역추적

		while (!pq.isEmpty()) {
			Pair cur = pq.poll();

			int next;
			if (cur.num % 2 == 0) {
				next = cur.num / 2;

				if (next == a)
					return cur.cnt + 1;
				if (next < a)
					continue;

				pq.add(new Pair(next, cur.cnt + 1));
			}

			if (cur.num % 10 == 1) {
				next = cur.num / 10;

				if (next == a)
					return cur.cnt + 1;
				if (next < a)
					continue;

				pq.add(new Pair(next, cur.cnt + 1));
			}
		}
		return -1;
	}
}
