// Isamukeli se-IR nerimothi: cindezela izinkinobho, ubone inombolo yazo; inkinobho 1 ikhanyisa i-LED.
// Ukuxhuma: Y (signal) -> 11, R -> 5V, G -> GND; i-LED -> 13
// Dinga umtapo: "IRremote" (Tools -> Manage Libraries)
#include <IRremote.hpp>
#include <isiZulu.h>

engaguquki inombolo ILED = 13;

ize qala() {
    Isiriyeli.ukuqala(9600);
    setha_iphini(ILED, OKUPHUMAYO);
    Isamukeli_se_IR.ukuqala(11, VUMELA_ILED_YOKUPHENDULA);
    Isiriyeli.bonisa_umugqa("Cindezela inkinobho kurimothi...");
}

ize phindaphinda() {
    uma (Isamukeli_se_IR.humusha_isignali()) {
        ibhayithi umyalo_wenkinobho = Isamukeli_se_IR.idatha_ehunyushiwe.umyalo;
        Isiriyeli.bonisa("Inkinobho: 0x");
        Isiriyeli.bonisa_umugqa(umyalo_wenkinobho, NGEHEKSA);
        khetha (umyalo_wenkinobho) {
            isimo 0x0C: bhala_idijithali(ILED, PHEZULU); phuma;   // "1" kurimothi encane
            isimo 0x18: bhala_idijithali(ILED, PHANSI);  phuma;   // "2"
            okujwayelekile: phuma;
        }
        Isamukeli_se_IR.qhubeka_ulalele();
    }
}
