// I-tilt switch: uma ubhodi lutshekile, i-LED iyakhanya.
// Ukuxhuma: i-tilt switch -> 2 no-GND; i-LED -> 13
#include <Sesotho.h>

e_sa_fetoheng palo ITILT = 2;
e_sa_fetoheng palo ILED = 13;

lefeela qala() {
    beha_phini(ITILT, TSE_KENANG_HO_HULA);
    beha_phini(ILED, TSE_TSWANG);
    Seriale.qalo(9600);
}

lefeela pheta_pheta() {
    haeba (bala_dijithale(ITILT) == TLASE) {
        ngola_dijithale(ILED, TLASE);
    } ho_seng_jwalo {
        ngola_dijithale(ILED, HODIMO);
        Seriale.bontsha_mola("Kutshekile!");
    }
    ema(100);
}
