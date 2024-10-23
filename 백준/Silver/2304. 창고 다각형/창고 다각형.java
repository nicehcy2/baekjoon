import java.io.*;
import java.util.*;

public class Main {

    static int N, maxHeight = -1, maxHeightIdx = -1, minFirst = 10000, maxLast = -1;
    static int[] arr = new int[1001];

    static int solve() {

        int area = 0;
        int max = arr[minFirst];

        for (int i=minFirst; i<=maxHeightIdx; i++) {
            if (max < arr[i]) {
                max = arr[i];
            }

            area += max;
        }

        max = arr[maxLast];
        for (int i=maxLast; i>maxHeightIdx; i--) {
            if (max < arr[i]) {
                max = arr[i];
            }

            area += max;
        }

        return area;
    }

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        N = Integer.parseInt(br.readLine());
        for (int i=0; i<N; i++) {
            int k, v;
            st = new StringTokenizer(br.readLine());
            k = Integer.parseInt(st.nextToken());
            v = Integer.parseInt(st.nextToken());

            if (maxHeight < v) {
                maxHeight = v;
                maxHeightIdx = k;
            }
            minFirst = Math.min(minFirst, k);
            maxLast = Math.max(maxLast, k);

            arr[k] = v;
        }

        int result = solve();
        bw.write(String.valueOf(result));

        bw.flush();
        bw.close();
        br.close();
    }
}