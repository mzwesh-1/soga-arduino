// I-LED ye-RGB (cathode efanayo): ishintsha imibala.
// Ukuxhuma: R -> 6, G -> 5, B -> 3 (ngamunye nge-220 ohm), umlenze omude -> GND
#include <isiXhosa.h>

engatshintshiyo inani OKUBOMVU = 6;
engatshintshiyo inani OKULUHLAZA = 5;
engatshintshiyo inani OKUKHUHLAZA_OKWESIBHAKABHAKA = 3;

ize umbala(inani r, inani g, inani b) {
    bhala_ianalogu(OKUBOMVU, r);
    bhala_ianalogu(OKULUHLAZA, g);
    bhala_ianalogu(OKUKHUHLAZA_OKWESIBHAKABHAKA, b);
}

ize qalisa() {
    misela_iphini(OKUBOMVU, OKUPHUMAYO);
    misela_iphini(OKULUHLAZA, OKUPHUMAYO);
    misela_iphini(OKUKHUHLAZA_OKWESIBHAKABHAKA, OKUPHUMAYO);
}

ize phinda_phinda() {
    umbala(255, 0, 0);   linda(1000);   // obomvu
    umbala(0, 255, 0);   linda(1000);   // oluhlaza
    umbala(0, 0, 255);   linda(1000);   // oluhlaza okwesibhakabhaka
    umbala(255, 255, 0); linda(1000);   // ophuzi
    umbala(255, 0, 255); linda(1000);   // onsomi
    umbala(255, 255, 255); linda(1000); // omhlophe
}
