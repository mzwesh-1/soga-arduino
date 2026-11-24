// I-photoresistor (LDR): lapho kumnyama, i-LED ikhanya kakhulu.
// Ukuxhuma: LDR phakathi kuka-5V no-A0, 10k ohm phakathi kuka-A0 no-GND; i-LED -> 9 (220 ohm)
#include <isiZulu.h>

engaguquki inombolo ILED = 9;

ize qala() {
    setha_iphini(ILED, OKUPHUMAYO);
    Isiriyeli.ukuqala(9600);
}

ize phindaphinda() {
    inombolo ukukhanya = funda_ianalogi(A0);                       // 0 (kumnyama) - 1023 (kukhanya)
    inombolo amandla_eled = linganisa_kabusha(ukukhanya, 0, 1023, 255, 0);
    bhala_ianalogi(ILED, vimbela(amandla_eled, 0, 255));
    Isiriyeli.bonisa("Ukukhanya: ");
    Isiriyeli.bonisa_umugqa(ukukhanya);
    linda(100);
}
