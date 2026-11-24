// I-MAX7219 8x8: ibonisa ubuso obumamathekayo nenhliziyo.
// Ukuxhuma: DIN -> 12, CS -> 10, CLK -> 11, VCC -> 5V, GND -> GND
// Dinga umtapo: "LedControl" (Tools -> Manage Libraries)
#include <LedControl.h>
#include <Afrikaans.h>

LedBeheer amaled(12, 11, 10, 1);   // DIN, CLK, CS, inani lamamojula

greep ubuso[8] = {0x3C, 0x42, 0xA5, 0x81, 0xA5, 0x99, 0x42, 0x3C};
greep inhliziyo[8] = {0x00, 0x66, 0xFF, 0xFF, 0xFF, 0x7E, 0x3C, 0x18};

leeg dweba(greep isithombe[8]) {
    vir (heelgetal umugqa_wamaled = 0; umugqa_wamaled < 8; umugqa_wamaled++) amaled.stel_ry(0, umugqa_wamaled, isithombe[umugqa_wamaled]);
}

leeg opstel() {
    amaled.slaap(0, vals);         // vusa imojula
    amaled.stel_helderheid(0, 8);     // ukukhanya 0-15
    amaled.vee_skerm(0);
}

leeg lus() {
    dweba(ubuso);
    wag(1000);
    dweba(inhliziyo);
    wag(1000);
}
