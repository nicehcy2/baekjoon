import java.util.*;
import java.io.*;

public class Main {

    static int T, N, M;
    static long result = 0;
    static int[] A, B, prefixA, prefixB;
    static HashMap<Integer, Integer> map;

    static void solve() throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        T = Integer.parseInt(br.readLine());
        map = new HashMap<>();

        N = Integer.parseInt(br.readLine());
        A = new int[N];
        prefixA = new int[N + 1];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i=0; i<N; i++) {
            A[i] = Integer.parseInt(st.nextToken());
            prefixA[i + 1] = prefixA[i] + A[i];
        }

        M= Integer.parseInt(br.readLine());
        B = new int[M];
        prefixB = new int[M + 1];

        st = new StringTokenizer(br.readLine());
        for (int i=0; i<M; i++) {
            B[i] = Integer.parseInt(st.nextToken());
            prefixB[i + 1] = prefixB[i] + B[i];
        }

        for (int size=1; size<=M; size++) {
            for (int i=0; i<=M-size; i++) {
                int sum = prefixB[i + size] - prefixB[i];
                map.put(sum, map.getOrDefault(sum, 0) + 1);
            }
        }

        for (int size=1; size<=N; size++) {
            for (int i=0; i<= N - size; i++) {
                int keyA = prefixA[i + size] - prefixA[i];

                int keyB = T - keyA;
                if (map.containsKey(keyB)) {
                    result += map.get(keyB);
                }
            }
        }

        System.out.println(result);
    }

    public static void main(String[] args) throws Exception {

        solve();
    }
}
