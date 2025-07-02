import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static int N;
	static long result = 0;
	static int[] arr;
	static long[] dp;

	public static void main(String args[]) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		arr = new int[N];
		dp = new long[N];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}

		dp[0] = arr[0];
		for (int i = 1; i < N; i++) {
			dp[i] = dp[i - 1] + arr[i];
			result += dp[i - 1] * arr[i];
		}

		System.out.println(result);
	}
}