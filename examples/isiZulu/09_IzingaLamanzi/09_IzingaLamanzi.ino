// Inzwa yamanzi: ilinganisa ukuthi amanzi aphakeme kangakanani (0-1023).
// Ukuxhuma: S -> A0, + -> 5V, - -> GND
#include <isiZulu.h>

ize qala() {
    Isiriyeli.ukuqala(9600);
}

ize phindaphinda() {
    inombolo izinga = funda_ianalogi(A0);
    Isiriyeli.bonisa("Izinga lamanzi: ");
    Isiriyeli.bonisa(izinga);
    uma (izinga < 100) Isiriyeli.bonisa_umugqa("  (yomile)");
    kungenjalo uma (izinga < 400) Isiriyeli.bonisa_umugqa("  (aphansi)");
    kungenjalo uma (izinga < 600) Isiriyeli.bonisa_umugqa("  (aphakathi)");
    kungenjalo Isiriyeli.bonisa_umugqa("  (aphezulu!)");
    linda(500);
}
