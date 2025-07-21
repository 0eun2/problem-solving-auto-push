import java.util.Scanner;
 
public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
 
        for (int tc = 1; tc <= T; tc++) {
            int N = sc.nextInt();
            int[][] matrix = new int[N][N];
 
            for (int i = 0; i < N; i++)
                for (int j = 0; j < N; j++)
                    matrix[i][j] = sc.nextInt();
 
            int[][] rotate90 = rotate(matrix, N, 90);
            int[][] rotate180 = rotate(matrix, N, 180);
            int[][] rotate270 = rotate(matrix, N, 270);
 
            System.out.println("#" + tc);
            for (int i = 0; i < N; i++) {
                printRow(rotate90[i]);
                System.out.print(" ");
                printRow(rotate180[i]);
                System.out.print(" ");
                printRow(rotate270[i]);
                System.out.println();
            }
        }
    }
 
    public static int[][] rotate(int[][] matrix, int N, int degree) {
        int[][] result = new int[N][N];
        switch (degree) {
            case 90:
                for (int i = 0; i < N; i++)
                    for (int j = 0; j < N; j++)
                        result[j][N - 1 - i] = matrix[i][j];
                break;
            case 180:
                for (int i = 0; i < N; i++)
                    for (int j = 0; j < N; j++)
                        result[N - 1 - i][N - 1 - j] = matrix[i][j];
                break;
            case 270:
                for (int i = 0; i < N; i++)
                    for (int j = 0; j < N; j++)
                        result[N - 1 - j][i] = matrix[i][j];
                break;
        }
        return result;
    }
 
    public static void printRow(int[] row) {
        for (int num : row)
            System.out.print(num);
    }
}