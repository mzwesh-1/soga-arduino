// I-LED ye-RGB (cathode efanayo): ishintsha imibala.
// Ukuxhuma: R -> 6, G -> 5, B -> 3 (ngamunye nge-220 ohm), umlenze omude -> GND
#include <Sesotho.h>

e_sa_fetoheng palo OKUBOMVU = 6;
e_sa_fetoheng palo OKULUHLAZA = 5;
e_sa_fetoheng palo OKUKHUHLAZA_OKWESIBHAKABHAKA = 3;

lefeela umbala(palo r, palo g, palo b) {
    ngola_analoko(OKUBOMVU, r);
    ngola_analoko(OKULUHLAZA, g);
    ngola_analoko(OKUKHUHLAZA_OKWESIBHAKABHAKA, b);
}

lefeela qala() {
    beha_phini(OKUBOMVU, TSE_TSWANG);
    beha_phini(OKULUHLAZA, TSE_TSWANG);
    beha_phini(OKUKHUHLAZA_OKWESIBHAKABHAKA, TSE_TSWANG);
}

lefeela pheta_pheta() {
    umbala(255, 0, 0);   ema(1000);   // obomvu
    umbala(0, 255, 0);   ema(1000);   // oluhlaza
    umbala(0, 0, 255);   ema(1000);   // oluhlaza okwesibhakabhaka
    umbala(255, 255, 0); ema(1000);   // ophuzi
    umbala(255, 0, 255); ema(1000);   // onsomi
    umbala(255, 255, 255); ema(1000); // omhlophe
}
