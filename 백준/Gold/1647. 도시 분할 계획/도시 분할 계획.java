import java.util.*;
import java.io.*;

public class Main {

    static int N, M, result = 0, cnt = 0;
    static int[] parent;
    static int[][] graph;

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        graph = new int[M][3];
        parent = new int[N + 1];

        for (int i=0; i<M; i++) {
            st = new StringTokenizer(br.readLine());
            graph[i][0] = Integer.parseInt(st.nextToken());
            graph[i][1] = Integer.parseInt(st.nextToken());
            graph[i][2] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(graph, (o1, o2) -> Integer.compare(o1[2], o2[2]));
        for (int i=1; i<=N; i++) parent[i] = i;

        for (int i=0; i<M; i++) {

            if (find(graph[i][0]) != find(graph[i][1])) {
                if (cnt++==N-2) break;

                result += graph[i][2];
                union(graph[i][0], graph[i][1]);
            }
        }

        System.out.println(result);
        br.close();
    }

    static int find(int x) {

        if (parent[x] == x) return x;
        else return parent[x] = find(parent[x]);
    }

    static void union(int x, int y) {

        x = find(x);
        y = find(y);

        if (x > y) parent[x] = y;
        else parent[y] = x;
    }
}