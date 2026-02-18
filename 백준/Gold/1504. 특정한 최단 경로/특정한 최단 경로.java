import java.util.*;
import java.io.*;

public class Main {

    static int N, E, V1, V2;
    static List<int[]>[] graph;
    static boolean[] visited;
    static int[] dist;

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        E = Integer.parseInt(st.nextToken());
        graph = new ArrayList[N + 1];
        visited = new boolean[N + 1];
        dist = new int[N + 1];

        for (int i=1; i<=N; i++) graph[i] = new ArrayList<>();

        for (int i=0; i<E; i++) {
            st = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(st.nextToken());
            int e = Integer.parseInt(st.nextToken());
            int cost = Integer.parseInt(st.nextToken());

            graph[s].add(new int[]{e, cost});
            graph[e].add(new int[]{s, cost});
        }
        st = new StringTokenizer(br.readLine());
        V1 = Integer.parseInt(st.nextToken());
        V2 = Integer.parseInt(st.nextToken());

        // 주의사항: V1과 V2의 순서는 상관없다. 더 적합한걸 방문해야됨.
        // 1 -> V1 -> V2 -> N
        // 1 -> V2 -> V1 -> N
        int result1 = 0, result2 = 0, result;

        result1 += dijkstra(1, V1);
        result1 += dijkstra(V1, V2);
        result1 += dijkstra(V2, N);

        result2 += dijkstra(1, V2);
        result2 += dijkstra(V2, V1);
        result2 += dijkstra(V1, N);

        result = Math.min(result1, result2);
        if (result >= 700000000) result = -1;
        System.out.println(result);

        br.close();
    }

    static int dijkstra(int start, int target) {

        Arrays.fill(visited, false);
        Arrays.fill(dist, Integer.MAX_VALUE);

        PriorityQueue<int[]> pq = new PriorityQueue<>((o1, o2) -> Integer.compare(o1[1], o2[1]));
        pq.add(new int[]{start, 0});
        dist[start] = 0;

        while (!pq.isEmpty()) {
            int[] cur = pq.poll();
            int curVertex = cur[0];

            if (visited[curVertex]) continue;;

            visited[curVertex] = true;

            for (int i=0; i<graph[curVertex].size(); i++) {
                int nextVertex = graph[curVertex].get(i)[0];
                int nextCost = graph[curVertex].get(i)[1];

                if (dist[nextVertex] > dist[curVertex] + nextCost) {
                    dist[nextVertex] = dist[curVertex] + nextCost;
                    pq.add(new int[]{nextVertex, dist[nextVertex]});
                }
            }
        }

        return dist[target] == Integer.MAX_VALUE ? 700000000 : dist[target];
    }
}