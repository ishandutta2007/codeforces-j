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

        public InputReader(InputStream stream)
        {
            this.stream = stream;
        }
        
        public int read()
        {
            if (numChars==-1) 
                throw new InputMismatchException();
            
            if (curChar >= numChars)
            {
                curChar = 0;
                try 
                {
                    numChars = stream.read(buf);
                }
                catch (IOException e)
                {
                    throw new InputMismatchException();
                }
                
                if(numChars <= 0)               
                    return -1;
            }
            return buf[curChar++];
        }
     
        public String nextLine()
        {
            String str = "";
            try
            {
                str = br.readLine();
            }
            catch (IOException e)
            {
                e.printStackTrace();
            }
            return str;
        }
        public int nextInt()
        {
            int c = read();
            
            while(isSpaceChar(c)) 
                c = read();
            
            int sgn = 1;
            
            if (c == '-') 
            {
                sgn = -1;
                c = read();
            }
            
            int res = 0;
            do 
            {
                if(c<'0'||c>'9') 
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = read();
            }
            while (!isSpaceChar(c)); 
            
            return res * sgn;
        }
        
        public long nextLong() 
        {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            int sgn = 1;
            if (c == '-') 
            {
                sgn = -1;
                c = read();
            }
            long res = 0;
            
            do 
            {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = read();
            }
            while (!isSpaceChar(c));
                return res * sgn;
        }
        
        public double nextDouble() 
        {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            int sgn = 1;
            if (c == '-') 
            {
                sgn = -1;
                c = read();
            }
            double res = 0;
            while (!isSpaceChar(c) && c != '.') 
            {
                if (c == 'e' || c == 'E')
                    return res * Math.pow(10, nextInt());
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = read();
            }
            if (c == '.') 
            {
                c = read();
                double m = 1;
                while (!isSpaceChar(c)) 
                {
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
        
        public String readString() 
        {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            StringBuilder res = new StringBuilder();
            do 
            {
                res.appendCodePoint(c);
                c = read();
            } 
            while (!isSpaceChar(c));
            
            return res.toString();
        }
     
        public boolean isSpaceChar(int c) 
        {
            if (filter != null)
                return filter.isSpaceChar(c);
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }
     
        public String next() 
        {
            return readString();
        }
        
        public interface SpaceCharFilter 
        {
            public boolean isSpaceChar(int ch);
        }

    }
    public static void main(String args[]) throws Exception
    {
        new Thread(null, new Main(),"Main",1<<26).start();
    }
    public void run() {
        InputReader sc= new InputReader(System.in);
        PrintWriter w= new PrintWriter(System.out);

        char[] s = sc.next().toCharArray();

        ArrayList<Integer> list[] = new ArrayList[s.length];
        for(int i = 0; i < s.length; ++i)
            list[i] = new ArrayList<>();  

        TreeMap<Integer, Integer> map0 = new TreeMap<>();
        TreeMap<Integer, Integer> map1 = new TreeMap<>();

        for(int i = 0; i < s.length; ++i)
            map0.put(i, 1);

        for(int i = 0; i < s.length; ++i) {
            if(s[i] == '0') {
                if(map0.size() == 0) {
                    w.print("-1");
                    w.close();
                    return;
                }
                int poss = map0.firstKey();
                list[poss].add(i);
                map0.remove(poss);
                map1.put(poss, 1);
            }
            else {
                if(map1.size() == 0) {
                    w.print("-1");
                    w.close();
                    return;
                }
                int poss = map1.firstKey();
                list[poss].add(i);
                map1.remove(poss);
                map0.put(poss, 1);
            }
        }

        int cnt = 0;

        for(int i = 0; i < s.length; ++i) {
            if(list[i].size() > 0 && s[list[i].get(list[i].size() - 1)] == '1') {
                w.print("-1");
                w.close();
                return;
            }
            if(list[i].size() > 0)
                cnt++;
        }

        w.println(cnt);
        for(int i = 0; i < cnt; ++i) {
            w.print(list[i].size() + " ");
            for(int j : list[i])
                w.print((j + 1) + " ");
            w.println();
        }

        w.close();      
    }
}