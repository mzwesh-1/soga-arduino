// GY-521 MPU-6050: ifunda ukusheshisa (accelerometer) nokujika (gyroscope) ezinhlangothini ezi-3.
// Ukuxhuma ku-Mega: VCC -> 5V, GND -> GND, SDA -> 20, SCL -> 21
#include <Wire.h>
#include <isiZulu.h>

engaguquki inombolo IKHELI_LE_MPU = 0x68;

inombolo16 funda_amabhayithi_amabili() {
    inombolo16 phezulu = Ucingo.funda_ibhayithi();
    buyisa (phezulu << 8) | Ucingo.funda_ibhayithi();
}

ize qala() {
    Isiriyeli.ukuqala(9600);
    Ucingo.ukuqala();
    Ucingo.qala_ukuthumela(IKHELI_LE_MPU);
    Ucingo.bhala_ibhayithi(0x6B);          // irejista yamandla
    Ucingo.bhala_ibhayithi(0);             // vusa i-MPU-6050
    Ucingo.qeda_ukuthumela(iqiniso);
}

ize phindaphinda() {
    Ucingo.qala_ukuthumela(IKHELI_LE_MPU);
    Ucingo.bhala_ibhayithi(0x3B);          // qala kurejista ye-accelerometer
    Ucingo.qeda_ukuthumela(amanga);
    Ucingo.cela_ku(IKHELI_LE_MPU, 14, iqiniso);
    inombolo16 ax = funda_amabhayithi_amabili(), ay = funda_amabhayithi_amabili(), az = funda_amabhayithi_amabili();
    inombolo16 ukushisa = funda_amabhayithi_amabili();
    inombolo16 gx = funda_amabhayithi_amabili(), gy = funda_amabhayithi_amabili(), gz = funda_amabhayithi_amabili();

    Isiriyeli.bonisa("Ukusheshisa X/Y/Z: ");
    Isiriyeli.bonisa(ax); Isiriyeli.bonisa(" "); Isiriyeli.bonisa(ay); Isiriyeli.bonisa(" "); Isiriyeli.bonisa(az);
    Isiriyeli.bonisa("   Ukujika X/Y/Z: ");
    Isiriyeli.bonisa(gx); Isiriyeli.bonisa(" "); Isiriyeli.bonisa(gy); Isiriyeli.bonisa(" "); Isiriyeli.bonisa(gz);
    Isiriyeli.bonisa("   Ukushisa: ");
    Isiriyeli.bonisa_umugqa(ukushisa / 340.0 + 36.53);
    linda(500);
}
