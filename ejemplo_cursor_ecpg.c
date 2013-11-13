#include <stdio.h>

 EXEC SQL BEGIN DECLARE SECTION;
   short int asistente_id;
   char asistente_nya[250];
   short nya_ind=0;

 EXEC SQL END DECLARE SECTION;

 EXEC SQL WHENEVER SQLERROR   SQLPRINT;
 EXEC SQL WHENEVER SQLWARNING SQLPRINT;
 EXEC SQL WHENEVER NOT FOUND  SQLPRINT;



main()
{

 EXEC SQL CONNECT TO pgday@127.0.0.1:5432 USER postgres;

 if (sqlca.sqlcode!=0)
 {
   printf("TIPO DE ERROR: %d\n", sqlca.sqlcode);
   printf("MENSAJE:%s\n", sqlca.sqlerrm.sqlerrmc);
 }

 EXEC SQL DECLARE cursor_asistentes CURSOR FOR SELECT * FROM asistentes;
 
 EXEC SQL WHENEVER NOT FOUND DO BREAK;

 EXEC SQL OPEN cursor_asistentes;

 while(1)
 {
    EXEC SQL FETCH FROM cursor_asistentes INTO :asistente_id, :asistente_nya :nya_ind;
  //  if( sqlca.sqlcode != 100 )
        printf("Valor del indicador %d\n",nya_ind);
        if (nya_ind < 0) strcpy(asistente_nya,"NULO\0");

 	printf("ID del asistente %d - Apellido y nombre  %s\n", asistente_id, asistente_nya);

   // else
//	break;

 }	
 
 EXEC SQL CLOSE cursor_asistentes;
 EXEC SQL DISCONNECT ALL;



}
