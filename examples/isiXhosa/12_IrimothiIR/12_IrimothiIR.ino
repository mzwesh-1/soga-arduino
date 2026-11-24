// Isamukeli se-IR nerimothi: cindezela izinkinobho, ubone inombolo yazo; inkinobho 1 ikhanyisa i-LED.
// Ukuxhuma: Y (signal) -> 11, R -> 5V, G -> GND; i-LED -> 13
// Dinga umtapo: "IRremote" (Tools -> Manage Libraries)
#include <IRremote.hpp>
#include <isiXhosa.h>

engatshintshiyo inani ILED = 13;

ize qalisa() {
    Isiriyali.ukuqala(9600);
    misela_iphini(ILED, OKUPHUMAYO);
    Isamkeli_se_IR.ukuqala(11, VUMELA_ILED_YEMPENDULO);
    Isiriyali.bonisa_umgca("Cindezela inkinobho kurimothi...");
}

ize phinda_phinda() {
    ukuba (Isamkeli_se_IR.humusha_umqondiso()) {
        ibhayithi umyalo_wenkinobho = Isamkeli_se_IR.idatha_eguqulelweyo.umyalelo;
        Isiriyali.bonisa("Inkinobho: 0x");
        Isiriyali.bonisa_umgca(umyalo_wenkinobho, NGEHEKSA);
        khetha (umyalo_wenkinobho) {
            imeko 0x0C: bhala_idijithali(ILED, PHEZULU); phuma;   // "1" kurimothi encane
            imeko 0x18: bhala_idijithali(ILED, EZANTSI);  phuma;   // "2"
            okuqhelekileyo: phuma;
        }
        Isamkeli_se_IR.qhubeka_umamele();
    }
}
