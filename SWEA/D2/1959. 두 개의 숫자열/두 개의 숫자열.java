import java.util.Scanner;
 
public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
 
        for (int tc = 1; tc <= T; tc++) {
            int n = sc.nextInt();
            int m = sc.nextInt();
 
            int[] A = new int[n];
            int[] B = new int[m];
 
            for (int i = 0; i < n; i++) {
                A[i] = sc.nextInt();
            }
 
            for (int i = 0; i < m; i++) {
                B[i] = sc.nextInt();
            }
 
            int ans = Integer.MIN_VALUE;
 
            if (n <= m) {
                for (int i = 0; i <= m - n; i++) {
                    int sum = 0;
                    for (int j = 0; j < n; j++) {
                        sum += A[j] * B[i + j];
                    }
                    ans = Math.max(ans, sum);
                }
            } else {
                for (int i = 0; i <= n - m; i++) {
                    int sum = 0;
                    for (int j = 0; j < m; j++) {
                        sum += B[j] * A[i + j];
                    }
                    ans = Math.max(ans, sum);
                }
            }
 
            System.out.println("#" + tc + " " + ans);
        }
    }
}