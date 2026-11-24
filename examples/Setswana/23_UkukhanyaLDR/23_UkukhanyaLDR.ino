// I-photoresistor (LDR): lapho kumnyama, i-LED ikhanya kakhulu.
// Ukuxhuma: LDR phakathi kuka-5V no-A0, 10k ohm phakathi kuka-A0 no-GND; i-LED -> 9 (220 ohm)
#include <Setswana.h>

e_sa_fetogeng palo ILED = 9;

lefela simolola() {
    baya_phini(ILED, TSE_DI_TSWANG);
    Seriale.tshimologo(9600);
}

lefela boeletsa() {
    palo ukukhanya = bala_analoko(A0);                       // 0 (kumnyama) - 1023 (kukhanya)
    palo amandla_eled = lekanya_gape(ukukhanya, 0, 1023, 255, 0);
    kwala_analoko(ILED, thibela(amandla_eled, 0, 255));
    Seriale.bontsha("Ukukhanya: ");
    Seriale.bontsha_mola(ukukhanya);
    ema(100);
}
