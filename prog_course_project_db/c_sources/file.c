#include "database.h"

void save_file()
{
	// ���������������� ����
	int i, temp;
	char filename[255], mode[255];
	system("cls");

	// ����� ������������� ����� ����� � ������
	printf("\n\t������� ��� ����� -> ");
	scanf("%s", filename);
	printf("\n");

	printf("\t�� ������ ������� ������ �� ����� ����� (0 - ��, 1 - ���) -> ");
	scanf("%d", &temp);
	printf("\n\n");
	if( temp == 0 )
		strcpy(mode, "w");
	else
		strcpy(mode, "a+");

	// �������� �����
	if( ( f = fopen(filename, mode) ) == NULL )
	{
		fprintf(stderr, "������: ���������� ������� ���� %s\n", filename);
		return;
	}

	// ������ � ���� ������ ������ �������
	for (i = 0; i < table_row[EMPLOYEE_TABLE]; ++i)
		if( employee_table[i].employee_id > 0 )
		{
			// ���������� ���� �������
			fputs("0;", f);
			// ���������� ���� ����������
			fprintf(f, "%d", employee_table[i].employee_id);
			fputc(';', f);
			// ���������� ���� ���������
			fprintf(f, "%d", employee_table[i].position_id);
			fputc(';', f);
			// ���������� ���
			fputs(employee_table[i].name, f);
			fputc(';', f);
			// ���������� ��������
			fprintf(f, "%d", employee_table[i].age);
			fputc(';', f);
			// ���������� ����
			if( employee_table[i].gender == male )
				fputc('0', f);
			else
				fputc('1', f);
			fputc(';', f);
			// ���������� ������
			fputs(employee_table[i].address, f);
			fputc(';', f);
			// ���������� ��������
			fputs(employee_table[i].phone, f);
			fputc(';', f);
			// ���������� ���������� ������
			fputs(employee_table[i].passport, f);
			fputc('\n', f);
		}

	for (i = 0; i < table_row[POSITION_TABLE]; ++i)
		if( position_table[i].position_id > 0 )
		{
			// ���������� ���� �������
			fputs("1;", f);
			// ���������� ���� ���������
			fprintf(f, "%d", position_table[i].position_id);
			fputc(';', f);
			// ���������� ������������
			fputs(position_table[i].name, f);
			fputc(';', f);
			// ���������� ������
			fprintf(f, "%d", position_table[i].salary);
			fputc(';', f);
			// ���������� ������������
			fputs(position_table[i].duties, f);
			fputc(';', f);
			// ���������� ����������
			fputs(position_table[i].requirements, f);
			fputc('\n', f);
		}

	for (i = 0; i < table_row[BRAND_TABLE]; ++i)
		if( brand_table[i].brand_id > 0 )
		{
			// ���������� ���� �������
			fputs("2;", f);
			// ���������� ���� �����
			fprintf(f, "%d", brand_table[i].brand_id);
			fputc(';', f);
			// ���������� ������������
			fputs(brand_table[i].name, f);
			fputc(';', f);
			// ���������� ����������� �������������
			fputs(brand_table[i].specs, f);
			fputc(';', f);
			// ���������� ��������
			fputs(brand_table[i].description, f);
			fputc('\n', f);
		}

	for (i = 0; i < table_row[SERVICE_TABLE]; ++i)
		if( service_table[i].service_id > 0 )
		{
			// ���������� ���� �������
			fputs("3;", f);
			// ���������� ���� ������
			fprintf(f, "%d", service_table[i].service_id);
			fputc(';', f);
			// ���������� ������������
			fputs(service_table[i].name, f);
			fputc(';', f);
			// ���������� ��������
			fputs(service_table[i].description, f);
			fputc(';', f);
			// ���������� ����
			fprintf(f, "%d", service_table[i].price);
			fputc('\n', f);
		}

	for (i = 0; i < table_row[CAR_TABLE]; ++i)
		if( car_table[i].car_id > 0 )
		{
			// ���������� ���� �������
			fputs("4;", f);
			// ���������� ���� ����������
			fprintf(f, "%d", car_table[i].car_id);
			fputc(';', f);
			// ���������� ���� �����
			fprintf(f, "%d", car_table[i].brand_id);
			fputc(';', f);
			// ���������� ���� ����������-��������
			fprintf(f, "%d", car_table[i].employee_id);
			fputc(';', f);
			// ���������� ���������������� ������
			fprintf(f, "%d", car_table[i].reg_number);
			fputc(';', f);
			// ���������� ������ ������
			fprintf(f, "%d", car_table[i].body_number);
			fputc(';', f);
			// ���������� ������ ���������
			fprintf(f, "%d", car_table[i].engine_number);
			fputc(';', f);
			// ���������� ���� �������
			fprintf(f, "%d", car_table[i].release_year);
			fputc(';', f);
			// ���������� �������
			fprintf(f, "%d", car_table[i].mileage);
			fputc(';', f);
			// ���������� ���� ����������
			fprintf(f, "%d", car_table[i].price);
			fputc(';', f);
			// ���������� ���� ��� ������� ����������
			fprintf(f, "%d", car_table[i].rent_price);
			fputc(';', f);
			// ���������� ��� ���� ���������� ��
			fprintf(f, "%d", car_table[i].maintenance_date.day);
			fputc(';', f);
			// ���������� ������ ���� ���������� ��
			fprintf(f, "%d", car_table[i].maintenance_date.month);
			fputc(';', f);
			// ���������� ���� ���� ���������� ��
			fprintf(f, "%d", car_table[i].maintenance_date.year);
			fputc(';', f);
			// ���������� ����������� �������
			fputs(car_table[i].special_marks, f);
			fputc(';', f);
			// ���������� ����������� �������
			fputs(car_table[i].return_mark, f);
			fputc('\n', f);
		}

	for (i = 0; i < table_row[CLIENT_TABLE]; ++i)
		if( client_table[i].client_id > 0 )
		{
			// ���������� ���� �������
			fputs("5;", f);
			// ���������� ���� ����������
			fprintf(f, "%d", client_table[i].client_id);
			fputc(';', f);
			// ���������� ���
			fputs(client_table[i].name, f);
			fputc(';', f);
			// ���������� ����
			if( client_table[i].gender == male )
				fputc('0', f);
			else
				fputc('1', f);
			fputc(';', f);
			// ���������� ��� ���� ��������
			fprintf(f, "%d", client_table[i].birth_date.day);
			fputc(';', f);
			// ���������� ������ ���� ��������
			fprintf(f, "%d", client_table[i].birth_date.month);
			fputc(';', f);
			// ���������� ���� ���� ��������
			fprintf(f, "%d", client_table[i].birth_date.year);
			fputc(';', f);
			// ���������� ������
			fputs(client_table[i].address, f);
			fputc(';', f);
			// ���������� ��������
			fputs(client_table[i].phone, f);
			fputc(';', f);
			// ���������� ���������� ������
			fputs(client_table[i].passport, f);
			fputc('\n', f);
		}

	for (i = 0; i < table_row[RENT_TABLE]; ++i)
		if( rent_table[i].car_id > 0 )
		{
			// ���������� ���� �������
			fputs("6;", f);
			// ���������� ���� ����������
			fprintf(f, "%d", rent_table[i].car_id);
			fputc(';', f);
			// ���������� ���� �������
			fprintf(f, "%d", rent_table[i].client_id);
			fputc(';', f);
			// ���������� ���� ����������
			fprintf(f, "%d", rent_table[i].employee_id);
			fputc(';', f);
			// ���������� ���� ������ 1
			fprintf(f, "%d", rent_table[i].service1_id);
			fputc(';', f);
			// ���������� ���� ������ 2
			fprintf(f, "%d", rent_table[i].service2_id);
			fputc(';', f);
			// ���������� ���� ������ 3
			fprintf(f, "%d", rent_table[i].service3_id);
			fputc(';', f);
			// ���������� ��� ���� ������
			fprintf(f, "%d", rent_table[i].delivery_date.day);
			fputc(';', f);
			// ���������� ������ ���� ������
			fprintf(f, "%d", rent_table[i].delivery_date.month);
			fputc(';', f);
			// ���������� ���� ���� ������
			fprintf(f, "%d", rent_table[i].delivery_date.year);
			fputc(';', f);
			// ���������� ����� �������
			fprintf(f, "%d", rent_table[i].rent_time);
			fputc(';', f);
			// ���������� ��� ���� ��������
			fprintf(f, "%d", rent_table[i].return_date.day);
			fputc(';', f);
			// ���������� ������ ���� ��������
			fprintf(f, "%d", rent_table[i].return_date.month);
			fputc(';', f);
			// ���������� ���� ���� ��������
			fprintf(f, "%d", rent_table[i].return_date.year);
			fputc(';', f);
			// ���������� ���� �������
			fprintf(f, "%d", rent_table[i].rent_price);
			fputc(';', f);
			// ���������� ������� �� ������
			fputs(rent_table[i].payment_mark, f);
			fputc('\n', f);
		}

	fclose(f);
}

void load_file()
{
	/*
	 * ���������������� ����
	 */ 
	int i;
	int *line_char_count;
	int line_count = 0;
	int gone_through = 0;
	char c;
	char buffer[4096];	// ����� ��� ���������� ������
	char filename[255];	// ��� �����
	char *token;		// ����� ��� ������
	int i_token;		// ������������� �����

	activated = 1;
	for (i = 0; i < 7; ++i, table_row[i] = 0);
	system("cls");

	// ����� ������������� ����� ����� � ������
	printf("\n\t������� ��� ����� -> ");
	scanf("%s", filename);
	printf("\n");

	// �������� �����
	if( ( f = fopen(filename, "r") ) == NULL )
	{
		fprintf(stderr, "������: ���������� ������� ���� %s\n", filename);
		return;
	}
	rewind(f);

	// ������� ���������� ����� � �����
	while ( ( c = fgetc(f) ) != EOF )
		if( c == '\n' )
		{
			line_count++;
			continue;
		}

	line_char_count = (int *) calloc( line_count, sizeof(int) );
	rewind(f);

	// ������� ���������� �������� � ������ ������
	i = 0;
	while ( ( c = fgetc(f) ) != EOF )
	{
		if( c == '\n' )
		{
			i++;
			continue;
		}
		line_char_count[i]++;
	}
	rewind(f);

	printf("\tline_count: %d\n", line_count);
	printf("\tline_char_count[0]: %d\n", line_char_count[0]);
	printf("\tline_char_count[1]: %d\n", line_char_count[1]);

	/*
	 * ���������� �����
	 */
	for (i = 0; i < line_count; ++i)
	{
		fgets( buffer, line_char_count[i], f );
		gone_through += line_char_count[i] + 2;
		fseek( f, gone_through, SEEK_SET );

		printf("Buffer: %s\n", buffer);
		token = strtok( buffer, ";" );
		i_token = atoi(token);
		
		switch (i_token) 
		{
			case (EMPLOYEE_TABLE):
				// ��������� ������
				employee_table = realloc( employee_table, sizeof(employee_struct)*(table_row[EMPLOYEE_TABLE]+1) );
				
				// ���������� �����
				token = strtok( NULL, ";" );
				employee_table[ table_row[EMPLOYEE_TABLE] ].employee_id = atoi(token);
				if( employee_table[ table_row[EMPLOYEE_TABLE] ].employee_id < 0 )
					break;
				token = strtok( NULL, ";" );
				employee_table[ table_row[EMPLOYEE_TABLE] ].position_id = atoi(token);
				token = strtok( NULL, ";" );
				strcpy( employee_table[ table_row[EMPLOYEE_TABLE] ].name, token );
				token = strtok( NULL, ";" );
				employee_table[ table_row[EMPLOYEE_TABLE] ].age = atoi(token);
				token = strtok( NULL, ";" ); i_token = atoi(token);
				employee_table[ table_row[EMPLOYEE_TABLE] ].gender = i_token ? female : male;
				token = strtok( NULL, ";" );
				strcpy( employee_table[ table_row[EMPLOYEE_TABLE] ].address, token );
				token = strtok( NULL, ";" );
				strcpy( employee_table[ table_row[EMPLOYEE_TABLE] ].phone, token );
				token = strtok( NULL, ";" );
				strcpy( employee_table[ table_row[EMPLOYEE_TABLE] ].passport, token );

				// ����������� �������� ������� �������
				table_row[EMPLOYEE_TABLE]++;
				break;

			case (POSITION_TABLE):
				// ��������� ������
				position_table = realloc( position_table, sizeof(position_struct)*(table_row[POSITION_TABLE]+1) );
				
				// ���������� �����
				token = strtok( NULL, ";" );
				position_table[ table_row[POSITION_TABLE] ].position_id = atoi(token);
				if( position_table[ table_row[POSITION_TABLE] ].position_id < 0 )
					break;
				token = strtok( NULL, ";" );
				strcpy( position_table[ table_row[POSITION_TABLE] ].name, token );
				token = strtok( NULL, ";" );
				position_table[ table_row[POSITION_TABLE] ].salary = atoi(token);
				token = strtok( NULL, ";" );
				strcpy( position_table[ table_row[POSITION_TABLE] ].duties, token );
				token = strtok( NULL, ";" );
				strcpy( position_table[ table_row[POSITION_TABLE] ].requirements, token );

				// ����������� �������� ������� �������
				table_row[POSITION_TABLE]++;
				break;

			case (BRAND_TABLE):
				// ��������� ������
				brand_table = realloc( brand_table, sizeof(brand_struct)*(table_row[BRAND_TABLE]+1) );
				
				// ���������� �����
				token = strtok( NULL, ";" );
				brand_table[ table_row[BRAND_TABLE] ].brand_id = atoi(token);
				if( brand_table[ table_row[BRAND_TABLE] ].brand_id < 0 )
					break;
				token = strtok( NULL, ";" );
				strcpy( brand_table[ table_row[BRAND_TABLE] ].name, token );
				token = strtok( NULL, ";" );
				strcpy( brand_table[ table_row[BRAND_TABLE] ].specs, token );
				token = strtok( NULL, ";" );
				strcpy( brand_table[ table_row[BRAND_TABLE] ].description, token );

				// ����������� �������� ������� �������
				table_row[BRAND_TABLE]++;
				break;

			case (SERVICE_TABLE):
				// ��������� ������
				service_table = realloc( service_table, sizeof(service_struct)*(table_row[SERVICE_TABLE]+1) );
				
				// ���������� �����
				token = strtok( NULL, ";" );
				service_table[ table_row[SERVICE_TABLE] ].service_id = atoi(token);
				if( service_table[ table_row[SERVICE_TABLE] ].service_id < 0 )
					break;
				token = strtok( NULL, ";" );
				strcpy( service_table[ table_row[SERVICE_TABLE] ].name, token );
				token = strtok( NULL, ";" );
				strcpy( service_table[ table_row[SERVICE_TABLE] ].description, token );
				token = strtok( NULL, ";" );
				service_table[ table_row[SERVICE_TABLE] ].price = atoi(token);

				// ����������� �������� ������� �������
				table_row[SERVICE_TABLE]++;
				break;

			case (CAR_TABLE):
				// ��������� ������
				car_table = realloc( car_table, sizeof(car_struct)*(table_row[CAR_TABLE]+1) );
				
				// ���������� �����
				token = strtok( NULL, ";" );
				car_table[ table_row[CAR_TABLE] ].car_id = atoi(token);
				if( car_table[ table_row[CAR_TABLE] ].car_id < 0 )
					break;
				token = strtok( NULL, ";" );
				car_table[ table_row[CAR_TABLE] ].brand_id = atoi(token);
				token = strtok( NULL, ";" );
				car_table[ table_row[CAR_TABLE] ].employee_id = atoi(token);
				token = strtok( NULL, ";" );
				car_table[ table_row[CAR_TABLE] ].reg_number = atoi(token);
				token = strtok( NULL, ";" );
				car_table[ table_row[CAR_TABLE] ].body_number = atoi(token);
				token = strtok( NULL, ";" );
				car_table[ table_row[CAR_TABLE] ].engine_number = atoi(token);
				token = strtok( NULL, ";" );
				car_table[ table_row[CAR_TABLE] ].release_year = atoi(token);
				token = strtok( NULL, ";" );
				car_table[ table_row[CAR_TABLE] ].mileage = atoi(token);
				token = strtok( NULL, ";" );
				car_table[ table_row[CAR_TABLE] ].price = atoi(token);
				token = strtok( NULL, ";" );
				car_table[ table_row[CAR_TABLE] ].rent_price = atoi(token);
				token = strtok( NULL, ";" );
				car_table[ table_row[CAR_TABLE] ].maintenance_date.day = atoi(token);
				token = strtok( NULL, ";" );
				car_table[ table_row[CAR_TABLE] ].maintenance_date.month = atoi(token);
				token = strtok( NULL, ";" );
				car_table[ table_row[CAR_TABLE] ].maintenance_date.year = atoi(token);
				token = strtok( NULL, ";" );
				strcpy( car_table[ table_row[CAR_TABLE] ].special_marks, token );
				token = strtok( NULL, ";" );
				strcpy( car_table[ table_row[CAR_TABLE] ].return_mark, token );

				// ����������� �������� ������� �������
				table_row[CAR_TABLE]++;
				break;

			case (CLIENT_TABLE):
				// ��������� ������
				client_table = realloc( client_table, sizeof(client_struct)*(table_row[CLIENT_TABLE]+1) );
				
				// ���������� �����
				token = strtok( NULL, ";" );
				client_table[ table_row[CLIENT_TABLE] ].client_id = atoi(token);
				if( client_table[ table_row[CLIENT_TABLE] ].client_id < 0 )
					break;
				token = strtok( NULL, ";" );
				strcpy( client_table[ table_row[CLIENT_TABLE] ].name, token );
				token = strtok( NULL, ";" ); i_token = atoi(token);
				client_table[ table_row[CLIENT_TABLE] ].gender = i_token ? female : male;
				token = strtok( NULL, ";" );
				client_table[ table_row[CLIENT_TABLE] ].birth_date.day = atoi(token);
				token = strtok( NULL, ";" );
				client_table[ table_row[CLIENT_TABLE] ].birth_date.month = atoi(token);
				token = strtok( NULL, ";" );
				client_table[ table_row[CLIENT_TABLE] ].birth_date.year = atoi(token);
				token = strtok( NULL, ";" );
				strcpy( client_table[ table_row[CLIENT_TABLE] ].address, token );
				token = strtok( NULL, ";" );
				strcpy( client_table[ table_row[CLIENT_TABLE] ].phone, token );
				token = strtok( NULL, ";" );
				strcpy( client_table[ table_row[CLIENT_TABLE] ].passport, token );

				// ����������� �������� ������� �������
				table_row[CLIENT_TABLE]++;
				break;

			case (RENT_TABLE):
				// ��������� ������
				rent_table = realloc( rent_table, sizeof(rent_struct)*(table_row[RENT_TABLE]+1) );
				
				// ���������� �����
				token = strtok( NULL, ";" );
				rent_table[ table_row[RENT_TABLE] ].car_id = atoi(token);
				if( rent_table[ table_row[RENT_TABLE] ].car_id < 0 )
					break;
				token = strtok( NULL, ";" );
				rent_table[ table_row[RENT_TABLE] ].client_id = atoi(token);
				token = strtok( NULL, ";" );
				rent_table[ table_row[RENT_TABLE] ].employee_id = atoi(token);
				token = strtok( NULL, ";" );
				rent_table[ table_row[RENT_TABLE] ].service1_id = atoi(token);
				token = strtok( NULL, ";" );
				rent_table[ table_row[RENT_TABLE] ].service2_id = atoi(token);
				token = strtok( NULL, ";" );
				rent_table[ table_row[RENT_TABLE] ].service3_id = atoi(token);
				token = strtok( NULL, ";" );
				rent_table[ table_row[RENT_TABLE] ].delivery_date.day = atoi(token);
				token = strtok( NULL, ";" );
				rent_table[ table_row[RENT_TABLE] ].delivery_date.month = atoi(token);
				token = strtok( NULL, ";" );
				rent_table[ table_row[RENT_TABLE] ].delivery_date.year = atoi(token);
				token = strtok( NULL, ";" );
				rent_table[ table_row[RENT_TABLE] ].rent_time = atoi(token);
				token = strtok( NULL, ";" );
				rent_table[ table_row[RENT_TABLE] ].return_date.day = atoi(token);
				token = strtok( NULL, ";" );
				rent_table[ table_row[RENT_TABLE] ].return_date.month = atoi(token);
				token = strtok( NULL, ";" );
				rent_table[ table_row[RENT_TABLE] ].return_date.year = atoi(token);
				token = strtok( NULL, ";" );
				rent_table[ table_row[RENT_TABLE] ].rent_price = atoi(token);
				token = strtok( NULL, ";" );
				strcpy( rent_table[ table_row[RENT_TABLE] ].payment_mark, token );

				// ����������� �������� ������� �������
				table_row[RENT_TABLE]++;
				break;
		}
	}

	free(line_char_count);
	fclose(f);
}