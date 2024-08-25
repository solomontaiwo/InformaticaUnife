package es4;

import java.util.HashMap;
import java.util.Map;

public class Magazzino {
    Map<String, Integer> oggetti = null;

    public Magazzino() {
        oggetti = new HashMap<String, Integer>();

    public synchronized boolean verificaOggetto(String object) {
        try {
            Thread.sleep(500);
        } catch (InterruptedException e) {
        }
        return oggetti.containsKey(object);
    }

    public synchronized void aggiungiOggetto(String object) {
        try {
            Thread.sleep(500);
        } catch (InterruptedException e) {
        }
        if (!verificaOggetto(object)) {
            oggetti.put(object, new Integer(0));
        }
    }

    public synchronized void increaseQuantity(String object, int qta) {
        if (verificaOggetto(object)) {
            Integer value = oggetti.get(object);
            if (value.intValue() + qta < 0) {
                System.err.println("Impossibile aggiornare la quantità, dato inserito non corretto");
                return;
            }
            try {
                Thread.sleep(500);
            } catch (InterruptedException e) {
            }
            oggetti.put(object, new Integer(oggetti.get(object).intValue() + qta));
        } else {
            System.err.println("Oggetto: " + object + " non esiste in magazzino");
        }
    }

    public synchronized String toString() {
        String result = "";
        for (Map.Entry<String, Integer> obj : oggetti.entrySet()) {
            result += obj.getKey() + ": " + obj.getValue() + "\n";
        }
        return result;
    }
}