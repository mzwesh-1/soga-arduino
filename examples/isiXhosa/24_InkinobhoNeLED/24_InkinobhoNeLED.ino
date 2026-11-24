// Izinkinobho ezimbili: eyokuqala ikhanyisa i-LED, eyesibili iyayicisha.
// Ukuxhuma: inkinobho A -> 9 no-GND, inkinobho B -> 8 no-GND, i-LED -> 5 (220 ohm)
#include <isiXhosa.h>

engatshintshiyo inani INKINOBHO_A = 9;
engatshintshiyo inani INKINOBHO_B = 8;
engatshintshiyo inani ILED = 5;

ize qalisa() {
    misela_iphini(INKINOBHO_A, OKUNGENAYO_KUTSALWE);
    misela_iphini(INKINOBHO_B, OKUNGENAYO_KUTSALWE);
    misela_iphini(ILED, OKUPHUMAYO);
}

ize phinda_phinda() {
    ukuba (funda_idijithali(INKINOBHO_A) == EZANTSI) bhala_idijithali(ILED, PHEZULU);
    ukuba (funda_idijithali(INKINOBHO_B) == EZANTSI) bhala_idijithali(ILED, EZANTSI);
}
