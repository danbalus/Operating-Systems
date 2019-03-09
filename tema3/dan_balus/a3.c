#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
//#include <dir.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/param.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <ctype.h>
#include <sys/shm.h>
#include <sys/mman.h>
/*char *prelucrare_mesaj(char * mesaj)
{
	
	//int *final = (int *)malloc(sizeof(int));
	int lungime_mesaj = strlen(mesaj);
	char *buffer = (char *)malloc(sizeof(char));
	//char dim2[2];
	for (int i = 0; i < lungime_mesaj; ++i) 
	{
		if ((mesaj[i] >= 'a' && mesaj[i] <= 'z' )||( mesaj[i] >= 'A' && mesaj[i] <= 'Z') )//e litera mare sau mica
		{
			int x = mesaj[i];
			//printf("\n%d", x);
			//snprintf(buffer, "%02x", x);
			
			//char hex[5];
			sprintf(buffer, "%x", x);
			//puts(buffer);
			//printf("%s", buffer);--bun
			//strcat(buffer, dim2);
		}
		else if ((mesaj[i] >= '0' && mesaj[i] <= '9' && mesaj[i] != '\0') )
		{
			int j=i;
			int secventa = 0;
			while(mesaj[j] != '\0')
			{
				if((mesaj[j] >= '0' && mesaj[j] <= '9' ) )
				{
					secventa ++;
				}
			}
			for(int k = 0; k < secventa; k++)
			{

			}
		}
	}

	
	return buffer;
}

char *prelucrare_mesaj_scriere(char *mesaj)
{
	//int *final = (int *)malloc(sizeof(int));
	int lungime_mesaj = strlen(mesaj);
	char *buffer = (char *)malloc(sizeof(char));
	char *litera;
	//char dim2[2];
	char *lungime = (char *)malloc(sizeof(char));
	sprintf(lungime, "%d", lungime_mesaj);
	strcat(buffer, lungime);

	//int aInt = 368;
//char str[15];
//sprintf(str, "%d", aInt);
	for (int i = 0; i < lungime_mesaj; ++i) 
	{
		if ((mesaj[i] >= 'a' && mesaj[i] <= 'z' )||( mesaj[i] >= 'A' && mesaj[i] <= 'Z') )//e litera mare sau mica
		{
			if(mesaj[i] == 'C')
			{
				litera  = "43";//{'4','3'};
			}else
			if(mesaj[i] == 'O')
			{
				litera  = "4F"; //{'4', 'F'};
			}else
			if(mesaj[i] == 'N')
			{
				litera  = "4E";//{'4','E'};
			}else
			if(mesaj[i] == 'E')
			{
				litera  ="45";// {'4','5'};
			}else
			if(mesaj[i] == 'T')
			{
				litera  = "54"; //{'5','4'};
			}else
			if(mesaj[i] == 'S')
			{
				litera  = "53";// {'5','3'};
			}else
			if(mesaj[i] == 'U')
			{
				litera  = "55";// {'5','5'};
			}else
			if(mesaj[i] == 'R')
			{
				litera  = "52";//{'5','2'};
			}
		}
		strcat(buffer, litera);
	}
	return buffer;
}
*/
 //struct stat st;
int *glob_var;
char *shared_memory_reg;
char *PChar;
//static int lungime_fisier;
long int dimensiune_mapare;
int eroare = 0;
int fd, fd2;
//int pid;
char buf[256];
//int n;
//int nr;
int id_virtual;
int fd3;
int lungime_fisier;
int lungime_citire = 0;
char path[100];// = (char*)malloc(sizeof(char));

void conexiune()
{
	short kk = 7;
	write(fd2, &kk, 1);
	write(fd2, "CONNECT", 7);

}

void ping()
{
	int nr = 13735;
	short lungime_string = 4;
	write(fd2, &lungime_string, 1);
	write(fd2, "PING", 4);
	write(fd2, &lungime_string, 1);
	write(fd2, "PONG", 4);
	write(fd2, &nr, sizeof(int));
}

void scrie_eroare(short lungime_eroare, short lungime_mesaj, char* mesaj_comanda)
{
	short eroare = lungime_eroare, mesaj = lungime_mesaj;
	write(fd2, &mesaj, 1);
	write(fd2, mesaj_comanda, mesaj);
	write(fd2, &eroare, 1);
	write(fd2, "ERROR", eroare);
}
void scrie_succes(short lungime_succes, short lungime_mesaj, char* mesaj_comanda)
{
	short succes = lungime_succes, mesaj = lungime_mesaj;
	write(fd2, &mesaj, 1);
	write(fd2, mesaj_comanda, mesaj);
	write(fd2, &succes, 1);
	write(fd2, "SUCCESS", succes);
}

int main(){
	
	fd2 = mkfifo("RESP_PIPE_13735", 0666); 
	if ( fd2 < 0)
	{	
		eroare = 1;
		printf("ERROR\ncannot create the response pipe"); 
		exit(1); 
	}


	fd = open("REQ_PIPE_13735", O_RDONLY); //O_RDONLY)
	if (fd < 0)
	{ 
		eroare = 1;
		printf("ERROR\ncannot open the request pipe");
		exit(1);

	}

	//printf("vine");
	

		//pid = fork();
		//if (pid == 0)
		//{
	fd2 = open("RESP_PIPE_13735", O_WRONLY);
	//if (fd2 < 0)
	//{
	//	eroare = 1;
	//	printf("\neroare deschidere scriere 2 ");
		//exit(1);
	//}
	


	if( eroare == 0)
	{	
		printf("SUCCES");	
	}
	else
	{
		exit(1);
	}

	//char mesaj[] = ;//connect //07434f4e4e454354
	//char *final = prelucrare_mesaj(mesaj);
	//printf("%s", final);
	
	//printf("intra\n");
	//read(fd, buf, 14 );
	//int aux = (buf[1] - '0');
	conexiune();
	//bool ok = true;
	while(true)
	{	

		int n = read(fd, &lungime_citire, 1);
		if(n < 0)
		{
			printf("nu citeste lung_citire");
		}
		int n2 = read(fd, buf, lungime_citire);
		if(n2 < 0)
		{
			printf("nu citeste in buffer");
		}
		//printf("abcd");
		//if (n < 0)
		//{
		//	printf("\neroare citire  REQ_PIPE_13735 ");
			//buf[strlen(buf)] = '\0';
			//printf("%s\n", buf);
		//	exit(1);
		//}
		if(strncmp(buf, "EXIT", 4) == 0)
		{
			//ok = false;
			exit(1);
		}


		if(strncmp(buf, "PING", 4) == 0)
		{
			//buf[strlen(buf)] = '\0';
		 	ping();
		}
		else if(strncmp(buf,"CREATE_SHM", 10) == 0)
		{
			dimensiune_mapare = 0;
			read(fd, &dimensiune_mapare, sizeof(long) );
			//printf("%ld", dimensiune_mapare);
			id_virtual = shmget(15214, dimensiune_mapare, IPC_CREAT| 0664);
			

			 if(id_virtual == -1)
			{	
				scrie_eroare((short)5, (short)10, "CREATE_SHM");
			}
			else if(id_virtual != -1)
			{	
				shared_memory_reg = shmat(id_virtual, NULL, 0);
				//PChar = (char*) shmat(id_virtual, 0, 0);
				//int nr =2997886;
				//short succes = 7, mesaj = 10;
				scrie_succes((short)7, (short)10, "CREATE_SHM");
			}
		}else if(strncmp(buf,"WRITE_TO_SHM", 12) == 0)
		{
			unsigned int offset, valoare;
			//long int dimensiune_mapare = 0;
			read(fd, &offset, sizeof(unsigned int) );
			//printf("\n\n%d", offset);
			read(fd, &valoare, sizeof(unsigned int) );
			//printf("\n\n%d", valoare);
			if(id_virtual == -1)
			{	
				eticheta:;
				scrie_eroare((short)5, (short)12, "WRITE_TO_SHM");
			}
			else if(id_virtual != -1)
			{	
				if( (offset >= 0) && (offset + sizeof(valoare) <= 2997886) )
				{
					memcpy ( &shared_memory_reg[offset], &valoare, sizeof(valoare) );
				}
				else
				{
					goto eticheta;
				}
				//printf("\n\n%d", shared_memory_reg[offset]);

				scrie_succes((short)7, (short)12, "WRITE_TO_SHM");
			}
		}else if(strncmp(buf,"MAP_FILE", 8) == 0)
		{
			unsigned char lung;
			read(fd, &lung, 1);
			//printf("\n\n\n%d", lung);
			
			read(fd, &path, lung);
			path[lung] = '\0';
			
			//path[lung]= '\0';
			//printf("999999999999999999999");
			//printf("\n\n\n%s", path);
			if(id_virtual == -1)
			{
				eticheta2:;
				scrie_eroare((short)5, (short)8, "MAP_FILE");
			}
			else if(id_virtual != -1)
			{	
				//printf("\n\n%d", shared_memory_reg[offset]);
				fd3 = open(path, O_RDONLY , (mode_t)0640);
			    if (fd3 == -1) 
			    {
					perror("Error opening file for writing");
					exit(EXIT_FAILURE);
			    }

			    lungime_fisier = lseek(fd3, 0, SEEK_END);
				glob_var = mmap(0, lungime_fisier, PROT_READ,  MAP_SHARED | MAP_FILE, fd3, 0);//O_RDONLY

				if(glob_var == MAP_FAILED)
				{	goto eticheta2;
					perror("nu mere map");
					
				}

				scrie_succes((short)7, (short)8, "MAP_FILE");
			}
							//munmap(glob_var, lungime_fisier);

			
		}else if(strncmp(buf,"READ_FROM_FILE_OFFSET", 21) == 0)
		{
			//char* mem = shared_memory_reg;
			
			//printf("\n\n%d", shared_memory_reg[offset]);
			unsigned int offset = 0, no_of_bytes =0;
			//long int dimensiune_mapare = 0;
			read(fd, &offset, sizeof(unsigned int) );
			//printf("\n\n%d", offset);
			//memcpy();
			//read(*glob_var, &offset, no_of_bytes );
			read(fd, &no_of_bytes, sizeof(unsigned int) );
			
				
				if((shared_memory_reg != (void*)-1) && (no_of_bytes >0) && (0 <= offset ) && (glob_var != MAP_FAILED) && ((offset + no_of_bytes )<= lungime_fisier )  )
				{
					
					scrie_succes((short)7, (short)21, "READ_FROM_FILE_OFFSET");
					//for(int i=0; i< no_of_bytes; i++)
					//{
					//	shared_memory_reg[i] = glob_var[offset + i];
					//}
					memcpy ( shared_memory_reg, (glob_var + offset), no_of_bytes);
				}
				else
				{
					scrie_eroare((short)5, (short)21, "READ_FROM_FILE_OFFSET");
					//exit(1);
						//goto eticheta3;
				}
				
			
		}else if(strncmp(buf,"READ_FROM_FILE_SECTION", 22) == 0)//-----------------------
		{
			
			if(id_virtual == -1)
			{

				scrie_eroare((short)5, (short)22, "READ_FROM_FILE_SECTION");

			}
			else if(id_virtual != -1)
			{	unsigned int offset, no_of_bytes, section_no;

				 int lungime_fisier = lseek(fd3, 0, SEEK_END);
				
				read(fd, &section_no, sizeof(unsigned int) );
				read(fd, &offset, sizeof(unsigned int) );
				read(fd, &no_of_bytes, sizeof(unsigned int) );

				glob_var = mmap(0, lungime_fisier, PROT_READ, MAP_SHARED, fd3, 0);//O_RDONLY
				scrie_succes((short)7, (short)22, "READ_FROM_FILE_SECTION");

			}
		}else if(strncmp(buf,"READ_FROM_LOGICAL_SPACE_OFFSET", 30) == 0)//-----------------------
		{
			
			if(id_virtual == -1)
			{
				//logical_offset
				
				scrie_eroare((short)5, (short)30, "READ_FROM_LOGICAL_SPACE_OFFSET");

				//exit(1);
			}
			else if(id_virtual != -1)
			{	
				unsigned int  no_of_bytes, logical_offset;

				read(fd, &logical_offset, sizeof(unsigned int) );
				read(fd, &no_of_bytes, sizeof(unsigned int) );

				scrie_succes((short)7, (short)30, "READ_FROM_LOGICAL_SPACE_OFFSET");

			}
		}

			//"READ_FROM_FILE_OFFSET"
		

		
	}
	unlink("RESP_PIPE_13735");
			
		//}
		//else //if pid != 0 ---> parinte
		//{
			


			//printf("\nblabla");
		//}
		//eticheta1:;
	

	


	return 0;
}