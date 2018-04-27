import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;

public class HiddenNumbers {

	public static void main(String[] args) throws IOException {
		String input = "C://Users/aramos/workspace/Tuenti/Files/testInput_SecretNumbers.txt";
		String output = "C://Users/aramos/workspace/Tuenti/Files/testOutput_SecretNumbers.txt";
		Path pathInput = Paths.get(input);
		Path pathOutput = Paths.get(output);
		FileWriter fw = new FileWriter(output);

		try (InputStream in = Files.newInputStream(pathInput);
				BufferedReader reader = new BufferedReader(new InputStreamReader(in))) {
			int base, cases = Integer.parseInt(reader.readLine());
			BigInteger minValue, maxValue;
			String line = null;
			for (int i = 1; i <= cases; ++i) {
				line = reader.readLine();
				base = line.length();	// base == number of chars in string
				minValue = BigInteger.valueOf((long)Math.pow(base, base - 1));
				maxValue = BigInteger.valueOf(0);
				
				for (int j = base - 1; j >= 0; --j) {

					maxValue = maxValue.add(BigInteger.valueOf((long)(j * Math.pow(base, j))));
				}
				
				for (int k = 2; k < base; ++k) {
					
					minValue = minValue.add(BigInteger.valueOf((long)(k * Math.pow(base, base - k - 1))));
				}

				fw.write("Case #" + i + ": " + maxValue.subtract(minValue).toString() + "\n");
				
			}
			fw.close();
		} catch (IOException x) {
			System.err.println(x);
		}
	}

}
