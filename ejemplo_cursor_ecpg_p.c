/* Processed by ecpg (4.7.0) */
/* These include files are added by the preprocessor */
#include <ecpglib.h>
#include <ecpgerrno.h>
#include <sqlca.h>
/* End of automatic include section */

#line 1 "ejemplo_cursor_ecpg.c"
#include <stdio.h>

 /* exec sql begin declare section */
     
    
    

 
#line 4 "ejemplo_cursor_ecpg.c"
 short asistente_id ;
 
#line 5 "ejemplo_cursor_ecpg.c"
 char asistente_nya [ 250 ] ;
 
#line 6 "ejemplo_cursor_ecpg.c"
 short nya_ind = 0 ;
/* exec sql end declare section */
#line 8 "ejemplo_cursor_ecpg.c"


 /* exec sql whenever sqlerror  sqlprint ; */
#line 10 "ejemplo_cursor_ecpg.c"

 /* exec sql whenever sql_warning  sqlprint ; */
#line 11 "ejemplo_cursor_ecpg.c"

 /* exec sql whenever not found  sqlprint ; */
#line 12 "ejemplo_cursor_ecpg.c"




main()
{

 { ECPGconnect(__LINE__, 0, "pgday@127.0.0.1:5432" , "postgres" , NULL , NULL, 0); 
#line 19 "ejemplo_cursor_ecpg.c"

if (sqlca.sqlwarn[0] == 'W') sqlprint();
#line 19 "ejemplo_cursor_ecpg.c"

if (sqlca.sqlcode < 0) sqlprint();}
#line 19 "ejemplo_cursor_ecpg.c"


 if (sqlca.sqlcode!=0)
 {
   printf("TIPO DE ERROR: %d\n", sqlca.sqlcode);
   printf("MENSAJE:%s\n", sqlca.sqlerrm.sqlerrmc);
 }

 /* declare cursor_asistentes cursor for select * from asistentes */
#line 27 "ejemplo_cursor_ecpg.c"

 
 /* exec sql whenever not found  break ; */
#line 29 "ejemplo_cursor_ecpg.c"


 { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare cursor_asistentes cursor for select * from asistentes", ECPGt_EOIT, ECPGt_EORT);
#line 31 "ejemplo_cursor_ecpg.c"

if (sqlca.sqlwarn[0] == 'W') sqlprint();
#line 31 "ejemplo_cursor_ecpg.c"

if (sqlca.sqlcode < 0) sqlprint();}
#line 31 "ejemplo_cursor_ecpg.c"


 while(1)
 {
    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch from cursor_asistentes", ECPGt_EOIT, 
	ECPGt_short,&(asistente_id),(long)1,(long)1,sizeof(short), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(asistente_nya),(long)250,(long)1,(250)*sizeof(char), 
	ECPGt_short,&(nya_ind),(long)1,(long)1,sizeof(short), ECPGt_EORT);
#line 35 "ejemplo_cursor_ecpg.c"

if (sqlca.sqlcode == ECPG_NOT_FOUND) break;
#line 35 "ejemplo_cursor_ecpg.c"

if (sqlca.sqlwarn[0] == 'W') sqlprint();
#line 35 "ejemplo_cursor_ecpg.c"

if (sqlca.sqlcode < 0) sqlprint();}
#line 35 "ejemplo_cursor_ecpg.c"

  //  if( sqlca.sqlcode != 100 )
        printf("Valor del indicador %d\n",nya_ind);
        if (nya_ind < 0) strcpy(asistente_nya,"NULO\0");

 	printf("ID del asistente %d - Apellido y nombre  %s\n", asistente_id, asistente_nya);

   // else
//	break;

 }	
 
 { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close cursor_asistentes", ECPGt_EOIT, ECPGt_EORT);
#line 47 "ejemplo_cursor_ecpg.c"

if (sqlca.sqlwarn[0] == 'W') sqlprint();
#line 47 "ejemplo_cursor_ecpg.c"

if (sqlca.sqlcode < 0) sqlprint();}
#line 47 "ejemplo_cursor_ecpg.c"

 { ECPGdisconnect(__LINE__, "ALL");
#line 48 "ejemplo_cursor_ecpg.c"

if (sqlca.sqlwarn[0] == 'W') sqlprint();
#line 48 "ejemplo_cursor_ecpg.c"

if (sqlca.sqlcode < 0) sqlprint();}
#line 48 "ejemplo_cursor_ecpg.c"




}
