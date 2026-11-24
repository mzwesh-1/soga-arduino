#include <Xitsonga.h>

// Irobhothi lomgwaqo: amalambu omgwaqo nge-Arduino Mega 2560, ngesiZulu.
// Arduino traffic light (CMT Robotic Industries guide), written in isiZulu with Soga.
//   Okuluhlaza (hamba) 10 s -> okuphuzi (nciphisa ijubane) 3 s -> okubomvu (yima) 5 s -> phinda
// Ukuxhuma: okubomvu -> iphini 10, okuphuzi -> iphini 9, okuluhlaza -> iphini 8, GND -> umugqa oluhlaza (-)
// Wiring: red -> pin 10, yellow -> pin 9, green -> pin 8, each through a 220 ohm resistor to GND.

// Amaphini ku-Arduino Mega (pins on the Mega)
lexi_nga_cinciki nomboro ILAMBU_ELIBOMVU   = 10;
lexi_nga_cinciki nomboro ILAMBU_ELIPHUZI   = 9;
lexi_nga_cinciki nomboro ILAMBU_ELILUHLAZA = 8;

// Izikhathi ngama-millisecond (1000 ms = umzuzwana owodwa)
lexi_nga_cinciki nomboro ISIKHATHI_SOKUHAMBA  = 10000;   // 10 imizuzwana
lexi_nga_cinciki nomboro ISIKHATHI_SOKUNCIPHA = 3000;    // 3 imizuzwana
lexi_nga_cinciki nomboro ISIKHATHI_SOKUMA     = 5000;    // 5 imizuzwana

swi_hava sungula() {
    // Yenza amaphini amalambu abe ngokuphumayo (make the LED pins outputs)
    veka_phini(ILAMBU_ELIBOMVU, LESWI_HUMAKA);
    veka_phini(ILAMBU_ELIPHUZI, LESWI_HUMAKA);
    veka_phini(ILAMBU_ELILUHLAZA, LESWI_HUMAKA);
}

swi_hava phindha_phindha() {
    // HAMBA: okuluhlaza kukhanya imizuzwana eyi-10 (GO: green on)
    tsala_dijitali(ILAMBU_ELILUHLAZA, HENHLA);
    tsala_dijitali(ILAMBU_ELIPHUZI, HANSI);
    tsala_dijitali(ILAMBU_ELIBOMVU, HANSI);
    rindza(ISIKHATHI_SOKUHAMBA);

    // NCIPHISA IJUBANE: okuphuzi kukhanya imizuzwana emi-3 (SLOW DOWN: yellow on)
    tsala_dijitali(ILAMBU_ELILUHLAZA, HANSI);
    tsala_dijitali(ILAMBU_ELIPHUZI, HENHLA);
    rindza(ISIKHATHI_SOKUNCIPHA);

    // YIMA: okubomvu kukhanya imizuzwana emi-5 (STOP: red on)
    tsala_dijitali(ILAMBU_ELIPHUZI, HANSI);
    tsala_dijitali(ILAMBU_ELIBOMVU, HENHLA);
    rindza(ISIKHATHI_SOKUMA);

    // phindaphinda() iqala futhi ngokwayo -> ibuyela kokuluhlaza
}
