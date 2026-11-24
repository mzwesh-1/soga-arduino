#include <Setswana.h>

// Traffic light: green 10 s -> yellow 3 s -> red 5 s. Red pin 10, yellow pin 9, green pin 8 (220 ohm to GND).

e_sa_fetogeng palo ILAMBU_ELIBOMVU   = 10;
e_sa_fetogeng palo ILAMBU_ELIPHUZI   = 9;
e_sa_fetogeng palo ILAMBU_ELILUHLAZA = 8;

e_sa_fetogeng palo ISIKHATHI_SOKUHAMBA  = 10000;
e_sa_fetogeng palo ISIKHATHI_SOKUNCIPHA = 3000;
e_sa_fetogeng palo ISIKHATHI_SOKUMA     = 5000;

lefela simolola() {
    baya_phini(ILAMBU_ELIBOMVU, TSE_DI_TSWANG);
    baya_phini(ILAMBU_ELIPHUZI, TSE_DI_TSWANG);
    baya_phini(ILAMBU_ELILUHLAZA, TSE_DI_TSWANG);
}

lefela boeletsa() {
    kwala_dijithale(ILAMBU_ELILUHLAZA, GODIMO);
    kwala_dijithale(ILAMBU_ELIPHUZI, TLASE);
    kwala_dijithale(ILAMBU_ELIBOMVU, TLASE);
    ema(ISIKHATHI_SOKUHAMBA);

    kwala_dijithale(ILAMBU_ELILUHLAZA, TLASE);
    kwala_dijithale(ILAMBU_ELIPHUZI, GODIMO);
    ema(ISIKHATHI_SOKUNCIPHA);

    kwala_dijithale(ILAMBU_ELIPHUZI, TLASE);
    kwala_dijithale(ILAMBU_ELIBOMVU, GODIMO);
    ema(ISIKHATHI_SOKUMA);
}
