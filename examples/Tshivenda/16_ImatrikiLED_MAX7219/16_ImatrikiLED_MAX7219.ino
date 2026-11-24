// I-MAX7219 8x8: ibonisa ubuso obumamathekayo nenhliziyo.
// Ukuxhuma: DIN -> 12, CS -> 10, CLK -> 11, VCC -> 5V, GND -> GND
// Dinga umtapo: "LedControl" (Tools -> Manage Libraries)
#include <LedControl.h>
#include <Tshivenda.h>

Mulanguli_wa_dziLED amaled(12, 11, 10, 1);   // DIN, CLK, CS, inani lamamojula

baithi ubuso[8] = {0x3C, 0x42, 0xA5, 0x81, 0xA5, 0x99, 0x42, 0x3C};
baithi inhliziyo[8] = {0x00, 0x66, 0xFF, 0xFF, 0xFF, 0x7E, 0x3C, 0x18};

a_huna dweba(baithi isithombe[8]) {
    mona (nomboro umugqa_wamaled = 0; umugqa_wamaled < 8; umugqa_wamaled++) amaled.vhea_mutsetse(0, umugqa_wamaled, isithombe[umugqa_wamaled]);
}

a_huna thoma() {
    amaled.edzisa(0, mazwifhi);         // vusa imojula
    amaled.vhea_tshedza(0, 8);     // ukukhanya 0-15
    amaled.phumula_tshisumbedzi(0);
}

a_huna dovholola() {
    dweba(ubuso);
    lindela(1000);
    dweba(inhliziyo);
    lindela(1000);
}
