#include "database.h"

void hrd_request()
{
	// ���������������� ����
	int i, j;
	char g[8];
	system("cls");

	// �����
	printf("\n\t����� �� ������� \"����� ������\"\n\n");
	for (i = 0; i < table_row[EMPLOYEE_TABLE]; ++i)
	{
		// ��� ����������� ������ ����
		if( employee_table[i].gender == 0 )
			strcpy(g, "�������");
		else
			strcpy(g, "�������");

		printf("\t����� ������: %d\n",		i+1); 
		printf("\t��� ����������: %d\n",	employee_table[i].employee_id);
		printf("\t���: %s\n",				employee_table[i].name);
		printf("\t�������: %d\n",			employee_table[i].age);
		printf("\t���: %s\n",				g);
		printf("\t�����: %s\n",				employee_table[i].address);
		printf("\t�������: %s\n",			employee_table[i].phone);
		printf("\t���������� ������: %s\n",	employee_table[i].passport);
		printf("\t��� ���������: %d\n",		employee_table[i].position_id);

		// ����� ��������������� ��������� �� ���� � ���������� �����
		for (j = 0; j < table_row[POSITION_TABLE]; ++j)
			if( employee_table[i].position_id == position_table[j].position_id )
			{
				printf("\t������������ ���������: %s\n",	position_table[j].name);
				printf("\t�����: %d\n",						position_table[j].salary);
				printf("\t�����������: %s\n",				position_table[j].duties);
				printf("\t����������: %s\n\n",				position_table[j].requirements);
			}
	}
}

void autopark_request()
{
	// ���������������� ����
	int i, j, k;
	char g[8];
	system("cls");
	
	// �����
	printf("\n\t����� �� ������� \"��������\"\n\n");
	for (i = 0; i < table_row[CAR_TABLE]; ++i)
	{
		printf("\t����� ������: %d\n",			i+1); 
		printf("\t��� ����������: %d\n",		car_table[i].car_id);
		printf("\t��������������� �����: %d\n",	car_table[i].reg_number);
		printf("\t����� ������: %d\n",			car_table[i].body_number);
		printf("\t����� ���������: %d\n",		car_table[i].engine_number);
		printf("\t��� �������: %d\n",			car_table[i].release_year);
		printf("\t������: %d\n",				car_table[i].mileage);
		printf("\t���� ����������: %d\n",		car_table[i].price);
		printf("\t���� ��� �������: %d\n",		car_table[i].rent_price);
		printf("\t���� ���������� ��: %02d.%02d.%04d\n",
			car_table[i].maintenance_date.day,
			car_table[i].maintenance_date.month,
			car_table[i].maintenance_date.year);
		printf("\t����������� �������: %s\n",	car_table[i].special_marks);
		printf("\t������� � ��������: %s\n",	car_table[i].return_mark);
		printf("\t��� �����: %d\n",				car_table[i].brand_id);
		
		// ����� ��������������� ����� �� ���� � ���������� �����
		for (j = 0; j < table_row[BRAND_TABLE]; ++j)
			if( car_table[i].brand_id == brand_table[j].brand_id )
			{
				printf("\t������������ �����: %s\n",			brand_table[j].name);
				printf("\t����������� ��������������: %s\n",	brand_table[j].specs);
				printf("\t��������: %s\n",						brand_table[j].description);
			}

		printf("\t��� ����������-��������: %d\n",	car_table[i].employee_id);

		// ����� ���������������� ��������� � ���������� �����
		for (j = 0; j < table_row[EMPLOYEE_TABLE]; ++j)
			if( car_table[i].employee_id == employee_table[j].employee_id )
			{
				// ��� ����������� ������ ����
				if( employee_table[j].gender == 0 )
					strcpy(g, "�������");
				else
					strcpy(g, "�������");

				printf("\t���: %s\n",				employee_table[j].name);
				printf("\t�������: %d\n",			employee_table[j].age);
				printf("\t���: %s\n",				g);
				printf("\t�����: %s\n",				employee_table[j].address);
				printf("\t�������: %s\n",			employee_table[j].phone);
				printf("\t���������� ������: %s\n",	employee_table[j].passport);
				printf("\t��� ���������: %d\n",		employee_table[j].position_id);

				// ����� ��������������� ��������� �� ���� � ���������� �����
				for (k = 0; k < table_row[POSITION_TABLE]; ++k)
					if( employee_table[j].position_id == position_table[k].position_id )
					{
						printf("\t������������ ���������: %s\n",	position_table[k].name);
						printf("\t�����: %d\n",						position_table[k].salary);
						printf("\t�����������: %s\n",				position_table[k].duties);
						printf("\t����������: %s\n\n",				position_table[k].requirements);
					}
				
			}
	}
}

void rent_request()
{
	// ���������������� ����
	int i, j, k, l;
	char g[8];
	system("cls");

	// �����
	printf("\n\t����� �� ������� \"���������� � �������\"\n\n");
	for (i = 0; i < table_row[RENT_TABLE]; ++i)
	{
		printf("\t����� ������: %d\n",		i+1); 
		printf("\t��� ����������: %d\n",	rent_table[i].car_id);

		for (j = 0; j < table_row[CAR_TABLE]; ++j)
			if( rent_table[i].car_id == car_table[j].car_id )
			{
				printf("\t��������������� �����: %d\n",	car_table[j].reg_number);
				printf("\t����� ������: %d\n",			car_table[j].body_number);
				printf("\t����� ���������: %d\n",		car_table[j].engine_number);
				printf("\t��� �������: %d\n",			car_table[j].release_year);
				printf("\t������: %d\n",				car_table[j].mileage);
				printf("\t���� ����������: %d\n",		car_table[j].price);
				printf("\t���� ��� �������: %d\n",		car_table[j].rent_price);
				printf("\t���� ���������� ��: %02d.%02d.%04d\n",
					car_table[j].maintenance_date.day,
					car_table[j].maintenance_date.month,
					car_table[j].maintenance_date.year);
				printf("\t����������� �������: %s\n",	car_table[j].special_marks);
				printf("\t������� � ��������: %s\n",	car_table[j].return_mark);
				printf("\t��� �����: %d\n",				car_table[j].brand_id);

				// ����� ��������������� ����� �� ���� � ���������� �����
				for (k = 0; k < table_row[CAR_TABLE]; ++k)
					if( car_table[j].brand_id == brand_table[k].brand_id )
					{
						printf("\t������������ �����: %s\n",			brand_table[k].name);
						printf("\t����������� ��������������: %s\n",	brand_table[k].specs);
						printf("\t��������: %s\n",						brand_table[k].description);
					}

				printf("\t��� ����������-��������: %d\n", car_table[j].employee_id);

				// ����� ���������������� ��������� � ���������� �����
				for (k = 0; k < table_row[EMPLOYEE_TABLE]; ++k)
					if( car_table[j].employee_id == employee_table[k].employee_id )
					{
						// ��� ����������� ������ ����
						if( employee_table[k].gender == 0 )
							strcpy(g, "�������");
						else
							strcpy(g, "�������");

						printf("\t��� ����������-��������: %s\n",	employee_table[k].name);
						printf("\t�������: %d\n",					employee_table[k].age);
						printf("\t���: %s\n",						g);
						printf("\t�����: %s\n",						employee_table[k].address);
						printf("\t�������: %s\n",					employee_table[k].phone);
						printf("\t���������� ������: %s\n",			employee_table[k].passport);
						printf("\t��� ���������: %d\n",				employee_table[k].position_id);

						// ����� ��������������� ��������� �� ���� � ���������� �����
						for (l = 0; l < table_row[POSITION_TABLE]; ++l)
							if( employee_table[k].position_id == position_table[l].position_id )
							{
								printf("\t������������ ���������: %s\n",	position_table[l].name);
								printf("\t�����: %d\n",						position_table[l].salary);
								printf("\t�����������: %s\n",				position_table[l].duties);
								printf("\t����������: %s\n\n",				position_table[l].requirements);
							}
					}
			}

		printf("\t��� �������: %d\n",		rent_table[i].client_id);

		for (j = 0; j < table_row[CLIENT_TABLE]; ++j)
			if( rent_table[i].client_id == client_table[j].client_id )
			{
				// ��� ����������� ������ ����
				if( client_table[j].gender == 0 )
					strcpy(g, "�������");
				else
					strcpy(g, "�������");

				printf("\t���: %s\n",		client_table[j].name);
				printf("\t���: %s\n",		g);
				printf("\t���� ��������: %02d.%02d.%04d\n",
					client_table[j].birth_date.day,
					client_table[j].birth_date.month,
					client_table[j].birth_date.year);
				printf("\t�����: %s\n",		client_table[j].address);
				printf("\t�������: %s\n",	client_table[j].phone);
				printf("\t�������: %s\n",	client_table[j].passport);
			}

		printf("\t��� ����������: %d\n",	rent_table[i].employee_id);
		
		for (j = 0; j < table_row[EMPLOYEE_TABLE]; ++j)
			if( rent_table[i].employee_id == employee_table[j].employee_id )
			{
				// ��� ����������� ������ ����
				if( employee_table[j].gender == 0 )
					strcpy(g, "�������");
				else
					strcpy(g, "�������");

				printf("\t���: %s\n",				employee_table[j].name);
				printf("\t�������: %d\n",			employee_table[j].age);
				printf("\t���: %s\n",				g);
				printf("\t�����: %s\n",				employee_table[j].address);
				printf("\t�������: %s\n",			employee_table[j].phone);
				printf("\t���������� ������: %s\n",	employee_table[j].passport);
				printf("\t��� ���������: %d\n",		employee_table[j].position_id);

				// ����� ��������������� ��������� �� ���� � ���������� �����
				for (k = 0; k < table_row[POSITION_TABLE]; ++k)
					if( employee_table[j].position_id == position_table[k].position_id )
					{
						printf("\t������������ ���������: %s\n",	position_table[k].name);
						printf("\t�����: %d\n",						position_table[k].salary);
						printf("\t�����������: %s\n",				position_table[k].duties);
						printf("\t����������: %s\n\n",				position_table[k].requirements);
					}
			}

		printf("\t��� ������ 1: %d\n",		rent_table[i].service1_id);

		for (j = 0; j < table_row[SERVICE_TABLE]; ++j)
			if( rent_table[i].service1_id == service_table[j].service_id )
			{
				printf("\t������������: %s\n",	service_table[j].name);
				printf("\t��������: %s\n",		service_table[j].description);
				printf("\t����: %d\n",			service_table[j].price);
			}

		printf("\t��� ������ 2: %d\n",		rent_table[i].service2_id);

		for (j = 0; j < table_row[SERVICE_TABLE]; ++j)
			if( rent_table[i].service2_id == service_table[j].service_id )
			{
				printf("\t������������: %s\n",	service_table[j].name);
				printf("\t��������: %s\n",		service_table[j].description);
				printf("\t����: %d\n",			service_table[j].price);
			}

		printf("\t��� ������ 3: %d\n",		rent_table[i].service3_id);

		for (j = 0; j < table_row[SERVICE_TABLE]; ++j)
			if( rent_table[i].service3_id == service_table[j].service_id )
			{
				printf("\t������������: %s\n",	service_table[j].name);
				printf("\t��������: %s\n",		service_table[j].description);
				printf("\t����: %d\n",			service_table[j].price);
			}

		printf("\t���� ������: %02d.%02d.%04d\n",
			rent_table[i].delivery_date.day,
			rent_table[i].delivery_date.month,
			rent_table[i].delivery_date.year);
		printf("\t���� �������: %d\n",		rent_table[i].rent_time);
		printf("\t���� ��������: %02d.%02d.%04d\n",
			rent_table[i].return_date.day,
			rent_table[i].return_date.month,
			rent_table[i].return_date.year);
		printf("\t���� �������: %d\n",		rent_table[i].rent_price);
		printf("\t������� �� ������: %s\n",	rent_table[i].payment_mark);
	}
}

void hrd_filter_specific_position()
{
	// ���������������� ����
	int i, j;
	char g[8];
	int temp;
	system("cls");

	// ���� ������������� �������
	print_position_info();
	printf("\n\t������� ��� ��������� -> ");
	scanf("%d", &temp);

	// �����
	printf("\n\t����� �� ������� \"����� ������\" � �������� ��� �����������\n");
	printf("\t����������� ��������� ����������\n\n");
	// �����
	printf("\n\t����� �� ������� \"����� ������\"\n\n");
	for (i = 0; i < table_row[EMPLOYEE_TABLE]; ++i)
		if( temp == employee_table[i].position_id )
		{
			// ��� ����������� ������ ����
			if( employee_table[i].gender == 0 )
				strcpy(g, "�������");
			else
				strcpy(g, "�������");

			printf("\t����� ������: %d\n",		i+1); 
			printf("\t��� ����������: %d\n",	employee_table[i].employee_id);
			printf("\t���: %s\n",				employee_table[i].name);
			printf("\t�������: %d\n",			employee_table[i].age);
			printf("\t���: %s\n",				g);
			printf("\t�����: %s\n",				employee_table[i].address);
			printf("\t�������: %s\n",			employee_table[i].phone);
			printf("\t���������� ������: %s\n",	employee_table[i].passport);
			printf("\t��� ���������: %d\n",		employee_table[i].position_id);

			// ����� ��������������� ��������� �� ���� � ���������� �����
			for (j = 0; j < table_row[POSITION_TABLE]; ++j)
				if( employee_table[i].position_id == position_table[j].position_id )
				{
					printf("\t������������ ���������: %s\n",	position_table[j].name);
					printf("\t�����: %d\n",						position_table[j].salary);
					printf("\t�����������: %s\n",				position_table[j].duties);
					printf("\t����������: %s\n\n",				position_table[j].requirements);
				}
		}
}

void autopark_filter_specific_brand()
{
	// ���������������� ����
	int i, j, k;
	char g[8];
	int temp;
	system("cls");
	
	// ���� ������������� �������
	print_brand_info();
	printf("\n\t������� ��� ����� -> ");
	scanf("%d", &temp);

	// �����
	printf("\n\t����� �� ������� \"��������\" c �������� ��� �����������\n");
	printf("\t����������� ��������� �����\n\n");
	for (i = 0; i < table_row[CAR_TABLE]; ++i)
		if( temp == car_table[i].brand_id )
		{
			printf("\t����� ������: %d\n",			i+1); 
			printf("\t��� ����������: %d\n",		car_table[i].car_id);
			printf("\t��������������� �����: %d\n",	car_table[i].reg_number);
			printf("\t����� ������: %d\n",			car_table[i].body_number);
			printf("\t����� ���������: %d\n",		car_table[i].engine_number);
			printf("\t��� �������: %d\n",			car_table[i].release_year);
			printf("\t������: %d\n",				car_table[i].mileage);
			printf("\t���� ����������: %d\n",		car_table[i].price);
			printf("\t���� ��� �������: %d\n",		car_table[i].rent_price);
			printf("\t���� ���������� ��: %02d.%02d.%04d\n",
				car_table[i].maintenance_date.day,
				car_table[i].maintenance_date.month,
				car_table[i].maintenance_date.year);
			printf("\t����������� �������: %s\n",	car_table[i].special_marks);
			printf("\t������� � ��������: %s\n",	car_table[i].return_mark);
			printf("\t��� �����: %d\n",				car_table[i].brand_id);
			
			// ����� ��������������� ����� �� ���� � ���������� �����
			for (j = 0; j < table_row[BRAND_TABLE]; ++j)
				if( car_table[i].brand_id == brand_table[j].brand_id )
				{
					printf("\t������������ �����: %s\n",			brand_table[j].name);
					printf("\t����������� ��������������: %s\n",	brand_table[j].specs);
					printf("\t��������: %s\n",						brand_table[j].description);
				}

			printf("\t��� ����������-��������: %d\n",	car_table[i].employee_id);

			// ����� ���������������� ��������� � ���������� �����
			for (j = 0; j < table_row[EMPLOYEE_TABLE]; ++j)
				if( car_table[i].employee_id == employee_table[j].employee_id )
				{
					// ��� ����������� ������ ����
					if( employee_table[j].gender == 0 )
						strcpy(g, "�������");
					else
						strcpy(g, "�������");

					printf("\t���: %s\n",				employee_table[j].name);
					printf("\t�������: %d\n",			employee_table[j].age);
					printf("\t���: %s\n",				g);
					printf("\t�����: %s\n",				employee_table[j].address);
					printf("\t�������: %s\n",			employee_table[j].phone);
					printf("\t���������� ������: %s\n",	employee_table[j].passport);
					printf("\t��� ���������: %d\n",		employee_table[j].position_id);

					// ����� ��������������� ��������� �� ���� � ���������� �����
					for (k = 0; k < table_row[POSITION_TABLE]; ++k)
						if( employee_table[j].position_id == position_table[k].position_id )
						{
							printf("\t������������ ���������: %s\n",	position_table[k].name);
							printf("\t�����: %d\n",						position_table[k].salary);
							printf("\t�����������: %s\n",				position_table[k].duties);
							printf("\t����������: %s\n\n",				position_table[k].requirements);
						}
					
				}
		}
}

void autopark_filter_in_and_off_rent()
{
	// ���������������� ����
	int i, j, k, l;
	char g[8];
	int mode;
	system("cls");
	
	// ����� �����������, ����������� � �������
	for (i = 0; i < table_row[CAR_TABLE]; ++i)
		for (j = 0; j < table_row[RENT_TABLE]; ++j)
			if( car_table[i].car_id > 0 && rent_table[j].car_id > 0 )
				if( car_table[i].car_id == rent_table[j].car_id )
					printf("\t\t%d (���. ����� %d) - ��������� � �������\n\n", 
					car_table[i].car_id, car_table[i].reg_number);
				else
					printf("\t\t%d (���. ����� %d) - �� ��������� � �������\n\n", 
					car_table[i].car_id, car_table[i].reg_number);

	// ���� ������������� �������
	printf("\n\t���������� � ������� - 1\n\t���������� �� � ������� - 2:\n\t -> ");
	scanf("%d", &mode);

	// �����
	for (i = 0; i < table_row[CAR_TABLE]; ++i)
		for (j = 0; j < table_row[RENT_TABLE]; ++j)
			if( (( mode == 1 ) && ( car_table[i].car_id == rent_table[j].car_id )) ||
				(( mode == 2 ) && ( car_table[i].car_id != rent_table[j].car_id )) )
			{
				printf("\n\t����� �� ������� \"��������\" c �������� ��� �����������\n");
				printf("\t�����������, ����������� � �������\n\n");
				for (i = 0; i < table_row[CAR_TABLE]; ++i)
					if( mode == car_table[i].brand_id )
					{
						printf("\t����� ������: %d\n",			i+1); 
						printf("\t��� ����������: %d\n",		car_table[i].car_id);
						printf("\t��������������� �����: %d\n",	car_table[i].reg_number);
						printf("\t����� ������: %d\n",			car_table[i].body_number);
						printf("\t����� ���������: %d\n",		car_table[i].engine_number);
						printf("\t��� �������: %d\n",			car_table[i].release_year);
						printf("\t������: %d\n",				car_table[i].mileage);
						printf("\t���� ����������: %d\n",		car_table[i].price);
						printf("\t���� ��� �������: %d\n",		car_table[i].rent_price);
						printf("\t���� ���������� ��: %02d.%02d.%04d\n",
							car_table[i].maintenance_date.day,
							car_table[i].maintenance_date.month,
							car_table[i].maintenance_date.year);
						printf("\t����������� �������: %s\n",	car_table[i].special_marks);
						printf("\t������� � ��������: %s\n",	car_table[i].return_mark);
						printf("\t��� �����: %d\n",				car_table[i].brand_id);
						
						// ����� ��������������� ����� �� ���� � ���������� �����
						for (j = 0; j < table_row[BRAND_TABLE]; ++j)
							if( car_table[i].brand_id == brand_table[j].brand_id )
							{
								printf("\t������������ �����: %s\n",			brand_table[j].name);
								printf("\t����������� ��������������: %s\n",	brand_table[j].specs);
								printf("\t��������: %s\n",						brand_table[j].description);
							}

						printf("\t��� ����������-��������: %d\n",	car_table[i].employee_id);

						// ����� ���������������� ��������� � ���������� �����
						for (j = 0; j < table_row[EMPLOYEE_TABLE]; ++j)
							if( car_table[i].employee_id == employee_table[j].employee_id )
							{
								// ��� ����������� ������ ����
								if( employee_table[j].gender == 0 )
									strcpy(g, "�������");
								else
									strcpy(g, "�������");

								printf("\t���: %s\n",				employee_table[j].name);
								printf("\t�������: %d\n",			employee_table[j].age);
								printf("\t���: %s\n",				g);
								printf("\t�����: %s\n",				employee_table[j].address);
								printf("\t�������: %s\n",			employee_table[j].phone);
								printf("\t���������� ������: %s\n",	employee_table[j].passport);
								printf("\t��� ���������: %d\n",		employee_table[j].position_id);

								// ����� ��������������� ��������� �� ���� � ���������� �����
								for (k = 0; k < table_row[POSITION_TABLE]; ++k)
									if( employee_table[j].position_id == position_table[k].position_id )
									{
										printf("\t������������ ���������: %s\n",	position_table[k].name);
										printf("\t�����: %d\n",						position_table[k].salary);
										printf("\t�����������: %s\n",				position_table[k].duties);
										printf("\t����������: %s\n\n",				position_table[k].requirements);
									}
								
							}
					}
			}
}

void autopark_filter_specific_delivery_and_return_date()
{
	// ���������������� ����
	int i, j, k, l;
	char g[8];
	int mode, d, m, y;
	system("cls");
	
	// ���� ������������� �������
	printf("\n\t���� ������ - 1\n\t���� �������� - 2:\n\t -> ");
	scanf("%d", &mode);
	printf("\n\t������� ���� (��.��.����) -> ");
	scanf("%d.%d.%d", &d, &m, &y);

	// �����
	printf("\n\t����� �� ������� \"��������\" c �������� ��� �����������\n");
	printf("\t�����������, �������� � ������������ � ����������� ����\n\n");

	for (i = 0; i < table_row[CAR_TABLE]; ++i)
		for (l = 0; l < table_row[RENT_TABLE]; ++l)
			if( (( mode == 1 ) && (d == rent_table[l].delivery_date.day) &&
				(m == rent_table[l].delivery_date.month) &&	
				(y == rent_table[l].delivery_date.year))
				|| 
				(( mode == 2 ) && (d == rent_table[l].return_date.day) &&
				(m == rent_table[l].return_date.month) &&	
				(y == rent_table[l].return_date.year)) )
			{
				printf("\t����� ������: %d\n",			i+1); 
				printf("\t��� ����������: %d\n",		car_table[i].car_id);
				printf("\t��������������� �����: %d\n",	car_table[i].reg_number);
				printf("\t����� ������: %d\n",			car_table[i].body_number);
				printf("\t����� ���������: %d\n",		car_table[i].engine_number);
				printf("\t��� �������: %d\n",			car_table[i].release_year);
				printf("\t������: %d\n",				car_table[i].mileage);
				printf("\t���� ����������: %d\n",		car_table[i].price);
				printf("\t���� ��� �������: %d\n",		car_table[i].rent_price);
				printf("\t���� ���������� ��: %02d.%02d.%04d\n",
					car_table[i].maintenance_date.day,
					car_table[i].maintenance_date.month,
					car_table[i].maintenance_date.year);
				printf("\t����������� �������: %s\n",	car_table[i].special_marks);
				printf("\t������� � ��������: %s\n",	car_table[i].return_mark);
				printf("\t��� �����: %d\n",				car_table[i].brand_id);
				
				// ����� ��������������� ����� �� ���� � ���������� �����
				for (j = 0; j < table_row[BRAND_TABLE]; ++j)
					if( car_table[i].brand_id == brand_table[j].brand_id )
					{
						printf("\t������������ �����: %s\n",			brand_table[j].name);
						printf("\t����������� ��������������: %s\n",	brand_table[j].specs);
						printf("\t��������: %s\n",						brand_table[j].description);
					}

				printf("\t��� ����������-��������: %d\n",	car_table[i].employee_id);

				// ����� ���������������� ��������� � ���������� �����
				for (j = 0; j < table_row[EMPLOYEE_TABLE]; ++j)
					if( car_table[i].employee_id == employee_table[j].employee_id )
					{
						// ��� ����������� ������ ����
						if( employee_table[j].gender == 0 )
							strcpy(g, "�������");
						else
							strcpy(g, "�������");

						printf("\t���: %s\n",				employee_table[j].name);
						printf("\t�������: %d\n",			employee_table[j].age);
						printf("\t���: %s\n",				g);
						printf("\t�����: %s\n",				employee_table[j].address);
						printf("\t�������: %s\n",			employee_table[j].phone);
						printf("\t���������� ������: %s\n",	employee_table[j].passport);
						printf("\t��� ���������: %d\n",		employee_table[j].position_id);

						// ����� ��������������� ��������� �� ���� � ���������� �����
						for (k = 0; k < table_row[POSITION_TABLE]; ++k)
							if( employee_table[j].position_id == position_table[k].position_id )
							{
								printf("\t������������ ���������: %s\n",	position_table[k].name);
								printf("\t�����: %d\n",						position_table[k].salary);
								printf("\t�����������: %s\n",				position_table[k].duties);
								printf("\t����������: %s\n\n",				position_table[k].requirements);
							}
					}
			}
}
void autopark_filter_paid_and_unpaid_rented_cars()
{
	// ���������������� ����
	int i, j, k;
	char g[8];
	int temp;
	system("cls");
	
	// ���� ������������� �������
	for (i = 0; i < table_row[RENT_TABLE]; ++i)
		printf("\t%d - ������� �� ������: %s\n", 
			rent_table[i].car_id, rent_table[i].payment_mark);

	printf("\n\t������� ��� ���������� -> ");
	scanf("%d", &temp);

	// �����
	printf("\n\t����� �� ������� \"��������\" c �������� ��� �����������\n");
	printf("\t����������� ��������� �����\n\n");
	for (i = 0; i < table_row[CAR_TABLE]; ++i)
		if( temp == car_table[i].car_id )
		{
			printf("\t����� ������: %d\n",			i+1); 
			printf("\t��� ����������: %d\n",		car_table[i].car_id);
			printf("\t��������������� �����: %d\n",	car_table[i].reg_number);
			printf("\t����� ������: %d\n",			car_table[i].body_number);
			printf("\t����� ���������: %d\n",		car_table[i].engine_number);
			printf("\t��� �������: %d\n",			car_table[i].release_year);
			printf("\t������: %d\n",				car_table[i].mileage);
			printf("\t���� ����������: %d\n",		car_table[i].price);
			printf("\t���� ��� �������: %d\n",		car_table[i].rent_price);
			printf("\t���� ���������� ��: %02d.%02d.%04d\n",
				car_table[i].maintenance_date.day,
				car_table[i].maintenance_date.month,
				car_table[i].maintenance_date.year);
			printf("\t����������� �������: %s\n",	car_table[i].special_marks);
			printf("\t������� � ��������: %s\n",	car_table[i].return_mark);
			printf("\t��� �����: %d\n",				car_table[i].brand_id);
			
			// ����� ��������������� ����� �� ���� � ���������� �����
			for (j = 0; j < table_row[BRAND_TABLE]; ++j)
				if( car_table[i].brand_id == brand_table[j].brand_id )
				{
					printf("\t������������ �����: %s\n",			brand_table[j].name);
					printf("\t����������� ��������������: %s\n",	brand_table[j].specs);
					printf("\t��������: %s\n",						brand_table[j].description);
				}

			printf("\t��� ����������-��������: %d\n",	car_table[i].employee_id);

			// ����� ���������������� ��������� � ���������� �����
			for (j = 0; j < table_row[EMPLOYEE_TABLE]; ++j)
				if( car_table[i].employee_id == employee_table[j].employee_id )
				{
					// ��� ����������� ������ ����
					if( employee_table[j].gender == 0 )
						strcpy(g, "�������");
					else
						strcpy(g, "�������");

					printf("\t���: %s\n",				employee_table[j].name);
					printf("\t�������: %d\n",			employee_table[j].age);
					printf("\t���: %s\n",				g);
					printf("\t�����: %s\n",				employee_table[j].address);
					printf("\t�������: %s\n",			employee_table[j].phone);
					printf("\t���������� ������: %s\n",	employee_table[j].passport);
					printf("\t��� ���������: %d\n",		employee_table[j].position_id);

					// ����� ��������������� ��������� �� ���� � ���������� �����
					for (k = 0; k < table_row[POSITION_TABLE]; ++k)
						if( employee_table[j].position_id == position_table[k].position_id )
						{
							printf("\t������������ ���������: %s\n",	position_table[k].name);
							printf("\t�����: %d\n",						position_table[k].salary);
							printf("\t�����������: %s\n",				position_table[k].duties);
							printf("\t����������: %s\n\n",				position_table[k].requirements);
						}
					
				}
		}
}
