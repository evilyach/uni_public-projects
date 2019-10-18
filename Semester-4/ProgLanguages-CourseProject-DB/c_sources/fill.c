#include "database.h"

int input_string(char *what, const int buffer, char *description)
{
	printf("\t\t%s", description);
	if( !fgets(what, buffer, stdin) )
	{
		fprintf(stderr, "ОШИБКА: Невозможно прочитать строку\n");
		return 1;
	}	
	what[strlen(what) - 1] = '\0';

	fflush(stdin);
	return 0;
}

int input_int(int *what, const int buffer, char *description)
{
	char *temp = (char *) malloc(buffer * sizeof(char));

	printf("\t\t%s", description);
	if( !fgets(temp, buffer, stdin) )
	{
		fprintf(stderr, "ОШИБКА: Невозможно прочитать строку\n");
		return 1;
	}	
	if( !sscanf(temp, "%d", what) )
	{
		fprintf(stderr, "ОШИБКА: Невозможно распознать в строке число\n");
		return 1;
	}

	fflush(stdin);
	free(temp);
	return 0;
}

int input_gender(enum gender_t *what, const int buffer, char *description)
{
	char *temp = (char *) malloc(buffer * sizeof(char));

	printf("\t\t%s", description);
	if( !fgets(temp, buffer, stdin) )
	{
		fprintf(stderr, "ОШИБКА: Невозможно прочитать строку\n");
		return 1;
	}	
	if( temp[0] == 'м' || temp[0] == 'М')
		*what = male;
	else if( temp[0] == 'ж' || temp[0] == 'Ж')
		*what = female;
	else
	{
		fprintf(stderr, "ОШИБКА: Не удалось распознать пол\n");
		return 1;
	}

	fflush(stdin);
	free(temp);
	return 0;
}

int input_date(date *what, const int buffer, char *description)
{
	printf("\t\t%s\n", description);

	if( input_int(&what->day, buffer,
		"\tВведите день  -> ") )
		return 1;
	if( input_int(&what->month, buffer,
		"\tВведите месяц -> ") )
		return 1;
	if( input_int(&what->year, buffer,
		"\tВведите год   -> ") )
		return 1;

	return 0;
}

int fill_employee_table(int row)
{
	activated = 1;
	employee_table = realloc( employee_table, sizeof(employee_struct)*(table_row[EMPLOYEE_TABLE]+1) );
	
	printf("\t\tЗаполните таблицу \"Сотрудники\"\n\n");

	if( input_int( &employee_table[row].employee_id, 10,
		"Введите код сотрудника (больше нуля) -> ") )
		return 1;
	if( employee_table[row].employee_id <= 0 )
	{
		fprintf(stderr, "ОШИБКА: введен код меньше нуля, таблица не добавится");
		return 1;
	}

	if( input_string( employee_table[row].name, 255,
		"Введите ФИО -> ") )
		return 1;

	if( input_int( &employee_table[row].age, 4,
		"Введите возраст -> ") )
		return 1;
	if( (employee_table[row].age < 0) || (employee_table[row].age > 110) )
		fprintf(stderr, "ПРЕДУПРЕЖДЕНИЕ: Скорее всего, введен не возраст\n");

	if( input_gender( &employee_table[row].gender, 10,
		"Введите пол -> ") )
		return 1;

	if( input_string( employee_table[row].address, 255,
		"Введите адрес -> ") )
		return 1;

	if( input_string( employee_table[row].phone, 20,
		"Введите телефон -> ") )
		return 1;
	if( !isdigit(employee_table[row].phone[2]) )
		fprintf(stderr, "ПРЕДУПРЕЖДЕНИЕ: Скорее всего, введен не телефон\n");

	if( input_string( employee_table[row].passport, 20,
		"Введите паспортные данные -> ") )
		return 1;
	if( !isdigit(employee_table[row].passport[1]) )
		fprintf(stderr, "ПРЕДУПРЕЖДЕНИЕ: Скорее всего, введены не паспортные данные\n");

	print_position_info();
	if( input_int( &employee_table[row].position_id, 10,
		"Введите код должности (больше нуля) -> ") )
		return 1;
	if( employee_table[row].position_id <= 0 )
	{
		fprintf(stderr, "ОШИБКА: введен код меньше нуля, таблица не добавится");
		return 1;
	}

	table_row[EMPLOYEE_TABLE]++;
	return 0;
}

int fill_position_table(int row)
{
	activated = 1;
	position_table = realloc( position_table, sizeof(position_struct)*(table_row[POSITION_TABLE]+1) );

	printf("\t\tЗаполните таблицу \"Должности\"\n\n");
	if( input_int(&position_table[row].position_id, 10,
		"Введите код должности (больше нуля) -> ") )
		return 1;
	if( position_table[row].position_id <= 0 )
	{
		fprintf(stderr, "ОШИБКА: введен код меньше нуля, таблица не добавится");
		return 1;
	}

	if( input_string(position_table[row].name, 255,
		"Введите наименование -> ") )
		return 1;

	if( input_int(&position_table[row].salary, 10,
		"Введите оклад -> ") )
		return 1;
	if( position_table[row].salary < 0 )
		fprintf(stderr, "ПРЕДУПРЕЖДЕНИЕ: Скорее всего, введен не оклад\n");

	if( input_string(position_table[row].duties, 255,
		"Введите обязанности -> ") )
		return 1;

	if( input_string(position_table[row].requirements, 255,
		"Введите требования -> ") )
		return 1;

	table_row[POSITION_TABLE]++;
	return 0;
}

int fill_brand_table(int row)
{
	activated = 1;
	brand_table = realloc( brand_table, sizeof(brand_struct)*(table_row[BRAND_TABLE]+1) );

	printf("\t\tЗаполните таблицу \"Марки автомобилей\"\n\n");
	if( input_int(&brand_table[row].brand_id, 10,
		"Введите код марки (больше нуля) -> ") )
		return 1;
	if( brand_table[row].brand_id <= 0 )
	{
		fprintf(stderr, "ОШИБКА: введен код меньше нуля, таблица не добавится");
		return 1;
	}

	if( input_string(brand_table[row].name, 255,
		"Введите наименование -> ") )
		return 1;

	if( input_string(brand_table[row].specs, 255,
		"Введите технические характеристики -> ") )
		return 1;

	if( input_string(brand_table[row].description, 255,
		"Введите описание -> ") )
		return 1;

	table_row[BRAND_TABLE]++;
	return 0;
}

int fill_service_table(int row)
{
	activated = 1;
	service_table = realloc( service_table, sizeof(service_struct)*(table_row[SERVICE_TABLE]+1) );

	printf("\t\tЗаполните таблицу \"Дополнительные услуги\"\n\n");
	if( input_int(&service_table[row].service_id, 10,
		"Введите код услуги (больше нуля) -> ") )
		return 1;
	if( service_table[row].service_id <= 0 )
	{
		fprintf(stderr, "ОШИБКА: введен код меньше нуля, таблица не добавится");
		return 1;
	}

	if( input_string(service_table[row].name, 255,
		"Введите наименование -> ") )
		return 1;

	if( input_string(service_table[row].description, 255,
		"Введите описание -> ") )
		return 1;

	if( input_int(&service_table[row].price, 10,
		"Введите цену -> ") )
		return 1;
	if( service_table[row].price < 0 )
		fprintf(stderr, "ПРЕДУПРЕЖДЕНИЕ: Скорее всего, введена не цена\n");

	table_row[SERVICE_TABLE]++;
	return 0;
}

int fill_car_table(int row)
{
	activated = 1;
	car_table = realloc( car_table, sizeof(car_struct)*(table_row[CAR_TABLE]+1) );

	printf("\t\tЗаполните таблицу \"Автомобили\"\n\n");
	if( input_int(&car_table[row].car_id, 10,
		"Введите код автомобиля (больше нуля) -> ") )
		return 1;
	if( car_table[row].car_id <= 0 )
	{
		fprintf(stderr, "ОШИБКА: введен код меньше нуля, таблица не добавится");
		return 1;
	}

	print_brand_info();
	if( input_int(&car_table[row].brand_id, 10,
		"Введите код марки -> ") )
		return 1;

	print_position_info();
	if( input_int(&car_table[row].employee_id, 10,
		"Введите код сотрудника-механика -> ") )
		return 1;

	if( input_int(&car_table[row].reg_number, 20,
		"Введите регистрационный номер -> ") )
		return 1;

	if( input_int(&car_table[row].body_number, 20,
		"Введите номер кузова -> ") )
		return 1;

	if( input_int(&car_table[row].engine_number, 20,
		"Введите номер двигателя -> ") )
		return 1;

	if( input_int(&car_table[row].release_year, 5,
		"Введите год выпуска -> ") )
		return 1;
	if( car_table[row].release_year < 0 )
		fprintf(stderr, "ПРЕДУПРЕЖДЕНИЕ: Скорее всего, введен не год\n");

	if( input_int(&car_table[row].mileage, 10,
		"Введите пробег -> ") )
		return 1;
	if( car_table[row].mileage < 0 )
		fprintf(stderr, "ПРЕДУПРЕЖДЕНИЕ: Скорее всего, введен не пробег\n");

	if( input_int(&car_table[row].price, 10,
		"Введите цену автомобиля -> ") )
		return 1;
	if( car_table[row].price < 0 )
		fprintf(stderr, "ПРЕДУПРЕЖДЕНИЕ: Скорее всего, введена не цена\n");

	if( input_int(&car_table[row].rent_price, 20,
		"Введите цену дня проката -> ") )
		return 1;
	if( car_table[row].rent_price < 0 )
		fprintf(stderr, "ПРЕДУПРЕЖДЕНИЕ: Скорее всего, введена не цена проката\n");

	if( input_date(&car_table[row].maintenance_date, 10,
		"Введите дату последнего ТО") )
		return 1;
	if( car_table[row].maintenance_date.day < 0 ||
		car_table[row].maintenance_date.day > 31 ||
		car_table[row].maintenance_date.month < 0 ||
		car_table[row].maintenance_date.month > 12 ||
		car_table[row].maintenance_date.year < 0 )
		fprintf(stderr, "ПРЕДУПРЕЖДЕНИЕ: Скорее всего, введена не дата последнего ТО\n");

	if( input_string(car_table[row].special_marks, 255,
		"Введите специальные отметки -> ") )
		return 1;

	if( input_string(car_table[row].return_mark, 255,
		"Введите отметку о возврате -> ") )
		return 1;

	table_row[CAR_TABLE]++;
	return 0;
}

int fill_client_table(int row)
{
	activated = 1;
	client_table = realloc( client_table, sizeof(client_struct)*(table_row[CLIENT_TABLE]+1) );

	printf("\t\tЗаполните таблицу \"Клиенты\"\n\n");
	if( input_int(&client_table[row].client_id, 10,
		"Введите код клиента (больше нуля) -> ") )
		return 1;
	if( client_table[row].client_id <= 0 )
	{
		fprintf(stderr, "ОШИБКА: введен код меньше нуля, таблица не добавится");
		return 1;
	}

	if( input_string(client_table[row].name, 255,
		"Введите ФИО -> ") )
		return 1;

	if( input_gender(&client_table[row].gender, 10,
		"Введите пол -> ") )
		return 1;

	if( input_date(&client_table[row].birth_date, 10,
		"Введите дату рождения") )
		return 1;
	if( client_table[row].birth_date.day < 0 ||
		client_table[row].birth_date.day > 31 ||
		client_table[row].birth_date.month < 0 ||
		client_table[row].birth_date.month > 12 ||
		client_table[row].birth_date.year < 0 )
		fprintf(stderr, "ПРЕДУПРЕЖДЕНИЕ: Скорее всего, введена не дата рождения\n");

	if( input_string(client_table[row].address, 255,
		"Введите адрес -> ") )
		return 1;

	if( input_string(client_table[row].phone, 20,
		"Введите телефон -> ") )
		return 1;
	if( !isdigit(client_table[row].phone[2]) )
		fprintf(stderr, "ПРЕДУПРЕЖДЕНИЕ: Скорее всего, введен не телефон\n");

	if( input_string(client_table[row].passport, 20,
		"Введите паспортные данные -> ") )
		return 1;
	if( !isdigit(client_table[row].passport[0]) )
		fprintf(stderr, "ПРЕДУПРЕЖДЕНИЕ: Скорее всего, введены не паспортные данные\n");

	table_row[CLIENT_TABLE]++;
	return 0;
}

int fill_rent_table(int row)
{
	activated = 1;
	rent_table = realloc( rent_table, sizeof(rent_struct)*(table_row[RENT_TABLE]+1) );

	printf("\t\tЗаполните таблицу \"Прокат\"\n\n");
	print_car_info();
	if( input_int(&rent_table[row].car_id, 10,
		"Введите код автомобиля (больше нуля) -> ") )
		return 1;
	if( rent_table[row].car_id <= 0 )
	{
		fprintf(stderr, "ОШИБКА: введен код меньше нуля, таблица не добавится");
		return 1;
	}

	print_client_info();
	if( input_int(&rent_table[row].client_id, 10,
		"Введите код клиента (больше нуля) -> ") )
		return 1;
	if( rent_table[row].client_id <= 0 )
	{
		fprintf(stderr, "ОШИБКА: введен код меньше нуля, таблица не добавится");
		return 1;
	}

	print_employee_info();
	if( input_int(&rent_table[row].employee_id, 10,
		"Введите код сотрудника (больше нуля) -> ") )
		return 1;
	if( rent_table[row].employee_id <= 0 )
	{
		fprintf(stderr, "ОШИБКА: введен код меньше нуля, таблица не добавится");
		return 1;
	}

	print_service_info();
	if( input_int(&rent_table[row].service1_id, 10,
		"Введите код 1-ой услуги (больше нуля) -> ") )
		return 1;
	if( rent_table[row].service1_id <= 0 )
	{
		fprintf(stderr, "ОШИБКА: введен код меньше нуля, таблица не добавится");
		return 1;
	}

	if( input_int(&rent_table[row].service2_id, 10,
		"Введите код 2-ой услуги (больше нуля) -> ") )
		return 1;
	if( rent_table[row].service2_id <= 0 )
	{
		fprintf(stderr, "ОШИБКА: введен код меньше нуля, таблица не добавится");
		return 1;
	}

	if( input_int(&rent_table[row].service3_id, 10,
		"Введите код 3-ой услуги (больше нуля) -> ") )
		return 1;
	if( rent_table[row].service2_id <= 0 )
	{
		fprintf(stderr, "ОШИБКА: введен код меньше нуля, таблица не добавится");
		return 1;
	}

	if( input_date(&rent_table[row].delivery_date, 10,
		"Введите дату выдачи") )
		return 1;
	if( rent_table[row].delivery_date.day < 0 ||
		rent_table[row].delivery_date.day > 31 ||
		rent_table[row].delivery_date.month < 0 ||
		rent_table[row].delivery_date.month > 12 ||
		rent_table[row].delivery_date.year < 0 )
		fprintf(stderr, "ПРЕДУПРЕЖДЕНИЕ: Скорее всего, введена не дата выдачи\n");

	if( input_int(&rent_table[row].rent_time, 10,
		"Введите срок проката -> ") )
		return 1;
	if( rent_table[row].rent_time < 0 )
		fprintf(stderr, "ПРЕДУПРЕЖДЕНИЕ: Скорее всего, введено не время проката\n");

	if( input_date(&rent_table[row].return_date, 10,
		"Введите дату возврата") )
		return 1;
	if( rent_table[row].return_date.day < 0 ||
		rent_table[row].return_date.day > 31 ||
		rent_table[row].return_date.month < 0 ||
		rent_table[row].return_date.month > 12 ||
		rent_table[row].return_date.year < 0 )
		fprintf(stderr, "ПРЕДУПРЕЖДЕНИЕ: Скорее всего, введена не дата возврата\n");

	if( input_int(&rent_table[row].rent_price, 10,
		"Введите цену проката -> ") )
		return 1;
	if( rent_table[row].rent_price < 0 )
		fprintf(stderr, "ПРЕДУПРЕЖДЕНИЕ: Скорее всего, введена не цена проката\n");

	if( input_string(rent_table[row].payment_mark, 255,
		"Введите пометку об оплате -> ") )
		return 1;

	table_row[RENT_TABLE]++;
	return 0;
}