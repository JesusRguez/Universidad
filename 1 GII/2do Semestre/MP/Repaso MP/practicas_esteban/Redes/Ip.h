// Modulo Ip


#ifndef __IP__
#define __IP__


#define TAM_IP 4
#define T_IP_CAD 15

typedef unsigned char ip[TAM_IP];

void IntroducirIp(ip prt, char *cad);
void LeerIp(ip prt);
void MostrarIp(ip prt);
int CompararIp(ip prt1,ip prt2);
int PerteneceRed(ip prt,ip mascara,ip puesto);


#endif
