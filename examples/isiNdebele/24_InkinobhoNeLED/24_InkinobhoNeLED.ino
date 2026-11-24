// Izinkinobho ezimbili: eyokuqala ikhanyisa i-LED, eyesibili iyayicisha.
// Ukuxhuma: inkinobho A -> 9 no-GND, inkinobho B -> 8 no-GND, i-LED -> 5 (220 ohm)
#include <isiNdebele.h>

okungatjhugulukiko inomboro INKINOBHO_A = 9;
okungatjhugulukiko inomboro INKINOBHO_B = 8;
okungatjhugulukiko inomboro ILED = 5;

ilize thoma() {
    beka_iphini(INKINOBHO_A, OKUNGENAKO_KUDONSIWE);
    beka_iphini(INKINOBHO_B, OKUNGENAKO_KUDONSIWE);
    beka_iphini(ILED, OKUPHUMAKO);
}

ilize phinda_phinda() {
    nangabe (funda_idijithali(INKINOBHO_A) == PHASI) tlola_idijithali(ILED, PHEZULU);
    nangabe (funda_idijithali(INKINOBHO_B) == PHASI) tlola_idijithali(ILED, PHASI);
}
