import java.io.*;
import java.util.*;

public class Main {

    static int N, M;
    static int[] arr;

    static boolean isPossible(int K) {

        int money = 0, count = 0;

        for (int i=0; i<N; i++) {

            if (money < arr[i]) {
                count++;
                money = K - arr[i];
            } else {
                money -= arr[i];
            }
        }

        if (count <= M) return true;
        else return false;
    }

    public static void solution() throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        arr = new int[N];
        int start = 0, end = 0, mid;

        for (int i=0; i<N; i++) {
            arr[i] = Integer.parseInt(br.readLine());
            start = Math.max(start, arr[i]);
            end += arr[i];
        }

        while (start <= end) {

            mid = (start + end) / 2;

            if (isPossible(mid)) {
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }

        System.out.println(start);
    }


    public static void main(String[] args) throws IOException {

        solution();
    }
}