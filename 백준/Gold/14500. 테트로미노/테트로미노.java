import java.io.*;
import java.util.*;

public class Main {
    public static final int BUFSIZE = 512;
    public static int n, m;
    public static int[][] arr = new int[BUFSIZE][BUFSIZE];

    public static void main(String[] args) throws Exception {
        Input();
        Solve();
    }

    static void Input() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }
    }

    static boolean checkIndex0(int i, int j, int op) {
        if (op == 0) {
            if (i < n && j + 3 < m) return true;
            else return false;
        } else if (op == 1) {
            if (i + 3 < n && j < m) return true;
            else return false;
        }

        return false;
    }

    static boolean checkIndex1(int i, int j, int op) {
        if (op == 0) {
            if (i + 1 < n && j + 1 < m) return true;
            else return false;
        }

        return false;
    }

    static boolean checkIndex2(int i, int j, int op) {
        if (op == 0 || op == 2 || op == 4 || op == 6) {
            if (i + 2 < n && j + 1 < m) return true;
            else return false;
        } else if (op == 1 || op == 3 || op == 5 || op == 7) {
            if (i + 1 < n && j + 2 < m) return true;
            else return false;
        }

        return false;
    }

    static boolean checkIndex3(int i, int j, int op) {
        if (op == 0 || op == 2) {
            if (i + 2 < n && j + 1 < m) return true;
            else return false;
        } else if (op == 1 || op == 3) {
            if (i + 1 < n && j + 2 < m) return true;
            else return false;
        }

        return false;
    }

    static boolean checkIndex4(int i, int j, int op) {
        if (op == 0 || op == 2) {
            if (i + 1 < n && j + 2 < m) return true;
            else return false;
        } else if (op == 1 || op == 3) {
            if (i + 2 < n && j + 1 < m) return true;
            else return false;
        }

        return false;
    }

    static int checkValue0(int i, int j, int op) {
        int cnt = 0;

        if (op == 0) {
            for (int x = 0; x < 4; x++) {
                cnt += arr[i][j + x];
            }
        } else if (op == 1) {
            for (int y = 0; y < 4; y++) {
                cnt += arr[i + y][j];
            }
        }

        return cnt;
    }

    static int checkValue1(int i, int j, int op) {
        int cnt = 0;

        if (op == 0) {
            for (int y = 0; y < 2; y++) {
                for (int x = 0; x < 2; x++) {
                    cnt += arr[i + y][j + x];
                }
            }
        }

        return cnt;
    }

    static int checkValue2(int i, int j, int op) {
        int cnt = 0;

        if (op == 0) {
            for (int y = 0; y < 3; y++) {
                cnt += arr[i + y][j];
            }
            cnt += arr[i + 2][j + 1];
        } else if (op == 1) {
            for (int x = 0; x < 3; x++) {
                cnt += arr[i][j + x];
            }
            cnt += arr[i + 1][j];
        } else if (op == 2) {
            cnt += arr[i][j];

            for (int y = 0; y < 3; y++) {
                cnt += arr[i + y][j + 1];
            }
        } else if (op == 3) {
            for (int x = 0; x < 3; x++) {
                cnt += arr[i + 1][j + x];
            }
            cnt += arr[i][j + 2];
        } else if (op == 4) {
            for (int y = 0; y < 3; y++) {
                cnt += arr[i + y][j];
            }
            cnt += arr[i][j + 1];
        } else if (op == 5) {
            for (int x = 0; x < 3; x++) {
                cnt += arr[i][j + x];
            }
            cnt += arr[i + 1][j + 2];
        } else if (op == 6) {
            cnt += arr[i + 2][j];

            for (int y = 0; y < 3; y++) {
                cnt += arr[i + y][j + 1];
            }
        } else if (op == 7) {
            for (int x = 0; x < 3; x++) {
                cnt += arr[i + 1][j + x];
            }
            cnt += arr[i][j];
        }

        return cnt;
    }

    static int checkValue3(int i, int j, int op) {
        int cnt = 0;

        if (op == 0) {
            for (int y = 0; y < 2; y++) {
                cnt += arr[i + y][j];
            }
            for (int y = 1; y < 3; y++) {
                cnt += arr[i + y][j + 1];
            }
        } else if (op == 1) {
            for (int x = 0; x < 2; x++) {
                cnt += arr[i + 1][j + x];
            }
            for (int x = 1; x < 3; x++) {
                cnt += arr[i][j + x];
            }
        } else if (op == 2) {
            for (int y = 0; y < 2; y++) {
                cnt += arr[i + y][j + 1];
            }
            for (int y = 1; y < 3; y++) {
                cnt += arr[i + y][j];
            }
        } else if (op == 3) {
            for (int x = 0; x < 2; x++) {
                cnt += arr[i][j + x];
            }
            for (int x = 1; x < 3; x++) {
                cnt += arr[i + 1][j + x];
            }
        }

        return cnt;
    }

    static int checkValue4(int i, int j, int op) {
        int cnt = 0;

        if (op == 0) {
            for (int x = 0; x < 3; x++) {
                cnt += arr[i][j + x];
            }
            cnt += arr[i + 1][j + 1];
        } else if (op == 1) {
            for (int y = 0; y < 3; y++) {
                cnt += arr[i + y][j];
            }
            cnt += arr[i + 1][j + 1];
        } else if (op == 2) {
            for (int x = 0; x < 3; x++) {
                cnt += arr[i + 1][j + x];
            }
            cnt += arr[i][j + 1];
        } else if (op == 3) {
            for (int y = 0; y < 3; y++) {
                cnt += arr[i + y][j + 1];
            }
            cnt += arr[i + 1][j];
        }

        return cnt;
    }

    static int checkMax(int a, int b) throws Exception {
        if (a > b) return a;
        else return b;
    }

    static void Solve() throws Exception {
        int max = 0;

        for (int i = 0; i < n; i++) {
            int cnt = 0;

            for (int j = 0; j < m; j++) {
                for (int op = 0; op < 4; op++) {
                    if (checkIndex0(i, j, op)) {
                        cnt = checkValue0(i, j, op);
                        max = checkMax(cnt, max);
                    }
                }
                for (int op = 0; op < 4; op++) {
                    if (checkIndex1(i, j, op)) {
                        cnt = checkValue1(i, j, op);
                        max = checkMax(cnt, max);
                    }
                }
                for (int op = 0; op < 8; op++) {
                    if (checkIndex2(i, j, op)) {
                        cnt = checkValue2(i, j, op);
                        max = checkMax(cnt, max);
                    }
                }
                for (int op = 0; op < 4; op++) {
                    if (checkIndex3(i, j, op)) {
                        cnt = checkValue3(i, j, op);
                        max = checkMax(cnt, max);
                    }
                }
                for (int op = 0; op < 4; op++) {
                    if (checkIndex4(i, j, op)) {
                        cnt = checkValue4(i, j, op);
                        max = checkMax(cnt, max);
                    }
                }
            }
        }

        System.out.println(max);
    }
}