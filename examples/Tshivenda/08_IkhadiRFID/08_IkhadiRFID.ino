// RC522 RFID: ifunda inombolo yekhadi elimhlophe noma ye-key fob eluhlaza.
// Ukuxhuma ku-Mega: SDA -> 53, SCK -> 52, MOSI -> 51, MISO -> 50, RST -> 5, 3.3V -> 3.3V (HHAYI 5V!), GND -> GND
// Dinga umtapo: "MFRC522" (Tools -> Manage Libraries)
#include <SPI.h>
#include <MFRC522.h>
#include <Tshivenda.h>

MFRC522 isifundi(53, 5);

a_huna thoma() {
    Siriale.mathomo(9600);
    Bisi_ya_spi.mathomo();
    isifundi.thomisa_muvhali();
    Siriale.sumbedza_mutalo("Sondeza ikhadi esifundini...");
}

a_huna dovholola() {
    arali (!isifundi.karada_ntswa_i_hone() || !isifundi.vhala_nomboro_ya_karada()) vhuisa;
    Siriale.sumbedza("Inombolo yekhadi:");
    mona (baithi i = 0; i < isifundi.vhutalukanyi.vhuhulu; i++) {
        Siriale.sumbedza(isifundi.vhutalukanyi.dzibaithi_dza_vhutalukanyi[i] < 0x10 ? " 0" : " ");
        Siriale.sumbedza(isifundi.vhutalukanyi.dzibaithi_dza_vhutalukanyi[i], NGA_HEKSA);
    }
    Siriale.sumbedza_mutalo();
    isifundi.imisa_karada();
}
