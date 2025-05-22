import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.PriorityQueue;

class Main {

	static int N;
	static PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> Integer.compare(b, a));

	public static void main(String args[]) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());

		for (int i = 0; i < N; i++) {
			int x = Integer.parseInt(br.readLine());

			if (x == 0) {
				if (pq.isEmpty())
					System.out.println(0);
				else
					System.out.println(pq.poll());
			} else {
				pq.add(x);
			}
		}
	}
}