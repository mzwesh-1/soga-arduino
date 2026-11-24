#include <siSwati.h>

// Irobhothi lomgwaqo: amalambu omgwaqo nge-Arduino Mega 2560, ngesiZulu.
// Arduino traffic light (CMT Robotic Industries guide), written in isiZulu with Soga.
//   Okuluhlaza (hamba) 10 s -> okuphuzi (nciphisa ijubane) 3 s -> okubomvu (yima) 5 s -> phinda
// Ukuxhuma: okubomvu -> iphini 10, okuphuzi -> iphini 9, okuluhlaza -> iphini 8, GND -> umugqa oluhlaza (-)
// Wiring: red -> pin 10, yellow -> pin 9, green -> pin 8, each through a 220 ohm resistor to GND.

// Amaphini ku-Arduino Mega (pins on the Mega)
lokungagucuki inombolo ILAMBU_ELIBOMVU   = 10;
lokungagucuki inombolo ILAMBU_ELIPHUZI   = 9;
lokungagucuki inombolo ILAMBU_ELILUHLAZA = 8;

// Izikhathi ngama-millisecond (1000 ms = umzuzwana owodwa)
lokungagucuki inombolo ISIKHATHI_SOKUHAMBA  = 10000;   // 10 imizuzwana
lokungagucuki inombolo ISIKHATHI_SOKUNCIPHA = 3000;    // 3 imizuzwana
lokungagucuki inombolo ISIKHATHI_SOKUMA     = 5000;    // 5 imizuzwana

lite cala() {
    // Yenza amaphini amalambu abe ngokuphumayo (make the LED pins outputs)
    setha_liphini(ILAMBU_ELIBOMVU, LOKUPHUMAKO);
    setha_liphini(ILAMBU_ELIPHUZI, LOKUPHUMAKO);
    setha_liphini(ILAMBU_ELILUHLAZA, LOKUPHUMAKO);
}

lite phindza_phindza() {
    // HAMBA: okuluhlaza kukhanya imizuzwana eyi-10 (GO: green on)
    bhala_idijithali(ILAMBU_ELILUHLAZA, PHETULU);
    bhala_idijithali(ILAMBU_ELIPHUZI, PHANSI);
    bhala_idijithali(ILAMBU_ELIBOMVU, PHANSI);
    lindza(ISIKHATHI_SOKUHAMBA);

    // NCIPHISA IJUBANE: okuphuzi kukhanya imizuzwana emi-3 (SLOW DOWN: yellow on)
    bhala_idijithali(ILAMBU_ELILUHLAZA, PHANSI);
    bhala_idijithali(ILAMBU_ELIPHUZI, PHETULU);
    lindza(ISIKHATHI_SOKUNCIPHA);

    // YIMA: okubomvu kukhanya imizuzwana emi-5 (STOP: red on)
    bhala_idijithali(ILAMBU_ELIPHUZI, PHANSI);
    bhala_idijithali(ILAMBU_ELIBOMVU, PHETULU);
    lindza(ISIKHATHI_SOKUMA);

    // phindaphinda() iqala futhi ngokwayo -> ibuyela kokuluhlaza
}
