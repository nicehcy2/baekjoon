import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static long N, K;

	public static void main(String args[]) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Long.parseLong(st.nextToken());
		K = Long.parseLong(st.nextToken());

		long start = 0, end = (long) Math.ceil((double) N / 2);
		while (start <= end) {

			long mid = (start + end) / 2;

			long val = (mid + 1) * (N - mid + 1);

			if (val == K) {
				System.out.println("YES");
				return;
			} else if (val > K) {
				end = mid - 1;
			} else if (val < K) {
				start = mid + 1;
			}
		}

		System.out.println("NO");
	}
}