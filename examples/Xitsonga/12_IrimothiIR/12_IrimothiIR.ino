// Isamukeli se-IR nerimothi: cindezela izinkinobho, ubone inombolo yazo; inkinobho 1 ikhanyisa i-LED.
// Ukuxhuma: Y (signal) -> 11, R -> 5V, G -> GND; i-LED -> 13
// Dinga umtapo: "IRremote" (Tools -> Manage Libraries)
#include <IRremote.hpp>
#include <Xitsonga.h>

lexi_nga_cinciki nomboro ILED = 13;

swi_hava sungula() {
    Siriyali.ku_sungula(9600);
    veka_phini(ILED, LESWI_HUMAKA);
    Muamukeri_wa_IR.ku_sungula(11, PFUMELELA_LED_YA_NHLAMULO);
    Siriyali.kombisa_layini("Cindezela inkinobho kurimothi...");
}

swi_hava phindha_phindha() {
    loko (Muamukeri_wa_IR.hlamusela_xikombiso()) {
        bayiti umyalo_wenkinobho = Muamukeri_wa_IR.data_leyi_hlamuseriweke.xileriso;
        Siriyali.kombisa("Inkinobho: 0x");
        Siriyali.kombisa_layini(umyalo_wenkinobho, HI_HEKSA);
        hlawula (umyalo_wenkinobho) {
            xiyimo 0x0C: tsala_dijitali(ILED, HENHLA); yimisa;   // "1" kurimothi encane
            xiyimo 0x18: tsala_dijitali(ILED, HANSI);  yimisa;   // "2"
            ntolovelo: yimisa;
        }
        Muamukeri_wa_IR.ya_emahlweni_u_yingisela();
    }
}
