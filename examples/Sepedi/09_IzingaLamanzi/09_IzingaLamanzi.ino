// Inzwa yamanzi: ilinganisa ukuthi amanzi aphakeme kangakanani (0-1023).
// Ukuxhuma: S -> A0, + -> 5V, - -> GND
#include <Sepedi.h>

lefeela thoma() {
    Seriale.mathomo(9600);
}

lefeela boeletsa() {
    palo izinga = bala_analoko(A0);
    Seriale.bontsha("Izinga lamanzi: ");
    Seriale.bontsha(izinga);
    ge (izinga < 100) Seriale.bontsha_mothaladi("  (yomile)");
    go_sego_bjalo ge (izinga < 400) Seriale.bontsha_mothaladi("  (aphansi)");
    go_sego_bjalo ge (izinga < 600) Seriale.bontsha_mothaladi("  (aphakathi)");
    go_sego_bjalo Seriale.bontsha_mothaladi("  (aphezulu!)");
    leta(500);
}
