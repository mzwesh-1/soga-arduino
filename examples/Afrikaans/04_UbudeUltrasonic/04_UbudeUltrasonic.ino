// HC-SR04: ilinganisa ibanga ukuya entweni ngomsindo (ama-sentimitha).
// Ukuxhuma: VCC -> 5V, Trig -> 12, Echo -> 11, GND -> GND
#include <Afrikaans.h>

konstant heelgetal ITRIG = 12;
konstant heelgetal IECHO = 11;

leeg opstel() {
    Seriaal.begin(9600);
    penmodus(ITRIG, UITSET);
    penmodus(IECHO, INSET);
}

dryfgetal linganisa_ibanga() {
    skryfdigitaal(ITRIG, LAAG);
    wagmikro(2);
    skryfdigitaal(ITRIG, HOOG);      // thumela umsindo isikhathi esingu-10 us
    wagmikro(10);
    skryfdigitaal(ITRIG, LAAG);
    ongeteken lank isikhathi_sokubuya = meet_puls(IECHO, HOOG, 30000);
    terug isikhathi_sokubuya * 0.0343 / 2;         // umsindo uhamba 0.0343 cm nge-us, uya ubuye
}

leeg lus() {
    dryfgetal ibanga = linganisa_ibanga();
    as (ibanga == 0) {
        Seriaal.drukreel("Ayikho into ebangeni");
    } anders {
        Seriaal.druk("Ibanga: ");
        Seriaal.druk(ibanga);
        Seriaal.drukreel(" cm");
    }
    wag(500);
}
