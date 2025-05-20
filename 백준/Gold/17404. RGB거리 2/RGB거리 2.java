import java.util.*;
import java.io.*;

public class Main {

    static int N;
    static int[][] arr, dp;
    static final int INF = 1_000_000_001;

    static void solve() throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        arr = new int[N][3];
        dp = new int[N][3];
        int result = INF;

        for (int i=0; i<N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());

            for (int j=0; j<3; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        for (int i=0; i<3; i++) {

            for (int j=0; j<3; j++) {
                if (i == j) dp[0][j] = arr[0][j];
                else dp[0][j] = INF;
            }

            for (int j=1; j<N; j++) {
                dp[j][0] = Math.min(dp[j - 1][1], dp[j - 1][2]) + arr[j][0];
                dp[j][1] = Math.min(dp[j - 1][0], dp[j - 1][2]) + arr[j][1];
                dp[j][2] = Math.min(dp[j - 1][1], dp[j - 1][0]) + arr[j][2];
            }

            if (i == 0) dp[N - 1][0] = Math.min(dp[N - 1][1], dp[N - 1][2]);
            else if (i == 1) dp[N - 1][1] = Math.min(dp[N - 1][0], dp[N - 1][2]);
            else dp[N - 1][2] = Math.min(dp[N - 1][1], dp[N - 1][0]);

            for (int j=0; j<3; j++) {
                result = Math.min(result, dp[N - 1][j]);
            }
        }

        System.out.println(result);
    }

    public static void main(String[] args) throws Exception {

        solve();
    }
}
