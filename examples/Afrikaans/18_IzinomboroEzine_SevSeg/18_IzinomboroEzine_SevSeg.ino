// Isibonisi sezinombolo ezi-4: isibali-sikhathi esibala imizuzwana eyishumi (0.0 - 999.9).
// Ukuxhuma: D1-D4 -> 2, 3, 4, 5; a-g, DP -> 6-13 (220 ohm)
// Dinga umtapo: "SevSeg" (Tools -> Manage Libraries)
#include <SevSeg.h>
#include <Afrikaans.h>

Syferskerm isibonisi;

leeg opstel() {
    greep amaphini_ezinombolo[] = {2, 3, 4, 5};
    greep amaphini_ezingxenye[] = {6, 7, 8, 9, 10, 11, 12, 13};
    isibonisi.begin(COMMON_CATHODE, 4, amaphini_ezinombolo, amaphini_ezingxenye, vals);
    isibonisi.stel_glans(90);
}

leeg lus() {
    staties ongeteken lank isikhathi_sokugcina = 0;
    staties heelgetal isibali = 0;
    as (millisekondes() - isikhathi_sokugcina >= 100) {
        isikhathi_sokugcina = millisekondes();
        isibali = (isibali + 1) % 10000;
        isibonisi.stel_getal(isibali, 1);   // ichashazi le-desimali endaweni yoku-1
    }
    isibonisi.verfris_skerm();             // kumele kubizwe njalo
}
