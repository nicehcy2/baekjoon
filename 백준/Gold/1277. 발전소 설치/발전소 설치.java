
import java.util.*;
import java.io.*;

public class Main {

    static int N, W;
    static double M;
    static Pos[] nodePos;
    static ArrayList<Node>[] graph;
    static double[] dist;

    static class Node {
        int dest;
        double cost;

        Node(int dest, double cost) {
            this.dest = dest;
            this.cost = cost;
        }
    }

    static class Pos {
        int y;
        int x;

        Pos(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }

    static void solve() throws Exception {

        PriorityQueue<Node> pq = new PriorityQueue<>((o1, o2) -> Double.compare(o1.cost, o2.cost));
        pq.add(new Node(1, 0));
        dist[1] = 0;

        while (!pq.isEmpty()) {

            Node cur = pq.poll();

            if (dist[cur.dest] < cur.cost) continue;

            for (int i=0; i<graph[cur.dest].size(); i++) {

                Node next = graph[cur.dest].get(i);

                if (dist[next.dest] > dist[cur.dest] + next.cost) {
                    dist[next.dest] = dist[cur.dest] + next.cost;
                    pq.add(new Node(next.dest, dist[next.dest]));
                }
            }
        }

        long answer = (long)(dist[N] * 1000);
        System.out.println(answer);
    }

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        W = Integer.parseInt(st.nextToken());

        M = Double.parseDouble(br.readLine());

        nodePos = new Pos[N + 1];
        graph = new ArrayList[N + 1];
        dist = new double[N + 1];
        Arrays.fill(dist, Double.POSITIVE_INFINITY);

        for (int i=1; i<=N; i++) {
            st= new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());

            nodePos[i] = new Pos(y, x);
        }

        for (int i=1; i<=N; i++) {

            graph[i] = new ArrayList<>();
        }

        for (int i=0; i<W; i++) {
            st= new StringTokenizer(br.readLine());
            int s = Integer.parseInt(st.nextToken());
            int e = Integer.parseInt(st.nextToken());

            graph[s].add(new Node(e, 0));
            graph[e].add(new Node(s, 0));
        }

        // 가능성이 있는 edge 계산 후 추가
        for (int i=1; i<=N; i++) {
            int cy = nodePos[i].y;
            int cx = nodePos[i].x;

            for (int j=1; j<=N; j++) {
                if (i == j) continue;

                int ny = nodePos[j].y;
                int nx = nodePos[j].x;

                double dist = Math.sqrt((Math.pow((long)ny - cy, 2) + Math.pow((long)nx - cx, 2)));
                if (dist <= M) {
                    graph[i].add(new Node(j, dist));
                }
            }
        }

        solve();
    }
}