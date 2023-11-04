import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;

public class LargeHelloWorldFile {
    public static void main(String[] args) {
        int fileSizeInBytes = 1000000; // Adjust the size as needed
        String helloWorld = "Hello, World!";

        try (BufferedWriter writer = new BufferedWriter(new FileWriter("large_hello_world.txt"))) {
            while (fileSizeInBytes > 0) {
                int chunkSize = Math.min(helloWorld.length(), fileSizeInBytes);
                writer.write(helloWorld, 0, chunkSize);
                fileSizeInBytes -= chunkSize;
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

        System.out.println("Large 'Hello, World!' file created.");
    }
}
