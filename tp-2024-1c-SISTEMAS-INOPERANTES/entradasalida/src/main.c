#include <stdlib.h>
#include <stdio.h>
#include <utils/hello.h>

//Creación del cliente (I/O)

int main(int argc, char* argv[]) {

	char* ipKernel;
	char* puertoKernel;
	char* ipMemoria;
	char* puertoMemoria;
	char* valor;

    if(argc < 1){
		printf("Faltan parametros de entrada\n");
		return EXIT_FAILURE;
	}

	char *path_config = strdup(argv[1]);
	iolog = iniciar_logger();
	//leer_configuracion(path_config);
	config = iniciar_config();
	ipKernel = config_get_string_value(config, "IP_KERNEL");
	puertoKernel = config_get_string_value(config, "PUERTO_KERNEL");
	ipMemoria = config_get_string_value(config, "IP_MEMORIA");
	puertoMemoria = config_get_string_value(config, "PUERTO_MEMORIA");
	//------

	int conexionIOConCPU = conectar_con_CPU();
	int conxionIOConKernel = conectar_Con_KERNEL();
    return 0;
}



t_config* iniciar_config(char* config)
{
	t_config* nuevo_config;
    nuevo_config = config_create(config);//NOMBRE DEL ARCHIVO CONFIG
	if (nuevo_config == NULL) {
    printf("¡No se pudo crear el config!");
    // Terminemos el programa
	exit(NULL);
	}
	return nuevo_config;
}