// I-rotary encoder: jika ukwandisa/ukunciphisa inombolo; cindezela ukuyibuyisela ku-0.
// Ukuxhuma: CLK -> 2, DT -> 3, SW -> 4, + -> 5V, GND -> GND
#include <isiZulu.h>

engaguquki inombolo I_CLK = 2;
engaguquki inombolo I_DT = 3;
engaguquki inombolo I_SW = 4;
okuguquguqukayo inombolo isibali = 0;
inombolo isibali_esidala = 0;

ize uma_kujikiwe() {
    uma (funda_idijithali(I_DT) != funda_idijithali(I_CLK)) isibali++;   // ngokwewashi
    kungenjalo isibali--;                                               // ngokuphambene
}

ize qala() {
    setha_iphini(I_CLK, OKUNGENAYO);
    setha_iphini(I_DT, OKUNGENAYO);
    setha_iphini(I_SW, OKUNGENAYO_KUDONSELWE);
    Isiriyeli.ukuqala(9600);
    namathisela_ukuphazamiseka(iphini_kuya_ekuphazamisekeni(I_CLK), uma_kujikiwe, UMA_KUSHINTSHA);
}

ize phindaphinda() {
    uma (funda_idijithali(I_SW) == PHANSI) {
        isibali = 0;
        linda(200);
    }
    uma (isibali != isibali_esidala) {
        isibali_esidala = isibali;
        Isiriyeli.bonisa("Isibali: ");
        Isiriyeli.bonisa_umugqa(isibali);
    }
}
