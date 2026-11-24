#include <Sesotho.h>

// Traffic light: green 10 s -> yellow 3 s -> red 5 s. Red pin 10, yellow pin 9, green pin 8 (220 ohm to GND).

e_sa_fetoheng palo ILAMBU_ELIBOMVU   = 10;
e_sa_fetoheng palo ILAMBU_ELIPHUZI   = 9;
e_sa_fetoheng palo ILAMBU_ELILUHLAZA = 8;

e_sa_fetoheng palo ISIKHATHI_SOKUHAMBA  = 10000;
e_sa_fetoheng palo ISIKHATHI_SOKUNCIPHA = 3000;
e_sa_fetoheng palo ISIKHATHI_SOKUMA     = 5000;

lefeela qala() {
    beha_phini(ILAMBU_ELIBOMVU, TSE_TSWANG);
    beha_phini(ILAMBU_ELIPHUZI, TSE_TSWANG);
    beha_phini(ILAMBU_ELILUHLAZA, TSE_TSWANG);
}

lefeela pheta_pheta() {
    ngola_dijithale(ILAMBU_ELILUHLAZA, HODIMO);
    ngola_dijithale(ILAMBU_ELIPHUZI, TLASE);
    ngola_dijithale(ILAMBU_ELIBOMVU, TLASE);
    ema(ISIKHATHI_SOKUHAMBA);

    ngola_dijithale(ILAMBU_ELILUHLAZA, TLASE);
    ngola_dijithale(ILAMBU_ELIPHUZI, HODIMO);
    ema(ISIKHATHI_SOKUNCIPHA);

    ngola_dijithale(ILAMBU_ELIPHUZI, TLASE);
    ngola_dijithale(ILAMBU_ELIBOMVU, HODIMO);
    ema(ISIKHATHI_SOKUMA);
}
