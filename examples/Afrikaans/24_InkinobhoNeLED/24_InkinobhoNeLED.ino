// Izinkinobho ezimbili: eyokuqala ikhanyisa i-LED, eyesibili iyayicisha.
// Ukuxhuma: inkinobho A -> 9 no-GND, inkinobho B -> 8 no-GND, i-LED -> 5 (220 ohm)
#include <Afrikaans.h>

konstant heelgetal INKINOBHO_A = 9;
konstant heelgetal INKINOBHO_B = 8;
konstant heelgetal ILED = 5;

leeg opstel() {
    penmodus(INKINOBHO_A, INSET_OPTREK);
    penmodus(INKINOBHO_B, INSET_OPTREK);
    penmodus(ILED, UITSET);
}

leeg lus() {
    as (leesdigitaal(INKINOBHO_A) == LAAG) skryfdigitaal(ILED, HOOG);
    as (leesdigitaal(INKINOBHO_B) == LAAG) skryfdigitaal(ILED, LAAG);
}
