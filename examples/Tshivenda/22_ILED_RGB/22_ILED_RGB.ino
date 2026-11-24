// I-LED ye-RGB (cathode efanayo): ishintsha imibala.
// Ukuxhuma: R -> 6, G -> 5, B -> 3 (ngamunye nge-220 ohm), umlenze omude -> GND
#include <Tshivenda.h>

zwi_sa_shanduki nomboro OKUBOMVU = 6;
zwi_sa_shanduki nomboro OKULUHLAZA = 5;
zwi_sa_shanduki nomboro OKUKHUHLAZA_OKWESIBHAKABHAKA = 3;

a_huna umbala(nomboro r, nomboro g, nomboro b) {
    nwala_analogo(OKUBOMVU, r);
    nwala_analogo(OKULUHLAZA, g);
    nwala_analogo(OKUKHUHLAZA_OKWESIBHAKABHAKA, b);
}

a_huna thoma() {
    vhea_phini(OKUBOMVU, ZWI_BVAHO);
    vhea_phini(OKULUHLAZA, ZWI_BVAHO);
    vhea_phini(OKUKHUHLAZA_OKWESIBHAKABHAKA, ZWI_BVAHO);
}

a_huna dovholola() {
    umbala(255, 0, 0);   lindela(1000);   // obomvu
    umbala(0, 255, 0);   lindela(1000);   // oluhlaza
    umbala(0, 0, 255);   lindela(1000);   // oluhlaza okwesibhakabhaka
    umbala(255, 255, 0); lindela(1000);   // ophuzi
    umbala(255, 0, 255); lindela(1000);   // onsomi
    umbala(255, 255, 255); lindela(1000); // omhlophe
}
