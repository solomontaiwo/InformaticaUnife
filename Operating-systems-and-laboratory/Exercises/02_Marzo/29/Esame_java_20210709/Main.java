public class Main {
    public static void main(String args[]) {
        Consumi consumi = new Consumi();
        SimulaConsumi simulaConsumi = new SimulaConsumi(consumi);
        Thread tsc = new Thread(simulaConsumi);
        tsc.start();

        float corrente = 0.0F;
        float precedente = 0.0F;
        int consecutivi = 0;

        while (true) {
            try {
                Thread.sleep(900);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }

            corrente = consumi.getConsumi();
            if (corrente > precedente) {
                if ((corrente - precedente) > (precedente * 30) / 100) {
                    System.out.println("Warning: superato il 30% della rilevazione precedente (" + precedente + ")");
                }
            }

            if (corrente > 20) {
                consecutivi++;
            } else
                consecutivi = 0;

            if (consecutivi == 3) {
                System.out.println("Rilevati 3 valori consecutivi maggiori di 20, termino SimulazioneConsumi...");
                simulaConsumi.terminaSimulazioneConsumi();
                break;
            }

            precedente = corrente;

        }

        System.out.println("Attendo la terminazione di SimulazioneConsumi...");

        try {
            tsc.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        System.out.println("SimulazioneConsumi terminato, conclusione di Main");

    }
}