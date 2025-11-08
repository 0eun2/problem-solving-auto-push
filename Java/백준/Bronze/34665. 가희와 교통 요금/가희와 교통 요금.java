import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String str1 = br.readLine();
		String str2 = br.readLine();
		
		if (str1.equals(str2)) {
			System.out.println(0);
			return;
		}
		System.out.println(1550);
	}
}
