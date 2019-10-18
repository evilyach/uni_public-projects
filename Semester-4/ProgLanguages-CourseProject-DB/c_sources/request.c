#include "database.h"

void hrd_request()
{
	// Подготовительный этап
	int i, j;
	char g[8];
	system("cls");

	// Вывод
	printf("\n\tОтчет по запросу \"Отдел кадров\"\n\n");
	for (i = 0; i < table_row[EMPLOYEE_TABLE]; ++i)
	{
		// Для корректного вывода пола
		if( employee_table[i].gender == 0 )
			strcpy(g, "Мужской");
		else
			strcpy(g, "Женский");

		printf("\tНомер записи: %d\n",		i+1); 
		printf("\tКод сотрудника: %d\n",	employee_table[i].employee_id);
		printf("\tФИО: %s\n",				employee_table[i].name);
		printf("\tВозраст: %d\n",			employee_table[i].age);
		printf("\tПол: %s\n",				g);
		printf("\tАдрес: %s\n",				employee_table[i].address);
		printf("\tТелефон: %s\n",			employee_table[i].phone);
		printf("\tПаспортные данные: %s\n",	employee_table[i].passport);
		printf("\tКод должности: %d\n",		employee_table[i].position_id);

		// Поиск соответствующей должности по коду и дальнейший вывод
		for (j = 0; j < table_row[POSITION_TABLE]; ++j)
			if( employee_table[i].position_id == position_table[j].position_id )
			{
				printf("\tНаименование должности: %s\n",	position_table[j].name);
				printf("\tОклад: %d\n",						position_table[j].salary);
				printf("\tОбязанности: %s\n",				position_table[j].duties);
				printf("\tТребования: %s\n\n",				position_table[j].requirements);
			}
	}
}

void autopark_request()
{
	// Подготовительный этап
	int i, j, k;
	char g[8];
	system("cls");
	
	// Вывод
	printf("\n\tОтчет по запросу \"Автопарк\"\n\n");
	for (i = 0; i < table_row[CAR_TABLE]; ++i)
	{
		printf("\tНомер записи: %d\n",			i+1); 
		printf("\tКод автомобиля: %d\n",		car_table[i].car_id);
		printf("\tРегистрационный номер: %d\n",	car_table[i].reg_number);
		printf("\tНомер кузова: %d\n",			car_table[i].body_number);
		printf("\tНомер двигателя: %d\n",		car_table[i].engine_number);
		printf("\tГод выпуска: %d\n",			car_table[i].release_year);
		printf("\tПробег: %d\n",				car_table[i].mileage);
		printf("\tЦена автомобиля: %d\n",		car_table[i].price);
		printf("\tЦена дня проката: %d\n",		car_table[i].rent_price);
		printf("\tДата последнего ТО: %02d.%02d.%04d\n",
			car_table[i].maintenance_date.day,
			car_table[i].maintenance_date.month,
			car_table[i].maintenance_date.year);
		printf("\tСпециальные отметки: %s\n",	car_table[i].special_marks);
		printf("\tОтметка о возврате: %s\n",	car_table[i].return_mark);
		printf("\tКод марки: %d\n",				car_table[i].brand_id);
		
		// Поиск соответствующей марки по коду и дальнейший вывод
		for (j = 0; j < table_row[BRAND_TABLE]; ++j)
			if( car_table[i].brand_id == brand_table[j].brand_id )
			{
				printf("\tНаименование марки: %s\n",			brand_table[j].name);
				printf("\tТехнические характеристики: %s\n",	brand_table[j].specs);
				printf("\tОписание: %s\n",						brand_table[j].description);
			}

		printf("\tКод сотрудника-механика: %d\n",	car_table[i].employee_id);

		// Поиск соответствующего работника и дальнейший вывод
		for (j = 0; j < table_row[EMPLOYEE_TABLE]; ++j)
			if( car_table[i].employee_id == employee_table[j].employee_id )
			{
				// Для корректного вывода пола
				if( employee_table[j].gender == 0 )
					strcpy(g, "Мужской");
				else
					strcpy(g, "Женский");

				printf("\tФИО: %s\n",				employee_table[j].name);
				printf("\tВозраст: %d\n",			employee_table[j].age);
				printf("\tПол: %s\n",				g);
				printf("\tАдрес: %s\n",				employee_table[j].address);
				printf("\tТелефон: %s\n",			employee_table[j].phone);
				printf("\tПаспортные данные: %s\n",	employee_table[j].passport);
				printf("\tКод должности: %d\n",		employee_table[j].position_id);

				// Поиск соответствующей должности по коду и дальнейший вывод
				for (k = 0; k < table_row[POSITION_TABLE]; ++k)
					if( employee_table[j].position_id == position_table[k].position_id )
					{
						printf("\tНаименование должности: %s\n",	position_table[k].name);
						printf("\tОклад: %d\n",						position_table[k].salary);
						printf("\tОбязанности: %s\n",				position_table[k].duties);
						printf("\tТребования: %s\n\n",				position_table[k].requirements);
					}
				
			}
	}
}

void rent_request()
{
	// Подготовительный этап
	int i, j, k, l;
	char g[8];
	system("cls");

	// Вывод
	printf("\n\tОтчет по запросу \"Автомобили в прокате\"\n\n");
	for (i = 0; i < table_row[RENT_TABLE]; ++i)
	{
		printf("\tНомер записи: %d\n",		i+1); 
		printf("\tКод автомобиля: %d\n",	rent_table[i].car_id);

		for (j = 0; j < table_row[CAR_TABLE]; ++j)
			if( rent_table[i].car_id == car_table[j].car_id )
			{
				printf("\tРегистрационный номер: %d\n",	car_table[j].reg_number);
				printf("\tНомер кузова: %d\n",			car_table[j].body_number);
				printf("\tНомер двигателя: %d\n",		car_table[j].engine_number);
				printf("\tГод выпуска: %d\n",			car_table[j].release_year);
				printf("\tПробег: %d\n",				car_table[j].mileage);
				printf("\tЦена автомобиля: %d\n",		car_table[j].price);
				printf("\tЦена дня проката: %d\n",		car_table[j].rent_price);
				printf("\tДата последнего ТО: %02d.%02d.%04d\n",
					car_table[j].maintenance_date.day,
					car_table[j].maintenance_date.month,
					car_table[j].maintenance_date.year);
				printf("\tСпециальные отметки: %s\n",	car_table[j].special_marks);
				printf("\tОтметка о возврате: %s\n",	car_table[j].return_mark);
				printf("\tКод марки: %d\n",				car_table[j].brand_id);

				// Поиск соответствующей марки по коду и дальнейший вывод
				for (k = 0; k < table_row[CAR_TABLE]; ++k)
					if( car_table[j].brand_id == brand_table[k].brand_id )
					{
						printf("\tНаименование марки: %s\n",			brand_table[k].name);
						printf("\tТехнические характеристики: %s\n",	brand_table[k].specs);
						printf("\tОписание: %s\n",						brand_table[k].description);
					}

				printf("\tКод сотрудника-механика: %d\n", car_table[j].employee_id);

				// Поиск соответствующего работника и дальнейший вывод
				for (k = 0; k < table_row[EMPLOYEE_TABLE]; ++k)
					if( car_table[j].employee_id == employee_table[k].employee_id )
					{
						// Для корректного вывода пола
						if( employee_table[k].gender == 0 )
							strcpy(g, "Мужской");
						else
							strcpy(g, "Женский");

						printf("\tФИО сотрудника-механика: %s\n",	employee_table[k].name);
						printf("\tВозраст: %d\n",					employee_table[k].age);
						printf("\tПол: %s\n",						g);
						printf("\tАдрес: %s\n",						employee_table[k].address);
						printf("\tТелефон: %s\n",					employee_table[k].phone);
						printf("\tПаспортные данные: %s\n",			employee_table[k].passport);
						printf("\tКод должности: %d\n",				employee_table[k].position_id);

						// Поиск соответствующей должности по коду и дальнейший вывод
						for (l = 0; l < table_row[POSITION_TABLE]; ++l)
							if( employee_table[k].position_id == position_table[l].position_id )
							{
								printf("\tНаименование должности: %s\n",	position_table[l].name);
								printf("\tОклад: %d\n",						position_table[l].salary);
								printf("\tОбязанности: %s\n",				position_table[l].duties);
								printf("\tТребования: %s\n\n",				position_table[l].requirements);
							}
					}
			}

		printf("\tКод клиента: %d\n",		rent_table[i].client_id);

		for (j = 0; j < table_row[CLIENT_TABLE]; ++j)
			if( rent_table[i].client_id == client_table[j].client_id )
			{
				// Для корректного вывода пола
				if( client_table[j].gender == 0 )
					strcpy(g, "Мужской");
				else
					strcpy(g, "Женский");

				printf("\tФИО: %s\n",		client_table[j].name);
				printf("\tПол: %s\n",		g);
				printf("\tДата рождения: %02d.%02d.%04d\n",
					client_table[j].birth_date.day,
					client_table[j].birth_date.month,
					client_table[j].birth_date.year);
				printf("\tАдрес: %s\n",		client_table[j].address);
				printf("\tТелефон: %s\n",	client_table[j].phone);
				printf("\tПаспорт: %s\n",	client_table[j].passport);
			}

		printf("\tКод сотрудника: %d\n",	rent_table[i].employee_id);
		
		for (j = 0; j < table_row[EMPLOYEE_TABLE]; ++j)
			if( rent_table[i].employee_id == employee_table[j].employee_id )
			{
				// Для корректного вывода пола
				if( employee_table[j].gender == 0 )
					strcpy(g, "Мужской");
				else
					strcpy(g, "Женский");

				printf("\tФИО: %s\n",				employee_table[j].name);
				printf("\tВозраст: %d\n",			employee_table[j].age);
				printf("\tПол: %s\n",				g);
				printf("\tАдрес: %s\n",				employee_table[j].address);
				printf("\tТелефон: %s\n",			employee_table[j].phone);
				printf("\tПаспортные данные: %s\n",	employee_table[j].passport);
				printf("\tКод должности: %d\n",		employee_table[j].position_id);

				// Поиск соответствующей должности по коду и дальнейший вывод
				for (k = 0; k < table_row[POSITION_TABLE]; ++k)
					if( employee_table[j].position_id == position_table[k].position_id )
					{
						printf("\tНаименование должности: %s\n",	position_table[k].name);
						printf("\tОклад: %d\n",						position_table[k].salary);
						printf("\tОбязанности: %s\n",				position_table[k].duties);
						printf("\tТребования: %s\n\n",				position_table[k].requirements);
					}
			}

		printf("\tКод услуги 1: %d\n",		rent_table[i].service1_id);

		for (j = 0; j < table_row[SERVICE_TABLE]; ++j)
			if( rent_table[i].service1_id == service_table[j].service_id )
			{
				printf("\tНаименование: %s\n",	service_table[j].name);
				printf("\tОписание: %s\n",		service_table[j].description);
				printf("\tЦена: %d\n",			service_table[j].price);
			}

		printf("\tКод услуги 2: %d\n",		rent_table[i].service2_id);

		for (j = 0; j < table_row[SERVICE_TABLE]; ++j)
			if( rent_table[i].service2_id == service_table[j].service_id )
			{
				printf("\tНаименование: %s\n",	service_table[j].name);
				printf("\tОписание: %s\n",		service_table[j].description);
				printf("\tЦена: %d\n",			service_table[j].price);
			}

		printf("\tКод услуги 3: %d\n",		rent_table[i].service3_id);

		for (j = 0; j < table_row[SERVICE_TABLE]; ++j)
			if( rent_table[i].service3_id == service_table[j].service_id )
			{
				printf("\tНаименование: %s\n",	service_table[j].name);
				printf("\tОписание: %s\n",		service_table[j].description);
				printf("\tЦена: %d\n",			service_table[j].price);
			}

		printf("\tДата выдачи: %02d.%02d.%04d\n",
			rent_table[i].delivery_date.day,
			rent_table[i].delivery_date.month,
			rent_table[i].delivery_date.year);
		printf("\tСрок проката: %d\n",		rent_table[i].rent_time);
		printf("\tДата возврата: %02d.%02d.%04d\n",
			rent_table[i].return_date.day,
			rent_table[i].return_date.month,
			rent_table[i].return_date.year);
		printf("\tЦена проката: %d\n",		rent_table[i].rent_price);
		printf("\tПометка об оплате: %s\n",	rent_table[i].payment_mark);
	}
}

void hrd_filter_specific_position()
{
	// Подготовительный этап
	int i, j;
	char g[8];
	int temp;
	system("cls");

	// Ввод пользователем фильтра
	print_position_info();
	printf("\n\tВведите код должности -> ");
	scanf("%d", &temp);

	// Вывод
	printf("\n\tОтчет по запросу \"Отдел кадров\" с фильтром для отображения\n");
	printf("\tсотрудников отдельных должностей\n\n");
	// Вывод
	printf("\n\tОтчет по запросу \"Отдел кадров\"\n\n");
	for (i = 0; i < table_row[EMPLOYEE_TABLE]; ++i)
		if( temp == employee_table[i].position_id )
		{
			// Для корректного вывода пола
			if( employee_table[i].gender == 0 )
				strcpy(g, "Мужской");
			else
				strcpy(g, "Женский");

			printf("\tНомер записи: %d\n",		i+1); 
			printf("\tКод сотрудника: %d\n",	employee_table[i].employee_id);
			printf("\tФИО: %s\n",				employee_table[i].name);
			printf("\tВозраст: %d\n",			employee_table[i].age);
			printf("\tПол: %s\n",				g);
			printf("\tАдрес: %s\n",				employee_table[i].address);
			printf("\tТелефон: %s\n",			employee_table[i].phone);
			printf("\tПаспортные данные: %s\n",	employee_table[i].passport);
			printf("\tКод должности: %d\n",		employee_table[i].position_id);

			// Поиск соответствующей должности по коду и дальнейший вывод
			for (j = 0; j < table_row[POSITION_TABLE]; ++j)
				if( employee_table[i].position_id == position_table[j].position_id )
				{
					printf("\tНаименование должности: %s\n",	position_table[j].name);
					printf("\tОклад: %d\n",						position_table[j].salary);
					printf("\tОбязанности: %s\n",				position_table[j].duties);
					printf("\tТребования: %s\n\n",				position_table[j].requirements);
				}
		}
}

void autopark_filter_specific_brand()
{
	// Подготовительный этап
	int i, j, k;
	char g[8];
	int temp;
	system("cls");
	
	// Ввод пользователем фильтра
	print_brand_info();
	printf("\n\tВведите код марки -> ");
	scanf("%d", &temp);

	// Вывод
	printf("\n\tОтчет по запросу \"Автопарк\" c фильтром для отображения\n");
	printf("\tавтомобилей отдельных марок\n\n");
	for (i = 0; i < table_row[CAR_TABLE]; ++i)
		if( temp == car_table[i].brand_id )
		{
			printf("\tНомер записи: %d\n",			i+1); 
			printf("\tКод автомобиля: %d\n",		car_table[i].car_id);
			printf("\tРегистрационный номер: %d\n",	car_table[i].reg_number);
			printf("\tНомер кузова: %d\n",			car_table[i].body_number);
			printf("\tНомер двигателя: %d\n",		car_table[i].engine_number);
			printf("\tГод выпуска: %d\n",			car_table[i].release_year);
			printf("\tПробег: %d\n",				car_table[i].mileage);
			printf("\tЦена автомобиля: %d\n",		car_table[i].price);
			printf("\tЦена дня проката: %d\n",		car_table[i].rent_price);
			printf("\tДата последнего ТО: %02d.%02d.%04d\n",
				car_table[i].maintenance_date.day,
				car_table[i].maintenance_date.month,
				car_table[i].maintenance_date.year);
			printf("\tСпециальные отметки: %s\n",	car_table[i].special_marks);
			printf("\tОтметка о возврате: %s\n",	car_table[i].return_mark);
			printf("\tКод марки: %d\n",				car_table[i].brand_id);
			
			// Поиск соответствующей марки по коду и дальнейший вывод
			for (j = 0; j < table_row[BRAND_TABLE]; ++j)
				if( car_table[i].brand_id == brand_table[j].brand_id )
				{
					printf("\tНаименование марки: %s\n",			brand_table[j].name);
					printf("\tТехнические характеристики: %s\n",	brand_table[j].specs);
					printf("\tОписание: %s\n",						brand_table[j].description);
				}

			printf("\tКод сотрудника-механика: %d\n",	car_table[i].employee_id);

			// Поиск соответствующего работника и дальнейший вывод
			for (j = 0; j < table_row[EMPLOYEE_TABLE]; ++j)
				if( car_table[i].employee_id == employee_table[j].employee_id )
				{
					// Для корректного вывода пола
					if( employee_table[j].gender == 0 )
						strcpy(g, "Мужской");
					else
						strcpy(g, "Женский");

					printf("\tФИО: %s\n",				employee_table[j].name);
					printf("\tВозраст: %d\n",			employee_table[j].age);
					printf("\tПол: %s\n",				g);
					printf("\tАдрес: %s\n",				employee_table[j].address);
					printf("\tТелефон: %s\n",			employee_table[j].phone);
					printf("\tПаспортные данные: %s\n",	employee_table[j].passport);
					printf("\tКод должности: %d\n",		employee_table[j].position_id);

					// Поиск соответствующей должности по коду и дальнейший вывод
					for (k = 0; k < table_row[POSITION_TABLE]; ++k)
						if( employee_table[j].position_id == position_table[k].position_id )
						{
							printf("\tНаименование должности: %s\n",	position_table[k].name);
							printf("\tОклад: %d\n",						position_table[k].salary);
							printf("\tОбязанности: %s\n",				position_table[k].duties);
							printf("\tТребования: %s\n\n",				position_table[k].requirements);
						}
					
				}
		}
}

void autopark_filter_in_and_off_rent()
{
	// Подготовительный этап
	int i, j, k, l;
	char g[8];
	int mode;
	system("cls");
	
	// Вывод автомобилей, находящихся в прокате
	for (i = 0; i < table_row[CAR_TABLE]; ++i)
		for (j = 0; j < table_row[RENT_TABLE]; ++j)
			if( car_table[i].car_id > 0 && rent_table[j].car_id > 0 )
				if( car_table[i].car_id == rent_table[j].car_id )
					printf("\t\t%d (рег. номер %d) - находится в прокате\n\n", 
					car_table[i].car_id, car_table[i].reg_number);
				else
					printf("\t\t%d (рег. номер %d) - не находится в прокате\n\n", 
					car_table[i].car_id, car_table[i].reg_number);

	// Ввод пользователем фильтра
	printf("\n\tАвтомобили в прокате - 1\n\tАвтомобили не в прокате - 2:\n\t -> ");
	scanf("%d", &mode);

	// Вывод
	for (i = 0; i < table_row[CAR_TABLE]; ++i)
		for (j = 0; j < table_row[RENT_TABLE]; ++j)
			if( (( mode == 1 ) && ( car_table[i].car_id == rent_table[j].car_id )) ||
				(( mode == 2 ) && ( car_table[i].car_id != rent_table[j].car_id )) )
			{
				printf("\n\tОтчет по запросу \"Автопарк\" c фильтром для отображения\n");
				printf("\tавтомобилей, находящихся в прокате\n\n");
				for (i = 0; i < table_row[CAR_TABLE]; ++i)
					if( mode == car_table[i].brand_id )
					{
						printf("\tНомер записи: %d\n",			i+1); 
						printf("\tКод автомобиля: %d\n",		car_table[i].car_id);
						printf("\tРегистрационный номер: %d\n",	car_table[i].reg_number);
						printf("\tНомер кузова: %d\n",			car_table[i].body_number);
						printf("\tНомер двигателя: %d\n",		car_table[i].engine_number);
						printf("\tГод выпуска: %d\n",			car_table[i].release_year);
						printf("\tПробег: %d\n",				car_table[i].mileage);
						printf("\tЦена автомобиля: %d\n",		car_table[i].price);
						printf("\tЦена дня проката: %d\n",		car_table[i].rent_price);
						printf("\tДата последнего ТО: %02d.%02d.%04d\n",
							car_table[i].maintenance_date.day,
							car_table[i].maintenance_date.month,
							car_table[i].maintenance_date.year);
						printf("\tСпециальные отметки: %s\n",	car_table[i].special_marks);
						printf("\tОтметка о возврате: %s\n",	car_table[i].return_mark);
						printf("\tКод марки: %d\n",				car_table[i].brand_id);
						
						// Поиск соответствующей марки по коду и дальнейший вывод
						for (j = 0; j < table_row[BRAND_TABLE]; ++j)
							if( car_table[i].brand_id == brand_table[j].brand_id )
							{
								printf("\tНаименование марки: %s\n",			brand_table[j].name);
								printf("\tТехнические характеристики: %s\n",	brand_table[j].specs);
								printf("\tОписание: %s\n",						brand_table[j].description);
							}

						printf("\tКод сотрудника-механика: %d\n",	car_table[i].employee_id);

						// Поиск соответствующего работника и дальнейший вывод
						for (j = 0; j < table_row[EMPLOYEE_TABLE]; ++j)
							if( car_table[i].employee_id == employee_table[j].employee_id )
							{
								// Для корректного вывода пола
								if( employee_table[j].gender == 0 )
									strcpy(g, "Мужской");
								else
									strcpy(g, "Женский");

								printf("\tФИО: %s\n",				employee_table[j].name);
								printf("\tВозраст: %d\n",			employee_table[j].age);
								printf("\tПол: %s\n",				g);
								printf("\tАдрес: %s\n",				employee_table[j].address);
								printf("\tТелефон: %s\n",			employee_table[j].phone);
								printf("\tПаспортные данные: %s\n",	employee_table[j].passport);
								printf("\tКод должности: %d\n",		employee_table[j].position_id);

								// Поиск соответствующей должности по коду и дальнейший вывод
								for (k = 0; k < table_row[POSITION_TABLE]; ++k)
									if( employee_table[j].position_id == position_table[k].position_id )
									{
										printf("\tНаименование должности: %s\n",	position_table[k].name);
										printf("\tОклад: %d\n",						position_table[k].salary);
										printf("\tОбязанности: %s\n",				position_table[k].duties);
										printf("\tТребования: %s\n\n",				position_table[k].requirements);
									}
								
							}
					}
			}
}

void autopark_filter_specific_delivery_and_return_date()
{
	// Подготовительный этап
	int i, j, k, l;
	char g[8];
	int mode, d, m, y;
	system("cls");
	
	// Ввод пользователем фильтра
	printf("\n\tДата выдачи - 1\n\tДата возврата - 2:\n\t -> ");
	scanf("%d", &mode);
	printf("\n\tВведите дату (ДД.ММ.ГГГГ) -> ");
	scanf("%d.%d.%d", &d, &m, &y);

	// Вывод
	printf("\n\tОтчет по запросу \"Автопарк\" c фильтром для отображения\n");
	printf("\tавтомобилей, выданных и возвращённых в определённую дату\n\n");

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
				printf("\tНомер записи: %d\n",			i+1); 
				printf("\tКод автомобиля: %d\n",		car_table[i].car_id);
				printf("\tРегистрационный номер: %d\n",	car_table[i].reg_number);
				printf("\tНомер кузова: %d\n",			car_table[i].body_number);
				printf("\tНомер двигателя: %d\n",		car_table[i].engine_number);
				printf("\tГод выпуска: %d\n",			car_table[i].release_year);
				printf("\tПробег: %d\n",				car_table[i].mileage);
				printf("\tЦена автомобиля: %d\n",		car_table[i].price);
				printf("\tЦена дня проката: %d\n",		car_table[i].rent_price);
				printf("\tДата последнего ТО: %02d.%02d.%04d\n",
					car_table[i].maintenance_date.day,
					car_table[i].maintenance_date.month,
					car_table[i].maintenance_date.year);
				printf("\tСпециальные отметки: %s\n",	car_table[i].special_marks);
				printf("\tОтметка о возврате: %s\n",	car_table[i].return_mark);
				printf("\tКод марки: %d\n",				car_table[i].brand_id);
				
				// Поиск соответствующей марки по коду и дальнейший вывод
				for (j = 0; j < table_row[BRAND_TABLE]; ++j)
					if( car_table[i].brand_id == brand_table[j].brand_id )
					{
						printf("\tНаименование марки: %s\n",			brand_table[j].name);
						printf("\tТехнические характеристики: %s\n",	brand_table[j].specs);
						printf("\tОписание: %s\n",						brand_table[j].description);
					}

				printf("\tКод сотрудника-механика: %d\n",	car_table[i].employee_id);

				// Поиск соответствующего работника и дальнейший вывод
				for (j = 0; j < table_row[EMPLOYEE_TABLE]; ++j)
					if( car_table[i].employee_id == employee_table[j].employee_id )
					{
						// Для корректного вывода пола
						if( employee_table[j].gender == 0 )
							strcpy(g, "Мужской");
						else
							strcpy(g, "Женский");

						printf("\tФИО: %s\n",				employee_table[j].name);
						printf("\tВозраст: %d\n",			employee_table[j].age);
						printf("\tПол: %s\n",				g);
						printf("\tАдрес: %s\n",				employee_table[j].address);
						printf("\tТелефон: %s\n",			employee_table[j].phone);
						printf("\tПаспортные данные: %s\n",	employee_table[j].passport);
						printf("\tКод должности: %d\n",		employee_table[j].position_id);

						// Поиск соответствующей должности по коду и дальнейший вывод
						for (k = 0; k < table_row[POSITION_TABLE]; ++k)
							if( employee_table[j].position_id == position_table[k].position_id )
							{
								printf("\tНаименование должности: %s\n",	position_table[k].name);
								printf("\tОклад: %d\n",						position_table[k].salary);
								printf("\tОбязанности: %s\n",				position_table[k].duties);
								printf("\tТребования: %s\n\n",				position_table[k].requirements);
							}
					}
			}
}
void autopark_filter_paid_and_unpaid_rented_cars()
{
	// Подготовительный этап
	int i, j, k;
	char g[8];
	int temp;
	system("cls");
	
	// Ввод пользователем фильтра
	for (i = 0; i < table_row[RENT_TABLE]; ++i)
		printf("\t%d - Отметка об оплате: %s\n", 
			rent_table[i].car_id, rent_table[i].payment_mark);

	printf("\n\tВведите код автомобиля -> ");
	scanf("%d", &temp);

	// Вывод
	printf("\n\tОтчет по запросу \"Автопарк\" c фильтром для отображения\n");
	printf("\tавтомобилей отдельных марок\n\n");
	for (i = 0; i < table_row[CAR_TABLE]; ++i)
		if( temp == car_table[i].car_id )
		{
			printf("\tНомер записи: %d\n",			i+1); 
			printf("\tКод автомобиля: %d\n",		car_table[i].car_id);
			printf("\tРегистрационный номер: %d\n",	car_table[i].reg_number);
			printf("\tНомер кузова: %d\n",			car_table[i].body_number);
			printf("\tНомер двигателя: %d\n",		car_table[i].engine_number);
			printf("\tГод выпуска: %d\n",			car_table[i].release_year);
			printf("\tПробег: %d\n",				car_table[i].mileage);
			printf("\tЦена автомобиля: %d\n",		car_table[i].price);
			printf("\tЦена дня проката: %d\n",		car_table[i].rent_price);
			printf("\tДата последнего ТО: %02d.%02d.%04d\n",
				car_table[i].maintenance_date.day,
				car_table[i].maintenance_date.month,
				car_table[i].maintenance_date.year);
			printf("\tСпециальные отметки: %s\n",	car_table[i].special_marks);
			printf("\tОтметка о возврате: %s\n",	car_table[i].return_mark);
			printf("\tКод марки: %d\n",				car_table[i].brand_id);
			
			// Поиск соответствующей марки по коду и дальнейший вывод
			for (j = 0; j < table_row[BRAND_TABLE]; ++j)
				if( car_table[i].brand_id == brand_table[j].brand_id )
				{
					printf("\tНаименование марки: %s\n",			brand_table[j].name);
					printf("\tТехнические характеристики: %s\n",	brand_table[j].specs);
					printf("\tОписание: %s\n",						brand_table[j].description);
				}

			printf("\tКод сотрудника-механика: %d\n",	car_table[i].employee_id);

			// Поиск соответствующего работника и дальнейший вывод
			for (j = 0; j < table_row[EMPLOYEE_TABLE]; ++j)
				if( car_table[i].employee_id == employee_table[j].employee_id )
				{
					// Для корректного вывода пола
					if( employee_table[j].gender == 0 )
						strcpy(g, "Мужской");
					else
						strcpy(g, "Женский");

					printf("\tФИО: %s\n",				employee_table[j].name);
					printf("\tВозраст: %d\n",			employee_table[j].age);
					printf("\tПол: %s\n",				g);
					printf("\tАдрес: %s\n",				employee_table[j].address);
					printf("\tТелефон: %s\n",			employee_table[j].phone);
					printf("\tПаспортные данные: %s\n",	employee_table[j].passport);
					printf("\tКод должности: %d\n",		employee_table[j].position_id);

					// Поиск соответствующей должности по коду и дальнейший вывод
					for (k = 0; k < table_row[POSITION_TABLE]; ++k)
						if( employee_table[j].position_id == position_table[k].position_id )
						{
							printf("\tНаименование должности: %s\n",	position_table[k].name);
							printf("\tОклад: %d\n",						position_table[k].salary);
							printf("\tОбязанности: %s\n",				position_table[k].duties);
							printf("\tТребования: %s\n\n",				position_table[k].requirements);
						}
					
				}
		}
}
