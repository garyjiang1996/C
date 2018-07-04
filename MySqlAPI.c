#include <stdio.h>
#include "C:\Program Files\MySQL\MySQL Server 8.0\include\mysql.h"

int main(){
	MYSQL *mysql;
	MYSQL_RES *res;
	MYSQL_ROW *row;
	
	if(mysql_init(mysql)==NULL){
		fprintf(stderr,"can't initialize mysql");
		return 1;
	}
	if(!mysql_real_connect(mysql,"localhost","public_api"),
		"123","db1",0,NULL,0){
		fprintf(stderr,"%d:%s\n",mysql_errno(mysql),mysql_error(mysql));
		return 1;
	}
	if(mysql_query(mysql,"SELECT common_name, scientific_name FROM birds")){
		fprintf(stderr,"%d:%s\n",mysql_erron(mysql),mysqsl_error(mysql));
	}else{
		result=mysql_store_result(mysql);
		
		while(row=mysql_fetch_row(result)){
			printf("%s - \%s \n",row[0],row[1]);
		}
		mysql_free_result(result);
	}
	mysql_close(mysql);
	return 0;
}