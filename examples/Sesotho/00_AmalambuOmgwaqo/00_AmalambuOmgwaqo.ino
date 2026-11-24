#include <Sesotho.h>

// Irobhothi lomgwaqo: amalambu omgwaqo nge-Arduino Mega 2560, ngesiZulu.
// Arduino traffic light (CMT Robotic Industries guide), written in isiZulu with Soga.
//   Okuluhlaza (hamba) 10 s -> okuphuzi (nciphisa ijubane) 3 s -> okubomvu (yima) 5 s -> phinda
// Ukuxhuma: okubomvu -> iphini 10, okuphuzi -> iphini 9, okuluhlaza -> iphini 8, GND -> umugqa oluhlaza (-)
// Wiring: red -> pin 10, yellow -> pin 9, green -> pin 8, each through a 220 ohm resistor to GND.

// Amaphini ku-Arduino Mega (pins on the Mega)
e_sa_fetoheng palo ILAMBU_ELIBOMVU   = 10;
e_sa_fetoheng palo ILAMBU_ELIPHUZI   = 9;
e_sa_fetoheng palo ILAMBU_ELILUHLAZA = 8;

// Izikhathi ngama-millisecond (1000 ms = umzuzwana owodwa)
e_sa_fetoheng palo ISIKHATHI_SOKUHAMBA  = 10000;   // 10 imizuzwana
e_sa_fetoheng palo ISIKHATHI_SOKUNCIPHA = 3000;    // 3 imizuzwana
e_sa_fetoheng palo ISIKHATHI_SOKUMA     = 5000;    // 5 imizuzwana

lefeela qala() {
    // Yenza amaphini amalambu abe ngokuphumayo (make the LED pins outputs)
    beha_phini(ILAMBU_ELIBOMVU, TSE_TSWANG);
    beha_phini(ILAMBU_ELIPHUZI, TSE_TSWANG);
    beha_phini(ILAMBU_ELILUHLAZA, TSE_TSWANG);
}

lefeela pheta_pheta() {
    // HAMBA: okuluhlaza kukhanya imizuzwana eyi-10 (GO: green on)
    ngola_dijithale(ILAMBU_ELILUHLAZA, HODIMO);
    ngola_dijithale(ILAMBU_ELIPHUZI, TLASE);
    ngola_dijithale(ILAMBU_ELIBOMVU, TLASE);
    ema(ISIKHATHI_SOKUHAMBA);

    // NCIPHISA IJUBANE: okuphuzi kukhanya imizuzwana emi-3 (SLOW DOWN: yellow on)
    ngola_dijithale(ILAMBU_ELILUHLAZA, TLASE);
    ngola_dijithale(ILAMBU_ELIPHUZI, HODIMO);
    ema(ISIKHATHI_SOKUNCIPHA);

    // YIMA: okubomvu kukhanya imizuzwana emi-5 (STOP: red on)
    ngola_dijithale(ILAMBU_ELIPHUZI, TLASE);
    ngola_dijithale(ILAMBU_ELIBOMVU, HODIMO);
    ema(ISIKHATHI_SOKUMA);

    // phindaphinda() iqala futhi ngokwayo -> ibuyela kokuluhlaza
}
