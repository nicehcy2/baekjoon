import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static int T, N, M, K;
	static int[] arr;

	public static void main(String args[]) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		T = Integer.parseInt(br.readLine());
		StringBuilder sb = new StringBuilder();

		for (int t = 0; t < T; t++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			M = Integer.parseInt(st.nextToken());
			K = Integer.parseInt(st.nextToken());
			long result = 0;
			int sum = 0;
			arr = new int[N + M - 1];

			st = new StringTokenizer(br.readLine());
			for (int i = 0; i < N; i++) {
				arr[i] = Integer.parseInt(st.nextToken());
			}
			for (int i = 0; i < M - 1; i++) {
				arr[N + i] = arr[i];
			}

			for (int i = 0; i < M; i++) {
				sum += arr[i];
			}

			if (sum < K) {
				result++;
			}

			if (N == M) {
				sb.append(result).append("\n");
				continue;
			}

			for (int i = M; i < N + M - 1; i++) {
				sum -= arr[i - M];
				sum += arr[i];

				if (sum < K) {
					result++;
				}
			}

			sb.append(result).append("\n");
		}

		System.out.println(sb);
	}
}