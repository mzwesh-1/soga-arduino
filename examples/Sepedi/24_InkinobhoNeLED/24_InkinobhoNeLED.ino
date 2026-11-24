// Izinkinobho ezimbili: eyokuqala ikhanyisa i-LED, eyesibili iyayicisha.
// Ukuxhuma: inkinobho A -> 9 no-GND, inkinobho B -> 8 no-GND, i-LED -> 5 (220 ohm)
#include <Sepedi.h>

sa_fetogego palo INKINOBHO_A = 9;
sa_fetogego palo INKINOBHO_B = 8;
sa_fetogego palo ILED = 5;

lefeela thoma() {
    bea_phini(INKINOBHO_A, TSE_TSENAGO_GO_GOGA);
    bea_phini(INKINOBHO_B, TSE_TSENAGO_GO_GOGA);
    bea_phini(ILED, TSE_TSWAGO);
}

lefeela boeletsa() {
    ge (bala_dijithale(INKINOBHO_A) == FASE) ngwala_dijithale(ILED, GODIMO);
    ge (bala_dijithale(INKINOBHO_B) == FASE) ngwala_dijithale(ILED, FASE);
}
