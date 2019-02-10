/* 
ID: teerth.1
LANG: JAVA
TASK: ride
 */
import java.io.*;
public class ride { //this is stupid; java is ridiculous in terms of file IO

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("ride.in"));
		String comet = br.readLine();
		String group = br.readLine();
		br.close();
		int cometProduct = 1, groupProduct = 1;
		for (int i = 0; i < comet.length(); i++)
			cometProduct *= comet.charAt(i) - 'A' + 1;
		for (int i = 0; i < group.length(); i++)
			groupProduct *= group.charAt(i) - 'A' + 1;

		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("ride.out")));
		if (cometProduct%47==groupProduct%47)
			pw.println("GO");
		else
			pw.println("STAY");
		pw.close();
	}

}
