import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] num = new int[n];
        int ans = 0;
        boolean[] primeN = new boolean[1001];
        Arrays.fill(primeN, true);
        primeN[1] = false;

        for (int i = 0; i < n; i++) {
            num[i] = Integer.parseInt(st.nextToken());
        }

        for (int i = 2; i <= 1000; i++) {
            for (int j = 2; i * j <= 1000; j++) {
                primeN[i * j] = false;
            }
        }

        /*
        for (int i = 0; i < 1001; i++) {
            System.out.printf("%d: %b | ", i, primeN[i]);
        }
        */

        for (int i = 0; i < n; i++) {
            if (primeN[num[i]])
                ans++;
        }

        System.out.println(ans);
    }
}
