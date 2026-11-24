#include <isiXhosa.h>

// Traffic light: green 10 s -> yellow 3 s -> red 5 s. Red pin 10, yellow pin 9, green pin 8 (220 ohm to GND).

engatshintshiyo inani ILAMBU_ELIBOMVU   = 10;
engatshintshiyo inani ILAMBU_ELIPHUZI   = 9;
engatshintshiyo inani ILAMBU_ELILUHLAZA = 8;

engatshintshiyo inani ISIKHATHI_SOKUHAMBA  = 10000;
engatshintshiyo inani ISIKHATHI_SOKUNCIPHA = 3000;
engatshintshiyo inani ISIKHATHI_SOKUMA     = 5000;

ize qalisa() {
    misela_iphini(ILAMBU_ELIBOMVU, OKUPHUMAYO);
    misela_iphini(ILAMBU_ELIPHUZI, OKUPHUMAYO);
    misela_iphini(ILAMBU_ELILUHLAZA, OKUPHUMAYO);
}

ize phinda_phinda() {
    bhala_idijithali(ILAMBU_ELILUHLAZA, PHEZULU);
    bhala_idijithali(ILAMBU_ELIPHUZI, EZANTSI);
    bhala_idijithali(ILAMBU_ELIBOMVU, EZANTSI);
    linda(ISIKHATHI_SOKUHAMBA);

    bhala_idijithali(ILAMBU_ELILUHLAZA, EZANTSI);
    bhala_idijithali(ILAMBU_ELIPHUZI, PHEZULU);
    linda(ISIKHATHI_SOKUNCIPHA);

    bhala_idijithali(ILAMBU_ELIPHUZI, EZANTSI);
    bhala_idijithali(ILAMBU_ELIBOMVU, PHEZULU);
    linda(ISIKHATHI_SOKUMA);
}
