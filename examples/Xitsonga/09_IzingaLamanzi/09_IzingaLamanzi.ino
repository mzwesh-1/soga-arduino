// Inzwa yamanzi: ilinganisa ukuthi amanzi aphakeme kangakanani (0-1023).
// Ukuxhuma: S -> A0, + -> 5V, - -> GND
#include <Xitsonga.h>

swi_hava sungula() {
    Siriyali.ku_sungula(9600);
}

swi_hava phindha_phindha() {
    nomboro izinga = hlaya_analogo(A0);
    Siriyali.kombisa("Izinga lamanzi: ");
    Siriyali.kombisa(izinga);
    loko (izinga < 100) Siriyali.kombisa_layini("  (yomile)");
    ku_nga_ri_tano loko (izinga < 400) Siriyali.kombisa_layini("  (aphansi)");
    ku_nga_ri_tano loko (izinga < 600) Siriyali.kombisa_layini("  (aphakathi)");
    ku_nga_ri_tano Siriyali.kombisa_layini("  (aphezulu!)");
    rindza(500);
}
