import java.util.*;
import java.io.*;

public class Main {

    static int N, M;
    static int[][] prefixSum;

    static void solve() {

        int max = Integer.MIN_VALUE;
        for (int i=1; i<=N; i++) {
            for (int j=1; j<=i; j++) {
                for (int k=1; k<=M; k++) {
                    for (int l=1; l<=k; l++) {

                        max = Integer.max(max, prefixSum[i][k] + prefixSum[j - 1][l - 1] - prefixSum[i][l - 1] - prefixSum[j - 1][k]);
                    }
                }
            }
        }

        System.out.println(max);
    }

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        prefixSum = new int[N + 1][M + 1];

        for (int i=0; i<N; i++) {

            st = new StringTokenizer(br.readLine());
            for (int j=0; j<M; j++) {
                prefixSum[i + 1][j + 1] = prefixSum[i][j + 1] + prefixSum[i + 1][j] - prefixSum[i][j] + Integer.parseInt(st.nextToken());
            }
        }

        solve();
    }
}