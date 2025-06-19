import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

	static int N, min = 2_000_000_001, A, B;
	static int[] arr;

	public static void main(String args[]) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		arr = new int[N];

		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}

		Arrays.sort(arr);

		for (int i = 0; i < N; i++) {
			int cur = arr[i];

			int start = i + 1, end = N - 1;

			while (start <= end) {

				int mid = (start + end) / 2;

				int val = arr[mid] + cur;

				if (Math.abs(val) < Math.abs(min)) {
					min = Math.abs(val);
					A = cur;
					B = arr[mid];
				}

				if (val > 0) {
					end = mid - 1;
				} else if (val < 0) {
					start = mid + 1;
				} else
					break;
			}
		}

		System.out.println(A + " " + B);
	}
}