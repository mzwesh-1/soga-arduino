// Isamukeli se-IR nerimothi: cindezela izinkinobho, ubone inombolo yazo; inkinobho 1 ikhanyisa i-LED.
// Ukuxhuma: Y (signal) -> 11, R -> 5V, G -> GND; i-LED -> 13
// Dinga umtapo: "IRremote" (Tools -> Manage Libraries)
#include <IRremote.hpp>
#include <Tshivenda.h>

zwi_sa_shanduki nomboro ILED = 13;

a_huna thoma() {
    Siriale.mathomo(9600);
    vhea_phini(ILED, ZWI_BVAHO);
    Mutanganedzi_wa_IR.mathomo(11, TENDELA_LED_YA_PHINDULO);
    Siriale.sumbedza_mutalo("Cindezela inkinobho kurimothi...");
}

a_huna dovholola() {
    arali (Mutanganedzi_wa_IR.talutshedza_tshiga()) {
        baithi umyalo_wenkinobho = Mutanganedzi_wa_IR.data_yo_talutshedzwaho.ndaela;
        Siriale.sumbedza("Inkinobho: 0x");
        Siriale.sumbedza_mutalo(umyalo_wenkinobho, NGA_HEKSA);
        nanga (umyalo_wenkinobho) {
            nyimele 0x0C: nwala_didzhithala(ILED, NTHA); imisa;   // "1" kurimothi encane
            nyimele 0x18: nwala_didzhithala(ILED, FHASI);  imisa;   // "2"
            zwo_dowelea: imisa;
        }
        Mutanganedzi_wa_IR.bvela_phanda_u_thetshelesa();
    }
}
