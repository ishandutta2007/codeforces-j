import java.io.*;
import java.util.*;
import java.math.*;
import java.lang.*;
 
import static java.lang.Math.*;

public class Main implements Runnable {
    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private SpaceCharFilter filter;
        private BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        public InputReader(InputStream stream) {
            this.stream = stream;
        }
        
        public int read() {
            if (numChars==-1) 
                throw new InputMismatchException();
            
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                }
                catch (IOException e) {
                    throw new InputMismatchException();
                }
                
                if(numChars <= 0)               
                    return -1;
            }
            return buf[curChar++];
        }
     
        public String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            }
            catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
        public int nextInt() {
            int c = read();
            
            while(isSpaceChar(c)) 
                c = read();
            
            int sgn = 1;
            
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            
            int res = 0;
            do {
                if(c<'0'||c>'9') 
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = read();
            }
            while (!isSpaceChar(c)); 
            
            return res * sgn;
        }
        
        public long nextLong() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            long res = 0;
            
            do {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = read();
            }
            while (!isSpaceChar(c));
                return res * sgn;
        }
        
        public double nextDouble() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            double res = 0;
            while (!isSpaceChar(c) && c != '.') {
                if (c == 'e' || c == 'E')
                    return res * Math.pow(10, nextInt());
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = read();
            }
            if (c == '.') {
                c = read();
                double m = 1;
                while (!isSpaceChar(c)) {
                    if (c == 'e' || c == 'E')
                        return res * Math.pow(10, nextInt());
                    if (c < '0' || c > '9')
                        throw new InputMismatchException();
                    m /= 10;
                    res += (c - '0') * m;
                    c = read();
                }
            }
            return res * sgn;
        }
        
        public String readString() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            StringBuilder res = new StringBuilder();
            do {
                res.appendCodePoint(c);
                c = read();
            } 
            while (!isSpaceChar(c));
            
            return res.toString();
        }
     
        public boolean isSpaceChar(int c) {
            if (filter != null)
                return filter.isSpaceChar(c);
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }
     
        public String next() {
            return readString();
        }
        
        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);
        }
    }
    public static void main(String args[]) throws Exception {
        new Thread(null, new Main(),"Main",1<<27).start();
    }
    public void run() {
        InputReader sc = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        char[] s = sc.next().toCharArray();
        char[] t = sc.next().toCharArray();

        int freq[] = new int[2];
        for(int i = 0; i < s.length; ++i) {
            freq[s[i] - '0']++;
        }

        char[] pattern = t;

        int n = pattern.length;

        int[] lps = new int[n];
        lps[0] = -1;
        int j = -1;
        for(int i = 1; i < n; ++i) {
            while(j != -1 && pattern[j + 1] != pattern[i]) {
                j = lps[j];
            }

            if(pattern[j + 1] == pattern[i]) {
                j = j + 1;
                lps[i] = j;
            }
            else {
                j = -1;
                lps[i] = -1;
            }
        }

        int startInd = lps[n - 1] + 1;

        ArrayList<Character> ans = new ArrayList<>();

        main : for(int i = 0; ;++i) {
            if(i == 0) {
                for(j = 0; j < n; ++j) {
                    char reqChar = pattern[j];
                    if(freq[reqChar - '0'] != 0) {
                        freq[reqChar - '0']--;
                        ans.add(reqChar);
                    }
                    else
                        break main;
                }
            }
            else {
                for(j = startInd; j < n; ++j) {
                    char reqChar = pattern[j];
                    if(freq[reqChar - '0'] != 0) {
                        freq[reqChar - '0']--;
                        ans.add(reqChar);
                    }
                    else
                        break main;
                }
            }
        }

        for(int i = 0; i < freq[0]; ++i)
            ans.add('0');
        for(int i = 0; i < freq[1]; ++i)
            ans.add('1');

        for(char i : ans)
            w.print(i);

        w.close();
    }
}