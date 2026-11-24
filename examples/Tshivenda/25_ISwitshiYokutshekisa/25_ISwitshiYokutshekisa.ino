// I-tilt switch: uma ubhodi lutshekile, i-LED iyakhanya.
// Ukuxhuma: i-tilt switch -> 2 no-GND; i-LED -> 13
#include <Tshivenda.h>

zwi_sa_shanduki nomboro ITILT = 2;
zwi_sa_shanduki nomboro ILED = 13;

a_huna thoma() {
    vhea_phini(ITILT, ZWI_DZHENAHO_NGA_U_KOKA);
    vhea_phini(ILED, ZWI_BVAHO);
    Siriale.mathomo(9600);
}

a_huna dovholola() {
    arali (vhala_didzhithala(ITILT) == FHASI) {
        nwala_didzhithala(ILED, FHASI);
    } nga_inwe_ndila {
        nwala_didzhithala(ILED, NTHA);
        Siriale.sumbedza_mutalo("Kutshekile!");
    }
    lindela(100);
}
