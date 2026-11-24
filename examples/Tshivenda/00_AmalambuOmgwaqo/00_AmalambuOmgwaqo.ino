#include <Tshivenda.h>

// Irobhothi lomgwaqo: amalambu omgwaqo nge-Arduino Mega 2560, ngesiZulu.
// Arduino traffic light (CMT Robotic Industries guide), written in isiZulu with Soga.
//   Okuluhlaza (hamba) 10 s -> okuphuzi (nciphisa ijubane) 3 s -> okubomvu (yima) 5 s -> phinda
// Ukuxhuma: okubomvu -> iphini 10, okuphuzi -> iphini 9, okuluhlaza -> iphini 8, GND -> umugqa oluhlaza (-)
// Wiring: red -> pin 10, yellow -> pin 9, green -> pin 8, each through a 220 ohm resistor to GND.

// Amaphini ku-Arduino Mega (pins on the Mega)
zwi_sa_shanduki nomboro ILAMBU_ELIBOMVU   = 10;
zwi_sa_shanduki nomboro ILAMBU_ELIPHUZI   = 9;
zwi_sa_shanduki nomboro ILAMBU_ELILUHLAZA = 8;

// Izikhathi ngama-millisecond (1000 ms = umzuzwana owodwa)
zwi_sa_shanduki nomboro ISIKHATHI_SOKUHAMBA  = 10000;   // 10 imizuzwana
zwi_sa_shanduki nomboro ISIKHATHI_SOKUNCIPHA = 3000;    // 3 imizuzwana
zwi_sa_shanduki nomboro ISIKHATHI_SOKUMA     = 5000;    // 5 imizuzwana

a_huna thoma() {
    // Yenza amaphini amalambu abe ngokuphumayo (make the LED pins outputs)
    vhea_phini(ILAMBU_ELIBOMVU, ZWI_BVAHO);
    vhea_phini(ILAMBU_ELIPHUZI, ZWI_BVAHO);
    vhea_phini(ILAMBU_ELILUHLAZA, ZWI_BVAHO);
}

a_huna dovholola() {
    // HAMBA: okuluhlaza kukhanya imizuzwana eyi-10 (GO: green on)
    nwala_didzhithala(ILAMBU_ELILUHLAZA, NTHA);
    nwala_didzhithala(ILAMBU_ELIPHUZI, FHASI);
    nwala_didzhithala(ILAMBU_ELIBOMVU, FHASI);
    lindela(ISIKHATHI_SOKUHAMBA);

    // NCIPHISA IJUBANE: okuphuzi kukhanya imizuzwana emi-3 (SLOW DOWN: yellow on)
    nwala_didzhithala(ILAMBU_ELILUHLAZA, FHASI);
    nwala_didzhithala(ILAMBU_ELIPHUZI, NTHA);
    lindela(ISIKHATHI_SOKUNCIPHA);

    // YIMA: okubomvu kukhanya imizuzwana emi-5 (STOP: red on)
    nwala_didzhithala(ILAMBU_ELIPHUZI, FHASI);
    nwala_didzhithala(ILAMBU_ELIBOMVU, NTHA);
    lindela(ISIKHATHI_SOKUMA);

    // phindaphinda() iqala futhi ngokwayo -> ibuyela kokuluhlaza
}
