#include <Sepedi.h>

// Irobhothi lomgwaqo: amalambu omgwaqo nge-Arduino Mega 2560, ngesiZulu.
// Arduino traffic light (CMT Robotic Industries guide), written in isiZulu with Soga.
//   Okuluhlaza (hamba) 10 s -> okuphuzi (nciphisa ijubane) 3 s -> okubomvu (yima) 5 s -> phinda
// Ukuxhuma: okubomvu -> iphini 10, okuphuzi -> iphini 9, okuluhlaza -> iphini 8, GND -> umugqa oluhlaza (-)
// Wiring: red -> pin 10, yellow -> pin 9, green -> pin 8, each through a 220 ohm resistor to GND.

// Amaphini ku-Arduino Mega (pins on the Mega)
sa_fetogego palo ILAMBU_ELIBOMVU   = 10;
sa_fetogego palo ILAMBU_ELIPHUZI   = 9;
sa_fetogego palo ILAMBU_ELILUHLAZA = 8;

// Izikhathi ngama-millisecond (1000 ms = umzuzwana owodwa)
sa_fetogego palo ISIKHATHI_SOKUHAMBA  = 10000;   // 10 imizuzwana
sa_fetogego palo ISIKHATHI_SOKUNCIPHA = 3000;    // 3 imizuzwana
sa_fetogego palo ISIKHATHI_SOKUMA     = 5000;    // 5 imizuzwana

lefeela thoma() {
    // Yenza amaphini amalambu abe ngokuphumayo (make the LED pins outputs)
    bea_phini(ILAMBU_ELIBOMVU, TSE_TSWAGO);
    bea_phini(ILAMBU_ELIPHUZI, TSE_TSWAGO);
    bea_phini(ILAMBU_ELILUHLAZA, TSE_TSWAGO);
}

lefeela boeletsa() {
    // HAMBA: okuluhlaza kukhanya imizuzwana eyi-10 (GO: green on)
    ngwala_dijithale(ILAMBU_ELILUHLAZA, GODIMO);
    ngwala_dijithale(ILAMBU_ELIPHUZI, FASE);
    ngwala_dijithale(ILAMBU_ELIBOMVU, FASE);
    leta(ISIKHATHI_SOKUHAMBA);

    // NCIPHISA IJUBANE: okuphuzi kukhanya imizuzwana emi-3 (SLOW DOWN: yellow on)
    ngwala_dijithale(ILAMBU_ELILUHLAZA, FASE);
    ngwala_dijithale(ILAMBU_ELIPHUZI, GODIMO);
    leta(ISIKHATHI_SOKUNCIPHA);

    // YIMA: okubomvu kukhanya imizuzwana emi-5 (STOP: red on)
    ngwala_dijithale(ILAMBU_ELIPHUZI, FASE);
    ngwala_dijithale(ILAMBU_ELIBOMVU, GODIMO);
    leta(ISIKHATHI_SOKUMA);

    // phindaphinda() iqala futhi ngokwayo -> ibuyela kokuluhlaza
}
