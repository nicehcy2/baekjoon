import java.util.*;
import java.io.*;

public class Main {

    static void solve() throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int E = Integer.parseInt(st.nextToken());
        int S = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        int count = 1, le = 1, ls = 1, lm = 1;

        while(true) {

            if (le == E && ls == S && lm == M) {
                System.out.println(count);
                break;
            }
            le = (le % 15) + 1;
            ls = (ls % 28) + 1;
            lm = (lm % 19) + 1;

            count++;
        }
    }

    public static void main(String[] args) throws Exception {

        solve();
    }
}
