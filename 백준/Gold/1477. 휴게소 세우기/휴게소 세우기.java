import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

	static int N, M, L, result = 100_000;
	static int[] arr;

	public static void main(String args[]) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		L = Integer.parseInt(st.nextToken());

		if (N == 0) {
			System.out.println((int) Math.ceil((double) L / (M + 1)));
			return;
		}

		arr = new int[N];

		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}

		Arrays.sort(arr);

		int start = 1, end = L;
		while (start <= end) {
			int mid = (start + end) / 2;

			int flag = isPossible(mid);

			if (flag >= 0) {
				result = Math.min(result, mid);
				end = mid - 1;
			} else if (flag == -1) {
				start = mid + 1;
			}
		}

		System.out.println(result);
	}

	static int isPossible(int diff) {

		int count = 0, prev = 0;
		for (int i = 0; i < N; i++) {
			int cur = arr[i];
			if (cur - prev > diff) {
				count += Math.ceil((double) (cur - prev) / diff) - 1;
			}
			prev = arr[i];
		}

		if (L - prev > diff) {
			count += Math.ceil((double) (L - prev) / diff) - 1;
		}

		if (count == M)
			return 0;
		else if (count > M)
			return -1;
		else
			return 1;
	}
}