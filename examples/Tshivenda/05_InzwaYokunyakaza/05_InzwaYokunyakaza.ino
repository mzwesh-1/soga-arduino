// HC-SR501 PIR: uma kukhona onyakazayo, i-LED iyakhanya nebhaza iyakhala.
// Ukuxhuma: PIR OUT -> 7, VCC -> 5V, GND -> GND; ibhaza esebenzayo (+) -> 6; i-LED -> 13
#include <Tshivenda.h>

zwi_sa_shanduki nomboro I_PIR = 7;
zwi_sa_shanduki nomboro IBHAZA = 6;
zwi_sa_shanduki nomboro ILED = 13;

a_huna thoma() {
    vhea_phini(I_PIR, ZWI_DZHENAHO);
    vhea_phini(IBHAZA, ZWI_BVAHO);
    vhea_phini(ILED, ZWI_BVAHO);
    Siriale.mathomo(9600);
    Siriale.sumbedza_mutalo("Linda imizuzwana engama-30 inzwa izilungiselele...");
}

a_huna dovholola() {
    arali (vhala_didzhithala(I_PIR) == NTHA) {
        nwala_didzhithala(ILED, NTHA);
        nwala_didzhithala(IBHAZA, NTHA);
        Siriale.sumbedza_mutalo("Kukhona onyakazayo!");
    } nga_inwe_ndila {
        nwala_didzhithala(ILED, FHASI);
        nwala_didzhithala(IBHAZA, FHASI);
    }
    lindela(200);
}
