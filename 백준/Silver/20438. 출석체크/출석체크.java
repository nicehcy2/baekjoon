import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {

	static int N, K, Q, M;
	static int[] selects, dp;
	static boolean[] visited;
	static HashMap<Integer, Boolean> sleepMap = new HashMap<>();

	public static void main(String args[]) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();

		N = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		Q = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		selects = new int[Q];
		visited = new boolean[N + 3];
		dp = new int[N + 3];

		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < K; i++) {
			int num = Integer.parseInt(st.nextToken());
			sleepMap.put(num, true);
		}

		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < Q; i++) {
			int num = Integer.parseInt(st.nextToken());
			selects[i] = num;

			if (sleepMap.containsKey(num)) {
				continue;
			}

			int mul = 1;
			while (true) {
				if (num * mul > N + 2) {
					break;
				}

				if (sleepMap.containsKey(num * mul)) {
					mul++;
					continue;
				}
				visited[num * mul] = true;
				mul++;
			}
		}

		int count = 0;
		for (int i = 3; i < N + 3; i++) {
			dp[i] = dp[i - 1] + (visited[i] ? 0 : 1);
		}

		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());
			int S = Integer.parseInt(st.nextToken());
			int E = Integer.parseInt(st.nextToken());

			sb.append(dp[E] - dp[S - 1]).append("\n");
		}

		System.out.println(sb);
	}
}