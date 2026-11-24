// I-MAX7219 8x8: ibonisa ubuso obumamathekayo nenhliziyo.
// Ukuxhuma: DIN -> 12, CS -> 10, CLK -> 11, VCC -> 5V, GND -> GND
// Dinga umtapo: "LedControl" (Tools -> Manage Libraries)
#include <LedControl.h>
#include <Xitsonga.h>

Mufambisi_wa_tiLED amaled(12, 11, 10, 1);   // DIN, CLK, CS, inani lamamojula

bayiti ubuso[8] = {0x3C, 0x42, 0xA5, 0x81, 0xA5, 0x99, 0x42, 0x3C};
bayiti inhliziyo[8] = {0x00, 0x66, 0xFF, 0xFF, 0xFF, 0x7E, 0x3C, 0x18};

swi_hava dweba(bayiti isithombe[8]) {
    rhendzeleka (nomboro umugqa_wamaled = 0; umugqa_wamaled < 8; umugqa_wamaled++) amaled.veka_layini(0, umugqa_wamaled, isithombe[umugqa_wamaled]);
}

swi_hava sungula() {
    amaled.etlerisa(0, mavunwa);         // vusa imojula
    amaled.veka_ku_vonakala(0, 8);     // ukukhanya 0-15
    amaled.sula_xikombisi(0);
}

swi_hava phindha_phindha() {
    dweba(ubuso);
    rindza(1000);
    dweba(inhliziyo);
    rindza(1000);
}
