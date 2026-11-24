// Inzwa yamanzi: ilinganisa ukuthi amanzi aphakeme kangakanani (0-1023).
// Ukuxhuma: S -> A0, + -> 5V, - -> GND
#include <siSwati.h>

lite cala() {
    Siriyali.kucala(9600);
}

lite phindza_phindza() {
    inombolo izinga = fundza_ianalogi(A0);
    Siriyali.khombisa("Izinga lamanzi: ");
    Siriyali.khombisa(izinga);
    nangabe (izinga < 100) Siriyali.khombisa_umugca("  (yomile)");
    ngalokunye nangabe (izinga < 400) Siriyali.khombisa_umugca("  (aphansi)");
    ngalokunye nangabe (izinga < 600) Siriyali.khombisa_umugca("  (aphakathi)");
    ngalokunye Siriyali.khombisa_umugca("  (aphezulu!)");
    lindza(500);
}
