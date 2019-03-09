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

//void extract_test(const char *path, int sectionn, int lline);

 /*off_t  size_for(char * nume)
 {
	struct stat st;
	stat(nume, &st);
	off_t  size = st.st_size;
	return size;
    return -1;
 }*/
/*int is_regular_file(const char *path)
{
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISREG(path_stat.st_mode);
}*/
int isDirectory(const char *path) {
   struct stat statbuf;
   if (stat(path, &statbuf) != 0)
       return 0;
   return S_ISDIR(statbuf.st_mode);
}
/*off_t fsize(const char *filename) {
    struct stat st; 

    if (stat(filename, &st) == 0)
        return st.st_size;

    return -1; 
}*/
/*off_t findSize(char *dirName)
{
    struct stat st;
    stat(dirName,&st);
    if(!S_ISDIR(st.st_mode)){
        return st.st_size;
    }
return -1;
}*/
int numara(char * path)
{
	int from, nr, n =0;
	char buf[1];
	if ((from=open(path, O_RDONLY)) < 0) {
  		perror("Error opening source file");
 		exit(1);
 	}
	while((nr=read(from, buf, sizeof( buf))) != 0) {
 		n++;
	}
	close(from);
return n;
}
void listDir(char *dirName, char *nume_inceput, bool validare_nume, long  size_fl, bool validare_size)
{
	//printf("\nintra in validare010101010\n");
          		DIR* dir;
                struct dirent *dirEntry;
                struct stat inode;
                char name[1000];
                int n;
                //char  pathx ;
                dir = opendir(dirName);
                if (dir == 0) 
                {
                    perror ("Eroare deschidere fisier");
                    exit(1);
                }
                while ((dirEntry=readdir(dir)) != 0  ) 
                {
                	n=0;
                	if(strcmp (dirEntry->d_name, "..") != 0 && strcmp (dirEntry->d_name, ".") != 0)
                	{
                		//printf("\nintra in validare_00000000000000000\n");
                		if(validare_nume == false && validare_size == false)
                		{
                    		sprintf(name,"%s/%s/",dirName,dirEntry->d_name);
                    		lstat (name, &inode);// test the type of file
                   			printf("%s/%s\n",dirName, dirEntry->d_name);
                		}
                		if(validare_nume == true && validare_size == false)
                		{
                			

                			//printf("\nintra in validare1\n");
                			if(strstr(dirEntry->d_name, nume_inceput))
                			{
                				//printf("\nintra in validare\n");

                				sprintf(name,"%s/%s/",dirName,dirEntry->d_name);
                    			lstat (name, &inode);// test the type of file
                   				printf("%s/%s\n",dirName, dirEntry->d_name);


                			}
                		}
                		if(validare_nume == false && validare_size == true)
                		{
                		//lstat (name, &inode);// test the type of file

                			//printf("\nintra in validare\n");
                			//printf("\nsize for dir:%ld\n",size_for(dirEntry->d_name));
							//printf("\nsize for dir:%ld\n",size_for(name));
							//strcpy(pathx, name);
							//printf("\n-----------%s\n", name);
							//printf("\nipathxxxxx %s\n", pathx);
                			sprintf(name,"%s/%s",dirName,dirEntry->d_name);
                			if( ( isDirectory(name) == 0 ))

                			{
                				
                				sprintf(name,"%s/%s",dirName,dirEntry->d_name);
                				n = numara(name);
                				//printf("\n%d\n",n);
                				if(n < size_fl)
                				{
                				//printf("\nsize for dir222:%ld\n",size_for(name));
                				//printf("\nintra in validare222\n");
                    			//sprintf(name,"%s/%s",dirName,dirEntry->d_name);
                    			//lstat (name, &inode);// test the type of file
                   					printf("%s/%s\n",dirName, dirEntry->d_name);
                   				}
                				
                			}
                		}
                    }
                }
}

static void list_dir (char * dir_name,char *nume_inceput, bool validare_nume, long  size_fl, bool validare_size)
{
    DIR * d;
    int n;
    char name[1000];
    d = opendir (dir_name);/* deschidem directoru specificat de "dir_name". */

    if (! d) 
    {      /* verificam daca i deschis */
        fprintf (stderr, "Cannot open directory '%s': %s\n",
                 dir_name, strerror (errno));
        exit (EXIT_FAILURE);
    }

    while (1)
     {
        struct dirent * entry;
        char * d_name;

        entry = readdir (d);        /* "Readdir" primeste urm intrari din "d". */
        if (! entry)
        {
            break;             /* nu sunt mai multe intrari de ci break */
        }

        d_name = entry->d_name;
		if (strcmp (d_name, "..") != 0 && strcmp (d_name, ".") != 0)    /* afisam fisierul si directorul. */
		{
			if(validare_nume == true && validare_size == false)
            {
                //printf("\nintra in validare1\n");
                if(strstr(d_name, nume_inceput ))
                {
                //printf("\nintra in validare\n");
                	printf ("%s/%s\n", dir_name, d_name);
                }
            }
            if(validare_nume == false && validare_size == false)
            {
                //printf("\nintra in validare1\n");
                
                //printf("\nintra in validare\n");
                	printf ("%s/%s\n", dir_name, d_name);
                
            }
            if(validare_size == true)
            {
            	//printf("\nintra in validare222\n");

				sprintf(name,"%s/%s",dir_name,d_name);
                if( ( isDirectory(name) == 0 ))
                {
                				
             		sprintf(name,"%s/%s",dir_name,d_name);
                	n = numara(name);
                	//printf("\n%d\n",n);
                	if(n < size_fl)
                	{
                		//printf("\nsize for dir222:%ld\n",size_for(name));
                		//printf("\nintra in validare222\n");
                		//sprintf(name,"%s/%s",dirName,dirEntry->d_name);
                		//lstat (name, &inode);// test the type of file
                		printf("%s/%s\n",dir_name, d_name);
                	}
                				
           		}
                				
                //}
                //printf ("%s/%s\n", dir_name, d_name);
                
            }
			
		}
		int ok = 0;
  		if (entry->d_type & DT_DIR) {
			if (strcmp (d_name, "..") != 0 && strcmp (d_name, ".") != 0 && ok == 0)/* verif daca direct nu e d sau d parinte */
			{
                int path_length;
                char path[PATH_MAX];
                path_length = snprintf (path, PATH_MAX,"%s/%s", dir_name, d_name);


                if (path_length >= PATH_MAX)
                {
                    fprintf (stderr, "Path length has got too long.\n");
                    exit (EXIT_FAILURE);
                }
				ok = 1;
				if(validare_nume == false && validare_size == false)
            	{
            		list_dir (path,"", false, 0, false);         /* apelam recursiv list_dir cu noua cale */
            	}
            	if(validare_nume == true && validare_size == false)
            	{
            		list_dir (path, nume_inceput, true, 0, false);         /* apelam recursiv list_dir cu noua cale */
            	}
            	if(validare_nume == false && validare_size == true)
            	{
            		list_dir (path, "", false, size_fl, true);         /* apelam recursiv list_dir cu noua cale */
            	}

				ok = 1;
            }
	}
    }
    /* dupa ce trecem prin toate intrarile inchidem directorul */
    if (closedir (d)) {
        fprintf (stderr, "Could not close '%s': %s\n", dir_name, strerror (errno));
        exit (EXIT_FAILURE);
    }
}
//int D_NR_OF_SECTIONS = 0;
void parse_corupt(char *path)
{
    int f = open(path, O_RDONLY);
    int version = 0;
    char buffer;
    char SECT_NAME[17];
    int SECT_TYPE;
    int HEADER_SIZE;
    int NR_OF_SECTIONS = 0;
    int lungime;
    int ct = 17;

    if(f < 0)
    {
        printf("\nEroare la deschiderea fisierului");
        exit(1);
    }
    
    
    lseek(f, 0, SEEK_SET);
    read(f, &buffer, 1);
        // printf("\nmagic-->%c",buffer);

    if(buffer != '0')
    {
        printf("ERROR\n");
        printf("wrong magic\n");
        goto exit_prog;
    }
    lseek(f, 1, SEEK_CUR);
    read(f, &HEADER_SIZE, 2);
    //printf("\nsize-->%d",HEADER_SIZE);

    lseek(f, 3, SEEK_SET);
    read(f, &version, 2);
    // printf("\nversion-->%d",version);
    if( version > 225 || version < 125 )
    {
        printf("ERROR\n");
        printf("wrong version\n");
        goto exit_prog;
    }

    read(f, &NR_OF_SECTIONS, 1);
    // printf("\nns-->%d",NR OF SECTIONS);

    if( NR_OF_SECTIONS > 18 || NR_OF_SECTIONS < 3 )
    {
        printf("ERROR\n");
        printf("wrong sect_nr\n");
        goto exit_prog;
    }

    lungime = lseek(f, 0, SEEK_CUR);
              
    for(int i = 0; i < NR_OF_SECTIONS; i ++)
    {
        lseek(f, ct, SEEK_CUR);
        read(f, &SECT_TYPE, 1);
        //printf("\ntype-->%d",SECT_TYPE);
                       
        if((SECT_TYPE == 57 || SECT_TYPE == 64 || SECT_TYPE == 50 || SECT_TYPE == 67) == 0)
        {
        	printf("ERROR\n");
        	printf("wrong sect_types\n");
            goto exit_prog;
        }
        lseek(f, 8, SEEK_CUR);// sect offset+ set size
    }
     
    printf("SUCCESS\n");
    printf("version=%d\n", version);
    printf("nr_sections=%d\n", NR_OF_SECTIONS);
    lseek(f, lungime, SEEK_SET);

    for(int i = 1; i <= NR_OF_SECTIONS; i ++)
    {
        int SECT_OFFSET = 0;
        read(f, SECT_NAME, ct);
        read(f, &SECT_TYPE, 1);
        lseek(f, 4, SEEK_CUR);
        read(f, &SECT_OFFSET, 4);
        // printf("\n\noffset--->%d",SECT_OFFSET);
        printf("section%d: %s %d %d\n", i, SECT_NAME, SECT_TYPE, SECT_OFFSET);
                        
    }
    exit_prog:; 
    close(f);
}



void extract_test_from(char *path, int sectionn, int lline)
{
	printf("SUCCESS\n");
	int i = 1;
    int lung_lin=0;
    int aux = 0;
    char buf[1];
	//char path[68] ="test_root/guRm6b6/nmwrQxgRrL/zuXAPmh/dITdzbXol/p6Yo/odRn/jD5qEJ2.dhD";
	 	//printf("---------------aici -1");

	int SECT_OFFSET = 0, SECT_SIZE = 0;
	 	//printf("---------------aici0");

 	int f = open(path, O_RDONLY);
 	if(f < 0)
    {
        printf("\nEroare la deschiderea fisierului");
        exit(1);
    }
		//lseek(f, 0, SEEK_SET);
	lseek(f, 6, SEEK_SET);
 	//printf("---------------aici");
	
		 //printf("---------------aici2");
		//printf("\nsection%d", i);

		lseek(f, (26*(sectionn -1)), SEEK_CUR);


	 	//printf("---------------aici3");

	lseek(f, 18, SEEK_CUR);
	 	//printf("---------------aici4");
    //int type;
	//read(f, &type, 1);
	//	 	printf("\ntypet%d", type);
	
	read(f, &SECT_OFFSET, 4);
	 	//printf("---------------aici5");
			 //printf("\noffset%d", SECT_OFFSET);
	read(f, &SECT_SIZE, 4);
	 //	printf("---------------aici6");
	//printf("\nsect size%d", SECT_SIZE);
	

	//lseek(f, SECT_OFFSET, SEEK_SET);
	 //	printf("---------------aici7");

	//lseek(f, (SECT_SIZE ), SEEK_SET);
	 //printf("---------------aici8");
	lseek(f, SECT_OFFSET, SEEK_SET);
	
    while(i <= lline)
    {
        read(f,&buf,1);
        aux ++;
        if(i == lline){
        printf("%c", buf[0]);}
        if (strcmp(buf, "\n") == 0)
        {
        	//printf("\n%d\n",k);
        	//printf("\n%d\n",kk);
            i++;
            lung_lin = aux;
            aux = 0;
        }

    }
        lseek(f,-2,SEEK_CUR);
        for(int j = 0; j < lung_lin; j++)
        {
            read(f, &buf, 1);
            printf("%c", buf[0]);
            lseek(f, -1, SEEK_CUR);
        }
close(f);
}

int main(int argc, char **argv)
{
	if(argc >= 2)
	{
        if(strstr(argv[1], "variant"))
        {
		printf("13735\n");
        }

		if(strstr(argv[1], "list"))
		{
			int path = 0, recursiv = 0, parametru_s = 0, parametru_n = 0, i = 2;
			while(i < argc)
			{
				if (strncmp(argv[i], "path=", 5) == 0)
				{
					path = i;
				}
				else
				{
					if(strcmp(argv[i], "recursive") == 0)
					{
						recursiv = i;
						                   // printf("RECURSIVV%d\n",recursiv);

					}
					else
					{
						if(strncmp(argv[i], "size_smaller=", 13) == 0 )
						{
							parametru_s = i;
						}
						else
						{
							if(strncmp(argv[i], "name_starts_with=", 17) == 0)
							{
								parametru_n = i;
							 // printf("PARAMETRU N------------%d\n",parametru_n);


							}
						}
					}
					
				}
			i ++;
			}
			struct stat fileMetadata;
			if(stat(argv[path] + 5, &fileMetadata) < 0)
			{
			printf("ERROR\ninvalid directory path\n");
			}
			else
            {
                if( recursiv == 0 && parametru_s == 0 && parametru_n == 0)
                {
                    printf("SUCCESS\n");
                    char pathh[1000] = "";
                    strcpy(pathh, argv[path] + 5);
					//printf("\n %s\n", argv[path]);
					//printf("\n pathh %s\n", pathh);
					listDir(pathh,"", false, 0, false);
                
                }
                if( recursiv != 0 && parametru_s == 0 && parametru_n == 0)
                {
                    printf("SUCCESS\n");
                    char pathh[1000] = "";
                    strcpy(pathh, argv[recursiv + 1] + 5);
					//printf("\n %s\n", pathh);
					list_dir (pathh,"", false, 0, false);
                }
                if( recursiv == 0 && parametru_s == 0 && parametru_n != 0)
                {
               		printf("SUCCESS\n");
                	char pathh[1000] = "";
                	char pathh2[1000] = "";
                    strcpy(pathh, argv[path] + 5);
                    strcpy(pathh2, argv[parametru_n] + 17);
                    //printf("\n pathh2 %s\n", pathh2);

                    listDir(pathh, pathh2, true, 0, false);

                }
                if( recursiv != 0 && parametru_s == 0 && parametru_n != 0)
                {
                	printf("SUCCESS\n");
                	char pathh[1000] = "";
                	char pathh2[1000] = "";
                    strcpy(pathh, argv[recursiv + 1] + 5);
                    strcpy(pathh2, argv[parametru_n] + 17);
                   // printf("\n pathh %s\n", pathh);
                   // printf("\n pathh2 %s\n", pathh2);


                    list_dir(pathh, pathh2, true, 0, false);

                }
                if( recursiv == 0 && parametru_s != 0 && parametru_n == 0)
                {
                	printf("SUCCESS\n");
                	char pathh[1000] = "";
                	char pathh2[1000] = "";
                    strcpy(pathh, argv[path] + 5);
                    strcpy(pathh2, argv[parametru_s] + 13);
                   // printf("\n pathh %s\n", pathh);
                    //printf("\n pathh2 %s\n", pathh2);
                    long  size = atoi(pathh2);
                    //printf("\n size este %li\n", size);



                    listDir(pathh, "", false, size, true);

                }
                if( recursiv != 0 && parametru_s != 0 && parametru_n == 0)
                {
                	printf("SUCCESS\n");
                	char pathh[1000] = "";
                	char pathh2[1000] = "";
                    strcpy(pathh, argv[path] + 5);
                    strcpy(pathh2, argv[parametru_s] + 13);
                   // printf("\n pathh %s\n", pathh);
                    //printf("\n pathh2 %s\n", pathh2);
                    long  size = atoi(pathh2);
                   // printf("\n size este %li\n", size);



                    list_dir(pathh, "", false, size, true);

                }



            }
		}
		if(strstr(argv[1], "parse"))
		{
			int path = 0, i = 2;
			while(i < argc)
			{
				if (strncmp(argv[i], "path=", 5) == 0)
				{
					path = i;
				}
				 //printf("SUCCESS\n");
				char *pathh = argv[path]+5;
				//printf("\n%s\n", pathh);
				parse_corupt(pathh);
				i++;
    		}

		}

		if(strstr(argv[1], "extract"))
		{
			int path = 0, section =0, line = 0, i = 2;
			while(i < argc)
			{
				if (strncmp(argv[i], "path=", 5) == 0)
				{
					path = i;
				}
				else
				{
					if (strncmp(argv[i], "section=", 8) == 0)
					{
						section = i;
					}
					else
					{
						if (strncmp(argv[i], "line=", 5) == 0)
						{
							line = i;
						}
					}
				}

				i++;
    		}
    		//printf("\npath--> %d\n", path);
    		//printf("\nsection---> %d\n", section);
    		//printf("\nline--> %d\n", line);
    		//printf("SUCCESS\n");
            char *pathh =  argv[path] + 5;
            int aux_section = atoi(argv[section] + 8);
            int aux_line = atoi(argv[line] + 5);

            //printf("\nsection---> %d\n", aux_section);
            //printf("\nsection---> %d\n", aux_line);

           // strcpy(pathh,;
           // printf("\n%s\n", pathh);
            extract_test_from(pathh, aux_section, aux_line);
            //printf("------------");
            printf("\n");

		}
	}


return 0;
}
/*
 
    [
        "extract_6", 
        [
            "extract", 
            "path=test_root/guRm6b6/nmwrQxgRrL/zuXAPmh/jYS1rf/gALT5snf.2Rt", 
            "section=10", 
            "line=14"
        ], 
        4, 
        [
            "SUCCESS", 
            "TQyeh7l7TiC0ErV1VO2lFrjR53PrPUPfnOAFuG4dWt2Q9QKxP33SEKXh0yog32WveJYVMboaXSfSROSBzlMojeLOaK3WOqfFpO1"
       
        ], */