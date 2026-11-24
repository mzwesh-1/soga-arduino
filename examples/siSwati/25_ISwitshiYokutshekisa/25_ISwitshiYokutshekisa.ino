// I-tilt switch: uma ubhodi lutshekile, i-LED iyakhanya.
// Ukuxhuma: i-tilt switch -> 2 no-GND; i-LED -> 13
#include <siSwati.h>

lokungagucuki inombolo ITILT = 2;
lokungagucuki inombolo ILED = 13;

lite cala() {
    setha_liphini(ITILT, LOKUNGENAKO_KUDONSIWE);
    setha_liphini(ILED, LOKUPHUMAKO);
    Siriyali.kucala(9600);
}

lite phindza_phindza() {
    nangabe (fundza_idijithali(ITILT) == PHANSI) {
        bhala_idijithali(ILED, PHANSI);
    } ngalokunye {
        bhala_idijithali(ILED, PHETULU);
        Siriyali.khombisa_umugca("Kutshekile!");
    }
    lindza(100);
}
