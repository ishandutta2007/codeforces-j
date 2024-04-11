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
        new Thread(null, new Main(),"Main",1<<26).start();
    }
    long gcd(long a, long b, long vx, long vy, long c) {
        if(b == 0) {
            q = 0;
            p = -c / (vy * a);  
            return a;
        }
        long val = gcd(b, a % b, vx, vy, c);
        long temp = p;
        p = -q * vx / vy;
        q = -(temp * vy + q * vx * (a / b)) / vx;
        return val;
    }
    long p, q;
    public void run() {
        InputReader sc = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);
        
        long n = sc.nextLong();
        long m = sc.nextLong();

        long x = sc.nextLong();
        long y = sc.nextLong();

        long vx = sc.nextLong();
        long vy = sc.nextLong();

        if(vx == 0) {
            if(x == 0 || x == n) {
                if(vy == 1) 
                    w.print(x + " " + m);
                else
                    w.print(x + " " + 0);
            }
            else
                w.print("-1");
            w.close();
            return;
        }
        if(vy == 0) {
            if(y == 0 || y == m) {
                if(vx == 1)
                    w.print(n + " " + y);
                else
                    w.print(0 + " " + y);
            }
            else
                w.print("-1");
            w.close();
            return;
        }

        long c = vx * y - vy * x;

        long gcdnm = gcd(n, m, vx, vy, c);

        if(c % gcdnm != 0) {
            w.print("-1");
            w.close();
            return;
        }

        if(vx == 1) {
            if(p > 0) {
                long reqDec = (p - 1L) / (m / gcdnm);
                p -= reqDec * (m / gcdnm);
                q -= reqDec * vy * (n / gcdnm);
            }
            else {
                long reqInc = (-p) / (m / gcdnm) + 1L;
                p += reqInc * (m / gcdnm);
                q += reqInc * vy * (n / gcdnm);
            }
        }
        else {
            if(p <= 0) {
                long reqInc = (-p) / (m / gcdnm);
                p += reqInc * (m / gcdnm);
                q -= reqInc * vy * (n / gcdnm); 
            }
            else {
                long reqDec = (p - 1L) / (m / gcdnm) + 1L;
                p -= reqDec * (m / gcdnm);
                q += reqDec * vy * (n / gcdnm);
            }
        }

        long ansx = n, ansy = m;
        if(p % 2 == 0)
            ansx = 0;
        if(q % 2 == 0)
            ansy = 0;

        w.print(ansx + " " + ansy);

        w.close();     
    }
}