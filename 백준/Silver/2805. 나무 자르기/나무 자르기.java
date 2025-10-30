import java.util.*;
import java.io.*;

public class Main {

    static long N, M;
    static long[] arr;

    static void solve() {

        long s = 1, e = 1000000000, answer = 0;
        while(s <= e) {

            long m = (s + e) / 2;
            long count = 0;
            for (int i=0; i<N; i++) {
                count += (arr[i] - m > 0 ? arr[i] - m : 0);
            }

            if (count < M) {
                e = m - 1;

            } else {
                s = m + 1;
                answer = Math.max(answer, m);
            }
        }

        System.out.println(answer);
    }

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Long.parseLong(st.nextToken());
        M = Long.parseLong(st.nextToken());
        arr = new long[(int) N];

        st = new StringTokenizer(br.readLine());
        for (int i=0; i<N; i++) {
            arr[i] = Long.parseLong(st.nextToken());
        }

        solve();
    }
}