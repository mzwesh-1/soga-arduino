// RC522 RFID: ifunda inombolo yekhadi elimhlophe noma ye-key fob eluhlaza.
// Ukuxhuma ku-Mega: SDA -> 53, SCK -> 52, MOSI -> 51, MISO -> 50, RST -> 5, 3.3V -> 3.3V (HHAYI 5V!), GND -> GND
// Dinga umtapo: "MFRC522" (Tools -> Manage Libraries)
#include <SPI.h>
#include <MFRC522.h>
#include <Sepedi.h>

MFRC522 isifundi(53, 5);

lefeela thoma() {
    Seriale.mathomo(9600);
    Bese_ya_spi.mathomo();
    isifundi.thoma_sebadi();
    Seriale.bontsha_mothaladi("Sondeza ikhadi esifundini...");
}

lefeela boeletsa() {
    ge (!isifundi.karata_ye_mpsha_e_gona() || !isifundi.bala_nomoro_ya_karata()) busetsa;
    Seriale.bontsha("Inombolo yekhadi:");
    dikologa (paete i = 0; i < isifundi.boitsebiso.bogolo; i++) {
        Seriale.bontsha(isifundi.boitsebiso.dipaete_tsa_boitsebiso[i] < 0x10 ? " 0" : " ");
        Seriale.bontsha(isifundi.boitsebiso.dipaete_tsa_boitsebiso[i], KA_HEKSA);
    }
    Seriale.bontsha_mothaladi();
    isifundi.emisa_karata();
}
