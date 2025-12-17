import java.util.*;
import java.io.*;

public class Main {

    static int N, M;
    static int[][] prefixSum;
    static int[] rowSum;

    static void solve() {

        int max = Integer.MIN_VALUE;

        for (int i=1; i<=M; i++) {
            for (int j=i; j<=M; j++) {
                for (int row = 1; row<=N; row++) {

                    rowSum[row] = prefixSum[row][j] - prefixSum[row][i - 1];
                }

                int cur = kadane();
                max = Math.max(max, cur);
            }
        }

        System.out.println(max);
    }

    static int kadane() {

        int[] dp = new int[N + 1];
        dp[0] = 0;
        int max = rowSum[1];
        for (int i=1; i<=N; i++) {
            dp[i] = Math.max(rowSum[i], dp[i - 1] + rowSum[i]);
            max = Math.max(dp[i], max);
        }
        return max;
    }

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        prefixSum = new int[N + 1][M + 1];
        rowSum = new int[N + 1];

        for (int i=0; i<N; i++) {

            st = new StringTokenizer(br.readLine());
            for (int j=0; j<M; j++) {
                prefixSum[i + 1][j + 1] = prefixSum[i + 1][j] + Integer.parseInt(st.nextToken());
            }
        }

        solve();
    }
}