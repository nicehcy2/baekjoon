import java.io.*;
import java.util.*;

public class Main {

    static int N;
    static int[][] arr;

    public static void solution() throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        arr = new int[N][2];
        double sum1 = 0, sum2 = 0;

        for (int i=0; i<N; i++) {
            st = new StringTokenizer(br.readLine());
            arr[i][0] = Integer.parseInt(st.nextToken());
            arr[i][1] = Integer.parseInt(st.nextToken());
        }

        for (int i=0; i< N; i++) {
            sum1 += (double) arr[i][0] * arr[(i + 1) % N][1];
            sum2 += (double) arr[i][1] * arr[(i + 1) % N][0];
        }

        System.out.printf("%.1f\n", Math.abs(sum2 - sum1) / 2);
    }

    public static void main(String[] args) throws IOException {

        solution();
    }
}