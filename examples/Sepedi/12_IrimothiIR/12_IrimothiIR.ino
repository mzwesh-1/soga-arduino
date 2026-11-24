// Isamukeli se-IR nerimothi: cindezela izinkinobho, ubone inombolo yazo; inkinobho 1 ikhanyisa i-LED.
// Ukuxhuma: Y (signal) -> 11, R -> 5V, G -> GND; i-LED -> 13
// Dinga umtapo: "IRremote" (Tools -> Manage Libraries)
#include <IRremote.hpp>
#include <Sepedi.h>

sa_fetogego palo ILED = 13;

lefeela thoma() {
    Seriale.mathomo(9600);
    bea_phini(ILED, TSE_TSWAGO);
    Moamogedi_wa_IR.mathomo(11, DUMELELA_LED_YA_KARABO);
    Seriale.bontsha_mothaladi("Cindezela inkinobho kurimothi...");
}

lefeela boeletsa() {
    ge (Moamogedi_wa_IR.hlatholla_seswayo()) {
        paete umyalo_wenkinobho = Moamogedi_wa_IR.data_ye_hlathollotswego.taelo;
        Seriale.bontsha("Inkinobho: 0x");
        Seriale.bontsha_mothaladi(umyalo_wenkinobho, KA_HEKSA);
        kgetha (umyalo_wenkinobho) {
            seemo 0x0C: ngwala_dijithale(ILED, GODIMO); kgaotsa;   // "1" kurimothi encane
            seemo 0x18: ngwala_dijithale(ILED, FASE);  kgaotsa;   // "2"
            tlwaelo: kgaotsa;
        }
        Moamogedi_wa_IR.tswela_pele_o_theeletse();
    }
}
