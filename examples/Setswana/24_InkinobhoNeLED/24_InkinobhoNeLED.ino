// Izinkinobho ezimbili: eyokuqala ikhanyisa i-LED, eyesibili iyayicisha.
// Ukuxhuma: inkinobho A -> 9 no-GND, inkinobho B -> 8 no-GND, i-LED -> 5 (220 ohm)
#include <Setswana.h>

e_sa_fetogeng palo INKINOBHO_A = 9;
e_sa_fetogeng palo INKINOBHO_B = 8;
e_sa_fetogeng palo ILED = 5;

lefela simolola() {
    baya_phini(INKINOBHO_A, TSE_DI_TSENANG_GO_GOGA);
    baya_phini(INKINOBHO_B, TSE_DI_TSENANG_GO_GOGA);
    baya_phini(ILED, TSE_DI_TSWANG);
}

lefela boeletsa() {
    fa (bala_dijithale(INKINOBHO_A) == TLASE) kwala_dijithale(ILED, GODIMO);
    fa (bala_dijithale(INKINOBHO_B) == TLASE) kwala_dijithale(ILED, TLASE);
}
