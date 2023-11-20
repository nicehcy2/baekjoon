import java.io.*;
import java.util.PriorityQueue;

public class Main {
    public static int x;
    public static final int init = 64;

    public static void main(String[] args) throws Exception {
        Input();
        Solve();
    }

    static void Input() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        x = Integer.valueOf(br.readLine());
    }

    static void Solve() throws Exception {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        pq.add(init);

        int sum = init, cnt = 0;
        while (true) {
            if (sum == x) {
                break;
            } else if (sum > x) {
                int min = pq.poll();
                if (sum - (min / 2) >= x) {
                    pq.add(min / 2);
                    sum = sum - min / 2;
                } else {
                    pq.add(min / 2);
                    pq.add(min / 2);
                }
            }
        }

        System.out.println(pq.size());
    }
}