public class Main {
    public static void main(String args[]) {
        Consumi consumi = new Consumi();
        SimulaConsumi sc = new SimulaConsumi(consumi);
        Thread tsc = new Thread(sc);
        tsc.start();

        int count = 0;
        float precedente = 0.0F;
        float attuale = 0.0F;

        while (true) {
            try {
                Thread.sleep(900);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }

            attuale = consumi.getConsumi();
            System.out.println("Consumo rilevato: " + attuale);

            if (attuale > precedente) {
                if ((attuale - precedente) > (precedente * 30) / 100) {
					System.out.println("warning: superato il 30% della rilevazione precedente (" + precedente + ")");
                }
            }

            if (attuale > 20) {
                count++;
            } else {
                count = 0;
            }

            if (count == 3) {
				System.out.println("rilevati 3 valori consecutivi maggiori di 20, termino SimulazioneConsumi");
                break;
            }

            precedente = attuale;
        }

        System.out.println("attendo la terminazione di SimulazioneConsumi");
        try {
            tsc.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

		System.out.println("SimulazioneConsumi terminato, conclusione di Main");
    }
}