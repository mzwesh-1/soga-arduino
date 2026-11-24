// RC522 RFID: ifunda inombolo yekhadi elimhlophe noma ye-key fob eluhlaza.
// Ukuxhuma ku-Mega: SDA -> 53, SCK -> 52, MOSI -> 51, MISO -> 50, RST -> 5, 3.3V -> 3.3V (HHAYI 5V!), GND -> GND
// Dinga umtapo: "MFRC522" (Tools -> Manage Libraries)
#include <SPI.h>
#include <MFRC522.h>
#include <siSwati.h>

MFRC522 isifundi(53, 5);

lite cala() {
    Siriyali.kucala(9600);
    Libhasi_spi.kucala();
    isifundi.calisa_sifundzi();
    Siriyali.khombisa_umugca("Sondeza ikhadi esifundini...");
}

lite phindza_phindza() {
    nangabe (!isifundi.likhona_likhadi_lelisha() || !isifundi.fundza_inombolo_yelikhadi()) buyisa;
    Siriyali.khombisa("Inombolo yekhadi:");
    jikeleta (libhayithi i = 0; i < isifundi.sazisi.bukhulu; i++) {
        Siriyali.khombisa(isifundi.sazisi.emabhayithi_esazisi[i] < 0x10 ? " 0" : " ");
        Siriyali.khombisa(isifundi.sazisi.emabhayithi_esazisi[i], NGEHEKSA);
    }
    Siriyali.khombisa_umugca();
    isifundi.misa_likhadi();
}
