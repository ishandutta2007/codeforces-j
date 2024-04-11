import java.io.*;
import java.util.*;
import java.math.*;
import java.lang.*;
 
import static java.lang.Math.*;
 
public class Main implements Runnable
{
	static class InputReader
	{
		private InputStream stream;
		private byte[] buf = new byte[1024];
		private int curChar;
		private int numChars;
		private SpaceCharFilter filter;
		private BufferedReader br=new BufferedReader(new InputStreamReader(System.in));

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
    
    long querySegTree(int low, int high, int pos, int l, int r)
    {
        if(low >= l && high <= r)
            return segTree[pos];
            
        if(low > r || high < l)
            return Long.MIN_VALUE;
       
        int mid = (low + high) >> 1;
        
        long val1 = querySegTree(low, mid, 2 * pos + 1, l, r);
        long val2 = querySegTree(mid + 1, high, 2 * pos + 2, l, r);
        return max(val1, val2);
    }
    
    void updateSegTree(int low, int high, int pos, int ind, long val)
    {
        if(low > ind || high < ind)
            return;
        if(low == high)
        {
            segTree[pos] = val;
            return;
        }
        int mid = (low + high) >> 1;
        updateSegTree(low, mid, 2 * pos + 1, ind, val);
        updateSegTree(mid + 1, high, 2 * pos + 2, ind, val);
        segTree[pos] = max(segTree[2 * pos + 1], segTree[2 * pos + 2]);
    }
    
    long segTree[];
	
    public void run()
	{
		InputReader sc = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
        
        int n = sc.nextInt();
        long s[] = new long[n];
        long g[] = new long[n];
        
        for(int i = 0; i < n; ++i)
        {
            s[i] = sc.nextInt();
            g[i] = sc.nextInt();
        }
        
        long mi[] = new long[n];
        long ma[] = new long[n];
        
        mi[0] = s[0];
        ma[0] = s[0] + g[0];
        for(int i = 1; i < n; ++i)
        {
            mi[i] = max(mi[i - 1] - 1, s[i]);
            if(mi[i] > ma[i - 1] + 1 || mi[i] > s[i] + g[i])
            {
                w.print("-1");
                w.close();
                return;
            }
            ma[i] = min(ma[i - 1] + 1, s[i] + g[i]);
        }
        
        long ans = ma[n - 1] - s[n - 1];
        long wid[] = new long[n];
        wid[n - 1] = ma[n - 1];
        
        for(int i = n - 2; i >= 0; --i)
        {
            if(wid[i + 1] + 1 <= ma[i])
            {
                ans += wid[i + 1] + 1 - s[i];
                wid[i] = wid[i + 1] + 1;
            }
            else if(wid[i + 1] == ma[i])
            {
                ans += wid[i + 1] - s[i];
                wid[i] = wid[i + 1];
            }
            else
            {
                ans += wid[i + 1] - 1 - s[i];
                wid[i] = wid[i + 1] - 1;
            }
        }
        
        w.println(ans);
        for(int i = 0; i < n; ++i)
            w.print(wid[i] + " ");
		w.close();
	}
}