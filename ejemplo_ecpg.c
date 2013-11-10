#include <stdio.h>

 EXEC SQL BEGIN DECLARE SECTION;
   short int asistente_id;
   char asistente_nya[250];

 EXEC SQL END DECLARE SECTION;

 EXEC SQL WHENEVER SQLERROR   SQLPRINT;
 EXEC SQL WHENEVER SQLWARNING SQLPRINT;
 EXEC SQL WHENEVER NOT FOUND  SQLPRINT;



main()
{

 EXEC SQL CONNECT TO pgday@127.0.0.1:5432 AS con1 USER postgres;

 if (sqlca.sqlcode!=0)
 {
   printf("TIPO DE ERROR: %d\n", sqlca.sqlcode);
   printf("MENSAJE:%s\n", sqlca.sqlerrm.sqlerrmc);
 }

 EXEC SQL SELECT id,nya INTO :asistente_id, :asistente_nya from asistentes where id=2;

 printf("ID del asistente %d - Apellido y nombre  %s\n", asistente_id, asistente_nya);


 EXEC SQL DISCONNECT ALL;



}
