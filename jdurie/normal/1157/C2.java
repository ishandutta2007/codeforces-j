import java.io.*;
import java.util.*;

public class C{
	// ------------------------

	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		int n=sc.nextInt();
		long[]a=new long[n];
		for(int i=0;i<n;i++)
			a[i]=sc.nextLong();
		int[]l=new int[n],r=new int[n];
		l[0]=0;
		for(int i=1;i<n;i++)
			l[i]=a[i]<a[i-1]?l[i-1]+1:0;
		r[n-1]=0;
		for(int i=n-2;i>=0;i--)
			r[i]=a[i]<a[i+1]?r[i+1]+1:0;
		int iL=0,iR=n-1;
		ArrayList<Boolean>aList=new ArrayList<Boolean>();
		long curr=Long.MIN_VALUE;
		while(iL<=iR&&Math.max(a[iL],a[iR])>curr)
			if(a[iL]==a[iR]){
				if(l[iR]>r[iL]){
					aList.add(false);
					curr=a[iR];
					iR--;
				}else{
					aList.add(true);
					curr=a[iL];
					iL++;
				}
			}else if(a[iL]>curr&&(a[iL]<a[iR]||a[iR]<=curr)){
				aList.add(true);
				curr=a[iL];
				iL++;
			}else{
				aList.add(false);
				curr=a[iR];
				iR--;
			}
		out.println(aList.size());
		for(boolean b:aList)
			out.print(b?"L":"R");
		out.println();
		// ------------------------
		out.close();
	}
	//------------------------

	public static PrintWriter out;
	public static class MyScanner {
		BufferedReader br;
		StringTokenizer st;
		public MyScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}
		String next() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}
		int nextInt() {
			return Integer.parseInt(next());
		}
		long nextLong() {
			return Long.parseLong(next());
		}
		double nextDouble() {
			return Double.parseDouble(next());
		}
		String nextLine() {
			String str = "";
			try {
				str = br.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			return str;
		}
	}
}