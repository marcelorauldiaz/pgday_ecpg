/* Processed by ecpg (4.7.0) */
/* These include files are added by the preprocessor */
#include <ecpglib.h>
#include <ecpgerrno.h>
#include <sqlca.h>
/* End of automatic include section */

#line 1 "ejemplo_ecpg.c"
#include <stdio.h>

 /* exec sql begin declare section */
     
    

 
#line 4 "ejemplo_ecpg.c"
 short asistente_id ;
 
#line 5 "ejemplo_ecpg.c"
 char asistente_nya [ 250 ] ;
/* exec sql end declare section */
#line 7 "ejemplo_ecpg.c"


 /* exec sql whenever sqlerror  sqlprint ; */
#line 9 "ejemplo_ecpg.c"

 /* exec sql whenever sql_warning  sqlprint ; */
#line 10 "ejemplo_ecpg.c"

 /* exec sql whenever not found  sqlprint ; */
#line 11 "ejemplo_ecpg.c"




main()
{

 { ECPGconnect(__LINE__, 0, "pgday@127.0.0.1:5432" , "postgres" , NULL , "con1", 0); 
#line 18 "ejemplo_ecpg.c"

if (sqlca.sqlwarn[0] == 'W') sqlprint();
#line 18 "ejemplo_ecpg.c"

if (sqlca.sqlcode < 0) sqlprint();}
#line 18 "ejemplo_ecpg.c"


 if (sqlca.sqlcode!=0)
 {
   printf("TIPO DE ERROR: %d\n", sqlca.sqlcode);
   printf("MENSAJE:%s\n", sqlca.sqlerrm.sqlerrmc);
 }

 { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select id , nya from asistentes where id = 2", ECPGt_EOIT, 
	ECPGt_short,&(asistente_id),(long)1,(long)1,sizeof(short), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(asistente_nya),(long)250,(long)1,(250)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 26 "ejemplo_ecpg.c"

if (sqlca.sqlcode == ECPG_NOT_FOUND) sqlprint();
#line 26 "ejemplo_ecpg.c"

if (sqlca.sqlwarn[0] == 'W') sqlprint();
#line 26 "ejemplo_ecpg.c"

if (sqlca.sqlcode < 0) sqlprint();}
#line 26 "ejemplo_ecpg.c"


 printf("ID del asistente %d - Apellido y nombre  %s\n", asistente_id, asistente_nya);


 { ECPGdisconnect(__LINE__, "ALL");
#line 31 "ejemplo_ecpg.c"

if (sqlca.sqlwarn[0] == 'W') sqlprint();
#line 31 "ejemplo_ecpg.c"

if (sqlca.sqlcode < 0) sqlprint();}
#line 31 "ejemplo_ecpg.c"




}
