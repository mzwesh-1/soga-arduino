// I-tilt switch: uma ubhodi lutshekile, i-LED iyakhanya.
// Ukuxhuma: i-tilt switch -> 2 no-GND; i-LED -> 13
#include <Setswana.h>

e_sa_fetogeng palo ITILT = 2;
e_sa_fetogeng palo ILED = 13;

lefela simolola() {
    baya_phini(ITILT, TSE_DI_TSENANG_GO_GOGA);
    baya_phini(ILED, TSE_DI_TSWANG);
    Seriale.tshimologo(9600);
}

lefela boeletsa() {
    fa (bala_dijithale(ITILT) == TLASE) {
        kwala_dijithale(ILED, TLASE);
    } go_seng_jalo {
        kwala_dijithale(ILED, GODIMO);
        Seriale.bontsha_mola("Kutshekile!");
    }
    ema(100);
}
