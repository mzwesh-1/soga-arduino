#include <isiZulu.h>

// Irobhothi lomgwaqo: amalambu omgwaqo nge-Arduino Mega 2560, ngesiZulu.
// Arduino traffic light (CMT Robotic Industries guide), written in isiZulu with Soga.
//   Okuluhlaza (hamba) 10 s -> okuphuzi (nciphisa ijubane) 3 s -> okubomvu (yima) 5 s -> phinda
// Ukuxhuma: okubomvu -> iphini 10, okuphuzi -> iphini 9, okuluhlaza -> iphini 8, GND -> umugqa oluhlaza (-)
// Wiring: red -> pin 10, yellow -> pin 9, green -> pin 8, each through a 220 ohm resistor to GND.

// Amaphini ku-Arduino Mega (pins on the Mega)
engaguquki inombolo ILAMBU_ELIBOMVU   = 10;
engaguquki inombolo ILAMBU_ELIPHUZI   = 9;
engaguquki inombolo ILAMBU_ELILUHLAZA = 8;

// Izikhathi ngama-millisecond (1000 ms = umzuzwana owodwa)
engaguquki inombolo ISIKHATHI_SOKUHAMBA  = 10000;   // 10 imizuzwana
engaguquki inombolo ISIKHATHI_SOKUNCIPHA = 3000;    // 3 imizuzwana
engaguquki inombolo ISIKHATHI_SOKUMA     = 5000;    // 5 imizuzwana

ize qala() {
    // Yenza amaphini amalambu abe ngokuphumayo (make the LED pins outputs)
    setha_iphini(ILAMBU_ELIBOMVU, OKUPHUMAYO);
    setha_iphini(ILAMBU_ELIPHUZI, OKUPHUMAYO);
    setha_iphini(ILAMBU_ELILUHLAZA, OKUPHUMAYO);
}

ize phindaphinda() {
    // HAMBA: okuluhlaza kukhanya imizuzwana eyi-10 (GO: green on)
    bhala_idijithali(ILAMBU_ELILUHLAZA, PHEZULU);
    bhala_idijithali(ILAMBU_ELIPHUZI, PHANSI);
    bhala_idijithali(ILAMBU_ELIBOMVU, PHANSI);
    linda(ISIKHATHI_SOKUHAMBA);

    // NCIPHISA IJUBANE: okuphuzi kukhanya imizuzwana emi-3 (SLOW DOWN: yellow on)
    bhala_idijithali(ILAMBU_ELILUHLAZA, PHANSI);
    bhala_idijithali(ILAMBU_ELIPHUZI, PHEZULU);
    linda(ISIKHATHI_SOKUNCIPHA);

    // YIMA: okubomvu kukhanya imizuzwana emi-5 (STOP: red on)
    bhala_idijithali(ILAMBU_ELIPHUZI, PHANSI);
    bhala_idijithali(ILAMBU_ELIBOMVU, PHEZULU);
    linda(ISIKHATHI_SOKUMA);

    // phindaphinda() iqala futhi ngokwayo -> ibuyela kokuluhlaza
}
