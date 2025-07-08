import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static int N;
	static long result = 0;
	static int[] fuels, roads;

	public static void main(String args[]) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		N = Integer.parseInt(br.readLine());
		roads = new int[N - 1];
		fuels = new int[N - 1];

		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N - 1; i++) {
			roads[i] = Integer.parseInt(st.nextToken());
		}

		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N - 1; i++) {
			fuels[i] = Integer.parseInt(st.nextToken());
		}

		result += (long)fuels[0] * roads[0];
		int cur = fuels[0];
		int count = 1;
		while (count < N - 1) {

			if (cur > fuels[count]) {
				cur = fuels[count];
			}
			result += (long)cur * roads[count++];
		}

		System.out.println(result);
	}
}