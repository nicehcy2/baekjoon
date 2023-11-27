import java.io.*;
import java.util.*;

public class Main {
    public static int n, m;
    public static int[] parent = new int[201];


    public static void main(String[] args) throws Exception {
        Input();
        Solve();
    }

    static void Input() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        n = Integer.valueOf(br.readLine());
        m = Integer.valueOf(br.readLine());

        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }

        for (int i = 1; i <= n; i++) {
            st = new StringTokenizer(br.readLine());

            for (int j = 1; j <= n; j++) {
                int edge = Integer.parseInt(st.nextToken());
                if (edge == 1) {
                    union(i, j);
                }
            }
        }

        st = new StringTokenizer(br.readLine());

        int start = find(Integer.parseInt(st.nextToken()));
        for (int i = 1; i < m; i++) {
            int now = Integer.parseInt(st.nextToken());

            if (start != find(now)) {
                System.out.println("NO");
                return;
            }
        }

        System.out.println("YES");
    }

    static int find(int x) {
        if (parent[x] == x) {
            return x;
        } else {
            return find(parent[x]);
        }
    }

    static void union(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);

        if (rootA < rootB) parent[rootB] = rootA;
        else parent[rootA] = rootB;

    }

    static void Solve() throws Exception {
    }
}