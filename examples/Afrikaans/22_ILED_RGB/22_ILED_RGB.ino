// I-LED ye-RGB (cathode efanayo): ishintsha imibala.
// Ukuxhuma: R -> 6, G -> 5, B -> 3 (ngamunye nge-220 ohm), umlenze omude -> GND
#include <Afrikaans.h>

konstant heelgetal OKUBOMVU = 6;
konstant heelgetal OKULUHLAZA = 5;
konstant heelgetal OKUKHUHLAZA_OKWESIBHAKABHAKA = 3;

leeg umbala(heelgetal r, heelgetal g, heelgetal b) {
    skryfanaloog(OKUBOMVU, r);
    skryfanaloog(OKULUHLAZA, g);
    skryfanaloog(OKUKHUHLAZA_OKWESIBHAKABHAKA, b);
}

leeg opstel() {
    penmodus(OKUBOMVU, UITSET);
    penmodus(OKULUHLAZA, UITSET);
    penmodus(OKUKHUHLAZA_OKWESIBHAKABHAKA, UITSET);
}

leeg lus() {
    umbala(255, 0, 0);   wag(1000);   // obomvu
    umbala(0, 255, 0);   wag(1000);   // oluhlaza
    umbala(0, 0, 255);   wag(1000);   // oluhlaza okwesibhakabhaka
    umbala(255, 255, 0); wag(1000);   // ophuzi
    umbala(255, 0, 255); wag(1000);   // onsomi
    umbala(255, 255, 255); wag(1000); // omhlophe
}
