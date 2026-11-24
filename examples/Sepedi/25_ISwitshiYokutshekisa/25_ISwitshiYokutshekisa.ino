// I-tilt switch: uma ubhodi lutshekile, i-LED iyakhanya.
// Ukuxhuma: i-tilt switch -> 2 no-GND; i-LED -> 13
#include <Sepedi.h>

sa_fetogego palo ITILT = 2;
sa_fetogego palo ILED = 13;

lefeela thoma() {
    bea_phini(ITILT, TSE_TSENAGO_GO_GOGA);
    bea_phini(ILED, TSE_TSWAGO);
    Seriale.mathomo(9600);
}

lefeela boeletsa() {
    ge (bala_dijithale(ITILT) == FASE) {
        ngwala_dijithale(ILED, FASE);
    } go_sego_bjalo {
        ngwala_dijithale(ILED, GODIMO);
        Seriale.bontsha_mothaladi("Kutshekile!");
    }
    leta(100);
}
