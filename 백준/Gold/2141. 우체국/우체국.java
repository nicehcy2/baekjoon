import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {

	static int N;
	static ArrayList<long[]> arr = new ArrayList<>();

	public static void main(String args[]) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st; // = new StringTokenizer(br.readLine());

		long sum = 0;
		N = Integer.parseInt(br.readLine());
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			long X = Long.parseLong(st.nextToken());
			long A = Long.parseLong(st.nextToken());
			arr.add(new long[] { X, A });
			sum += A;
		}
		arr.sort((a, b) -> Long.compare(a[0], b[0]));

		long mid = (sum + 1) / 2;
		long curSum = 0;
		for (int i = 0; i < N; i++) {
			curSum += arr.get(i)[1];

			if (curSum >= mid) {
				System.out.println(arr.get(i)[0]);
				return;
			}
		}
	}
}