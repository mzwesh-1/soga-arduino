// Inzwa yamanzi: ilinganisa ukuthi amanzi aphakeme kangakanani (0-1023).
// Ukuxhuma: S -> A0, + -> 5V, - -> GND
#include <Tshivenda.h>

a_huna thoma() {
    Siriale.mathomo(9600);
}

a_huna dovholola() {
    nomboro izinga = vhala_analogo(A0);
    Siriale.sumbedza("Izinga lamanzi: ");
    Siriale.sumbedza(izinga);
    arali (izinga < 100) Siriale.sumbedza_mutalo("  (yomile)");
    nga_inwe_ndila arali (izinga < 400) Siriale.sumbedza_mutalo("  (aphansi)");
    nga_inwe_ndila arali (izinga < 600) Siriale.sumbedza_mutalo("  (aphakathi)");
    nga_inwe_ndila Siriale.sumbedza_mutalo("  (aphezulu!)");
    lindela(500);
}
