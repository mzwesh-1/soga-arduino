// I-LED ye-RGB (cathode efanayo): ishintsha imibala.
// Ukuxhuma: R -> 6, G -> 5, B -> 3 (ngamunye nge-220 ohm), umlenze omude -> GND
#include <Sepedi.h>

sa_fetogego palo OKUBOMVU = 6;
sa_fetogego palo OKULUHLAZA = 5;
sa_fetogego palo OKUKHUHLAZA_OKWESIBHAKABHAKA = 3;

lefeela umbala(palo r, palo g, palo b) {
    ngwala_analoko(OKUBOMVU, r);
    ngwala_analoko(OKULUHLAZA, g);
    ngwala_analoko(OKUKHUHLAZA_OKWESIBHAKABHAKA, b);
}

lefeela thoma() {
    bea_phini(OKUBOMVU, TSE_TSWAGO);
    bea_phini(OKULUHLAZA, TSE_TSWAGO);
    bea_phini(OKUKHUHLAZA_OKWESIBHAKABHAKA, TSE_TSWAGO);
}

lefeela boeletsa() {
    umbala(255, 0, 0);   leta(1000);   // obomvu
    umbala(0, 255, 0);   leta(1000);   // oluhlaza
    umbala(0, 0, 255);   leta(1000);   // oluhlaza okwesibhakabhaka
    umbala(255, 255, 0); leta(1000);   // ophuzi
    umbala(255, 0, 255); leta(1000);   // onsomi
    umbala(255, 255, 255); leta(1000); // omhlophe
}
