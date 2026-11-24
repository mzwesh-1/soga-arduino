// I-LED ye-RGB (cathode efanayo): ishintsha imibala.
// Ukuxhuma: R -> 6, G -> 5, B -> 3 (ngamunye nge-220 ohm), umlenze omude -> GND
#include <isiNdebele.h>

okungatjhugulukiko inomboro OKUBOMVU = 6;
okungatjhugulukiko inomboro OKULUHLAZA = 5;
okungatjhugulukiko inomboro OKUKHUHLAZA_OKWESIBHAKABHAKA = 3;

ilize umbala(inomboro r, inomboro g, inomboro b) {
    tlola_ianalogi(OKUBOMVU, r);
    tlola_ianalogi(OKULUHLAZA, g);
    tlola_ianalogi(OKUKHUHLAZA_OKWESIBHAKABHAKA, b);
}

ilize thoma() {
    beka_iphini(OKUBOMVU, OKUPHUMAKO);
    beka_iphini(OKULUHLAZA, OKUPHUMAKO);
    beka_iphini(OKUKHUHLAZA_OKWESIBHAKABHAKA, OKUPHUMAKO);
}

ilize phinda_phinda() {
    umbala(255, 0, 0);   lindela(1000);   // obomvu
    umbala(0, 255, 0);   lindela(1000);   // oluhlaza
    umbala(0, 0, 255);   lindela(1000);   // oluhlaza okwesibhakabhaka
    umbala(255, 255, 0); lindela(1000);   // ophuzi
    umbala(255, 0, 255); lindela(1000);   // onsomi
    umbala(255, 255, 255); lindela(1000); // omhlophe
}
