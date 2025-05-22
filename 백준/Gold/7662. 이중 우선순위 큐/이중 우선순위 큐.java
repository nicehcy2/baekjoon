import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.TreeMap;

class Main {

	static int T;

	public static void main(String args[]) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		T = Integer.parseInt(br.readLine());

		while (T-- > 0) {
			int N = Integer.parseInt(br.readLine());
			TreeMap<Integer, Integer> map = new TreeMap<>();

			for (int i = 0; i < N; i++) {
				StringTokenizer st = new StringTokenizer(br.readLine());
				String op = st.nextToken();
				int num = Integer.parseInt(st.nextToken());

				if (op.equals("I")) {
					map.put(num, map.getOrDefault(num, 0) + 1);
				} else {
					int key;
					if (map.isEmpty())
						continue;

					if (num == -1)
						key = map.firstKey();
					else
						key = map.lastKey();

					if (map.put(key, map.get(key) - 1) == 1) {
						map.remove(key);
					}
				}
			}

			if (map.isEmpty())
				System.out.println("EMPTY");
			else
				System.out.println(map.lastKey() + " " + map.firstKey());
		}
	}
}