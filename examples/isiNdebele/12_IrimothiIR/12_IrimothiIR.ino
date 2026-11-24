// Isamukeli se-IR nerimothi: cindezela izinkinobho, ubone inombolo yazo; inkinobho 1 ikhanyisa i-LED.
// Ukuxhuma: Y (signal) -> 11, R -> 5V, G -> GND; i-LED -> 13
// Dinga umtapo: "IRremote" (Tools -> Manage Libraries)
#include <IRremote.hpp>
#include <isiNdebele.h>

okungatjhugulukiko inomboro ILED = 13;

ilize thoma() {
    Isiriyali.ukuthoma(9600);
    beka_iphini(ILED, OKUPHUMAKO);
    Isamukeli_se_IR.ukuthoma(11, VUMELA_ILED_YOKUPHENDULA);
    Isiriyali.khombisa_umugqa("Cindezela inkinobho kurimothi...");
}

ilize phinda_phinda() {
    nangabe (Isamukeli_se_IR.hlathulula_isignali()) {
        ibhayithi umyalo_wenkinobho = Isamukeli_se_IR.idatha_ehlathululiweko.umlayo;
        Isiriyali.khombisa("Inkinobho: 0x");
        Isiriyali.khombisa_umugqa(umyalo_wenkinobho, NGEHEKSA);
        khetha (umyalo_wenkinobho) {
            isimo 0x0C: tlola_idijithali(ILED, PHEZULU); phuma;   // "1" kurimothi encane
            isimo 0x18: tlola_idijithali(ILED, PHASI);  phuma;   // "2"
            okujayelekileko: phuma;
        }
        Isamukeli_se_IR.ragela_phambili_ulalele();
    }
}
