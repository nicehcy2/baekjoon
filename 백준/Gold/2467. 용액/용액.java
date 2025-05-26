import java.util.*;
import java.io.*;

public class Main {

    static int N;
    static int[] arr;

    static void solve() throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        arr = new int[N + 1];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i=0; i<N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        int start = 0, end = N - 1, diff = 2000000002, min = 1000000001, max = -1000000001;

        while (start < end) {
            int sum = arr[start] + arr[end];

            if (diff > Math.abs(sum)) {
                diff = Math.abs(sum);
                min = arr[start];
                max = arr[end];
            }

            if (sum > 0) end--;
            else if (sum < 0) start++;
            else {
                min = arr[start];
                max = arr[end];
                break;
            }
        }

        System.out.println(min + " " + max);
    }

    public static void main(String[] args) throws Exception {

        solve();
    }
}
