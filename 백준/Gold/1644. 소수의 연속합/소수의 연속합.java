import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Main {

	static int N;
	static long result = 0;
	static boolean[] isNotPrime = new boolean[4_000_001];
	static ArrayList<Long> prefixSum = new ArrayList<>();

	public static void main(String args[]) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		// StringTokenizer st = new StringTokenizer(br.readLine());

		isNotPrime[0] = isNotPrime[1] = true; // true면 소수아님.
		for (int i = 2; i <= Math.sqrt(N); i++) {

			// 만약 소수면(false면 소수)
			if (!isNotPrime[i]) {
				for (int j = i * i; j <= N; j += i) {
					isNotPrime[j] = true;
				}
			}
		}

		prefixSum.add(0L);
		int count = 0;
		for (int i = 2; i <= N; i++) {
			if (!isNotPrime[i]) {
				prefixSum.add(i + prefixSum.get(count));
				count++;
			}
		}

		int start = 0, end = 0;
		while (true) {

			if (start > end || end >= prefixSum.size() || start >= prefixSum.size()) {
				break;
			}

			long sum = prefixSum.get(end) - prefixSum.get(start);

			if (sum > N) {
				sum -= prefixSum.get(start++);
			} else if (sum < N) {
				sum += prefixSum.get(end++);
			} else if (sum == N) {
				result++;
				sum -= prefixSum.get(start++);
			}
		}

		System.out.println(result);
	}
}