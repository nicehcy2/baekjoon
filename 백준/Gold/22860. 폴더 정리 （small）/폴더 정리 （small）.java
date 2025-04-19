
import java.util.*;
import java.io.*;

public class Main {

    static int N, M, Q; // 파일 개수, 폴더 개수, 쿼리 개수
    static HashMap<String, Set<String>> map;
    static Set<String> dist = new HashSet<>();
    static ArrayList<String> ndist = new ArrayList<>();

    public static void solution() throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        map = new HashMap<>();
        map.put("main", new HashSet<>());

        for (int i=0; i<N+M; i++) {

            st = new StringTokenizer(br.readLine());
            String parent = st.nextToken();
            String current = st.nextToken();
            int isFolder = Integer.parseInt(st.nextToken());

            // 부모 해시에 자식 해시 추가
            if (!map.containsKey(parent)) map.put(parent, new HashSet<>());
            map.get(parent).add(current);

            // 폴더라면 자식 해시에 Set 초기화
            if (isFolder == 1 && !map.containsKey(current)) map.put(current, new HashSet<>());

        }

        Q = Integer.parseInt(br.readLine());
        for (int i=0; i<Q; i++) {
            String[] query = br.readLine().split("/");

            dfs(query[query.length - 1]);

            int first = dist.size();
            int second = ndist.size();

            System.out.println(first + " " + second);

            dist.clear();
            ndist.clear();
        }
    }

    static void dfs(String folderName) {

        Set<String> set;
        if (map.containsKey(folderName)) {
            set = map.get(folderName);
        } else return;

        for (String s : set) {
            if (map.containsKey(s)) {
                dfs(s);
            }
            else {
                dist.add(s);
                ndist.add(s);
            }
        }

    }

    public static void main(String[] args) throws IOException {

        solution();
    }
}