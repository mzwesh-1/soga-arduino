// Isamukeli se-IR nerimothi: cindezela izinkinobho, ubone inombolo yazo; inkinobho 1 ikhanyisa i-LED.
// Ukuxhuma: Y (signal) -> 11, R -> 5V, G -> GND; i-LED -> 13
// Dinga umtapo: "IRremote" (Tools -> Manage Libraries)
#include <IRremote.hpp>
#include <siSwati.h>

lokungagucuki inombolo ILED = 13;

lite cala() {
    Siriyali.kucala(9600);
    setha_liphini(ILED, LOKUPHUMAKO);
    Semukeli_se_IR.kucala(11, VUMELA_LED_YEKUPHENDVULA);
    Siriyali.khombisa_umugca("Cindezela inkinobho kurimothi...");
}

lite phindza_phindza() {
    nangabe (Semukeli_se_IR.humusha_lisignali()) {
        libhayithi umyalo_wenkinobho = Semukeli_se_IR.idatha_lehunyushiwe.umyalo;
        Siriyali.khombisa("Inkinobho: 0x");
        Siriyali.khombisa_umugca(umyalo_wenkinobho, NGEHEKSA);
        khetsa (umyalo_wenkinobho) {
            simo 0x0C: bhala_idijithali(ILED, PHETULU); phuma;   // "1" kurimothi encane
            simo 0x18: bhala_idijithali(ILED, PHANSI);  phuma;   // "2"
            lokujwayelekile: phuma;
        }
        Semukeli_se_IR.chubeka_ulalele();
    }
}
