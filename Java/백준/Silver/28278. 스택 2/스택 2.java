import java.io.*;
import java.util.*;

public class Main
{
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int n = Integer.parseInt(br.readLine());
		Stack<Integer> stack = new Stack<Integer>();
		
		while (n-- > 0) {
		    StringTokenizer st = new StringTokenizer(br.readLine());
		    int cmd = Integer.parseInt(st.nextToken());
		    switch (cmd) {
		        case 1:
		            int x = Integer.parseInt(st.nextToken());
		            stack.push(x);
		            break;
                case 2:
                    System.out.println(stack.isEmpty() ? -1 : stack.pop());
                    break;
                case 3:
                    System.out.println(stack.size());
                    break;
                case 4:
                    System.out.println(stack.isEmpty() ? 1 : 0);
                    break;
                case 5:
                    System.out.println(stack.isEmpty() ? -1 : stack.peek());
                    break;
		    }
		}
	}
}
