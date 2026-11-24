#include <siSwati.h>

// Traffic light: green 10 s -> yellow 3 s -> red 5 s. Red pin 10, yellow pin 9, green pin 8 (220 ohm to GND).

lokungagucuki inombolo ILAMBU_ELIBOMVU   = 10;
lokungagucuki inombolo ILAMBU_ELIPHUZI   = 9;
lokungagucuki inombolo ILAMBU_ELILUHLAZA = 8;

lokungagucuki inombolo ISIKHATHI_SOKUHAMBA  = 10000;
lokungagucuki inombolo ISIKHATHI_SOKUNCIPHA = 3000;
lokungagucuki inombolo ISIKHATHI_SOKUMA     = 5000;

lite cala() {
    setha_liphini(ILAMBU_ELIBOMVU, LOKUPHUMAKO);
    setha_liphini(ILAMBU_ELIPHUZI, LOKUPHUMAKO);
    setha_liphini(ILAMBU_ELILUHLAZA, LOKUPHUMAKO);
}

lite phindza_phindza() {
    bhala_idijithali(ILAMBU_ELILUHLAZA, PHETULU);
    bhala_idijithali(ILAMBU_ELIPHUZI, PHANSI);
    bhala_idijithali(ILAMBU_ELIBOMVU, PHANSI);
    lindza(ISIKHATHI_SOKUHAMBA);

    bhala_idijithali(ILAMBU_ELILUHLAZA, PHANSI);
    bhala_idijithali(ILAMBU_ELIPHUZI, PHETULU);
    lindza(ISIKHATHI_SOKUNCIPHA);

    bhala_idijithali(ILAMBU_ELIPHUZI, PHANSI);
    bhala_idijithali(ILAMBU_ELIBOMVU, PHETULU);
    lindza(ISIKHATHI_SOKUMA);
}
