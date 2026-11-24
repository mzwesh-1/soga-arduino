// Izinkinobho ezimbili: eyokuqala ikhanyisa i-LED, eyesibili iyayicisha.
// Ukuxhuma: inkinobho A -> 9 no-GND, inkinobho B -> 8 no-GND, i-LED -> 5 (220 ohm)
#include <isiZulu.h>

engaguquki inombolo INKINOBHO_A = 9;
engaguquki inombolo INKINOBHO_B = 8;
engaguquki inombolo ILED = 5;

ize qala() {
    setha_iphini(INKINOBHO_A, OKUNGENAYO_KUDONSELWE);
    setha_iphini(INKINOBHO_B, OKUNGENAYO_KUDONSELWE);
    setha_iphini(ILED, OKUPHUMAYO);
}

ize phindaphinda() {
    uma (funda_idijithali(INKINOBHO_A) == PHANSI) bhala_idijithali(ILED, PHEZULU);
    uma (funda_idijithali(INKINOBHO_B) == PHANSI) bhala_idijithali(ILED, PHANSI);
}
