// I-MAX7219 8x8: ibonisa ubuso obumamathekayo nenhliziyo.
// Ukuxhuma: DIN -> 12, CS -> 10, CLK -> 11, VCC -> 5V, GND -> GND
// Dinga umtapo: "LedControl" (Tools -> Manage Libraries)
#include <LedControl.h>
#include <isiZulu.h>

Isilawuli_samaLED amaled(12, 11, 10, 1);   // DIN, CLK, CS, inani lamamojula

ibhayithi ubuso[8] = {0x3C, 0x42, 0xA5, 0x81, 0xA5, 0x99, 0x42, 0x3C};
ibhayithi inhliziyo[8] = {0x00, 0x66, 0xFF, 0xFF, 0xFF, 0x7E, 0x3C, 0x18};

ize dweba(ibhayithi isithombe[8]) {
    jikeleza (inombolo umugqa_wamaled = 0; umugqa_wamaled < 8; umugqa_wamaled++) amaled.setha_umugqa(0, umugqa_wamaled, isithombe[umugqa_wamaled]);
}

ize qala() {
    amaled.lalisa(0, amanga);         // vusa imojula
    amaled.setha_ukukhanya(0, 8);     // ukukhanya 0-15
    amaled.sula_isibonisi(0);
}

ize phindaphinda() {
    dweba(ubuso);
    linda(1000);
    dweba(inhliziyo);
    linda(1000);
}
