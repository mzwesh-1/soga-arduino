// I-photoresistor (LDR): lapho kumnyama, i-LED ikhanya kakhulu.
// Ukuxhuma: LDR phakathi kuka-5V no-A0, 10k ohm phakathi kuka-A0 no-GND; i-LED -> 9 (220 ohm)
#include <isiNdebele.h>

okungatjhugulukiko inomboro ILED = 9;

ilize thoma() {
    beka_iphini(ILED, OKUPHUMAKO);
    Isiriyali.ukuthoma(9600);
}

ilize phinda_phinda() {
    inomboro ukukhanya = funda_ianalogi(A0);                       // 0 (kumnyama) - 1023 (kukhanya)
    inomboro amandla_eled = linganisa_butjha(ukukhanya, 0, 1023, 255, 0);
    tlola_ianalogi(ILED, vimbela(amandla_eled, 0, 255));
    Isiriyali.khombisa("Ukukhanya: ");
    Isiriyali.khombisa_umugqa(ukukhanya);
    lindela(100);
}
