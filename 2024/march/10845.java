import java.util.*;
import java.io.*;
import java.io.IOException;

class Main {
	public static void main(String[] args) throws IOException {
                // Scanner, System.out.println()을 이용한 입출력보다 속도가 빠름
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		Queue<Integer> queue = new LinkedList<>();
		int last = 0;
		String str = new String();

                // int 타입으로 변환
		int n = Integer.parseInt(bf.readLine());
  
                // 개행 문자까지 받아오므로, 'push 1' 같은 경우 공백을 기준으로 나눠줘야 함
		for(int i = 0; i < n; i++) {
			str = bf.readLine();
			String[] words = str.split(" ");
			
			switch(words[0]) {
				case "push":
					last = Integer.parseInt(words[1]); // push인 경우 공백 뒤의 숫자까지 가져오기
					queue.offer(last);
					break;
				case "front":
					if(queue.isEmpty()) bw.write(-1+"\n");
					else bw.write(queue.peek()+"\n");
					break;
				case "back":
					if(queue.isEmpty()) bw.write(-1+"\n");
					else bw.write(last+"\n");
					break;
				case "size":
					bw.write(queue.size()+"\n");
					break;
				case "empty":
					if(queue.isEmpty()) bw.write(1+"\n");
					else bw.write(0+"\n");
					break;
				case "pop":
					if(queue.isEmpty()) bw.write(-1+"\n");
					else bw.write(queue.poll()+"\n");
					break;
			}
		}
		
		bw.flush(); // 남아있는 값 지우기
		bw.close(); // 스트림 닫기
	}
}
