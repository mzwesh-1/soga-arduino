// Isamukeli se-IR nerimothi: cindezela izinkinobho, ubone inombolo yazo; inkinobho 1 ikhanyisa i-LED.
// Ukuxhuma: Y (signal) -> 11, R -> 5V, G -> GND; i-LED -> 13
// Dinga umtapo: "IRremote" (Tools -> Manage Libraries)
#include <IRremote.hpp>
#include <Sesotho.h>

e_sa_fetoheng palo ILED = 13;

lefeela qala() {
    Seriale.qalo(9600);
    beha_phini(ILED, TSE_TSWANG);
    Moamohedi_wa_IR.qalo(11, DUMELLA_LED_YA_KARABO);
    Seriale.bontsha_mola("Cindezela inkinobho kurimothi...");
}

lefeela pheta_pheta() {
    haeba (Moamohedi_wa_IR.toloka_letshwao()) {
        baete umyalo_wenkinobho = Moamohedi_wa_IR.data_e_tolokilweng.taelo;
        Seriale.bontsha("Inkinobho: 0x");
        Seriale.bontsha_mola(umyalo_wenkinobho, KA_HEKSA);
        kgetha (umyalo_wenkinobho) {
            boemo 0x0C: ngola_dijithale(ILED, HODIMO); kgaotsa;   // "1" kurimothi encane
            boemo 0x18: ngola_dijithale(ILED, TLASE);  kgaotsa;   // "2"
            tlwaelo: kgaotsa;
        }
        Moamohedi_wa_IR.tswela_pele_o_mamele();
    }
}
