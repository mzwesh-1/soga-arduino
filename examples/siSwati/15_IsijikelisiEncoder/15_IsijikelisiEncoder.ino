// I-rotary encoder: jika ukwandisa/ukunciphisa inombolo; cindezela ukuyibuyisela ku-0.
// Ukuxhuma: CLK -> 2, DT -> 3, SW -> 4, + -> 5V, GND -> GND
#include <siSwati.h>

lokungagucuki inombolo I_CLK = 2;
lokungagucuki inombolo I_DT = 3;
lokungagucuki inombolo I_SW = 4;
lokugucugucukako inombolo isibali = 0;
inombolo isibali_esidala = 0;

lite uma_kujikiwe() {
    nangabe (fundza_idijithali(I_DT) != fundza_idijithali(I_CLK)) isibali++;   // ngokwewashi
    ngalokunye isibali--;                                               // ngokuphambene
}

lite cala() {
    setha_liphini(I_CLK, LOKUNGENAKO);
    setha_liphini(I_DT, LOKUNGENAKO);
    setha_liphini(I_SW, LOKUNGENAKO_KUDONSIWE);
    Siriyali.kucala(9600);
    namatsisela_kuphazamiseka(liphini_kuya_ekuphazamisekeni(I_CLK), uma_kujikiwe, NAKUSHINTSHA);
}

lite phindza_phindza() {
    nangabe (fundza_idijithali(I_SW) == PHANSI) {
        isibali = 0;
        lindza(200);
    }
    nangabe (isibali != isibali_esidala) {
        isibali_esidala = isibali;
        Siriyali.khombisa("Isibali: ");
        Siriyali.khombisa_umugca(isibali);
    }
}
