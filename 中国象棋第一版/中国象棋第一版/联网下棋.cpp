#include "ÁªÍøÏÂÆå.h"
#include <thread>


SocketCli sc;
bool CliOpen(string Ip, string port) {
	return sc.Start(Ip, port);
}


void CliClose() {
	sc.Destroy();
}

S_PlayInfo g_pi;

void Cli_SendRequest(int Type, string Param) {
	Head H;
	H.Type = Type;
	string dataSend = sc.GenerateRequest(H, Param);
	sc.Send(sc.sc, dataSend);
}

void Cli_SendRequest(int Type) {
	Head H;
	H.Type = Type;
	string dataSend = sc.GenerateRequest(H, "None");
	sc.Send(sc.sc, dataSend);
}



/*







*/