// RC522 RFID: ifunda inombolo yekhadi elimhlophe noma ye-key fob eluhlaza.
// Ukuxhuma ku-Mega: SDA -> 53, SCK -> 52, MOSI -> 51, MISO -> 50, RST -> 5, 3.3V -> 3.3V (HHAYI 5V!), GND -> GND
// Dinga umtapo: "MFRC522" (Tools -> Manage Libraries)
#include <SPI.h>
#include <MFRC522.h>
#include <Afrikaans.h>

MFRC522 isifundi(53, 5);

leeg opstel() {
    Seriaal.begin(9600);
    Spi_bus.begin();
    isifundi.begin_leser();
    Seriaal.drukreel("Sondeza ikhadi esifundini...");
}

leeg lus() {
    as (!isifundi.nuwe_kaart_daar() || !isifundi.lees_kaartnommer()) terug;
    Seriaal.druk("Inombolo yekhadi:");
    vir (greep i = 0; i < isifundi.kaart_id.grootte; i++) {
        Seriaal.druk(isifundi.kaart_id.id_grepe[i] < 0x10 ? " 0" : " ");
        Seriaal.druk(isifundi.kaart_id.id_grepe[i], HEKSADESIMAAL);
    }
    Seriaal.drukreel();
    isifundi.stop_kaart();
}
