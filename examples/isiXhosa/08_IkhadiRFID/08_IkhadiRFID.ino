// RC522 RFID: ifunda inombolo yekhadi elimhlophe noma ye-key fob eluhlaza.
// Ukuxhuma ku-Mega: SDA -> 53, SCK -> 52, MOSI -> 51, MISO -> 50, RST -> 5, 3.3V -> 3.3V (HHAYI 5V!), GND -> GND
// Dinga umtapo: "MFRC522" (Tools -> Manage Libraries)
#include <SPI.h>
#include <MFRC522.h>
#include <isiXhosa.h>

MFRC522 isifundi(53, 5);

ize qalisa() {
    Isiriyali.ukuqala(9600);
    Ibhasi_spi.ukuqala();
    isifundi.qalisa_isifundi();
    Isiriyali.bonisa_umgca("Sondeza ikhadi esifundini...");
}

ize phinda_phinda() {
    ukuba (!isifundi.ikho_ikhadi_elitsha() || !isifundi.funda_inombolo_yekhadi()) buyisa;
    Isiriyali.bonisa("Inombolo yekhadi:");
    jikeleza (ibhayithi i = 0; i < isifundi.isazisi.ubungakanani; i++) {
        Isiriyali.bonisa(isifundi.isazisi.iibhayithi_zesazisi[i] < 0x10 ? " 0" : " ");
        Isiriyali.bonisa(isifundi.isazisi.iibhayithi_zesazisi[i], NGEHEKSA);
    }
    Isiriyali.bonisa_umgca();
    isifundi.misa_ikhadi();
}
