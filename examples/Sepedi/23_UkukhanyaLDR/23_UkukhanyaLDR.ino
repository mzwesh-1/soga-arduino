// I-photoresistor (LDR): lapho kumnyama, i-LED ikhanya kakhulu.
// Ukuxhuma: LDR phakathi kuka-5V no-A0, 10k ohm phakathi kuka-A0 no-GND; i-LED -> 9 (220 ohm)
#include <Sepedi.h>

sa_fetogego palo ILED = 9;

lefeela thoma() {
    bea_phini(ILED, TSE_TSWAGO);
    Seriale.mathomo(9600);
}

lefeela boeletsa() {
    palo ukukhanya = bala_analoko(A0);                       // 0 (kumnyama) - 1023 (kukhanya)
    palo amandla_eled = lekanya_lefsa(ukukhanya, 0, 1023, 255, 0);
    ngwala_analoko(ILED, thibela(amandla_eled, 0, 255));
    Seriale.bontsha("Ukukhanya: ");
    Seriale.bontsha_mothaladi(ukukhanya);
    leta(100);
}
