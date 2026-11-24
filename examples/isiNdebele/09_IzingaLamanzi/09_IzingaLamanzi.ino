// Inzwa yamanzi: ilinganisa ukuthi amanzi aphakeme kangakanani (0-1023).
// Ukuxhuma: S -> A0, + -> 5V, - -> GND
#include <isiNdebele.h>

ilize thoma() {
    Isiriyali.ukuthoma(9600);
}

ilize phinda_phinda() {
    inomboro izinga = funda_ianalogi(A0);
    Isiriyali.khombisa("Izinga lamanzi: ");
    Isiriyali.khombisa(izinga);
    nangabe (izinga < 100) Isiriyali.khombisa_umugqa("  (yomile)");
    ngokunye nangabe (izinga < 400) Isiriyali.khombisa_umugqa("  (aphansi)");
    ngokunye nangabe (izinga < 600) Isiriyali.khombisa_umugqa("  (aphakathi)");
    ngokunye Isiriyali.khombisa_umugqa("  (aphezulu!)");
    lindela(500);
}
