// I-rotary encoder: jika ukwandisa/ukunciphisa inombolo; cindezela ukuyibuyisela ku-0.
// Ukuxhuma: CLK -> 2, DT -> 3, SW -> 4, + -> 5V, GND -> GND
#include <Sesotho.h>

e_sa_fetoheng palo I_CLK = 2;
e_sa_fetoheng palo I_DT = 3;
e_sa_fetoheng palo I_SW = 4;
e_fetohang_kapele palo isibali = 0;
palo isibali_esidala = 0;

lefeela uma_kujikiwe() {
    haeba (bala_dijithale(I_DT) != bala_dijithale(I_CLK)) isibali++;   // ngokwewashi
    ho_seng_jwalo isibali--;                                               // ngokuphambene
}

lefeela qala() {
    beha_phini(I_CLK, TSE_KENANG);
    beha_phini(I_DT, TSE_KENANG);
    beha_phini(I_SW, TSE_KENANG_HO_HULA);
    Seriale.qalo(9600);
    hokela_tshitiso(phini_ho_tshitiso(I_CLK), uma_kujikiwe, HA_E_FETOHA);
}

lefeela pheta_pheta() {
    haeba (bala_dijithale(I_SW) == TLASE) {
        isibali = 0;
        ema(200);
    }
    haeba (isibali != isibali_esidala) {
        isibali_esidala = isibali;
        Seriale.bontsha("Isibali: ");
        Seriale.bontsha_mola(isibali);
    }
}
