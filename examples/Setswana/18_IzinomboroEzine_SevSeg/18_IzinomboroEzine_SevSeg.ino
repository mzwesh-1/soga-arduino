// Isibonisi sezinombolo ezi-4: isibali-sikhathi esibala imizuzwana eyishumi (0.0 - 999.9).
// Ukuxhuma: D1-D4 -> 2, 3, 4, 5; a-g, DP -> 6-13 (220 ohm)
// Dinga umtapo: "SevSeg" (Tools -> Manage Libraries)
#include <SevSeg.h>
#include <Setswana.h>

Pontsho_ya_dinomore isibonisi;

lefela simolola() {
    baete amaphini_ezinombolo[] = {2, 3, 4, 5};
    baete amaphini_ezingxenye[] = {6, 7, 8, 9, 10, 11, 12, 13};
    isibonisi.tshimologo(COMMON_CATHODE, 4, amaphini_ezinombolo, amaphini_ezingxenye, maaka);
    isibonisi.baya_phatsimo(90);
}

lefela boeletsa() {
    e_emeng e_se_na_tshwao leele isikhathi_sokugcina = 0;
    e_emeng palo isibali = 0;
    fa (dimilisekonte() - isikhathi_sokugcina >= 100) {
        isikhathi_sokugcina = dimilisekonte();
        isibali = (isibali + 1) % 10000;
        isibonisi.baya_nomore(isibali, 1);   // ichashazi le-desimali endaweni yoku-1
    }
    isibonisi.ntshafatsa_pontsho();             // kumele kubizwe njalo
}
