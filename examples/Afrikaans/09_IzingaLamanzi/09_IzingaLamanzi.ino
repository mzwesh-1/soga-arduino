// Inzwa yamanzi: ilinganisa ukuthi amanzi aphakeme kangakanani (0-1023).
// Ukuxhuma: S -> A0, + -> 5V, - -> GND
#include <Afrikaans.h>

leeg opstel() {
    Seriaal.begin(9600);
}

leeg lus() {
    heelgetal izinga = leesanaloog(A0);
    Seriaal.druk("Izinga lamanzi: ");
    Seriaal.druk(izinga);
    as (izinga < 100) Seriaal.drukreel("  (yomile)");
    anders as (izinga < 400) Seriaal.drukreel("  (aphansi)");
    anders as (izinga < 600) Seriaal.drukreel("  (aphakathi)");
    anders Seriaal.drukreel("  (aphezulu!)");
    wag(500);
}
