// I-photoresistor (LDR): lapho kumnyama, i-LED ikhanya kakhulu.
// Ukuxhuma: LDR phakathi kuka-5V no-A0, 10k ohm phakathi kuka-A0 no-GND; i-LED -> 9 (220 ohm)
#include <isiXhosa.h>

engatshintshiyo inani ILED = 9;

ize qalisa() {
    misela_iphini(ILED, OKUPHUMAYO);
    Isiriyali.ukuqala(9600);
}

ize phinda_phinda() {
    inani ukukhanya = funda_ianalogu(A0);                       // 0 (kumnyama) - 1023 (kukhanya)
    inani amandla_eled = linganisa_kwakhona(ukukhanya, 0, 1023, 255, 0);
    bhala_ianalogu(ILED, thintela(amandla_eled, 0, 255));
    Isiriyali.bonisa("Ukukhanya: ");
    Isiriyali.bonisa_umgca(ukukhanya);
    linda(100);
}
