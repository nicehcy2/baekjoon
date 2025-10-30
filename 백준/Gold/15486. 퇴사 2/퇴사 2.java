import java.util.*;
import java.io.*;

public class Main {

    static int N, answer = 0;
    static int[][] arr;
    static int[] dp;

    static void solve() {

        for (int i=N; i>0; i--) {

            int endDay = i + arr[i][0];
            int profit = arr[i][1];
            if (endDay <= N + 1) {
                dp[i] = Math.max(dp[endDay] + profit, dp[i + 1]);
            }
            else dp[i] = dp[i + 1];

            answer = Math.max(dp[i], answer);
        }

        System.out.println(answer);
    }

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        StringTokenizer st;
        arr = new int[N + 1][2];
        dp = new int[(N + 2) * 2];

        for (int i=0; i<N; i++) {
            st= new StringTokenizer(br.readLine());
            arr[i + 1][0] = Integer.parseInt(st.nextToken());
            arr[i + 1][1] = Integer.parseInt(st.nextToken());
        }

        solve();
    }
}