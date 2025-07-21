import java.io.*;
import java.util.*;
 
public class Solution {
 
    static class Pair {
        int taste;
        int calories;
 
        Pair(int taste, int calories) {
            this.taste = taste;
            this.calories = calories;
        }
    }
 
    static List<Pair> list = new ArrayList<>();
    static int l = 0;
    static int ans = 0;
 
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
 
        for (int tc = 1; tc <= T; tc++) {
            ans = 0;
            list.clear();
 
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            l = Integer.parseInt(st.nextToken());
 
            for (int i = 0; i < n; i++) {
                st = new StringTokenizer(br.readLine());
                int taste = Integer.parseInt(st.nextToken());
                int cal = Integer.parseInt(st.nextToken());
                list.add(new Pair(taste, cal));
            }
 
            backtracking(0, 0, 0);
            System.out.println("#" + tc + " " + ans);
        }
    }
 
    static void backtracking(int idx, int tasteSum, int calSum) {
        if (calSum > l) return;
        if (idx == list.size()) {
            ans = Math.max(ans, tasteSum);
            return;
        }
         
        backtracking(idx + 1, tasteSum + list.get(idx).taste, calSum + list.get(idx).calories);
        backtracking(idx + 1, tasteSum, calSum);
    }
}