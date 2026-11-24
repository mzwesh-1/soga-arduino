// Inzwa yamanzi: ilinganisa ukuthi amanzi aphakeme kangakanani (0-1023).
// Ukuxhuma: S -> A0, + -> 5V, - -> GND
#include <Setswana.h>

lefela simolola() {
    Seriale.tshimologo(9600);
}

lefela boeletsa() {
    palo izinga = bala_analoko(A0);
    Seriale.bontsha("Izinga lamanzi: ");
    Seriale.bontsha(izinga);
    fa (izinga < 100) Seriale.bontsha_mola("  (yomile)");
    go_seng_jalo fa (izinga < 400) Seriale.bontsha_mola("  (aphansi)");
    go_seng_jalo fa (izinga < 600) Seriale.bontsha_mola("  (aphakathi)");
    go_seng_jalo Seriale.bontsha_mola("  (aphezulu!)");
    ema(500);
}
