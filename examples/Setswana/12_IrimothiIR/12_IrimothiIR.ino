// Isamukeli se-IR nerimothi: cindezela izinkinobho, ubone inombolo yazo; inkinobho 1 ikhanyisa i-LED.
// Ukuxhuma: Y (signal) -> 11, R -> 5V, G -> GND; i-LED -> 13
// Dinga umtapo: "IRremote" (Tools -> Manage Libraries)
#include <IRremote.hpp>
#include <Setswana.h>

e_sa_fetogeng palo ILED = 13;

lefela simolola() {
    Seriale.tshimologo(9600);
    baya_phini(ILED, TSE_DI_TSWANG);
    Moamogedi_wa_IR.tshimologo(11, LETLA_LED_YA_KARABO);
    Seriale.bontsha_mola("Cindezela inkinobho kurimothi...");
}

lefela boeletsa() {
    fa (Moamogedi_wa_IR.ranola_letshwao()) {
        baete umyalo_wenkinobho = Moamogedi_wa_IR.data_e_ranotsweng.taelo;
        Seriale.bontsha("Inkinobho: 0x");
        Seriale.bontsha_mola(umyalo_wenkinobho, KA_HEKSA);
        tlhopha (umyalo_wenkinobho) {
            seemo 0x0C: kwala_dijithale(ILED, GODIMO); kgaotsa;   // "1" kurimothi encane
            seemo 0x18: kwala_dijithale(ILED, TLASE);  kgaotsa;   // "2"
            tlwaelo: kgaotsa;
        }
        Moamogedi_wa_IR.tswelela_o_reetsa();
    }
}
