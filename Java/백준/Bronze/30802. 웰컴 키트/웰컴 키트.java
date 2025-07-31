import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        // 입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());    // 참가자 수

        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] tsize = new int[6];
        for (int i = 0; i < 6; i++) {
            tsize[i] = Integer.parseInt(st.nextToken());
        }

        st = new StringTokenizer(br.readLine());
        int t = Integer.parseInt(st.nextToken());
        int p = Integer.parseInt(st.nextToken());
        int tcnt = 0;
        int pcnt = 0;
        
        // 연산
        for (int i = 0; i < 6; i++) {
            while (tsize[i] > 0) {
                tsize[i] -= t;
                tcnt++;
            }
        }

        while (n - p >= 0) {
            n -= p;
            pcnt++;
        }

        // 출력
        System.out.println(tcnt);
        System.out.println(pcnt + " " + n);
    }
}
