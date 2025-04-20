import java.util.*;
import java.io.*;

public class Main {

    public static void solution() throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        long[][][] dp = new long[101][10][1024];
        final int MOD = 1000000000;
        long result = 0;

        for (int i=1; i<=9; i++) {
            int bit = (1 << i);
            dp[1][i][bit] = 1;
        }

        for (int i=2; i<=N; i++) {
            for (int j=0; j<=9; j++) {
                for (int k=0; k<1024; k++) {
                    // 특정 수가 가질 수 있는 숫자의 개수를 int형 bit로 나타냄 -> bit masking
                    // bit는 마지막 자리에 숫자를 추가했을 경우 숫자의 개수
                    // k는 마지막 자리에 숫자를 추가하기 전에 숫자의 개수
                    // k를 반복하는 이유는 dp[N][D] 만으로는 끝자리 숫자가 D인 개수만 알 수 있기에 문제를 풀 수 없음.
                    // 그러기에 우리는 특정 수들이 가질 수 있는 숫자의 개수를 생각해야 한다.
                    // 00 0000 0000 특정 수가 9~0의 숫자를 가지고 있는지 10비트로 나타낸다.

                    int bit = k | (1 << j); // 비트마스킹에 원소 추가

                    if (j == 0) {
                        dp[i][j][bit] = (dp[i][j][bit] + dp[i - 1][j + 1][k]) % MOD;
                    } else if (j == 9) {
                        dp[i][j][bit] = (dp[i][j][bit] + dp[i - 1][j - 1][k]) % MOD;
                    } else {
                        dp[i][j][bit] = (dp[i][j][bit] + dp[i - 1][j - 1][k] + dp[i - 1][j + 1][k]) % MOD;
                    }
                }
            }
        }

        for (int i=0; i<=9; i++) {
            // 1023 = 0b1111111111
            result = (result + dp[N][i][1023]) % MOD;
        }

        System.out.println(result);
    }
    public static void main(String[] args) throws IOException {

        solution();
    }
}