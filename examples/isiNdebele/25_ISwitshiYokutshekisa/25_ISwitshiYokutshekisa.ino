// I-tilt switch: uma ubhodi lutshekile, i-LED iyakhanya.
// Ukuxhuma: i-tilt switch -> 2 no-GND; i-LED -> 13
#include <isiNdebele.h>

okungatjhugulukiko inomboro ITILT = 2;
okungatjhugulukiko inomboro ILED = 13;

ilize thoma() {
    beka_iphini(ITILT, OKUNGENAKO_KUDONSIWE);
    beka_iphini(ILED, OKUPHUMAKO);
    Isiriyali.ukuthoma(9600);
}

ilize phinda_phinda() {
    nangabe (funda_idijithali(ITILT) == PHASI) {
        tlola_idijithali(ILED, PHASI);
    } ngokunye {
        tlola_idijithali(ILED, PHEZULU);
        Isiriyali.khombisa_umugqa("Kutshekile!");
    }
    lindela(100);
}
