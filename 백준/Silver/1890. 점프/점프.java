import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static int n;

    public static long[][] arr, dp;

    public static void main(String[] args) throws Exception {
        Input();
        Solve();
    }

    static void Input() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        n = Integer.parseInt(br.readLine());
        arr = new long[n + 1][n + 1];
        dp = new long[n + 1][n + 1];

        for (int i = 1; i <= n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= n; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }
    }

    static void Solve() throws Exception {
        dp[1][1] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                long move = arr[i][j];
                if (dp[i][j] >= 1 && move != 0) {
                    if (i + move <= n) {
                        dp[i + (int) move][j] += dp[i][j];
                    }
                    if (j + move <= n) {
                        dp[i][j + (int) move] += dp[i][j];
                    }
                }
            }
        }

        System.out.println(dp[n][n]);
    }
}