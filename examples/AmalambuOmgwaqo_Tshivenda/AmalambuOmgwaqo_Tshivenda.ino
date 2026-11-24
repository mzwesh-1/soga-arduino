#include <Tshivenda.h>

// Traffic light: green 10 s -> yellow 3 s -> red 5 s. Red pin 10, yellow pin 9, green pin 8 (220 ohm to GND).

zwi_sa_shanduki nomboro ILAMBU_ELIBOMVU   = 10;
zwi_sa_shanduki nomboro ILAMBU_ELIPHUZI   = 9;
zwi_sa_shanduki nomboro ILAMBU_ELILUHLAZA = 8;

zwi_sa_shanduki nomboro ISIKHATHI_SOKUHAMBA  = 10000;
zwi_sa_shanduki nomboro ISIKHATHI_SOKUNCIPHA = 3000;
zwi_sa_shanduki nomboro ISIKHATHI_SOKUMA     = 5000;

a_huna thoma() {
    vhea_phini(ILAMBU_ELIBOMVU, ZWI_BVAHO);
    vhea_phini(ILAMBU_ELIPHUZI, ZWI_BVAHO);
    vhea_phini(ILAMBU_ELILUHLAZA, ZWI_BVAHO);
}

a_huna dovholola() {
    nwala_didzhithala(ILAMBU_ELILUHLAZA, NTHA);
    nwala_didzhithala(ILAMBU_ELIPHUZI, FHASI);
    nwala_didzhithala(ILAMBU_ELIBOMVU, FHASI);
    lindela(ISIKHATHI_SOKUHAMBA);

    nwala_didzhithala(ILAMBU_ELILUHLAZA, FHASI);
    nwala_didzhithala(ILAMBU_ELIPHUZI, NTHA);
    lindela(ISIKHATHI_SOKUNCIPHA);

    nwala_didzhithala(ILAMBU_ELIPHUZI, FHASI);
    nwala_didzhithala(ILAMBU_ELIBOMVU, NTHA);
    lindela(ISIKHATHI_SOKUMA);
}
