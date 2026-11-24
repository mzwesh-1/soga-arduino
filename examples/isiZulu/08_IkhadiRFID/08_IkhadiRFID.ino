// RC522 RFID: ifunda inombolo yekhadi elimhlophe noma ye-key fob eluhlaza.
// Ukuxhuma ku-Mega: SDA -> 53, SCK -> 52, MOSI -> 51, MISO -> 50, RST -> 5, 3.3V -> 3.3V (HHAYI 5V!), GND -> GND
// Dinga umtapo: "MFRC522" (Tools -> Manage Libraries)
#include <SPI.h>
#include <MFRC522.h>
#include <isiZulu.h>

MFRC522 isifundi(53, 5);

ize qala() {
    Isiriyeli.ukuqala(9600);
    Ibhasi_spi.ukuqala();
    isifundi.qalisa_isifundi();
    Isiriyeli.bonisa_umugqa("Sondeza ikhadi esifundini...");
}

ize phindaphinda() {
    uma (!isifundi.likhona_ikhadi_elisha() || !isifundi.funda_inombolo_yekhadi()) buyisa;
    Isiriyeli.bonisa("Inombolo yekhadi:");
    jikeleza (ibhayithi i = 0; i < isifundi.isazisi.ubukhulu; i++) {
        Isiriyeli.bonisa(isifundi.isazisi.amabhayithi_esazisi[i] < 0x10 ? " 0" : " ");
        Isiriyeli.bonisa(isifundi.isazisi.amabhayithi_esazisi[i], NGEHEKSA);
    }
    Isiriyeli.bonisa_umugqa();
    isifundi.misa_ikhadi();
}
