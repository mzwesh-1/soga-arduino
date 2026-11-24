// I-rotary encoder: jika ukwandisa/ukunciphisa inombolo; cindezela ukuyibuyisela ku-0.
// Ukuxhuma: CLK -> 2, DT -> 3, SW -> 4, + -> 5V, GND -> GND
#include <Tshivenda.h>

zwi_sa_shanduki nomboro I_CLK = 2;
zwi_sa_shanduki nomboro I_DT = 3;
zwi_sa_shanduki nomboro I_SW = 4;
zwi_shandukaho_nga_u_tavhanya nomboro isibali = 0;
nomboro isibali_esidala = 0;

a_huna uma_kujikiwe() {
    arali (vhala_didzhithala(I_DT) != vhala_didzhithala(I_CLK)) isibali++;   // ngokwewashi
    nga_inwe_ndila isibali--;                                               // ngokuphambene
}

a_huna thoma() {
    vhea_phini(I_CLK, ZWI_DZHENAHO);
    vhea_phini(I_DT, ZWI_DZHENAHO);
    vhea_phini(I_SW, ZWI_DZHENAHO_NGA_U_KOKA);
    Siriale.mathomo(9600);
    tumanya_tshithithisi(phini_u_ya_tshithithisi(I_CLK), uma_kujikiwe, MUSI_I_TSHI_SHANDUKA);
}

a_huna dovholola() {
    arali (vhala_didzhithala(I_SW) == FHASI) {
        isibali = 0;
        lindela(200);
    }
    arali (isibali != isibali_esidala) {
        isibali_esidala = isibali;
        Siriale.sumbedza("Isibali: ");
        Siriale.sumbedza_mutalo(isibali);
    }
}
