import java.util.*;
import java.io.*;

public class Main {

    static int N, M;
    static List<Integer>[] graph;
    static boolean[] visited;
    static int[] indegree;

    // 위상 정렬
    static void topologySort() {
        List<Integer> results = new ArrayList<>();
        Queue<Integer> q = new LinkedList<>();

        for (int i=1; i<=N; i++) {
            if (indegree[i] == 0) q.offer(i);
        }

        while (!q.isEmpty()) {

            int now = q.poll();
            results.add(now);

            for (int i=0; i<graph[now].size(); i++) {
                indegree[graph[now].get(i)] -= 1;

                if (indegree[graph[now].get(i)] == 0) {
                    q.offer(graph[now].get(i));
                }
            }
        }

        for (int i=0; i<results.size(); i++) {
            System.out.print(results.get(i) + " ");
        }
    }

    static void solve() throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        graph = new ArrayList[N + 1];
        indegree = new int[N + 1];
        for (int i=0; i<=N; i++) {
            graph[i] = new ArrayList<>();
        }

        for (int i=0; i<M; i++) {
            st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            graph[from].add(to); // 정점 from에서 to로 이동 가능
            indegree[to]++; // 진입 차수 1 증가
        }

        topologySort();
    }

    public static void main(String[] args) throws Exception {

        solve();
    }
}
