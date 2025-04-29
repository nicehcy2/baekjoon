import java.util.*;
import java.io.*;

public class Main {

    public static void solution() throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();

        int strLength = str.length();

        // 모두 같은 문자열일 경우
        if (str.chars().allMatch(c -> c == str.charAt(0))) {
            System.out.println("-1");
            return;
        }

        // 회문 검사
        for (int i=0; i<strLength/2; i++) {
            if (str.charAt(i) != str.charAt(strLength - 1 - i)) {
                System.out.println(strLength);
                return;
            }
        }

        System.out.println(strLength - 1);
    }
    public static void main(String[] args) throws IOException {

        solution();
    }
}