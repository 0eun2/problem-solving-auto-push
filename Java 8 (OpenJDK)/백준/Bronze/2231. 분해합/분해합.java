import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (i + sum(i) == n) {
                ans = i;
                break;
            }
        }

        System.out.println(ans);
    }

    static int sum(int n) {
        int ret = 0;
        while (n >= 10) {
            ret += (n % 10);
            n /= 10;
        }
        ret += n;
        return ret;
    }

}
