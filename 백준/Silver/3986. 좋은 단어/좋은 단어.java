import java.io.*;
import java.util.*;

public class Main {

    static int N, result = 0;

    static int solve(String word) {

        Stack<Character> st = new Stack<>();

        if (word.length() % 2 == 1) return 0;

        st.push(word.charAt(0));
        for (int i=1; i< word.length(); i++) {
            if (st.size() > 0 && st.peek() == word.charAt(i)) {
                st.pop();
            } else {
                st.push(word.charAt(i));
            }
        }

        if (st.empty()) return 1;
        else return 0;
    }

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        N = Integer.parseInt(br.readLine());
        for (int i=0;i<N; i++) {
            st= new StringTokenizer(br.readLine());
            String word = st.nextToken();
            result += solve(word);
        }

        bw.write(String.valueOf(result));

        bw.flush();
        bw.close();
        br.close();
    }
}