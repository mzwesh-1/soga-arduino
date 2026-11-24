// I-photoresistor (LDR): lapho kumnyama, i-LED ikhanya kakhulu.
// Ukuxhuma: LDR phakathi kuka-5V no-A0, 10k ohm phakathi kuka-A0 no-GND; i-LED -> 9 (220 ohm)
#include <Afrikaans.h>

konstant heelgetal ILED = 9;

leeg opstel() {
    penmodus(ILED, UITSET);
    Seriaal.begin(9600);
}

leeg lus() {
    heelgetal ukukhanya = leesanaloog(A0);                       // 0 (kumnyama) - 1023 (kukhanya)
    heelgetal amandla_eled = herskaal(ukukhanya, 0, 1023, 255, 0);
    skryfanaloog(ILED, beperk(amandla_eled, 0, 255));
    Seriaal.druk("Ukukhanya: ");
    Seriaal.drukreel(ukukhanya);
    wag(100);
}
