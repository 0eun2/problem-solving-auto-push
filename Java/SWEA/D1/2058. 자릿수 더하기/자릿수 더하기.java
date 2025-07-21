import java.util.*;
 
class Solution {
    public static void main(String args[]) throws Exception {
        Scanner sc = new Scanner(System.in);
        String n = sc.nextLine();
        int ans = 0;
 
        String[] tokens = n.split("");
        ArrayList<Integer> list = new ArrayList<>();
 
        for (String s : tokens){
            list.add(Integer.parseInt(s));
        }
 
        for (int i = 0; i < list.size(); i++){
            ans += list.get(i);
        }
        System.out.print(ans);
        sc.close();
    }
}