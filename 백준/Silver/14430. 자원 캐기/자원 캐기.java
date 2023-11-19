import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static int n, m;
    public static int[][] map, dp;

    public static int[] dx = {1, 0};
    public static int[] dy = {0, 1};


    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        map = new int[n + 1][m + 1];
        dp = new int[n + 1][m + 1];

        for (int i = 1; i <= n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= m; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int first = (i - 1 < 1) ? 0 : dp[i - 1][j];
                int second = (j - 1 < 1) ? 0 : dp[i][j - 1];
                dp[i][j] += map[i][j] + Math.max(first, second);
            }
        }

        System.out.println(dp[n][m]);
    }
}