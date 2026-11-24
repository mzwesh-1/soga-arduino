// I-photoresistor (LDR): lapho kumnyama, i-LED ikhanya kakhulu.
// Ukuxhuma: LDR phakathi kuka-5V no-A0, 10k ohm phakathi kuka-A0 no-GND; i-LED -> 9 (220 ohm)
#include <Xitsonga.h>

lexi_nga_cinciki nomboro ILED = 9;

swi_hava sungula() {
    veka_phini(ILED, LESWI_HUMAKA);
    Siriyali.ku_sungula(9600);
}

swi_hava phindha_phindha() {
    nomboro ukukhanya = hlaya_analogo(A0);                       // 0 (kumnyama) - 1023 (kukhanya)
    nomboro amandla_eled = ringanisa_nakambe(ukukhanya, 0, 1023, 255, 0);
    tsala_analogo(ILED, sivela(amandla_eled, 0, 255));
    Siriyali.kombisa("Ukukhanya: ");
    Siriyali.kombisa_layini(ukukhanya);
    rindza(100);
}
