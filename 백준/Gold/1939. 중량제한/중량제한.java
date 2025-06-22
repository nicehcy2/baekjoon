import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	static int N, M, S, E, mid = 0, result = 0;
	static ArrayList<Pair>[] graph;
	static boolean visited[];

	public static void main(String args[]) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());

		graph = new ArrayList[N + 1];
		visited = new boolean[N + 1];
		for (int i = 1; i <= N; i++) {
			graph[i] = new ArrayList<>();
		}

		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());
			int A = Integer.parseInt(st.nextToken());
			int B = Integer.parseInt(st.nextToken());
			int C = Integer.parseInt(st.nextToken());

			graph[A].add(new Pair(B, C));
			graph[B].add(new Pair(A, C));
		}
		st = new StringTokenizer(br.readLine());
		S = Integer.parseInt(st.nextToken());
		E = Integer.parseInt(st.nextToken());

		int start = 1, end = 1_000_000_000;

		while (start <= end) {

			mid = (start + end) / 2;

			Arrays.fill(visited, false);

			if (bfs(S)) {
				start = mid + 1;
				result = Math.max(result, mid);
			} else {
				end = mid - 1;
			}
		}

		System.out.println(result);
	}

	static boolean bfs(int start) {

		Queue<Integer> q = new LinkedList<>();
		q.add(start);
		visited[start] = true;

		while (!q.isEmpty()) {

			int cur = q.poll();

			if (cur == E) {
				return true;
			}

			for (int i = 0; i < graph[cur].size(); i++) {
				int nextIdx = graph[cur].get(i).dest;
				int nextLimit = graph[cur].get(i).weight;

				if (!visited[nextIdx] && nextLimit >= mid) {
					q.add(nextIdx);
					visited[nextIdx] = true;
				}
			}
		}

		return false;
	}

	static class Pair {
		public int dest;
		public int weight;

		public Pair(int dest, int weight) {
			this.dest = dest;
			this.weight = weight;
		}
	}
}