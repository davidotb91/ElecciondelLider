#include <stdio.h>
#include <stdlib.h> 
#include <mpi.h> 
#include <string.h> 
#define BUFSIZE 128 
#define TAG 0 
void main(int argc, char* argv[]) { 
	int numero, idlider, numeroProcesos, myid, i; 
	char buff[BUFSIZE];
	char auxbuff[BUFSIZE]; 
	char *cadena; 
	MPI_Status stat; 
	MPI_Init(&argc,&argv); 
	MPI_Comm_size(MPI_COMM_WORLD, &numeroProcesos); 
	MPI_Comm_rank(MPI_COMM_WORLD, &myid); 
	srand(MPI_Wtime()*1000000); 
	numero = rand()%100+1; 
	idlider = myid; 
	AsignacionNumero(numeroProcesos,buff[BUFSIZE],myid,i);
	EleccionLider(numeroProcesos,buff[BUFSIZE],auxbuff[BUFSIZE],idlider,myid,numero ,i,*cadena);
		 		
		 	}
		 	//funcion asignacion de numero de numero 
		 	void AsignacionNumero(int numeroProcesos,char buff[BUFSIZE],int myid,int i){

		 		for(i=0;i<numeroProcesos;i++){ 
		 			if (myid!=i){ 
		 				MPI_Send(buff, BUFSIZE, MPI_CHAR, i, TAG, MPI_COMM_WORLD);
		 			}
			else
				printf("Soy el procesoo %d y tengo el numero %d\n", myid,numero); 
		 } 
		}
		//funcion definicion de  lider
                  void EleccionLider(int numeroProcesos,char buff[BUFSIZE],char auxbuff[BUFSIZE],int idlider,int myid,int numero ,int i,char *cadena){
                  	for(i=0;i<numeroProcesos;i++){ 
                  		if (myid!=i){ 
		 				MPI_Recv(buff, BUFSIZE, MPI_CHAR, i, TAG, MPI_COMM_WORLD, &stat); 
		 				strcpy(auxbuff,buff); 
		 				cadena = strtok(auxbuff,"."); 
		 			if (numero <= atoi(cadena)){ 
		 				numero = atoi(cadena); 
		 				cadena = strtok(NULL, "."); 
		 				idlider = atoi(cadena); 
		 			}
		 		 } 
		 		} printf("%d: Soy el lider %d con el numero %d\n", myid, idlider, numero); 
		 		MPI_Finalize();


                  }