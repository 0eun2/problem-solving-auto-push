import java.util.*;
import java.io.*;
 
class Solution
{
    public static void main(String args[]) throws Exception
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
         
        for(int tc = 1; tc <= T; tc++)
        {
            int ans = 0;
            char temp = '0';
            String origin = br.readLine();
             
            for (char c : origin.toCharArray()) {
                if (c == temp)
                    continue;
                temp = (temp == '0' ? '1' : '0');
                ans++;
            }
            System.out.println("#" + tc + " " + ans);
        }
    }
}