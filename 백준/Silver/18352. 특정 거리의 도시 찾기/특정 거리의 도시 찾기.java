import java.util.*;
import java.io.*;

public class Main {

    static int N, M, K, X, answer = 0;
    static ArrayList<Integer>[] graph;
    static int[] dist;

    static void solve() throws Exception {

        PriorityQueue<Node> pq = new PriorityQueue<>((o1, o2) -> Integer.compare(o1.cost, o2.cost));
        pq.add(new Node(X, 0));
        dist[X] = 0;

        while (!pq.isEmpty()) {

            Node cur = pq.poll();

            // 꺼낸 노드 = 현재 최소 비용을 갖는 노드
            // 해당 노드의 비용이 현재 dist 배열에 기록된 내용보다 크다면 고려할 필요가 없으므로 스킵.
            // 생략할 경우 이미 방문해서 최소를 구한 정점을 중복하여 방문하게 된다.
            if (dist[cur.idx] < cur.cost) continue;

            for (int i=0; i<graph[cur.idx].size(); i++) {
                int next = graph[cur.idx].get(i);

                if (dist[next] > dist[cur.idx] + 1) {
                    dist[next] = dist[cur.idx] + 1;
                    pq.add(new Node(next, dist[cur.idx] + 1));
                }
            }
        }

        StringBuilder sb = new StringBuilder();
        for (int i=1; i<=N; i++) {
            if (dist[i] == K) sb.append(i).append("\n");
        }
        if (sb.isEmpty()) System.out.println("-1");
        else System.out.println(sb);
    }

    static class Node {
        int idx;
        int cost;

        Node(int idx, int cost) {
            this.idx = idx;
            this.cost = cost;
        }
    }


    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        X = Integer.parseInt(st.nextToken());

        graph = new ArrayList[N + 1];
        dist = new int[N + 1];
        Arrays.fill(dist, Integer.MAX_VALUE);

        for (int i=1; i<=N; i++) {
            graph[i] = new ArrayList<>();
        }
        for (int i=0; i<M; i++) {
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());

            graph[start].add(end);
        }

        solve();
    }
}