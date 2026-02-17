import java.util.*;
import java.io.*;

public class Main {

    static int N, result = Integer.MAX_VALUE;
    static int[][] arr;

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        N = Integer.parseInt(br.readLine());
        arr = new int[N][2];

        for (int i=0; i<N; i++) {
            st = new StringTokenizer(br.readLine());
            arr[i][0] = Integer.parseInt(st.nextToken());
            arr[i][1] = Integer.parseInt(st.nextToken());
        }

        solve();
        System.out.println(result);

        br.close();
    }

    static void solve() {

        int maxMask = (1 << N);

        for (int mask = 1; mask < maxMask; mask++) {

            int S = 1, B = 0;
            for (int i=0; i<N; i++) {
                if ((mask & (1<<i)) != 0) {
                    S *= arr[i][0];
                    B += arr[i][1];
                }
            }

            result = Math.min(Math.abs(S - B), result);
        }
    }
}
