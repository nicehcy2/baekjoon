import java.util.*;
import java.io.*;

public class Main {

    static int N, K;
    static int[] prefixSum;

    static void solve() {

        int max = -1 * Integer.MAX_VALUE;
        for (int i=0+K; i<=N; i++) {
            max = Math.max(max, prefixSum[i] - prefixSum[i - K]);
        }
        System.out.println(max);
    }

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        prefixSum = new int[N + 1];

        st = new StringTokenizer(br.readLine());
        for (int i=0; i<N; i++) {
            int num = Integer.parseInt(st.nextToken());
            prefixSum[i + 1] = prefixSum[i] + num;
        }

        solve();
    }
}