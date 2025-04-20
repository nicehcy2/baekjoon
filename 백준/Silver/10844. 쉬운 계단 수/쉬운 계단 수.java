import java.util.*;
import java.io.*;

public class Main {

    public static void solution() throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        long[][] dp = new long[101][10];
        final int MOD = 1000000000;
        long result = 0;

        for (int i=1; i<=9; i++) {
            dp[1][i] = 1;
        }

        for (int i=2; i<=N; i++) {
            for (int j=0; j<=9; j++) {
                if (j == 0) {
                    dp[i][j] = dp[i - 1][1] % MOD;
                } else if (j == 9) {
                    dp[i][j] = dp[i - 1][8] % MOD;
                } else {
                    dp[i][j] = ((dp[i - 1][j - 1] % MOD) + (dp[i - 1][j + 1] % MOD)) % MOD;
                }
            }
        }

        for (int i=0; i<=9; i++) {
            result = (result + dp[N][i]) % MOD;
        }

        System.out.println(result);
    }
    public static void main(String[] args) throws IOException {

        solution();
    }
}