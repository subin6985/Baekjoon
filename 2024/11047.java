import java.util.*;
import java.lang.*;
import java.io.*;

class Main
{
	public static void main (String[] args) throws java.lang.Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		String str = br.readLine();
		StringTokenizer st = new StringTokenizer(str);
		int n = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		
		int[] sort = new int[n];
		
		for(int i = 0; i < n; i++) {
			sort[i] = Integer.parseInt(br.readLine());
		}
		
		int count = 0;
		for(int i = n - 1; i >= 0; i--) { // 동전 가격을 내림차순으로 확인
			while(sort[i] <= k) {     // 동전 가격이 k보다 비싸질 때까지(k에서 동전 가격을 더 뺄 수 없을 때까지)
				k -= sort[i];     // k에서 동전 가격만큼 빼고
				count++;          // 사용한 동전 개수 1씩 증가
			}
			
			if(k == 0) break;          // k가 0이 된 경우(동전들의 합으로 k 값을 만든 경우) 반복문 종료
		}
		
		bw.write(count + "\n");
		bw.flush();
		bw.close();
	}
}
