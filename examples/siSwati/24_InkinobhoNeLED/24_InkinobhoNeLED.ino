// Izinkinobho ezimbili: eyokuqala ikhanyisa i-LED, eyesibili iyayicisha.
// Ukuxhuma: inkinobho A -> 9 no-GND, inkinobho B -> 8 no-GND, i-LED -> 5 (220 ohm)
#include <siSwati.h>

lokungagucuki inombolo INKINOBHO_A = 9;
lokungagucuki inombolo INKINOBHO_B = 8;
lokungagucuki inombolo ILED = 5;

lite cala() {
    setha_liphini(INKINOBHO_A, LOKUNGENAKO_KUDONSIWE);
    setha_liphini(INKINOBHO_B, LOKUNGENAKO_KUDONSIWE);
    setha_liphini(ILED, LOKUPHUMAKO);
}

lite phindza_phindza() {
    nangabe (fundza_idijithali(INKINOBHO_A) == PHANSI) bhala_idijithali(ILED, PHETULU);
    nangabe (fundza_idijithali(INKINOBHO_B) == PHANSI) bhala_idijithali(ILED, PHANSI);
}
