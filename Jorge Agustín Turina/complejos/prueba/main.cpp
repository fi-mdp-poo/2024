#include "cReloj.h"


int main()
{
    cReloj clock1, // por defecto: 0 0 0
           clock2(3, 4, 50),
           clock3(clock2);

    clock1.setTiempo(23, 58, 59);
    clock1.setMarca("primero");
    clock2.setMarca("segundo");
    clock3.setMarca("reloj copiado");



    cRadio radio1, // por defecto: 95.5 FM false
           radio2(103.3),
           radio3(860.0, AM),
           radio4(radio3);
    radio4.setPrendido(true);



    cRadioReloj alarma1(cTime(23, 59, 59)),
// reloj=(23,59,59) alarma=(0,0,0) Timbre
// alarma_off 100.1 FM radio_off
                alarma2(clock1.getTiempo(), cTime(8, 29, 58));


    alarma1.setPrendido(false);
    alarma1.setAlarma(12, 59, 59);
    alarma2.setBanda(AM);
// TODO : encender la radio de alarma2
    alarma1.incrementarTiempo();
    cTime tiempo = alarma1.getTiempo();
    cout<<"Hora mostrada en la radio_alarma1: "<<tiempo<<"\n";
        alarma2.incrementarTiempo();
    tiempo = alarma2.getTiempo();
    cout<<"Hora mostrada en la radio_alarma2: "<<tiempo<<"\n";
        alarma2.incrementarTiempo();
    tiempo = alarma2.getTiempo();
    cout<<"Hora mostrada en la radio_alarma2: "<<tiempo<<"\n";
        if(alarma1.verificarAlarma())
            cout << "La alarma 1 esta prendida" << endl;
    else
        cout << "La alarma 1 esta apagada " << endl;

    return 0;
}

