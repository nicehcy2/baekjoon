import java.util.*;
import java.io.*;

public class Main {


    static void solve() throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(br.readLine());
        String input = br.readLine();

        int count = 0;
        for (int i=0; i<N; i++) {

            char cur = input.charAt(i);
            if (i + 1 >= N) break;

            if (cur == 'E' && input.charAt(i + 1) == 'W') count++;
        }

        System.out.println(count);
    }

    public static void main(String[] args) throws Exception {

        solve();
    }
}
