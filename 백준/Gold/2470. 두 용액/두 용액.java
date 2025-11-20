import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }   // 입력 끝

        Arrays.sort(arr);

        int sum = Integer.MAX_VALUE;
        int ans1 = 0, ans2 = 0;

        int left = 0, right = n - 1;
        while (left < right) {
            int l = arr[left], r = arr[right];

            if (Math.abs(l + r) < sum) {
                sum = Math.abs(r + l);
                ans1 = l;
                ans2 = r;
            }

            if (l + r < 0) {
                left++;
                continue;
            }

            if (l + r > 0) {
                right--;
                continue;
            }

            break;
        }

        StringBuilder sb = new StringBuilder();
        sb.append(ans1).append(" ").append(ans2);
        System.out.println(sb);
    }
}
