import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

	static int N;
	static int[] arr;
	static long result = 0;

	public static void main(String args[]) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());
		arr = new int[N];

		for (int i = 0; i < N; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}

		Arrays.sort(arr);

		for (int i = 0; i < N; i++) {

			int cur = arr[i];

			int start = i + 1, end = N - 1;
			while (start < end) {
				int left = arr[start];
				int right = arr[end];
				int sum = cur + left + right;
				long l = 1, r = 1, count = 0;

				if (sum > 0) {
					end--;
				} else if (sum < 0) {
					start++;
				} else {
					if (left == right) {
						count = (end - start + 1) * (end - start) / 2;
						start = N - 1;
						end = 0;
					} else {
						int idx = start;
						while (arr[idx] == arr[idx + 1]) {
							idx++;
							l++;
						}
						idx = end;
						while (arr[idx] == arr[idx - 1]) {
							idx--;
							r++;
						}
						count = l * r;
					}
					result += count;

					start += l;
					end -= r;
				}
			}
		}

		System.out.println(result);
	}
}