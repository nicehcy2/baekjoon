import java.util.*;
import java.io.*;

public class Main {

    static int N;

    static void solve() {
    }

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());

        int min = Integer.MAX_VALUE, max = Integer.MIN_VALUE;
        for (int i=0; i<N; i++) {
            int num = Integer.parseInt(st.nextToken());
            min = Math.min(min, num);
            max = Math.max(max, num);
        }

        System.out.println(min * max);

        solve();
    }
}