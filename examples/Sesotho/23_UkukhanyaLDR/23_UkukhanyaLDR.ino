// I-photoresistor (LDR): lapho kumnyama, i-LED ikhanya kakhulu.
// Ukuxhuma: LDR phakathi kuka-5V no-A0, 10k ohm phakathi kuka-A0 no-GND; i-LED -> 9 (220 ohm)
#include <Sesotho.h>

e_sa_fetoheng palo ILED = 9;

lefeela qala() {
    beha_phini(ILED, TSE_TSWANG);
    Seriale.qalo(9600);
}

lefeela pheta_pheta() {
    palo ukukhanya = bala_analoko(A0);                       // 0 (kumnyama) - 1023 (kukhanya)
    palo amandla_eled = lekanya_botjha(ukukhanya, 0, 1023, 255, 0);
    ngola_analoko(ILED, thibela(amandla_eled, 0, 255));
    Seriale.bontsha("Ukukhanya: ");
    Seriale.bontsha_mola(ukukhanya);
    ema(100);
}
