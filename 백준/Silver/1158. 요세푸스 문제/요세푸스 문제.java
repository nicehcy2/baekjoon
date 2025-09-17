import java.util.*;
import java.io.*;

public class Main {

    static int N, K;
    static Queue<Integer> lq = new LinkedList<>();
    static Queue<Integer> dq = new LinkedList<>();

    static void solve() throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        for (int i=1; i<=N; i++) {
            lq.add(i);
        }

        while (!lq.isEmpty()) {

            for (int i=0; i< K - 1; i++) {
                int live = lq.poll();
                lq.add(live);
            }
            int dead = lq.poll();
            dq.add(dead);
        }

        System.out.print("<");
        while (!dq.isEmpty()) {
            System.out.print(dq.poll());
            if (dq.size() > 0) {
                System.out.print(", ");
            }
        }
        System.out.print(">");
    }

    public static void main(String[] args) throws Exception {

        solve();
    }
}
