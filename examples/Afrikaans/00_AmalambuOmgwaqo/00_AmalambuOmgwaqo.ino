#include <Afrikaans.h>

// Irobhothi lomgwaqo: amalambu omgwaqo nge-Arduino Mega 2560, ngesiZulu.
// Arduino traffic light (CMT Robotic Industries guide), written in isiZulu with Soga.
//   Okuluhlaza (hamba) 10 s -> okuphuzi (nciphisa ijubane) 3 s -> okubomvu (yima) 5 s -> phinda
// Ukuxhuma: okubomvu -> iphini 10, okuphuzi -> iphini 9, okuluhlaza -> iphini 8, GND -> umugqa oluhlaza (-)
// Wiring: red -> pin 10, yellow -> pin 9, green -> pin 8, each through a 220 ohm resistor to GND.

// Amaphini ku-Arduino Mega (pins on the Mega)
konstant heelgetal ILAMBU_ELIBOMVU   = 10;
konstant heelgetal ILAMBU_ELIPHUZI   = 9;
konstant heelgetal ILAMBU_ELILUHLAZA = 8;

// Izikhathi ngama-millisecond (1000 ms = umzuzwana owodwa)
konstant heelgetal ISIKHATHI_SOKUHAMBA  = 10000;   // 10 imizuzwana
konstant heelgetal ISIKHATHI_SOKUNCIPHA = 3000;    // 3 imizuzwana
konstant heelgetal ISIKHATHI_SOKUMA     = 5000;    // 5 imizuzwana

leeg opstel() {
    // Yenza amaphini amalambu abe ngokuphumayo (make the LED pins outputs)
    penmodus(ILAMBU_ELIBOMVU, UITSET);
    penmodus(ILAMBU_ELIPHUZI, UITSET);
    penmodus(ILAMBU_ELILUHLAZA, UITSET);
}

leeg lus() {
    // HAMBA: okuluhlaza kukhanya imizuzwana eyi-10 (GO: green on)
    skryfdigitaal(ILAMBU_ELILUHLAZA, HOOG);
    skryfdigitaal(ILAMBU_ELIPHUZI, LAAG);
    skryfdigitaal(ILAMBU_ELIBOMVU, LAAG);
    wag(ISIKHATHI_SOKUHAMBA);

    // NCIPHISA IJUBANE: okuphuzi kukhanya imizuzwana emi-3 (SLOW DOWN: yellow on)
    skryfdigitaal(ILAMBU_ELILUHLAZA, LAAG);
    skryfdigitaal(ILAMBU_ELIPHUZI, HOOG);
    wag(ISIKHATHI_SOKUNCIPHA);

    // YIMA: okubomvu kukhanya imizuzwana emi-5 (STOP: red on)
    skryfdigitaal(ILAMBU_ELIPHUZI, LAAG);
    skryfdigitaal(ILAMBU_ELIBOMVU, HOOG);
    wag(ISIKHATHI_SOKUMA);

    // phindaphinda() iqala futhi ngokwayo -> ibuyela kokuluhlaza
}
