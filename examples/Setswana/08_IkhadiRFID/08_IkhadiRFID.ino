// RC522 RFID: ifunda inombolo yekhadi elimhlophe noma ye-key fob eluhlaza.
// Ukuxhuma ku-Mega: SDA -> 53, SCK -> 52, MOSI -> 51, MISO -> 50, RST -> 5, 3.3V -> 3.3V (HHAYI 5V!), GND -> GND
// Dinga umtapo: "MFRC522" (Tools -> Manage Libraries)
#include <SPI.h>
#include <MFRC522.h>
#include <Setswana.h>

MFRC522 isifundi(53, 5);

lefela simolola() {
    Seriale.tshimologo(9600);
    Bese_ya_spi.tshimologo();
    isifundi.simolola_sebadi();
    Seriale.bontsha_mola("Sondeza ikhadi esifundini...");
}

lefela boeletsa() {
    fa (!isifundi.karata_e_ntsha_e_teng() || !isifundi.bala_nomore_ya_karata()) busa;
    Seriale.bontsha("Inombolo yekhadi:");
    dikologa (baete i = 0; i < isifundi.boitshupo.bogolo; i++) {
        Seriale.bontsha(isifundi.boitshupo.dibaete_tsa_boitshupo[i] < 0x10 ? " 0" : " ");
        Seriale.bontsha(isifundi.boitshupo.dibaete_tsa_boitshupo[i], KA_HEKSA);
    }
    Seriale.bontsha_mola();
    isifundi.emisa_karata();
}
