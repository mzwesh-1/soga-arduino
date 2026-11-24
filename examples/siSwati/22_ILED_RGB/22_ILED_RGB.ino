// I-LED ye-RGB (cathode efanayo): ishintsha imibala.
// Ukuxhuma: R -> 6, G -> 5, B -> 3 (ngamunye nge-220 ohm), umlenze omude -> GND
#include <siSwati.h>

lokungagucuki inombolo OKUBOMVU = 6;
lokungagucuki inombolo OKULUHLAZA = 5;
lokungagucuki inombolo OKUKHUHLAZA_OKWESIBHAKABHAKA = 3;

lite umbala(inombolo r, inombolo g, inombolo b) {
    bhala_ianalogi(OKUBOMVU, r);
    bhala_ianalogi(OKULUHLAZA, g);
    bhala_ianalogi(OKUKHUHLAZA_OKWESIBHAKABHAKA, b);
}

lite cala() {
    setha_liphini(OKUBOMVU, LOKUPHUMAKO);
    setha_liphini(OKULUHLAZA, LOKUPHUMAKO);
    setha_liphini(OKUKHUHLAZA_OKWESIBHAKABHAKA, LOKUPHUMAKO);
}

lite phindza_phindza() {
    umbala(255, 0, 0);   lindza(1000);   // obomvu
    umbala(0, 255, 0);   lindza(1000);   // oluhlaza
    umbala(0, 0, 255);   lindza(1000);   // oluhlaza okwesibhakabhaka
    umbala(255, 255, 0); lindza(1000);   // ophuzi
    umbala(255, 0, 255); lindza(1000);   // onsomi
    umbala(255, 255, 255); lindza(1000); // omhlophe
}
