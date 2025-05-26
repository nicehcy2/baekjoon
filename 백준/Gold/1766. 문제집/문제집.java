import java.util.*;
import java.io.*;

public class Main {

    static List<Integer>[] graph;
    static int[] indegree;
    static int N, M;
    static StringBuilder sb = new StringBuilder();

    static void topologySort() {

        Queue<Integer> q = new PriorityQueue<>();

        for (int t=1; t<=N; t++) {
            if (indegree[t] == 0) q.add(t);
        }

        while (!q.isEmpty()) {
            int cur = q.poll();
            sb.append(cur + " ");

            for (int i=0; i<graph[cur].size(); i++) {
                int next = graph[cur].get(i);
                indegree[next]--;

                if (indegree[next] == 0) {
                    q.add(next);
                }
            }
        }
    }

    static void solve() throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        graph = new ArrayList[N + 1];
        indegree = new int[N + 1];

        for (int i=1; i<=N; i++) {
            graph[i] = new ArrayList<>();
        }

        for (int i=0; i<M; i++) {

            st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());

            graph[from].add(to);

            indegree[to]++;
        }

        topologySort();

        System.out.println(sb);
    }

    public static void main(String[] args) throws Exception {

        solve();
    }
}
