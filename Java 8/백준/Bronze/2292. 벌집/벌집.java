import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int ans = 0;

        n -= 1;
        ans++;
        for (int i = 1; n > 0; i++) {
            n -= i * 6;
            ans++;
        }
        System.out.println(ans);
    }
}
