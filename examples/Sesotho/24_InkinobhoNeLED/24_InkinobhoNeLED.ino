// Izinkinobho ezimbili: eyokuqala ikhanyisa i-LED, eyesibili iyayicisha.
// Ukuxhuma: inkinobho A -> 9 no-GND, inkinobho B -> 8 no-GND, i-LED -> 5 (220 ohm)
#include <Sesotho.h>

e_sa_fetoheng palo INKINOBHO_A = 9;
e_sa_fetoheng palo INKINOBHO_B = 8;
e_sa_fetoheng palo ILED = 5;

lefeela qala() {
    beha_phini(INKINOBHO_A, TSE_KENANG_HO_HULA);
    beha_phini(INKINOBHO_B, TSE_KENANG_HO_HULA);
    beha_phini(ILED, TSE_TSWANG);
}

lefeela pheta_pheta() {
    haeba (bala_dijithale(INKINOBHO_A) == TLASE) ngola_dijithale(ILED, HODIMO);
    haeba (bala_dijithale(INKINOBHO_B) == TLASE) ngola_dijithale(ILED, TLASE);
}
