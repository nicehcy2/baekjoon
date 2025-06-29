import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

	static int N;
	static int[][] arr;
	static long result = 0;
	static int[] larr, rarr;

	public static void main(String args[]) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		arr = new int[4][N];
		larr = new int[N * N];
		rarr = new int[N * N];

		for (int i = 0; i < N; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			for (int j = 0; j < 4; j++) {
				arr[j][i] = Integer.parseInt(st.nextToken());
			}
		}

		for (int i = 0; i < 4; i++) {
			Arrays.sort(arr[i]);
		}

		int count = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				larr[count] = arr[0][i] + arr[1][j];
				rarr[count] = arr[2][i] + arr[3][j];
				count++;
			}
		}
		Arrays.sort(larr);
		Arrays.sort(rarr);

		int start = 0, end = N * N - 1;
		while (start < N * N && end >= 0) {
			int sum = larr[start] + rarr[end];

			if (sum == 0) {
				long lcnt = 1, rcnt = 1;

				while (start + 1 < N * N && larr[start] == larr[start + 1]) {
					start++;
					lcnt++;
				}
				while (end - 1 >= 0 && rarr[end] == rarr[end - 1]) {
					end--;
					rcnt++;
				}

				result += lcnt * rcnt;
				start++;
				end--;
			} else if (sum > 0) {
				end--;
			} else if (sum < 0) {
				start++;
			}
		}

		System.out.println(result);
	}
}