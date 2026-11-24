// I-LED ye-RGB (cathode efanayo): ishintsha imibala.
// Ukuxhuma: R -> 6, G -> 5, B -> 3 (ngamunye nge-220 ohm), umlenze omude -> GND
#include <Xitsonga.h>

lexi_nga_cinciki nomboro OKUBOMVU = 6;
lexi_nga_cinciki nomboro OKULUHLAZA = 5;
lexi_nga_cinciki nomboro OKUKHUHLAZA_OKWESIBHAKABHAKA = 3;

swi_hava umbala(nomboro r, nomboro g, nomboro b) {
    tsala_analogo(OKUBOMVU, r);
    tsala_analogo(OKULUHLAZA, g);
    tsala_analogo(OKUKHUHLAZA_OKWESIBHAKABHAKA, b);
}

swi_hava sungula() {
    veka_phini(OKUBOMVU, LESWI_HUMAKA);
    veka_phini(OKULUHLAZA, LESWI_HUMAKA);
    veka_phini(OKUKHUHLAZA_OKWESIBHAKABHAKA, LESWI_HUMAKA);
}

swi_hava phindha_phindha() {
    umbala(255, 0, 0);   rindza(1000);   // obomvu
    umbala(0, 255, 0);   rindza(1000);   // oluhlaza
    umbala(0, 0, 255);   rindza(1000);   // oluhlaza okwesibhakabhaka
    umbala(255, 255, 0); rindza(1000);   // ophuzi
    umbala(255, 0, 255); rindza(1000);   // onsomi
    umbala(255, 255, 255); rindza(1000); // omhlophe
}
