import java.util.*;
import java.io.*;

public class Main {

    static int N, K, answer;
    static ArrayList<Integer> list = new ArrayList<>();

    static void solve() {

        int start = 0, end = 0, count = 0;

        while (end < N && start <= end) {
            if (list.get(end++) == 1) count++;

            while (start < N && count >= K) {
                answer = Math.min(answer, end - start);
                if (list.get(start++) == 1) count--;
            }
        }

        System.out.println(answer);
    }

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        answer = N;

        st = new StringTokenizer(br.readLine());
        int rianCnt = 0;
        for (int i=0; i<N; i++) {
            int num = Integer.valueOf(st.nextToken());
            if (num == 1) rianCnt++;
            list.add(num);
        }

        if (rianCnt < K) {
            System.out.println(-1);
            return;
        }

        solve();
    }
}