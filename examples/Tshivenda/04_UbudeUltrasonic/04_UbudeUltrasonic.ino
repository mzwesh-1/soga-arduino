// HC-SR04: ilinganisa ibanga ukuya entweni ngomsindo (ama-sentimitha).
// Ukuxhuma: VCC -> 5V, Trig -> 12, Echo -> 11, GND -> GND
#include <Tshivenda.h>

zwi_sa_shanduki nomboro ITRIG = 12;
zwi_sa_shanduki nomboro IECHO = 11;

a_huna thoma() {
    Siriale.mathomo(9600);
    vhea_phini(ITRIG, ZWI_BVAHO);
    vhea_phini(IECHO, ZWI_DZHENAHO);
}

desimala linganisa_ibanga() {
    nwala_didzhithala(ITRIG, FHASI);
    lindela_maikhro(2);
    nwala_didzhithala(ITRIG, NTHA);      // thumela umsindo isikhathi esingu-10 us
    lindela_maikhro(10);
    nwala_didzhithala(ITRIG, FHASI);
    hu_si_na_tshiga lapfu isikhathi_sokubuya = ela_phalisi(IECHO, NTHA, 30000);
    vhuisa isikhathi_sokubuya * 0.0343 / 2;         // umsindo uhamba 0.0343 cm nge-us, uya ubuye
}

a_huna dovholola() {
    desimala ibanga = linganisa_ibanga();
    arali (ibanga == 0) {
        Siriale.sumbedza_mutalo("Ayikho into ebangeni");
    } nga_inwe_ndila {
        Siriale.sumbedza("Ibanga: ");
        Siriale.sumbedza(ibanga);
        Siriale.sumbedza_mutalo(" cm");
    }
    lindela(500);
}
