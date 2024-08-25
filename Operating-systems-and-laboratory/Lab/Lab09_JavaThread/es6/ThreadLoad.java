package es6;

import java.util.HashMap;
import java.util.Map;

/**
 * ThreadLoad rappresenta la classe responsabile di tenere traccia del cpuLoad
 * dei vari thread analizzati da Monitor. Un'istanza di ThreadLoad verrà creata
 * nel main e sarà condivisa fra i thread Monitor e Sorter.
 */
public class ThreadLoad {
	
    private HashMap<Integer, Double> threadLoad;

    public ThreadLoad() {
        threadLoad = new HashMap<>(10);
    }
	
    /**
     * Inserisce l'informazione di cpuLoad
     * riguardante il thread con id threadId
     * @param threadId
     * @param cpuLoad
     */
    public synchronized void setThreadLoad(int threadId, double cpuLoad) {
        threadLoad.put(new Integer(threadId), new Double(cpuLoad));
    }

    /**
     * Restituisce il threadId con il piu'
     * alto cpuLoad
     * @return
     */
    public synchronized Integer getMaximumThreadId() {
        Map.Entry<Integer,Double> max = null;
        for (Map.Entry<Integer, Double> entry : threadLoad.entrySet()) {
            if (max == null || entry.getValue().compareTo(max.getValue()) > 0) {
                max = entry;
            }
        }

        // null-check
        if (max ==  null) {
            return null;
        }
        return max.getKey();
    }

    public synchronized Double getCpuLoad(Integer threadId) {
        if (threadId == null) {
            return null;
        }
        return threadLoad.get(threadId);
    }

}
