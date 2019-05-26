#include "database.h"

void print_employee_table()
{
	int i;
	char g;
	system("cls");

	// Вывод шапки
	printf("\n\tТаблица \"Сотрудники\"\n\n");

	for (i = 0; i < 200; ++i, printf("_"));
	printf("\n");

	printf("| %14.14s | %14.14s | %40.40s | %7.7s | %3.3s | %60.60s | %15.15s | %21.21s |\n",
		"Код сотрудника", "Код должности", "ФИО", "Возраст", 
		"Пол", "Адрес", "Телефон", "Паспортные данные");

	for (i = 0; i < 200; ++i, printf("_"));
		printf("\n\n");

	for (i = 0; i < table_row[EMPLOYEE_TABLE]; ++i)
	{
		if( employee_table[i].gender == 0 )
			g = 'М';
		else
			g = 'Ж';

		if( employee_table[i].employee_id > 0 )		// Проверка на битые записи
			printf("| %14d | %14d | %40.40s | %7d | %3c | %60.60s | %15.15s | %21.21s |\n\n",
				employee_table[i].employee_id,
				employee_table[i].position_id,
				employee_table[i].name,
				employee_table[i].age,
				g,
				employee_table[i].address,
				employee_table[i].phone,
				employee_table[i].passport);
	}
}

void print_position_table()
{
	int i;
	system("cls");

	// Вывод шапки
	printf("\n\tТаблица \"Должности\"\n\n");

	for (i = 0; i < 200; ++i, printf("_"));
	printf("\n");

	printf("| %14.14s | %40.40s | %10.10s | %55.55s | %64.64s |\n",
		"Код должности", "Наименование", "Оклад", "Обязанности", "Требования");

	for (i = 0; i < 200; ++i, printf("_"));
		printf("\n\n");

	for (i = 0; i < table_row[POSITION_TABLE]; ++i)
		if( position_table[i].position_id > 0 )	// Проверка на битые записи
			printf("| %14d | %40.40s | %10d | %55.55s | %64.64s |\n\n",
				position_table[i].position_id,
				position_table[i].name,
				position_table[i].salary,
				position_table[i].duties,
				position_table[i].requirements);
}

void print_brand_table()
{
	int i;
	system("cls");

	// Вывод шапки
	printf("\n\tТаблица \"Марки автомобилей\"\n\n");

	for (i = 0; i < 200; ++i, printf("_"));
	printf("\n");

	printf("| %14.14s | %40.40s | %70.70s | %62.62s |\n",
		"Код марки", "Наименование", "Технические характеристики", "Описание");

	for (i = 0; i < 200; ++i, printf("_"));
		printf("\n\n");

	for (i = 0; i < table_row[BRAND_TABLE]; ++i)
		if( brand_table[i].brand_id > 0 )	// Проверка на битые записи
			printf("| %14d | %40.40s | %70.72s | %62.62s |\n\n",
				brand_table[i].brand_id,
				brand_table[i].name,
				brand_table[i].specs,
				brand_table[i].description);
}

void print_service_table()
{
	int i;
	system("cls");

	// Вывод шапки
	printf("\n\tТаблица \"Дополнительные услуги\"\n\n");

	for (i = 0; i < 200; ++i, printf("_"));
	printf("\n");

	printf("| %14.14s | %40.40s | %122.122s | %10.10s |\n",
		"Код услуги", "Наименование", "Описание", "Цена");

	for (i = 0; i < 200; ++i, printf("_"));
		printf("\n\n");

	for (i = 0; i < table_row[SERVICE_TABLE]; ++i)
		if( service_table[i].service_id > 0 )	// Проверка на битые записи
			printf("| %14d | %40.40s | %122.122s | %10d |\n\n",
				service_table[i].service_id,
				service_table[i].name,
				service_table[i].description,
				service_table[i].price);
}

void print_car_table()
{
	int i;
	system("cls");

	// Вывод шапки
	printf("\n\tТаблица \"Автомобили\"\n\n");

	for (i = 0; i < 200; ++i, printf("_"));
	printf("\n");

	printf("| %14.14s | %14.14s | %14.14s | %10.10s | %10.10s | %10.10s | %8.8s | %10.10s | %10.10s | %10.10s | %10.10s | %20.20s | %19.19s |\n",
		"Код автомобиля", "Код марки", "Код механика", "№ регистр.", "№ кузова",
		"№ двигат.", "Год вып.", "Пробег", "Цена", "Прокат",
		"Дата ТО", "Спец. отм.", "Возврат");

	for (i = 0; i < 200; ++i, printf("_"));
		printf("\n\n");

	for (i = 0; i < table_row[CAR_TABLE]; ++i)
		if( car_table[i].car_id > 0 )	// Проверка на битые записи
			printf("| %14d | %14d | %14d | %10d | %10d | %10d | %8d | %10d | %10d | %10d | %02d.%02d.%04d | %20.20s | %19.19s |\n\n",
				car_table[i].car_id,
				car_table[i].brand_id,
				car_table[i].employee_id,
				car_table[i].reg_number,
				car_table[i].body_number,
				car_table[i].engine_number,
				car_table[i].release_year,
				car_table[i].mileage,
				car_table[i].price,
				car_table[i].rent_price,
				car_table[i].maintenance_date.day,
				car_table[i].maintenance_date.month,
				car_table[i].maintenance_date.year,
				car_table[i].special_marks,
				car_table[i].return_mark);
}

void print_client_table()
{
	int i;
	char g;
	system("cls");

	// Вывод шапки
	printf("\n\tТаблица \"Клиенты\"\n\n");

	for (i = 0; i < 200; ++i, printf("_"));
	printf("\n");

	printf("| %14.14s | %40.40s | %3.3s | %13.13s | %65.65s | %21.21s | %21.21s |\n",
		"Код клиента", "ФИО", "Пол", "Дата рождения", "Адрес",
		"Телефон", "Паспортные данные");

	for (i = 0; i < 200; ++i, printf("_"));
		printf("\n\n");

	for (i = 0; i < table_row[CLIENT_TABLE]; ++i)
	{
		if( client_table[i].gender == 0 )
			g = 'М';
		else
			g = 'Ж';

		if( client_table[i].client_id > 0)	// Проверка на битые записи
			printf("| %14d | %40.40s | %3c |    %02d.%02d.%04d | %65.65s | %21.21s | %21.21s |\n\n",
				client_table[i].client_id,
				client_table[i].name,
				g,
				client_table[i].birth_date.day,
				client_table[i].birth_date.month,
				client_table[i].birth_date.year,
				client_table[i].address,
				client_table[i].phone,
				client_table[i].passport);
	}
}

void print_rent_table()
{
	int i;
	system("cls");

	// Вывод шапки
	printf("\n\tТаблица \"Прокат\"\n\n");

	for (i = 0; i < 200; ++i, printf("_"));
	printf("\n");

	printf("| %14.14s | %14.14s | %14.14s | %14.14s | %14.14s | %14.14s | %13.13s | %12.12s | %13.13s | %12.12s | %31.31s |\n",
		"Код автомобиля", "Код клиента", "Код сотрудника", "Код услуги 1",
		"Код услуги 2", "Код услуги 3", "Дата выдачи", "Срок проката",
		"Дата возврата", "Цена проката", "Пометка об оплате");

	for (i = 0; i < 200; ++i, printf("_"));
		printf("\n\n");

	for (i = 0; i < table_row[RENT_TABLE]; ++i)
		if( rent_table[i].car_id > 0 )	// Проверка на битые записи
			printf("| %14d | %14d | %14d | %14d | %14d | %14d |    %02d.%02d.%04d | %12d |    %02d.%02d.%04d | %12d | %31.31s |\n\n",
				rent_table[i].car_id,
				rent_table[i].client_id,
				rent_table[i].employee_id,
				rent_table[i].service1_id,
				rent_table[i].service2_id,
				rent_table[i].service3_id,
				rent_table[i].delivery_date.day,
				rent_table[i].delivery_date.month,
				rent_table[i].delivery_date.year,
				rent_table[i].rent_time,
				rent_table[i].return_date.day,
				rent_table[i].return_date.month,
				rent_table[i].return_date.year,
				rent_table[i].rent_price,
				rent_table[i].payment_mark);
}

void print_employee_info()
{
	int i;
	printf("\t\t\tДоступные работники:\n");
	for (i = 0; i < table_row[EMPLOYEE_TABLE]; ++i)
		if( employee_table[i].employee_id > 0 )		// Проверка на битые записи
			printf("\t\t\t%d - %s, код должности: %d\n", 
				employee_table[i].employee_id, employee_table[i].name, employee_table[i].position_id);
}
void print_position_info()
{
	int i;
	printf("\t\t\tДоступные должности:\n");
	for (i = 0; i < table_row[POSITION_TABLE]; ++i)
		if( position_table[i].position_id > 0 )	// Проверка на битые записи
			printf("\t\t\t%d - %s\n", position_table[i].position_id, position_table[i].name);
}

void print_brand_info()
{
	int i;
	printf("\t\t\tДоступные марки автомобилей:\n");
	for (i = 0; i < table_row[BRAND_TABLE]; ++i)
		if( brand_table[i].brand_id > 0 )	// Проверка на битые записи
			printf("\t\t\t%d - %s\n", brand_table[i].brand_id, brand_table[i].name);
}

void print_car_info()
{
	int i;
	printf("\t\t\tДоступные автомобили:\n");
	for (i = 0; i < table_row[CAR_TABLE]; ++i)
		if( car_table[i].car_id > 0 )	// Проверка на битые записи
			printf("\t\t\t%d - код марки: %d, регистрационный номер: %d\n",
				car_table[i].car_id, car_table[i].brand_id, car_table[i].reg_number);
}

void print_client_info()
{
	int i;
	printf("\t\t\tДоступные клиенты:\n");
	for (i = 0; i < table_row[CLIENT_TABLE]; ++i)
		if( client_table[i].client_id > 0)	// Проверка на битые записи
			printf("\t\t\t%d - %s\n", client_table[i].client_id, client_table[i].name);
}

void print_service_info()
{
	int i;
	printf("\t\t\tДоступные дополнительные услуги:\n");
	for (i = 0; i < table_row[SERVICE_TABLE]; ++i)
		if( service_table[i].service_id > 0 )	// Проверка на битые записи
			printf("\t\t\t%d - %s\n", service_table[i].service_id, service_table[i].name);
}