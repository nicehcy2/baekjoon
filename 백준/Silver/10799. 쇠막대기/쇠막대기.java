import java.util.*;
import java.io.*;

public class Main {

    static Stack<Character> st = new Stack<>();

    static void solve() throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // StringTokenizer st = new StringTokenizer(br.readLine());
        String input = br.readLine();
        int result = 0;
        char prev = '.';

        for (int i=0; i<input.length(); i++) {

            if (input.charAt(i) == '(') {
                st.push('(');
            }
            else {
                st.pop();
                if (prev == '(') {
                    result += st.size();
                }
                else {
                    result += 1;
                }
            }

            prev = input.charAt(i);
        }

        System.out.println(result);
    }

    public static void main(String[] args) throws Exception {

        solve();
    }
}