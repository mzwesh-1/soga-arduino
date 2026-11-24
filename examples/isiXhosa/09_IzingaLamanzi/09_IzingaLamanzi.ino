// Inzwa yamanzi: ilinganisa ukuthi amanzi aphakeme kangakanani (0-1023).
// Ukuxhuma: S -> A0, + -> 5V, - -> GND
#include <isiXhosa.h>

ize qalisa() {
    Isiriyali.ukuqala(9600);
}

ize phinda_phinda() {
    inani izinga = funda_ianalogu(A0);
    Isiriyali.bonisa("Izinga lamanzi: ");
    Isiriyali.bonisa(izinga);
    ukuba (izinga < 100) Isiriyali.bonisa_umgca("  (yomile)");
    kungenjalo ukuba (izinga < 400) Isiriyali.bonisa_umgca("  (aphansi)");
    kungenjalo ukuba (izinga < 600) Isiriyali.bonisa_umgca("  (aphakathi)");
    kungenjalo Isiriyali.bonisa_umgca("  (aphezulu!)");
    linda(500);
}
