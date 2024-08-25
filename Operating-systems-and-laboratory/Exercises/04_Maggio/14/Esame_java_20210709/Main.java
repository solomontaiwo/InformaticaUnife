public class Main {
    public static void main(String[] args) {
        Consumi consumi = new Consumi();
        SimulaConsumi simulaConsumi = new SimulaConsumi(consumi);
        Thread tsc = new Thread(simulaConsumi);
        tsc.start();

        int count = 0;
        float attuale = 0.0F;
        float precedente = 0.0F;

        while (true) {
            try {
                Thread.sleep(900);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }

            attuale = consumi.getConsumi();

            System.out.println("Valore fornito da SimulaConsumi: " + attuale);

            if (attuale > precedente) {
                if ((attuale - precedente) > (precedente * 30) / 100) {
                    System.out.println("Avviso: superato il 30% della rilevazione precedente (" + precedente + ")");
                }
            }

            if (attuale > 20) {
                count++;
            } else {
                count = 0;
            }

            if (count == 3) {
                System.out.println("Ricevuti 3 valori superiori a 20, terminazione SimulaConsumi...");
                simulaConsumi.terminaSimulazioneConsumi();
                break;
            }

            precedente = attuale;
        }

        System.out.println("Attendo la terminazione di SimulaConsumi...");

        try {
            tsc.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        System.out.println("SimulaConsumi terminato, conclusione main...");
    }
}
