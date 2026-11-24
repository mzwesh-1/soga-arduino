// RC522 RFID: ifunda inombolo yekhadi elimhlophe noma ye-key fob eluhlaza.
// Ukuxhuma ku-Mega: SDA -> 53, SCK -> 52, MOSI -> 51, MISO -> 50, RST -> 5, 3.3V -> 3.3V (HHAYI 5V!), GND -> GND
// Dinga umtapo: "MFRC522" (Tools -> Manage Libraries)
#include <SPI.h>
#include <MFRC522.h>
#include <isiNdebele.h>

MFRC522 isifundi(53, 5);

ilize thoma() {
    Isiriyali.ukuthoma(9600);
    Ibhasi_spi.ukuthoma();
    isifundi.thomisa_isifundi();
    Isiriyali.khombisa_umugqa("Sondeza ikhadi esifundini...");
}

ilize phinda_phinda() {
    nangabe (!isifundi.likhona_ikarada_elitjha() || !isifundi.funda_inomboro_yekarada()) buyisa;
    Isiriyali.khombisa("Inombolo yekhadi:");
    jikeleza (ibhayithi i = 0; i < isifundi.isazisi.ubukhulu; i++) {
        Isiriyali.khombisa(isifundi.isazisi.amabhayithi_wesazisi[i] < 0x10 ? " 0" : " ");
        Isiriyali.khombisa(isifundi.isazisi.amabhayithi_wesazisi[i], NGEHEKSA);
    }
    Isiriyali.khombisa_umugqa();
    isifundi.jamisa_ikarada();
}
