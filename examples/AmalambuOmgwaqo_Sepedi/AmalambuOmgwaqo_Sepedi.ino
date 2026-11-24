#include <Sepedi.h>

// Traffic light: green 10 s -> yellow 3 s -> red 5 s. Red pin 10, yellow pin 9, green pin 8 (220 ohm to GND).

sa_fetogego palo ILAMBU_ELIBOMVU   = 10;
sa_fetogego palo ILAMBU_ELIPHUZI   = 9;
sa_fetogego palo ILAMBU_ELILUHLAZA = 8;

sa_fetogego palo ISIKHATHI_SOKUHAMBA  = 10000;
sa_fetogego palo ISIKHATHI_SOKUNCIPHA = 3000;
sa_fetogego palo ISIKHATHI_SOKUMA     = 5000;

lefeela thoma() {
    bea_phini(ILAMBU_ELIBOMVU, TSE_TSWAGO);
    bea_phini(ILAMBU_ELIPHUZI, TSE_TSWAGO);
    bea_phini(ILAMBU_ELILUHLAZA, TSE_TSWAGO);
}

lefeela boeletsa() {
    ngwala_dijithale(ILAMBU_ELILUHLAZA, GODIMO);
    ngwala_dijithale(ILAMBU_ELIPHUZI, FASE);
    ngwala_dijithale(ILAMBU_ELIBOMVU, FASE);
    leta(ISIKHATHI_SOKUHAMBA);

    ngwala_dijithale(ILAMBU_ELILUHLAZA, FASE);
    ngwala_dijithale(ILAMBU_ELIPHUZI, GODIMO);
    leta(ISIKHATHI_SOKUNCIPHA);

    ngwala_dijithale(ILAMBU_ELIPHUZI, FASE);
    ngwala_dijithale(ILAMBU_ELIBOMVU, GODIMO);
    leta(ISIKHATHI_SOKUMA);
}
