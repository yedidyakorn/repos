import java.util.ArrayList;

import static java.util.Arrays.sort;

public class AirportUtil {
    public static void sortTransport(Comparable[] transport) {
        sort(transport);
    }

    static String reportAll(Movable[] movables) {
        ArrayList<String> buffer = new ArrayList<>();
        for (Movable m : movables) {
            String tmp = String.format("%s %d going from %s to %s. Currently in %s",
                    m.getType(), m.getId(), m.getSource(), m.getDestination(), m.getCurrentLocation());
            buffer.add(tmp);
        }
        return String.join("\n", buffer);
    }
}
