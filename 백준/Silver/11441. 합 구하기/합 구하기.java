import java.util.*;
import java.io.*;

public class Main {

    static int N, M;
    static int[] prefixSum;

    static void solve() {
    }

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        prefixSum = new int[N + 1];
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();

        for (int i=0; i<N; i++) {
            prefixSum[i + 1] = Integer.parseInt(st.nextToken()) + prefixSum[i];
        }
        M = Integer.parseInt(br.readLine());
        for (int i=0; i<M; i++) {
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());

            sb.append(prefixSum[end] - prefixSum[start - 1]).append("\n");
        }

        System.out.println(sb.toString());

        solve();
    }
}