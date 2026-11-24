// Inzwa yamanzi: ilinganisa ukuthi amanzi aphakeme kangakanani (0-1023).
// Ukuxhuma: S -> A0, + -> 5V, - -> GND
#include <Sesotho.h>

lefeela qala() {
    Seriale.qalo(9600);
}

lefeela pheta_pheta() {
    palo izinga = bala_analoko(A0);
    Seriale.bontsha("Izinga lamanzi: ");
    Seriale.bontsha(izinga);
    haeba (izinga < 100) Seriale.bontsha_mola("  (yomile)");
    ho_seng_jwalo haeba (izinga < 400) Seriale.bontsha_mola("  (aphansi)");
    ho_seng_jwalo haeba (izinga < 600) Seriale.bontsha_mola("  (aphakathi)");
    ho_seng_jwalo Seriale.bontsha_mola("  (aphezulu!)");
    ema(500);
}
