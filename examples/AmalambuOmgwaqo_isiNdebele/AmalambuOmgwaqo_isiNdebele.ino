#include <isiNdebele.h>

// Traffic light: green 10 s -> yellow 3 s -> red 5 s. Red pin 10, yellow pin 9, green pin 8 (220 ohm to GND).

okungatjhugulukiko inomboro ILAMBU_ELIBOMVU   = 10;
okungatjhugulukiko inomboro ILAMBU_ELIPHUZI   = 9;
okungatjhugulukiko inomboro ILAMBU_ELILUHLAZA = 8;

okungatjhugulukiko inomboro ISIKHATHI_SOKUHAMBA  = 10000;
okungatjhugulukiko inomboro ISIKHATHI_SOKUNCIPHA = 3000;
okungatjhugulukiko inomboro ISIKHATHI_SOKUMA     = 5000;

ilize thoma() {
    beka_iphini(ILAMBU_ELIBOMVU, OKUPHUMAKO);
    beka_iphini(ILAMBU_ELIPHUZI, OKUPHUMAKO);
    beka_iphini(ILAMBU_ELILUHLAZA, OKUPHUMAKO);
}

ilize phinda_phinda() {
    tlola_idijithali(ILAMBU_ELILUHLAZA, PHEZULU);
    tlola_idijithali(ILAMBU_ELIPHUZI, PHASI);
    tlola_idijithali(ILAMBU_ELIBOMVU, PHASI);
    lindela(ISIKHATHI_SOKUHAMBA);

    tlola_idijithali(ILAMBU_ELILUHLAZA, PHASI);
    tlola_idijithali(ILAMBU_ELIPHUZI, PHEZULU);
    lindela(ISIKHATHI_SOKUNCIPHA);

    tlola_idijithali(ILAMBU_ELIPHUZI, PHASI);
    tlola_idijithali(ILAMBU_ELIBOMVU, PHEZULU);
    lindela(ISIKHATHI_SOKUMA);
}
