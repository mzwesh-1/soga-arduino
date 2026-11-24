// I-LED ye-RGB (cathode efanayo): ishintsha imibala.
// Ukuxhuma: R -> 6, G -> 5, B -> 3 (ngamunye nge-220 ohm), umlenze omude -> GND
#include <Setswana.h>

e_sa_fetogeng palo OKUBOMVU = 6;
e_sa_fetogeng palo OKULUHLAZA = 5;
e_sa_fetogeng palo OKUKHUHLAZA_OKWESIBHAKABHAKA = 3;

lefela umbala(palo r, palo g, palo b) {
    kwala_analoko(OKUBOMVU, r);
    kwala_analoko(OKULUHLAZA, g);
    kwala_analoko(OKUKHUHLAZA_OKWESIBHAKABHAKA, b);
}

lefela simolola() {
    baya_phini(OKUBOMVU, TSE_DI_TSWANG);
    baya_phini(OKULUHLAZA, TSE_DI_TSWANG);
    baya_phini(OKUKHUHLAZA_OKWESIBHAKABHAKA, TSE_DI_TSWANG);
}

lefela boeletsa() {
    umbala(255, 0, 0);   ema(1000);   // obomvu
    umbala(0, 255, 0);   ema(1000);   // oluhlaza
    umbala(0, 0, 255);   ema(1000);   // oluhlaza okwesibhakabhaka
    umbala(255, 255, 0); ema(1000);   // ophuzi
    umbala(255, 0, 255); ema(1000);   // onsomi
    umbala(255, 255, 255); ema(1000); // omhlophe
}
