// I-rotary encoder: jika ukwandisa/ukunciphisa inombolo; cindezela ukuyibuyisela ku-0.
// Ukuxhuma: CLK -> 2, DT -> 3, SW -> 4, + -> 5V, GND -> GND
#include <Sepedi.h>

sa_fetogego palo I_CLK = 2;
sa_fetogego palo I_DT = 3;
sa_fetogego palo I_SW = 4;
fetogago_kapejana palo isibali = 0;
palo isibali_esidala = 0;

lefeela uma_kujikiwe() {
    ge (bala_dijithale(I_DT) != bala_dijithale(I_CLK)) isibali++;   // ngokwewashi
    go_sego_bjalo isibali--;                                               // ngokuphambene
}

lefeela thoma() {
    bea_phini(I_CLK, TSE_TSENAGO);
    bea_phini(I_DT, TSE_TSENAGO);
    bea_phini(I_SW, TSE_TSENAGO_GO_GOGA);
    Seriale.mathomo(9600);
    kgokaganya_tshitiso(phini_go_tshitiso(I_CLK), uma_kujikiwe, GE_E_FETOGA);
}

lefeela boeletsa() {
    ge (bala_dijithale(I_SW) == FASE) {
        isibali = 0;
        leta(200);
    }
    ge (isibali != isibali_esidala) {
        isibali_esidala = isibali;
        Seriale.bontsha("Isibali: ");
        Seriale.bontsha_mothaladi(isibali);
    }
}
