public class Main {
    public static void main(String[] args) {
        Consumi consumi = new Consumi();
        SimulaConsumi simulaConsumi = new SimulaConsumi(consumi);

        Thread tsc = new Thread(simulaConsumi);
        tsc.start();

        int count = 0;
        float precedente = 0.0F;
        float attuale = 0.0F;

        while (true) {
            try {
                Thread.sleep(900);
            } catch (InterruptedException e) {
                e.printStackTrace();
                System.err.println("Errore sleep Main");
            }

            attuale = consumi.getConsumi();
            System.out.println("Consumo rilevato: " + attuale);

            if (attuale > precedente) {
                if ((attuale - precedente) > (precedente * 30) / 100) {
                    System.out.println("Warning");
                }
            }

            if (attuale > 20) {
                count++;
            } else {
                count = 0;
            }

            if (count == 3) {
                System.out.println("Rilevati 3 valori consecutivi maggiori di 20, termino...");
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
            System.err.println("Errore join Main");
        }

        System.out.println("SimulaConsumi terminato, conclusione di Main");
    }
}