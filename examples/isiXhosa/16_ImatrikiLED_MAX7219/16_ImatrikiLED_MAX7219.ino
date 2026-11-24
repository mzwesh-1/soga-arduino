// I-MAX7219 8x8: ibonisa ubuso obumamathekayo nenhliziyo.
// Ukuxhuma: DIN -> 12, CS -> 10, CLK -> 11, VCC -> 5V, GND -> GND
// Dinga umtapo: "LedControl" (Tools -> Manage Libraries)
#include <LedControl.h>
#include <isiXhosa.h>

Isilawuli_seeLED amaled(12, 11, 10, 1);   // DIN, CLK, CS, inani lamamojula

ibhayithi ubuso[8] = {0x3C, 0x42, 0xA5, 0x81, 0xA5, 0x99, 0x42, 0x3C};
ibhayithi inhliziyo[8] = {0x00, 0x66, 0xFF, 0xFF, 0xFF, 0x7E, 0x3C, 0x18};

ize dweba(ibhayithi isithombe[8]) {
    jikeleza (inani umugqa_wamaled = 0; umugqa_wamaled < 8; umugqa_wamaled++) amaled.misela_umqolo(0, umugqa_wamaled, isithombe[umugqa_wamaled]);
}

ize qalisa() {
    amaled.lalisa(0, ubuxoki);         // vusa imojula
    amaled.misela_ukukhanya(0, 8);     // ukukhanya 0-15
    amaled.cima_isiboniso(0);
}

ize phinda_phinda() {
    dweba(ubuso);
    linda(1000);
    dweba(inhliziyo);
    linda(1000);
}
