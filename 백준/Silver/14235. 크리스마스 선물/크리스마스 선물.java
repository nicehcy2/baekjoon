import java.io.*;
import java.util.*;

public class Main {

    static int N;
    static Queue<Integer> pq = new PriorityQueue<>((a, b) -> b-a);

    static String solve() {

        if (pq.isEmpty()) {
            return "-1";
        }

        return String.valueOf(pq.poll());
    }

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;
        String result = "";

        N = Integer.parseInt(br.readLine());
        for (int i=0; i<N; i++) {
            st = new StringTokenizer(br.readLine());
            int a;
            a= Integer.parseInt(st.nextToken());

            for(int j=0; j<a; j++) {
                int gift = Integer.parseInt(st.nextToken());
                pq.offer(gift);
            }
            if (a == 0)
                result += (solve() + "\n");
        }
        bw.write(result);

        bw.flush();
        bw.close();
        br.close();
    }
}