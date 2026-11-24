#include <isiNdebele.h>

// Irobhothi lomgwaqo: amalambu omgwaqo nge-Arduino Mega 2560, ngesiZulu.
// Arduino traffic light (CMT Robotic Industries guide), written in isiZulu with Soga.
//   Okuluhlaza (hamba) 10 s -> okuphuzi (nciphisa ijubane) 3 s -> okubomvu (yima) 5 s -> phinda
// Ukuxhuma: okubomvu -> iphini 10, okuphuzi -> iphini 9, okuluhlaza -> iphini 8, GND -> umugqa oluhlaza (-)
// Wiring: red -> pin 10, yellow -> pin 9, green -> pin 8, each through a 220 ohm resistor to GND.

// Amaphini ku-Arduino Mega (pins on the Mega)
okungatjhugulukiko inomboro ILAMBU_ELIBOMVU   = 10;
okungatjhugulukiko inomboro ILAMBU_ELIPHUZI   = 9;
okungatjhugulukiko inomboro ILAMBU_ELILUHLAZA = 8;

// Izikhathi ngama-millisecond (1000 ms = umzuzwana owodwa)
okungatjhugulukiko inomboro ISIKHATHI_SOKUHAMBA  = 10000;   // 10 imizuzwana
okungatjhugulukiko inomboro ISIKHATHI_SOKUNCIPHA = 3000;    // 3 imizuzwana
okungatjhugulukiko inomboro ISIKHATHI_SOKUMA     = 5000;    // 5 imizuzwana

ilize thoma() {
    // Yenza amaphini amalambu abe ngokuphumayo (make the LED pins outputs)
    beka_iphini(ILAMBU_ELIBOMVU, OKUPHUMAKO);
    beka_iphini(ILAMBU_ELIPHUZI, OKUPHUMAKO);
    beka_iphini(ILAMBU_ELILUHLAZA, OKUPHUMAKO);
}

ilize phinda_phinda() {
    // HAMBA: okuluhlaza kukhanya imizuzwana eyi-10 (GO: green on)
    tlola_idijithali(ILAMBU_ELILUHLAZA, PHEZULU);
    tlola_idijithali(ILAMBU_ELIPHUZI, PHASI);
    tlola_idijithali(ILAMBU_ELIBOMVU, PHASI);
    lindela(ISIKHATHI_SOKUHAMBA);

    // NCIPHISA IJUBANE: okuphuzi kukhanya imizuzwana emi-3 (SLOW DOWN: yellow on)
    tlola_idijithali(ILAMBU_ELILUHLAZA, PHASI);
    tlola_idijithali(ILAMBU_ELIPHUZI, PHEZULU);
    lindela(ISIKHATHI_SOKUNCIPHA);

    // YIMA: okubomvu kukhanya imizuzwana emi-5 (STOP: red on)
    tlola_idijithali(ILAMBU_ELIPHUZI, PHASI);
    tlola_idijithali(ILAMBU_ELIBOMVU, PHEZULU);
    lindela(ISIKHATHI_SOKUMA);

    // phindaphinda() iqala futhi ngokwayo -> ibuyela kokuluhlaza
}
