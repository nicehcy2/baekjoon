import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static int N, Q;
	static int[] arr, dp;

	public static void main(String args[]) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		arr = new int[N + 1];
		dp = new int[N + 1];

		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 1; i <= N; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}

		for (int i = 1; i < N; i++) {
			dp[i] = dp[i - 1] + (arr[i] > arr[i + 1] ? 1 : 0);
		}
		dp[N] = dp[N - 1];

		StringBuilder sb = new StringBuilder();
		Q = Integer.parseInt(br.readLine());
		for (int i = 0; i < Q; i++) {
			st = new StringTokenizer(br.readLine());
			int X = Integer.parseInt(st.nextToken());
			int Y = Integer.parseInt(st.nextToken());

			sb.append(dp[Y - 1] - dp[X - 1]).append("\n");
		}

		System.out.println(sb);
	}
}