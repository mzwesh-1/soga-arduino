#include <Afrikaans.h>

// Traffic light: green 10 s -> yellow 3 s -> red 5 s. Red pin 10, yellow pin 9, green pin 8 (220 ohm to GND).

konstant heelgetal ILAMBU_ELIBOMVU   = 10;
konstant heelgetal ILAMBU_ELIPHUZI   = 9;
konstant heelgetal ILAMBU_ELILUHLAZA = 8;

konstant heelgetal ISIKHATHI_SOKUHAMBA  = 10000;
konstant heelgetal ISIKHATHI_SOKUNCIPHA = 3000;
konstant heelgetal ISIKHATHI_SOKUMA     = 5000;

leeg opstel() {
    penmodus(ILAMBU_ELIBOMVU, UITSET);
    penmodus(ILAMBU_ELIPHUZI, UITSET);
    penmodus(ILAMBU_ELILUHLAZA, UITSET);
}

leeg lus() {
    skryfdigitaal(ILAMBU_ELILUHLAZA, HOOG);
    skryfdigitaal(ILAMBU_ELIPHUZI, LAAG);
    skryfdigitaal(ILAMBU_ELIBOMVU, LAAG);
    wag(ISIKHATHI_SOKUHAMBA);

    skryfdigitaal(ILAMBU_ELILUHLAZA, LAAG);
    skryfdigitaal(ILAMBU_ELIPHUZI, HOOG);
    wag(ISIKHATHI_SOKUNCIPHA);

    skryfdigitaal(ILAMBU_ELIPHUZI, LAAG);
    skryfdigitaal(ILAMBU_ELIBOMVU, HOOG);
    wag(ISIKHATHI_SOKUMA);
}
