// GY-521 MPU-6050: ifunda ukusheshisa (accelerometer) nokujika (gyroscope) ezinhlangothini ezi-3.
// Ukuxhuma ku-Mega: VCC -> 5V, GND -> GND, SDA -> 20, SCL -> 21
#include <Wire.h>
#include <Tshivenda.h>

zwi_sa_shanduki nomboro IKHELI_LE_MPU = 0x68;

nomboro16 funda_amabhayithi_amabili() {
    nomboro16 phezulu = Waya.vhala_baithi();
    vhuisa (phezulu << 8) | Waya.vhala_baithi();
}

a_huna thoma() {
    Siriale.mathomo(9600);
    Waya.mathomo();
    Waya.thoma_u_rumela(IKHELI_LE_MPU);
    Waya.nwala_baithi(0x6B);          // irejista yamandla
    Waya.nwala_baithi(0);             // vusa i-MPU-6050
    Waya.fhedza_u_rumela(ngoho);
}

a_huna dovholola() {
    Waya.thoma_u_rumela(IKHELI_LE_MPU);
    Waya.nwala_baithi(0x3B);          // qala kurejista ye-accelerometer
    Waya.fhedza_u_rumela(mazwifhi);
    Waya.humbela_kha(IKHELI_LE_MPU, 14, ngoho);
    nomboro16 ax = funda_amabhayithi_amabili(), ay = funda_amabhayithi_amabili(), az = funda_amabhayithi_amabili();
    nomboro16 ukushisa = funda_amabhayithi_amabili();
    nomboro16 gx = funda_amabhayithi_amabili(), gy = funda_amabhayithi_amabili(), gz = funda_amabhayithi_amabili();

    Siriale.sumbedza("Ukusheshisa X/Y/Z: ");
    Siriale.sumbedza(ax); Siriale.sumbedza(" "); Siriale.sumbedza(ay); Siriale.sumbedza(" "); Siriale.sumbedza(az);
    Siriale.sumbedza("   Ukujika X/Y/Z: ");
    Siriale.sumbedza(gx); Siriale.sumbedza(" "); Siriale.sumbedza(gy); Siriale.sumbedza(" "); Siriale.sumbedza(gz);
    Siriale.sumbedza("   Ukushisa: ");
    Siriale.sumbedza_mutalo(ukushisa / 340.0 + 36.53);
    lindela(500);
}
