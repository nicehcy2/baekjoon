import java.io.*;
import java.util.*;

public class Main {
    public static int t;
    public static int x, y;


    public static void main(String[] args) throws Exception {
        Input();
        // Solve();
    }

    static void Input() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        t = Integer.valueOf(br.readLine());
        for (int i = 0; i < t; i++) {
            st = new StringTokenizer(br.readLine());
            x = Integer.parseInt(st.nextToken());
            y = Integer.parseInt(st.nextToken());
            Solve();
        }
    }

    static void Solve() throws Exception {
        int cnt = 2;
        int diff = y - x;
        int move = 2;

        if (diff == 1) {
            System.out.println(1);
            return;
        }

        int max = (int) Math.sqrt(diff);

        if (max == Math.sqrt(diff)) {
            cnt = 2 * max - 1;
        } else if (diff <= max * max + max) {
            cnt = 2 * max;
        } else {
            cnt = 2 * max + 1;
        }

        System.out.println(cnt);
    }
}