// I-MAX7219 8x8: ibonisa ubuso obumamathekayo nenhliziyo.
// Ukuxhuma: DIN -> 12, CS -> 10, CLK -> 11, VCC -> 5V, GND -> GND
// Dinga umtapo: "LedControl" (Tools -> Manage Libraries)
#include <LedControl.h>
#include <siSwati.h>

Silawuli_semaLED amaled(12, 11, 10, 1);   // DIN, CLK, CS, inani lamamojula

libhayithi ubuso[8] = {0x3C, 0x42, 0xA5, 0x81, 0xA5, 0x99, 0x42, 0x3C};
libhayithi inhliziyo[8] = {0x00, 0x66, 0xFF, 0xFF, 0xFF, 0x7E, 0x3C, 0x18};

lite dweba(libhayithi isithombe[8]) {
    jikeleta (inombolo umugqa_wamaled = 0; umugqa_wamaled < 8; umugqa_wamaled++) amaled.setha_lulayini(0, umugqa_wamaled, isithombe[umugqa_wamaled]);
}

lite cala() {
    amaled.lalisa(0, emanga);         // vusa imojula
    amaled.setha_kukhanya(0, 8);     // ukukhanya 0-15
    amaled.sula_sibonisi(0);
}

lite phindza_phindza() {
    dweba(ubuso);
    lindza(1000);
    dweba(inhliziyo);
    lindza(1000);
}
