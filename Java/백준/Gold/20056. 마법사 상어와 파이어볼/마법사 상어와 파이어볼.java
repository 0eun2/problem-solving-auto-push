import java.util.*;
import java.io.*;

public class Main {
	static class FireBall {
		int r, c, m, s, d;

		public FireBall(int r, int c, int m, int s, int d) {
			this.r = r;
			this.c = c;
			this.m = m;
			this.s = s;
			this.d = d;
		}
	}

	static int n;
	static List<FireBall> fireBall;
	static int[][] map;
	static int[] dr = { -1, -1, 0, 1, 1, 1, 0, -1 };
	static int[] dc = { 0, 1, 1, 1, 0, -1, -1, -1 };

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		fireBall = new ArrayList<>();
		map = new int[n][n];

		while (m-- > 0) {
			st = new StringTokenizer(br.readLine());
			int r = Integer.parseInt(st.nextToken()) - 1;
			int c = Integer.parseInt(st.nextToken()) - 1;
			fireBall.add(new FireBall(r, c, Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()),
					Integer.parseInt(st.nextToken())));
			map[r][c]++;
		} // 입력 끝

		while (k-- > 0) { // 명령
			move();

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (map[i][j] > 1) {
						divide(i, j);
					}
				}
			}
		}

		System.out.println(calcSum());
	}

	static void move() { // 파이어볼 이동
		for (FireBall f : fireBall) {
			map[f.r][f.c]--;
			f.r = (f.r + n + dr[f.d] * (f.s % n)) % n;
			f.c = (f.c + n + dc[f.d] * (f.s % n)) % n;

			map[f.r][f.c]++;
		}
	}

	static void divide(int r, int c) { // 파이어볼 분리
		int m = 0, s = 0, cnt = 0;
		boolean odd = false, even = false;

		for (int i = 0; i < fireBall.size(); i++) {
			FireBall cur = fireBall.get(i);
			if (cur.r == r && cur.c == c) {
				cnt++;
				m += cur.m;
				s += cur.s;
				if (cur.d % 2 == 0)
					even = true;
				else
					odd = true;

				fireBall.remove(i);
				i--;
			}
		}

		m /= 5;
		if (m == 0) {
			map[r][c] = 0;
			return;
		}

		s /= cnt;

		map[r][c] = 4;

		if (odd && even) {
			for (int i = 1; i < 8; i += 2) {
				fireBall.add(new FireBall(r, c, m, s, i));
			}
		} else {
			for (int i = 0; i < 8; i += 2) {
				fireBall.add(new FireBall(r, c, m, s, i));
			}
		}
	}

	static int calcSum() { // 질량 합
		int ans = 0;

		for (FireBall f : fireBall) {
			ans += f.m;
		}

		return ans;
	}
}
