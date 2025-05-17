import java.util.*;
import java.io.*;

public class Main {

    static int N, K;
    static List<int[]> list;
    static int[][] dp;

    static void solve() throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        list = new ArrayList<>();
        dp = new int[N + 1][K + 1];

        for (int i=0; i<N; i++) {
            st = new StringTokenizer(br.readLine());
            int W = Integer.parseInt(st.nextToken());
            int V = Integer.parseInt(st.nextToken());
            list.add(new int[]{W, V});

            for (int j=W; j<=K; j++) {
                dp[i][j] = V;
            }
        }

        for (int i=1; i<N; i++) {
            for (int j = 1; j <= K; j++) {
                if (j - list.get(i)[0] >= 0) {
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j] + dp[i - 1][j - list.get(i)[0]]);
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        System.out.println(dp[N - 1][K]);
    }

    public static void main(String[] args) throws Exception {

        solve();
    }
}
