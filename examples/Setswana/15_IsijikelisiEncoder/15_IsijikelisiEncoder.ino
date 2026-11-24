// I-rotary encoder: jika ukwandisa/ukunciphisa inombolo; cindezela ukuyibuyisela ku-0.
// Ukuxhuma: CLK -> 2, DT -> 3, SW -> 4, + -> 5V, GND -> GND
#include <Setswana.h>

e_sa_fetogeng palo I_CLK = 2;
e_sa_fetogeng palo I_DT = 3;
e_sa_fetogeng palo I_SW = 4;
e_fetogang_ka_bonako palo isibali = 0;
palo isibali_esidala = 0;

lefela uma_kujikiwe() {
    fa (bala_dijithale(I_DT) != bala_dijithale(I_CLK)) isibali++;   // ngokwewashi
    go_seng_jalo isibali--;                                               // ngokuphambene
}

lefela simolola() {
    baya_phini(I_CLK, TSE_DI_TSENANG);
    baya_phini(I_DT, TSE_DI_TSENANG);
    baya_phini(I_SW, TSE_DI_TSENANG_GO_GOGA);
    Seriale.tshimologo(9600);
    golaganya_tshitiso(phini_go_tshitiso(I_CLK), uma_kujikiwe, FA_E_FETOGA);
}

lefela boeletsa() {
    fa (bala_dijithale(I_SW) == TLASE) {
        isibali = 0;
        ema(200);
    }
    fa (isibali != isibali_esidala) {
        isibali_esidala = isibali;
        Seriale.bontsha("Isibali: ");
        Seriale.bontsha_mola(isibali);
    }
}
