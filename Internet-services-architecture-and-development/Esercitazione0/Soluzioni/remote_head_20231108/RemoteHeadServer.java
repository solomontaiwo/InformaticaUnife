import java.io.*;
import java.net.*;

public class RemoteHeadServer {
    public static void main(String[] args) {
        // java RemoteHeadServer porta
        //                       args[0]
        if (args.length != 1) {
            System.err.println("Errore! Sintassi corretta è:");
            System.err.println("\tjava RemoteHeadServer porta");
            System.exit(1);
        }

        var port = args[0];

        try {
            var server = new ServerSocket(Integer.parseInt(port));
            var s = server.accept();

            var netIn = new BufferedReader(new InputStreamReader(s.getInputStream(), "UTF-8"));
            var netOut = new BufferedWriter(new OutputStreamWriter(s.getOutputStream(), "UTF-8"));

            var filename = netIn.readLine();

            System.out.println("nomefile: " + filename);

            var inputFile = new BufferedReader(new FileReader(filename));

            String line;
            int i = 1;
            while ((line = inputFile.readLine()) != null) {
                System.out.println("line: " + line);
                netOut.write(line + "\n");
                if (i++ == 5) break;
            }
            netOut.flush();
            inputFile.close();

            s.close();
        } catch (Exception e) {
            System.err.println(e.getMessage());
            e.printStackTrace(System.err);
            System.exit(1);
        }
    }
}
