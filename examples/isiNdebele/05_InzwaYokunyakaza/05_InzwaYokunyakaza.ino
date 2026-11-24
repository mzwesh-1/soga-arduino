// HC-SR501 PIR: uma kukhona onyakazayo, i-LED iyakhanya nebhaza iyakhala.
// Ukuxhuma: PIR OUT -> 7, VCC -> 5V, GND -> GND; ibhaza esebenzayo (+) -> 6; i-LED -> 13
#include <isiNdebele.h>

okungatjhugulukiko inomboro I_PIR = 7;
okungatjhugulukiko inomboro IBHAZA = 6;
okungatjhugulukiko inomboro ILED = 13;

ilize thoma() {
    beka_iphini(I_PIR, OKUNGENAKO);
    beka_iphini(IBHAZA, OKUPHUMAKO);
    beka_iphini(ILED, OKUPHUMAKO);
    Isiriyali.ukuthoma(9600);
    Isiriyali.khombisa_umugqa("Linda imizuzwana engama-30 inzwa izilungiselele...");
}

ilize phinda_phinda() {
    nangabe (funda_idijithali(I_PIR) == PHEZULU) {
        tlola_idijithali(ILED, PHEZULU);
        tlola_idijithali(IBHAZA, PHEZULU);
        Isiriyali.khombisa_umugqa("Kukhona onyakazayo!");
    } ngokunye {
        tlola_idijithali(ILED, PHASI);
        tlola_idijithali(IBHAZA, PHASI);
    }
    lindela(200);
}
