import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

	static int N;
	static ArrayList<int[]> arr = new ArrayList<>();
	static PriorityQueue<Integer> pq = new PriorityQueue<>();

	public static void main(String args[]) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());

		for (int i = 0; i < N; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int start = Integer.parseInt(st.nextToken());
			int end = Integer.parseInt(st.nextToken());
			arr.add(new int[] { start, end });
		}

		arr.sort((a, b) -> Integer.compare(a[0], b[0]));

		pq.add(arr.get(0)[1]);
		for (int i = 1; i < arr.size(); i++) {

			int curStart = arr.get(i)[0];
			int curEnd = arr.get(i)[1];

			if (pq.isEmpty()) {
				pq.add(curEnd);
			} else {
				int prev = pq.peek();

				if (prev <= curStart) {
					pq.poll();
				}
				pq.add(curEnd);
			}
		}

		System.out.println(pq.size());
	}
}