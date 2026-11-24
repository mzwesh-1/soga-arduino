// RC522 RFID: ifunda inombolo yekhadi elimhlophe noma ye-key fob eluhlaza.
// Ukuxhuma ku-Mega: SDA -> 53, SCK -> 52, MOSI -> 51, MISO -> 50, RST -> 5, 3.3V -> 3.3V (HHAYI 5V!), GND -> GND
// Dinga umtapo: "MFRC522" (Tools -> Manage Libraries)
#include <SPI.h>
#include <MFRC522.h>
#include <Xitsonga.h>

MFRC522 isifundi(53, 5);

swi_hava sungula() {
    Siriyali.ku_sungula(9600);
    Bazi_ya_spi.ku_sungula();
    isifundi.sungula_muhlayi();
    Siriyali.kombisa_layini("Sondeza ikhadi esifundini...");
}

swi_hava phindha_phindha() {
    loko (!isifundi.karhi_leyintshwa_yi_kona() || !isifundi.hlaya_nomboro_ya_karhi()) vuyisa;
    Siriyali.kombisa("Inombolo yekhadi:");
    rhendzeleka (bayiti i = 0; i < isifundi.vutitivisi.vukulu; i++) {
        Siriyali.kombisa(isifundi.vutitivisi.tibayiti_ta_vutitivisi[i] < 0x10 ? " 0" : " ");
        Siriyali.kombisa(isifundi.vutitivisi.tibayiti_ta_vutitivisi[i], HI_HEKSA);
    }
    Siriyali.kombisa_layini();
    isifundi.yimisa_karhi();
}
