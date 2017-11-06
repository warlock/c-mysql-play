#include <mysql/mysql.h>
#include <stdio.h>

int main()
{
	MYSQL *conn;
	MYSQL_RES *res;
	MYSQL_ROW row;
	char *server = "server";
	char *user = "user";
	char *password = "password";
	char *database = "database";
	conn = mysql_init(NULL);

	if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
	{
		fprintf(stderr, "%s\n", mysql_error(conn));
		return(1);
	}

	if (mysql_query(conn, "select c_noticia, titular from noticia"))
	{
		fprintf(stderr, "%s\n", mysql_error(conn));
		return(1);
	}

	res = mysql_use_result(conn);
	printf("c_noticia\ttitular\t\fecha\n");
	while ((row = mysql_fetch_row(res)) != NULL)
		printf("%s\t%s\n", row[0],row[1]);

	mysql_free_result(res);
	mysql_close(conn);
	return (0);
}