#include <isiXhosa.h>

// Irobhothi lomgwaqo: amalambu omgwaqo nge-Arduino Mega 2560, ngesiZulu.
// Arduino traffic light (CMT Robotic Industries guide), written in isiZulu with Soga.
//   Okuluhlaza (hamba) 10 s -> okuphuzi (nciphisa ijubane) 3 s -> okubomvu (yima) 5 s -> phinda
// Ukuxhuma: okubomvu -> iphini 10, okuphuzi -> iphini 9, okuluhlaza -> iphini 8, GND -> umugqa oluhlaza (-)
// Wiring: red -> pin 10, yellow -> pin 9, green -> pin 8, each through a 220 ohm resistor to GND.

// Amaphini ku-Arduino Mega (pins on the Mega)
engatshintshiyo inani ILAMBU_ELIBOMVU   = 10;
engatshintshiyo inani ILAMBU_ELIPHUZI   = 9;
engatshintshiyo inani ILAMBU_ELILUHLAZA = 8;

// Izikhathi ngama-millisecond (1000 ms = umzuzwana owodwa)
engatshintshiyo inani ISIKHATHI_SOKUHAMBA  = 10000;   // 10 imizuzwana
engatshintshiyo inani ISIKHATHI_SOKUNCIPHA = 3000;    // 3 imizuzwana
engatshintshiyo inani ISIKHATHI_SOKUMA     = 5000;    // 5 imizuzwana

ize qalisa() {
    // Yenza amaphini amalambu abe ngokuphumayo (make the LED pins outputs)
    misela_iphini(ILAMBU_ELIBOMVU, OKUPHUMAYO);
    misela_iphini(ILAMBU_ELIPHUZI, OKUPHUMAYO);
    misela_iphini(ILAMBU_ELILUHLAZA, OKUPHUMAYO);
}

ize phinda_phinda() {
    // HAMBA: okuluhlaza kukhanya imizuzwana eyi-10 (GO: green on)
    bhala_idijithali(ILAMBU_ELILUHLAZA, PHEZULU);
    bhala_idijithali(ILAMBU_ELIPHUZI, EZANTSI);
    bhala_idijithali(ILAMBU_ELIBOMVU, EZANTSI);
    linda(ISIKHATHI_SOKUHAMBA);

    // NCIPHISA IJUBANE: okuphuzi kukhanya imizuzwana emi-3 (SLOW DOWN: yellow on)
    bhala_idijithali(ILAMBU_ELILUHLAZA, EZANTSI);
    bhala_idijithali(ILAMBU_ELIPHUZI, PHEZULU);
    linda(ISIKHATHI_SOKUNCIPHA);

    // YIMA: okubomvu kukhanya imizuzwana emi-5 (STOP: red on)
    bhala_idijithali(ILAMBU_ELIPHUZI, EZANTSI);
    bhala_idijithali(ILAMBU_ELIBOMVU, PHEZULU);
    linda(ISIKHATHI_SOKUMA);

    // phindaphinda() iqala futhi ngokwayo -> ibuyela kokuluhlaza
}
