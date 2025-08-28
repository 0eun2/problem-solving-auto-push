import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        // 입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        while (true) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int[] num = new int[3];

            for (int i = 0; i < 3; i++) {
                num[i] = Integer.parseInt(st.nextToken());
            }

            if (num[0] == 0 && num[1] == 0 && num[2] == 0) {
                break;
            }
            
            Arrays.sort(num);

            if (Math.pow(num[2], 2) == Math.pow(num[0], 2) + Math.pow(num[1], 2)) {
                System.out.println("right");
                continue;
            }

            System.out.println("wrong");
        }
    }
}
