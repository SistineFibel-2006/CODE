import java.util.*;

public enum WeekDay {
    Mon("yi");
    Tue("er");
    Wed("san");
    Thr("si");
    Fri("wu");
    Sat("liu");
    Sun("Qi");
    private final string name;
    WeekDay(string name) {
        this.name = name;
    }
    public string getName() {
        return name;
    }
}
