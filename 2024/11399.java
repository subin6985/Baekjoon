import java.util.*;
import java.lang.*;
import java.io.*;

class Main
{
	public static void main (String[] args) throws java.lang.Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int n = Integer.parseInt(br.readLine());
		
		int[] arr = new int[n];
		String time = br.readLine(); // 시간 입력은 공백을 두고 들어오므로, String 타입으로 통째로 입력 받음
		StringTokenizer st = new StringTokenizer(time);
		
		for(int i = 0; i < n; i++) {
			arr[i] = Integer.parseInt(st.nextToken()); // 공백 단위로 끊은 시간을 int형으로 배열에 저장
		}

		    // 오름차순으로 저장
		for(int i = 0; i < n; i++) {
			for(int j = i + 1; j < n; j++) {
				if(arr[i] > arr[j]) {
					int temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
			}
		}

		    // 문제 예시에 있는 (1) + (1 + 2) + (1 + 2 + 3) + ... 처럼,
		    // 제일 작은 수부터 차례로 반복해서 더해지므로 arr[i]를 (n - i)번씩 곱해서 더해줌
		int result = 0;
		for(int i = 0; i < n; i++) {
			result += arr[i] * (n - i);
		}
		
		bw.write(result + "\n");
		bw.flush();
		bw.close();
	}
}
