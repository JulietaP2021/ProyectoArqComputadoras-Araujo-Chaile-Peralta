#include <iostream>
#include <conio.h> //getch();
#include <cstdlib> //system("cls");
#include <windows.h> //Sleep

using namespace std;

void autoFantastico();
void elChoque();
void estrellaFugaz();
void elIndeciso();

void disp_binary(int);
void delay(int);

int main() {
    char password[] = {'A', 'B', 'C', '1', '0', '\0'}; //"\0" indica el fin de la cadena de caracteres
    char arr[6] = {};
    int verificarPsw = 1; //1 = password correcta
    int contador = 0; //3 intentos para ingresar el password
    int opcion;

    do {
        cout << "Ingrese su password de 5 digitos: ";
        for(int i = 0; i < 5; i++) {
            arr[i] = getch();
            cout << "*";
        }
        cout << endl;

        //verificar password
        for(int i = 0; i < 5; i++) {
            if(password[i] != arr[i]) {
                verificarPsw = 0;
            }
        }

        if(verificarPsw == 1) {
            cout << endl;
            cout << "Bienvenido al sistema" << endl;
            contador = 99;
        } else {
            cout << "Password no valida" << endl;
            cout << endl;
            verificarPsw = 1;
            contador++;
        }
    } while(contador < 3);

    if(contador == 3) {
        return 0;
    }

    //menú
    do {
        cout << endl;
        cout << "MENU" << endl;
        cout << "1 -> Auto fantastico" << endl;
        cout << "2 -> El choque" << endl;
        cout << "3 -> Estrella fugaz" << endl;
        cout << "4 -> El indeciso" << endl;
        cout << "5 -> Salir" << endl;
        cout << endl;
        cout << "Elija su opcion: ";
        cin >> opcion;
    } while(opcion < 1 || opcion > 5);

    switch(opcion) {
        case 1:
            autoFantastico();
        break;

        case 2:
            elChoque();
        break;

        case 3:
            estrellaFugaz();
        break;

        case 4:
            elIndeciso();
        break;

        default:
            return 0;
    }
}

//por algoritmo
void autoFantastico() {
    Sleep(2000);
    system("cls"); //limpiar pantalla

    unsigned char output; //un entero de 8 bits sin signo (rango de 0 a 255)
    int time = 1300; //tiempo de espera

    cout << "AUTO FANTASTICO" << endl;
    cout << endl;
    cout << "Secuencia en accion... Oprima una tecla para finalizar" << endl;
    cout << endl;

    do {
        //ida
        output = 0x80;
        for(int i = 0; i < 8; i++) { //8 leds
            disp_binary(output);
            delay(time); //espera un momento
            output = output >> 1; //">>" desplazamiento a la derecha
        }

        //vuelta
        output = 0x01;
        for(int i = 0; i < 6; i++) {
            output = output << 1; //"<<" desplazamiento a la izquierda
            disp_binary(output);
            delay(time);
        }
    } while(!kbhit()); //repeat loop until the keyboard is hit
}

//por tabla
void elChoque() {
    cout << endl;
    cout << "EL CHOQUE" << endl;
}

//por tabla
void estrellaFugaz() {
    Sleep(2000);
    system("cls"); //limpiar pantalla

    unsigned char output[16];

    output[0] = 0x80;  //1000 0000
    output[1] = 0xc0;  //1100 0000
    output[2] = 0xe0;  //1110 0000
    output[3] = 0xf0;  //1111 0000
    output[4] = 0xf8;  //1111 1000
    output[5] = 0xfc;  //1111 1100
    output[6] = 0xfe;  //1111 1110
    output[7] = 0xff;  //1111 1111

    output[8] = 0x7f;  //0111 1111
    output[9] = 0x3f;  //0011 1111
    output[10] = 0x1f; //0001 1111
    output[11] = 0x0f; //0000 1111
    output[12] = 0x07; //0000 0111
    output[13] = 0x03; //0000 0011
    output[14] = 0x01; //0000 0001
    output[15] = 0x00; //0000 0000

    cout << "ESTRELLA FUGAZ" << endl;
    cout << endl;
    cout << "Secuencia en accion... Oprima una tecla para finalizar" << endl;
    cout << endl;

    do {
        for(int i = 0; i < 8; i++) { //se prende
            disp_binary(output[i]);
            delay(700);
        }

        for(int i = 8; i < 16; i++) { //se apaga
            disp_binary(output[i]);
            delay(2300);
        }

        delay(17000);
    } while(!kbhit()); //repeat loop until the keyboard is hit
}

//por algoritmo
void elIndeciso() {
    Sleep(2000);
    system("cls"); //limpiar pantalla

    unsigned char output; //un entero de 8 bits sin signo (rango de 0 a 255)
    int time = 4000; //tiempo de espera
    int avanza = 1;

    cout << "EL INDECISO" << endl;
    cout << endl;
    cout << "Secuencia en accion... Oprima una tecla para finalizar" << endl;
    cout << endl;

    do {
        for(int i = 0; i < 8; i++) { //8 leds
            output = 0x80;
            for(int j = 0; j < avanza; j++) {
                disp_binary(output);
                delay(time); //espera un momento
                output = output >> 1; //">>" desplazamiento a la derecha
            }
            avanza = avanza + 1;
        }
        avanza = 1;
    } while(!kbhit()); //repeat loop until the keyboard is hit
}

//NO FUNCIONA EL KBHIT

void disp_binary(int n) {
    for(int i = 128; i > 0; i = i / 2) {
        if(n&i) { //"&" producto bit a bit (AND)
            cout << "* ";
        } else {
            cout << "_ ";
        }
    }
    cout << "\b \r"; //borrar línea
}

//no entiendo como funciona
void delay(int time) {
    for(int i = time; i > 0; i--) {
        for(int j = 0; j < 65535; j++);
    }
}
