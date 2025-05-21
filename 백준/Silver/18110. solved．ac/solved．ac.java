import java.util.*;
import java.io.*;

public class Main {

    static void solve() throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int[] arr = new int[N];
        for (int i=0; i<N; i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }

        Arrays.sort(arr);

        int bound = (int) Math.round(N * 0.15);
        int sum = 0;
        for (int i=bound; i<N-bound; i++) {
            sum += arr[i];
        }

        System.out.println(Math.round((double) sum / (N - bound * 2)));
    }

    public static void main(String[] args) throws Exception {

        solve();
    }
}
