// I-photoresistor (LDR): lapho kumnyama, i-LED ikhanya kakhulu.
// Ukuxhuma: LDR phakathi kuka-5V no-A0, 10k ohm phakathi kuka-A0 no-GND; i-LED -> 9 (220 ohm)
#include <siSwati.h>

lokungagucuki inombolo ILED = 9;

lite cala() {
    setha_liphini(ILED, LOKUPHUMAKO);
    Siriyali.kucala(9600);
}

lite phindza_phindza() {
    inombolo ukukhanya = fundza_ianalogi(A0);                       // 0 (kumnyama) - 1023 (kukhanya)
    inombolo amandla_eled = linganisa_kabusha(ukukhanya, 0, 1023, 255, 0);
    bhala_ianalogi(ILED, vimbela(amandla_eled, 0, 255));
    Siriyali.khombisa("Ukukhanya: ");
    Siriyali.khombisa_umugca(ukukhanya);
    lindza(100);
}
