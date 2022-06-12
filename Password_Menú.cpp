#include <iostream>
#include <conio.h> //getch();
#include <cstdlib> //system("cls");
#include <windows.h> //Sleep

using namespace std;

void autoFantastico();
void elChoque();
void estrellaFugaz();
//void opcion4();

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
        cout << "4 -> " << endl;
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
        /*
        case 4:
            opcion4();
        break;
        */
        default:
            return 0;
    }
}

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

void elChoque() {
    cout << endl;
    cout << "EL CHOQUE" << endl;
}

void estrellaFugaz() {
    cout << endl;
    cout << "ESTRELLA FUGAZ" << endl;
}

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
