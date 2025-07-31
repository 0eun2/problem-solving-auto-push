import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        int[][] apart = new int[15][15];

        for (int i = 0; i < 15; i++) {
            apart[0][i] = i;
        }

        for (int i = 1; i < 15; i++) {
            for (int j = 0; j < 15; j++) {
                for (int k = 0; k <= j; k++) {
                    apart[i][j] += apart[i - 1][k];
                }
            }
        }
        
        while (t-- > 0) {
            int k = Integer.parseInt(br.readLine());
            int n = Integer.parseInt(br.readLine());

            System.out.println(apart[k][n]);
        }
    }
}
