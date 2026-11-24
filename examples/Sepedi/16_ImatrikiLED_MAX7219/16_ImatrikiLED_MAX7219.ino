// I-MAX7219 8x8: ibonisa ubuso obumamathekayo nenhliziyo.
// Ukuxhuma: DIN -> 12, CS -> 10, CLK -> 11, VCC -> 5V, GND -> GND
// Dinga umtapo: "LedControl" (Tools -> Manage Libraries)
#include <LedControl.h>
#include <Sepedi.h>

Molaodi_wa_diLED amaled(12, 11, 10, 1);   // DIN, CLK, CS, inani lamamojula

paete ubuso[8] = {0x3C, 0x42, 0xA5, 0x81, 0xA5, 0x99, 0x42, 0x3C};
paete inhliziyo[8] = {0x00, 0x66, 0xFF, 0xFF, 0xFF, 0x7E, 0x3C, 0x18};

lefeela dweba(paete isithombe[8]) {
    dikologa (palo umugqa_wamaled = 0; umugqa_wamaled < 8; umugqa_wamaled++) amaled.bea_mothaladi(0, umugqa_wamaled, isithombe[umugqa_wamaled]);
}

lefeela thoma() {
    amaled.robatsa(0, maaka);         // vusa imojula
    amaled.bea_seetsa(0, 8);     // ukukhanya 0-15
    amaled.phumola_pontsho(0);
}

lefeela boeletsa() {
    dweba(ubuso);
    leta(1000);
    dweba(inhliziyo);
    leta(1000);
}
