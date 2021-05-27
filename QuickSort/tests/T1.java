import java.io.*;
import java.nio.file.*;
import java.util.*;
import java.util.stream.*;

public class T1 {

    public static void main(String[] args) throws IOException {
        int num = 1;
        for (int k = 0; k <= 100; k++){
            FileOutputStream fos = new FileOutputStream("output" + num + ".txt");
            PrintWriter pw = new PrintWriter(fos);
            int n = 1000 + 100*k;    
            int min = 0;
            int max = n;
            pw.println(n + " ");
            for(int i = 0; i < n; i++)
            {
                int temp = min + (int) (Math.random() * max);
                pw.print(temp + " ");
            }
            pw.close();
            num++;
        }
    }
}