// I-MAX7219 8x8: ibonisa ubuso obumamathekayo nenhliziyo.
// Ukuxhuma: DIN -> 12, CS -> 10, CLK -> 11, VCC -> 5V, GND -> GND
// Dinga umtapo: "LedControl" (Tools -> Manage Libraries)
#include <LedControl.h>
#include <Sesotho.h>

Molaodi_wa_diLED amaled(12, 11, 10, 1);   // DIN, CLK, CS, inani lamamojula

baete ubuso[8] = {0x3C, 0x42, 0xA5, 0x81, 0xA5, 0x99, 0x42, 0x3C};
baete inhliziyo[8] = {0x00, 0x66, 0xFF, 0xFF, 0xFF, 0x7E, 0x3C, 0x18};

lefeela dweba(baete isithombe[8]) {
    bakeng_sa (palo umugqa_wamaled = 0; umugqa_wamaled < 8; umugqa_wamaled++) amaled.beha_mola(0, umugqa_wamaled, isithombe[umugqa_wamaled]);
}

lefeela qala() {
    amaled.robatsa(0, leshano);         // vusa imojula
    amaled.beha_kganya(0, 8);     // ukukhanya 0-15
    amaled.hlakola_pontsho(0);
}

lefeela pheta_pheta() {
    dweba(ubuso);
    ema(1000);
    dweba(inhliziyo);
    ema(1000);
}
