// RC522 RFID: ifunda inombolo yekhadi elimhlophe noma ye-key fob eluhlaza.
// Ukuxhuma ku-Mega: SDA -> 53, SCK -> 52, MOSI -> 51, MISO -> 50, RST -> 5, 3.3V -> 3.3V (HHAYI 5V!), GND -> GND
// Dinga umtapo: "MFRC522" (Tools -> Manage Libraries)
#include <SPI.h>
#include <MFRC522.h>
#include <Sesotho.h>

MFRC522 isifundi(53, 5);

lefeela qala() {
    Seriale.qalo(9600);
    Bese_ya_spi.qalo();
    isifundi.qala_sebadi();
    Seriale.bontsha_mola("Sondeza ikhadi esifundini...");
}

lefeela pheta_pheta() {
    haeba (!isifundi.karete_e_ntjha_e_teng() || !isifundi.bala_nomoro_ya_karete()) kgutlisa;
    Seriale.bontsha("Inombolo yekhadi:");
    bakeng_sa (baete i = 0; i < isifundi.boitsebiso.boholo; i++) {
        Seriale.bontsha(isifundi.boitsebiso.dibaete_tsa_boitsebiso[i] < 0x10 ? " 0" : " ");
        Seriale.bontsha(isifundi.boitsebiso.dibaete_tsa_boitsebiso[i], KA_HEKSA);
    }
    Seriale.bontsha_mola();
    isifundi.emisa_karete();
}
