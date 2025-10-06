import java.util.*;
import java.io.*;

public class Main {

    static int N, M;
    static int[] T;

    static void solve() throws Exception {

        Arrays.sort(T);
        long start = 1, end = (long)T[T.length - 1] * M;
        long answer = end;

        while (start <= end) {

            long mid = (start + end) / 2;

            long sum = 0;
            for (int i=0; i<N; i++) {
                sum += (mid / T[i]);
                if (sum >= M) break;
            }

            if (sum >= M) {
                end = mid - 1;
                answer = Math.min(answer, mid);
            }
            else {
                start = mid + 1;
            }
        }

        System.out.println(answer);
    }

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        T = new int[N];

        for (int i=0; i<N; i++) {
            T[i] = Integer.parseInt(br.readLine());
        }

        solve();
    }
}