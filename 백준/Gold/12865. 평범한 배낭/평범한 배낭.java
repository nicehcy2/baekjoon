import java.util.*;
import java.io.*;

public class Main {

    static int N, K;
    static int[][] arr;
    static int[][] P;

    static void solve() {

        for (int i=1; i<=N; i++) {
            for (int j=1; j<=K; j++) {
                int W = arr[i][0];
                int V = arr[i][1];

                if (j < W) P[i][j] = P[i - 1][j];
                else P[i][j] = Math.max(P[i - 1][j], V + P[i - 1][j - W]);
            }
        }

        System.out.println(P[N][K]);
    }

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        arr = new int[N + 1][2];
        P = new int[N + 1][K + 1];

        for (int i=0; i<N; i++) {
            st = new StringTokenizer(br.readLine());
            int W = Integer.parseInt(st.nextToken());
            int V = Integer.parseInt(st.nextToken());
            arr[i + 1][0] = W;
            arr[i + 1][1] = V;
        }

        solve();
    }
}