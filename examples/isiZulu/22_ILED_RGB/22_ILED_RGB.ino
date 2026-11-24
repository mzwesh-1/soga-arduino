// I-LED ye-RGB (cathode efanayo): ishintsha imibala.
// Ukuxhuma: R -> 6, G -> 5, B -> 3 (ngamunye nge-220 ohm), umlenze omude -> GND
#include <isiZulu.h>

engaguquki inombolo OKUBOMVU = 6;
engaguquki inombolo OKULUHLAZA = 5;
engaguquki inombolo OKUKHUHLAZA_OKWESIBHAKABHAKA = 3;

ize umbala(inombolo r, inombolo g, inombolo b) {
    bhala_ianalogi(OKUBOMVU, r);
    bhala_ianalogi(OKULUHLAZA, g);
    bhala_ianalogi(OKUKHUHLAZA_OKWESIBHAKABHAKA, b);
}

ize qala() {
    setha_iphini(OKUBOMVU, OKUPHUMAYO);
    setha_iphini(OKULUHLAZA, OKUPHUMAYO);
    setha_iphini(OKUKHUHLAZA_OKWESIBHAKABHAKA, OKUPHUMAYO);
}

ize phindaphinda() {
    umbala(255, 0, 0);   linda(1000);   // obomvu
    umbala(0, 255, 0);   linda(1000);   // oluhlaza
    umbala(0, 0, 255);   linda(1000);   // oluhlaza okwesibhakabhaka
    umbala(255, 255, 0); linda(1000);   // ophuzi
    umbala(255, 0, 255); linda(1000);   // onsomi
    umbala(255, 255, 255); linda(1000); // omhlophe
}
