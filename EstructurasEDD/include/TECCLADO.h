#ifndef TECCLADO_H
#define TECCLADO_H
#include <string.h>
#include <ctype.h>


/* Caracteres especiales */
#define _BKSPC 0xe08   /* BACKSPACE ( tecla Retroceso) */
#define _TAB   0xf09   /* TAB */
#define _ENTER 0x10d   /* ENTER */
#define _ESC   0x11b   /* ESCAPE */
#define _ESP   0x3920  /* ESPACIO */

/* Teclas de codigo extendido */
#define _ARR  0x4800
#define _ABJ  0x5000
#define _IZQ  0x4b00
#define _DER  0x4d00

#define _INS  0x5200
#define _DEL  0x5300
#define _HOME 0x4700
#define _END  0x4f00
#define _PGUP 0x4900
#define _PGDN 0x5100

#define _F1  0x3b00
#define _F2  0x3c00
#define _F3  0x3d00
#define _F4  0x3e00
#define _F5  0x3f00
#define _F6  0x4000
#define _F7  0x4100
#define _F8  0x4200
#define _F9  0x4300
#define _F10 0x4400
//#include <bios.h>
#include <cstdio>
using namespace std;
class TECCLADO
{
    public:
        void Ptecla();

    private:
        int ObtenerTecla()
{
	int tecla;

	/* Espera a que una tecla sea presionada */
//	while (_bios_keybrd(_KEYBRD_READY) == 0);

	/* Obtiene la tecla presionada */
//	tecla = _bios_keybrd(_KEYBRD_READ);

	/* Si es alfanumerico retorna el codigo ASCII, por ejemplo para 'A', retornara 65 */
	if (isalnum(tecla & 0xFF)) return (char)tecla;

	/* Retorna el codigo de la tecla presionada */
	return tecla;
}

void ObtenerNombreTecla(char *nombre, int tecla)
{
	if(_BKSPC==tecla) strcpy(nombre,"BKSPC" );     /* BACKSPACE */
	else if(_TAB   == tecla) strcpy(nombre,"TAB");   /* TAB */
	else if(_ENTER == tecla) strcpy(nombre,"ENTER"); /* ENTER */
	else if(_ESC   == tecla) strcpy(nombre,"ESC");   /* ESCAPE */
	else if(_ESP   == tecla) strcpy(nombre,"ESP");   /* ESPACIO */

	/* Teclas de codigo extendido */
	else if(_ARR== tecla)  strcpy(nombre,"ARR");
	else if(_ABJ== tecla)  strcpy(nombre,"ABJ");
	else if(_IZQ== tecla)  strcpy(nombre,"IZQ");
	else if(_DER== tecla)  strcpy(nombre,"DER");

	else if(_INS== tecla)  strcpy(nombre, "INS");
	else if(_DEL== tecla)  strcpy(nombre, "DEL");
	else if(_HOME==tecla)  strcpy(nombre, "HOME");
	else if(_END== tecla)  strcpy(nombre, "END");
	else if(_PGUP==tecla)  strcpy(nombre, "PGUP");
	else if(_PGDN==tecla)  strcpy(nombre, "PGDN");

	else if(_F1== tecla)  strcpy(nombre, "F1");
	else if(_F2== tecla)  strcpy(nombre, "F2");
	else if(_F3== tecla)  strcpy(nombre, "F3");
	else if(_F4== tecla)  strcpy(nombre, "F4");
	else if(_F5== tecla)  strcpy(nombre, "F5");
	else if(_F6== tecla)  strcpy(nombre, "F6");
	else if(_F7== tecla)  strcpy(nombre, "F7");
	else if(_F8== tecla)  strcpy(nombre, "F8");
	else if(_F9== tecla)  strcpy(nombre, "F9");
	else if(_F10==tecla)  strcpy(nombre, "F10");

	/* Si es el alfanumerico */
	else if (isalnum(tecla & 0xFF)) sprintf(nombre, "%c", tecla);

	/* Si es un caracter desconocido, por ejemplo CTRL+F5, ALT+1...
	se retorna el codigo correspondiente y no su nombre ya que puede
	haber un gran numero de combinaciones */
	else sprintf(nombre, "%#02x", tecla);
}
};

#endif // TECCLADO_H
