import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
//        List<Integer>[] graph = new ArrayList[n + 1];

//        for (int i = 0; i <= n; i++) {
//            graph[i] = new ArrayList<>();
//        }

//        for (int i = 0; i < m; i++) {
//            st = new StringTokenizer(br.readLine());
//            int u = Integer.parseInt(st.nextToken());
//            int v = Integer.parseInt(st.nextToken());
//
////            graph[u].add(v);
////            graph[v].add(u);
//        }   // 입력 끝

        if (m <= n) System.out.println("Yes");
        else System.out.println("No");
    }
}