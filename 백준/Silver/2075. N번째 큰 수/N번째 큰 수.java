import java.util.*;
import java.io.*;

public class Main {

    static int N;
    static PriorityQueue<Integer> pq = new PriorityQueue<>();

    static void solve() {
    }

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        StringTokenizer st;

        for (int i=0; i<N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j=0; j<N; j++) {
                int num = Integer.parseInt(st.nextToken());
                if (pq.size() < N) pq.add(num);
                else {
                    if (pq.peek() < num) {
                        pq.poll();
                        pq.add(num);
                    }
                }
            }
        }

        System.out.println(pq.poll());

        solve();
    }
}