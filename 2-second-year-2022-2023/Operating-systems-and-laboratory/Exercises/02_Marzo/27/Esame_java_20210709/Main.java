public class Main {
    public static void main(String args[]) {
        Consumi consumi = new Consumi();
        SimulaConsumi simulaConsumi = new SimulaConsumi(consumi);
        Thread tsc = new Thread(simulaConsumi);
        tsc.start();

        float precedente = 0.0F;
        float attuale = 0.0F;
        int consecutivi = 0;

        while (true) {
            attuale = consumi.getConsumi();
            System.out.println("Consumo rilevato: " + attuale);

            if (attuale > precedente) {
                if ((attuale - precedente) > (precedente * 30) / 100) {
                    System.out.println("Warning: valore superiore del 30% al precedente");
                }
            }

            if (attuale > 20) {
                consecutivi++;
            } else {
                consecutivi = 0;
            }

            if (consecutivi == 3) {
                System.out.println("3 valori consecutivi superiori a 20, terminazione programma...");
                simulaConsumi.terminaSimulazioneConsumi();
                break;
            }

            precedente = attuale;

            try {
                Thread.sleep(900);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }

        }

        try {
            tsc.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}