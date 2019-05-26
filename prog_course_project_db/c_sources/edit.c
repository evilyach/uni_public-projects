#include "database.h"

int edit_employee_table()
{
	int i, id, row = -1;
	int input;
	
	// Вывод таблицы для наглядности
	print_employee_table();

	// Запрос пользователю выбрать нужную запись
	printf("\n\n\tВ записи с каким кодом Вы хотите поменять значение -> ");
	scanf("%d", &id);
	printf("\n");

	for (i = 0; i < table_row[EMPLOYEE_TABLE]; ++i)
		if( employee_table[i].employee_id == id )
			row = i;
	if( row == -1 )
	{
		fprintf(stderr, "ОШИБКА: Невозможно найти запись с таким кодом\n");
		return 1;
	}

	// Запрос пользователю выбрать нужный элемент записи и изменить его
	printf(
		"\tВведите, какой элемент Вы хотите изменить или удалить\n"
		"\t1 - Код сотрудника\n"
		"\t2 - Код должности\n"
		"\t3 - ФИО\n"
		"\t4 - Возраст\n"
		"\t5 - Пол\n"
		"\t6 - Адрес\n"
		"\t7 - Телефон\n"
		"\t8 - Паспортные данные\n"
		"\t -> ");
	scanf("%d", &input);
	printf("\n");

	// В зависимости от выбора пользователя происходит запрос пользователю
	// на изменение необходимого поля, либо выход из функции
	switch (input)
	{
		case (1):
			printf("\tВведите код сотрудника (больше нуля) -> ");
			if( scanf("%d", &employee_table[row].employee_id) )
				return 1;
			printf("\n");
			if( employee_table[row].employee_id <= 0 )
			{
				fprintf(stderr, "ОШИБКА: введен код меньше нуля, таблица не добавится");
				return 1;
			}
			break;

		case (2):
			print_position_info();
			printf("\tВведите код должности (больше нуля) -> ");
			if( scanf("%d", &employee_table[row].position_id) )
				return 1;
			printf("\n");
			if( employee_table[row].position_id <= 0 )
			{
				fprintf(stderr, "ОШИБКА: введен код меньше нуля, таблица не добавится");
				return 1;
			}
			break;

		case (3):
			printf("\tВведите ФИО -> ");
			if( scanf("%s", employee_table[row].name) )
				return 1;
			printf("\n");
			break;

		case (4):
			printf("\tВведите возраст -> ");
			if( scanf("%d", &employee_table[row].age) )
				return 1;
			printf("\n");
			if( (employee_table[row].age < 0) || (employee_table[row].age > 110) )
				fprintf(stderr, "ПРЕДУПРЕЖДЕНИЕ: Скорее всего, введен не возраст\n");
			break;

		case (5):
			if( input_gender( &employee_table[row].gender, 10,
				"Введите пол -> ") )
				return 1;
			break;

		case (6):
			printf("\tВведите адрес -> ");
			if( scanf("%s", employee_table[row].address) )
				return 1;
			printf("\n");
			break;

		case (7):
			printf("\tВведите телефон -> ");
			if( scanf("%s", employee_table[row].phone) )
				return 1;
			printf("\n");
			if( !isdigit(employee_table[row].phone[2]) )
				fprintf(stderr, "ПРЕДУПРЕЖДЕНИЕ: Скорее всего, введен не телефон\n");
			break;

		case (8):
			printf("\tВведите паспортные данные -> ");
			if( scanf("%s", employee_table[row].passport) )
				return 1;
			printf("\n");
			if( !isdigit(employee_table[row].passport[1]) )
				fprintf(stderr, "ПРЕДУПРЕЖДЕНИЕ: Скорее всего, введены не паспортные данные\n");
			break;
						
		default:
			fprintf(stderr, "ОШИБКА: Невозможно найти в записи такой элемент\n");
			return 1;
	}

	return 0;
}

int edit_position_table()
{
	int i, id, row = -1;
	int input;

	// Вывод таблицы для наглядности
	print_position_table();

	// Запрос пользователю выбрать нужную запись
	printf("\n\n\tВ записи с каким кодом Вы хотите поменять значение -> ");
	scanf("%d", &id);
	printf("\n");

	for (i = 0; i < table_row[POSITION_TABLE]; ++i)
		if( position_table[i].position_id == id )
			row = i;
	if( row == -1 )
	{
		fprintf(stderr, "ОШИБКА: Невозможно найти запись с таким кодом\n");
		return 1;
	}

	// Запрос пользователю выбрать нужный элемент записи и изменить его
	printf(
		"\tВведите, какой элемент Вы хотите изменить или удалить\n"
		"\t1 - Код должности\n"
		"\t2 - Наименование\n"
		"\t3 - Оклад\n"
		"\t4 - Обязанности\n"
		"\t5 - Требования\n"
		"\t -> ");
	scanf("%d", &input);
	printf("\n");

	// В зависимости от выбора пользователя происходит запрос пользователю
	// на изменение необходимого поля, либо выход из функции
	switch (input)
	{
		case (1):
			printf("\tВведите код должности (больше нуля) -> ");
			if( scanf("%d", &position_table[row].position_id) )
				return 1;
			printf("\n");
			if( position_table[row].position_id <= 0 )
			{
				fprintf(stderr, "ОШИБКА: введен код меньше нуля, таблица не добавится");
				return 1;
			}
			break;

		case (2):
			printf("\tВведите наименование -> ");
			if( scanf("%s", position_table[row].name) )
				return 1;
			printf("\n");
			break;

		case (3):
			printf("\tВведите оклад -> ");
			if( scanf("%d", &position_table[row].salary) )
				return 1;
			printf("\n");
			if( position_table[row].salary < 0 )
				fprintf(stderr, "ПРЕДУПРЕЖДЕНИЕ: Скорее всего, введен не оклад\n");
			break;

		case (4):
			printf("\tВведите обязанности -> ");
			if( scanf("%s", position_table[row].requirements) )
				return 1;
			printf("\n");
			break;

		case (5):
			printf("\tВведите требования -> ");
			if( scanf("%s", position_table[row].duties) )
				return 1;
			printf("\n");
			break;
						
		default:
			fprintf(stderr, "ОШИБКА: Невозможно найти в записи такой элемент\n");
			return 1;
	}

	return 0;
}

int edit_brand_table()
{
	int i, id, row = -1;
	int input;

	// Вывод таблицы для наглядности
	print_brand_table();

	// Запрос пользователю выбрать нужную запись
	printf("\n\n\tВ записи с каким кодом Вы хотите поменять значение -> ");
	scanf("%d", &id);
	printf("\n");

	for (i = 0; i < table_row[BRAND_TABLE]; ++i)
		if( brand_table[i].brand_id == id )
			row = i;
	if( row == -1 )
	{
		fprintf(stderr, "ОШИБКА: Невозможно найти запись с таким кодом\n");
		return 1;
	}

	// Запрос пользователю выбрать нужный элемент записи и изменить его
	printf(
		"\tВведите, какой элемент Вы хотите изменить или удалить\n"
		"\t1 - Код марки\n"
		"\t2 - Наименование\n"
		"\t3 - Технические характеристики\n"
		"\t4 - Описание\n"
		"\t -> ");
	scanf("%d", &input);
	printf("\n");

	// В зависимости от выбора пользователя происходит запрос пользователю
	// на изменение необходимого поля, либо выход из функции
	switch (input)
	{
		case (1):
			printf("\tВведите код марки (больше нуля) -> ");
			if( scanf("%d", &brand_table[row].brand_id) )
				return 1;
			printf("\n");
			if( brand_table[row].brand_id <= 0 )
			{
				fprintf(stderr, "ОШИБКА: введен код меньше нуля, таблица не добавится");
				return 1;
			}
			break;

		case (2):
			printf("\tВведите наименование -> ");
			if( scanf("%s", brand_table[row].name) )
				return 1;
			printf("\n");
			break;

		case (3):
			printf("\tВведите технические характеристики -> ");
			if( scanf("%s", brand_table[row].specs) )
				return 1;
			printf("\n");
			break;

		case (4):
			printf("\tВведите описание -> ");
			if( scanf("%s", brand_table[row].description) )
				return 1;
			printf("\n");
			break;
						
		default:
			fprintf(stderr, "ОШИБКА: Невозможно найти в записи такой элемент\n");
			return 1;
	}

	return 0;
}

int edit_service_table()
{
	int i, id, row = -1;
	int input;

	// Вывод таблицы для наглядности
	print_service_table();

	// Запрос пользователю выбрать нужную запись
	printf("\n\n\tВ записи с каким кодом Вы хотите поменять значение -> ");
	scanf("%d", &id);
	printf("\n");

	for (i = 0; i < table_row[SERVICE_TABLE]; ++i)
		if( service_table[i].service_id == id )
			row = i;
	if( row == -1 )
	{
		fprintf(stderr, "ОШИБКА: Невозможно найти запись с таким кодом\n");
		return 1;
	}

	// Запрос пользователю выбрать нужный элемент записи и изменить его
	printf(
		"\tВведите, какой элемент Вы хотите изменить или удалить\n"
		"\t1 - Код услуги\n"
		"\t2 - Наименование\n"
		"\t3 - Описание\n"
		"\t4 - Цена\n"
		"\t -> ");
	scanf("%d", &input);
	printf("\n");

	// В зависимости от выбора пользователя происходит запрос пользователю
	// на изменение необходимого поля, либо выход из функции
	switch (input)
	{
		case (1):
			printf("\tВведите код услуги (больше нуля) -> ");
			if( scanf("%d", &service_table[row].service_id) )
				return 1;
			printf("\n");
			if( service_table[row].service_id <= 0 )
			{
				fprintf(stderr, "ОШИБКА: введен код меньше нуля, таблица не добавится");
				return 1;
			}
			break;

		case (2):
			printf("\tВведите наименование -> ");
			if( scanf("%s", service_table[row].name) )
				return 1;
			printf("\n");
			break;

		case (3):
			printf("\tВведите описание -> ");
			if( scanf("%s", service_table[row].description) )
				return 1;
			printf("\n");
			break;

		case (4):
			printf("\tВведите цену -> ");
			if( scanf("%d", &service_table[row].price) )
				return 1;
			printf("\n");
			if( service_table[row].price < 0 )
				fprintf(stderr, "ПРЕДУПРЕЖДЕНИЕ: Скорее всего, введена не цена\n");
			break;
						
		default:
			fprintf(stderr, "ОШИБКА: Невозможно найти в записи такой элемент\n");
			return 1;
	}

	return 0;
}

int edit_car_table()
{
	int i, id, row = -1;
	int input;

	// Вывод таблицы для наглядности
	print_car_table();

	// Запрос пользователю выбрать нужную запись
	printf("\n\n\tВ записи с каким кодом Вы хотите поменять значение -> ");
	scanf("%d", &id);
	printf("\n");

	for (i = 0; i < table_row[CAR_TABLE]; ++i)
		if( car_table[i].car_id == id )
			row = i;
	if( row == -1 )
	{
		fprintf(stderr, "ОШИБКА: Невозможно найти запись с таким кодом\n");
		return 1;
	}

	// Запрос пользователю выбрать нужный элемент записи и изменить его
	printf(
		"\tВведите, какой элемент Вы хотите изменить или удалить\n"
		"\t1 - Код автомобиля\n"
		"\t2 - Код марки\n"
		"\t3 - Код механика\n"
		"\t4 - Регистрационный номер\n"
		"\t5 - Номер кузова\n"
		"\t6 - Номер двигателя\n"
		"\t7 - Год выпуска\n"
		"\t8 - Пробег\n"
		"\t9 - Цена автомобиля\n"
		"\t10 - Цена дня проката\n"
		"\t11 - День даты последнего ТО\n"
		"\t12 - Месяц даты последнего ТО\n"
		"\t13 - Год даты последнего ТО\n"
		"\t14 - Специальные отметки\n"
		"\t15 - Отметка о возврате"
		"\t -> ");
	scanf("%d", &input);
	printf("\n");

	// В зависимости от выбора пользователя происходит запрос пользователю
	// на изменение необходимого поля, либо выход из функции
	switch (input)
	{
		case (1):
			printf("\tВведите код автомобиля (больше нуля) -> ");
			if( scanf("%d", &car_table[row].car_id) )
				return 1;
			printf("\n");
			if( car_table[row].car_id <= 0 )
			{
				fprintf(stderr, "ОШИБКА: введен код меньше нуля, таблица не добавится");
				return 1;
			}
			break;

		case (2):
			printf("\tВведите код марки (больше нуля) -> ");
			if( scanf("%d", &car_table[row].brand_id) )
				return 1;
			printf("\n");
			if( car_table[row].brand_id <= 0 )
			{
				fprintf(stderr, "ОШИБКА: введен код меньше нуля, таблица не добавится");
				return 1;
			}
			break;

		case (3):
			printf("\tВведите код марки (больше нуля) -> ");
			if( scanf("%d", &car_table[row].employee_id) )
				return 1;
			printf("\n");
			if( car_table[row].employee_id <= 0 )
			{
				fprintf(stderr, "ОШИБКА: введен код меньше нуля, таблица не добавится");
				return 1;
			}
			break;

		case (4):
			printf("\tВведите регистрационный номер -> ");
			if( scanf("%d", &car_table[row].reg_number) )
				return 1;
			printf("\n");
			break;

		case (5):
			printf("\tВведите номер кузова -> ");
			if( scanf("%d", &car_table[row].body_number) )
				return 1;
			printf("\n");
			break;

		case (6):
			printf("\tВведите номер двигателя -> ");
			if( scanf("%d", &car_table[row].engine_number) )
				return 1;
			printf("\n");
			break;

		case (7):
			printf("\tВведите год выпуска -> ");
			if( scanf("%d", &car_table[row].release_year) )
				return 1;
			printf("\n");
			if( car_table[row].release_year < 0 )
				fprintf(stderr, "ПРЕДУПРЕЖДЕНИЕ: Скорее всего, введен не год\n");
			break;

		case (8):
			printf("\tВведите пробег -> ");
			if( scanf("%d", &car_table[row].mileage) )
				return 1;
			printf("\n");
			if( car_table[row].mileage < 0 )
				fprintf(stderr, "ПРЕДУПРЕЖДЕНИЕ: Скорее всего, введен не пробег\n");
			break;

		case (9):
			printf("\tВведите цену автомобиля -> ");
			if( scanf("%d", &car_table[row].price) )
				return 1;
			printf("\n");
			if( car_table[row].price < 0 )
				fprintf(stderr, "ПРЕДУПРЕЖДЕНИЕ: Скорее всего, введена не цена\n");
			break;

		case (10):
			printf("\tВведите цену дня автомобиля -> ");
			if( scanf("%d", &car_table[row].rent_price) )
				return 1;
			printf("\n");
			if( car_table[row].rent_price < 0 )
				fprintf(stderr, "ПРЕДУПРЕЖДЕНИЕ: Скорее всего, введена не цена проката\n");
			break;

		case (11):
			printf("\tВведите день даты последнего ТО -> ");
			if( scanf("%d", &car_table[row].maintenance_date.day) )
				return 1;
			printf("\n");
			if( car_table[row].maintenance_date.day < 0 ||
				car_table[row].maintenance_date.day > 31 )
				fprintf(stderr, "ПРЕДУПРЕЖДЕНИЕ: Скорее всего, введена не день даты последнего ТО\n");
			break;

		case (12):
			printf("\tВведите месяц даты последнего ТО -> ");
			if( scanf("%d", &car_table[row].maintenance_date.month) )
				return 1;
			printf("\n");
			if( car_table[row].maintenance_date.month < 0 ||
				car_table[row].maintenance_date.month > 12 )
				fprintf(stderr, "ПРЕДУПРЕЖДЕНИЕ: Скорее всего, введена не месяц даты последнего ТО\n");
			break;

		case (13):
			printf("\tВведите год даты последнего ТО -> ");
			if( scanf("%d", &car_table[row].maintenance_date.year) )
				return 1;
			printf("\n");
			if( car_table[row].maintenance_date.year < 0 )
				fprintf(stderr, "ПРЕДУПРЕЖДЕНИЕ: Скорее всего, введена не год даты последнего ТО\n");
			break;

		case (14):
			printf("\tВведите специальные отметки -> ");
			if( scanf("%s", car_table[row].special_marks) )
				return 1;
			printf("\n");
			break;

		case (15):
			printf("\tВведите отметку о возврате -> ");
			if( scanf("%s", car_table[row].return_mark) )
				return 1;
			printf("\n");
			break;
						
		default:
			fprintf(stderr, "ОШИБКА: Невозможно найти в записи такой элемент\n");
			return 1;
	}

	return 0;
}

int edit_client_table()
{
	int i, id, row = -1;
	int input;

	// Вывод таблицы для наглядности
	print_client_table();

	// Запрос пользователю выбрать нужную запись
	printf("\n\n\tВ записи с каким кодом Вы хотите поменять значение -> ");
	scanf("%d", &id);
	printf("\n");

	for (i = 0; i < table_row[CLIENT_TABLE]; ++i)
		if( client_table[i].client_id == id )
			row = i;
	if( row == -1 )
	{
		fprintf(stderr, "ОШИБКА: Невозможно найти запись с таким кодом\n");
		return 1;
	}

	// Запрос пользователю выбрать нужный элемент записи и изменить его
	printf(
		"\tВведите, какой элемент Вы хотите изменить или удалить\n"
		"\t1 - Код клиента\n"
		"\t2 - ФИО\n"
		"\t3 - Пол\n"
		"\t4 - День даты рождения\n"
		"\t5 - Месяц даты рождения\n"
		"\t6 - Год даты рождения\n"
		"\t7 - Адрес\n"
		"\t8 - Телефон\n"
		"\t9 - Паспортные данные"
		"\t -> ");
	scanf("%d", &input);
	printf("\n");

	// В зависимости от выбора пользователя происходит запрос пользователю
	// на изменение необходимого поля, либо выход из функции
	switch (input)
	{
		case (1):
			printf("\tВведите код клиента (больше нуля) -> ");
			if( scanf("%d", &client_table[row].client_id) )
				return 1;
			printf("\n");
			if( client_table[row].client_id <= 0 )
			{
				fprintf(stderr, "ОШИБКА: введен код меньше нуля, таблица не добавится");
				return 1;
			}
			break;

		case (2):
			printf("\tВведите ФИО -> ");
			if( scanf("%s", client_table[row].name) )
				return 1;
			printf("\n");
			break;

		case (3):
			if( input_gender( &client_table[row].gender, 10,
				"Введите пол -> ") )
				return 1;
			break;

		case (4):
			printf("\tВведите день даты рождения -> ");
			if( scanf("%d", &client_table[row].birth_date.day) )
				return 1;
			printf("\n");
			if( client_table[row].birth_date.day < 0 ||
				client_table[row].birth_date.day > 31 )
				fprintf(stderr, "ПРЕДУПРЕЖДЕНИЕ: Скорее всего, введен не день даты рождения\n");
			break;

		case (5):
			printf("\tВведите месяц даты рождения -> ");
			if( scanf("%d", &client_table[row].birth_date.month) )
				return 1;
			printf("\n");
			if( client_table[row].birth_date.month < 0 ||
				client_table[row].birth_date.month > 12 )
				fprintf(stderr, "ПРЕДУПРЕЖДЕНИЕ: Скорее всего, введен не месяц день рождения\n");
			break;

		case (6):
			printf("\tВведите год даты рождения -> ");
			if( scanf("%d", &client_table[row].birth_date.year) )
				return 1;
			printf("\n");
			if( client_table[row].birth_date.year < 0 )
				fprintf(stderr, "ПРЕДУПРЕЖДЕНИЕ: Скорее всего, введен не год день рождения\n");
			break;

		case (7):
			printf("\tВведите адрес -> ");
			if( scanf("%s", client_table[row].address) )
				return 1;
			printf("\n");
			break;
	
		case (8):
			printf("\tВведите телефон -> ");
			if( scanf("%s", client_table[row].phone) )
				return 1;
			printf("\n");
			if( !isdigit(client_table[row].phone[2]) )
				fprintf(stderr, "ПРЕДУПРЕЖДЕНИЕ: Скорее всего, введен не телефон\n");
			break;

		case (9):
			printf("\tВведите паспортные данные -> ");
			if( scanf("%s", client_table[row].passport) )
				return 1;
			printf("\n");
			if( !isdigit(client_table[row].passport[1]) )
				fprintf(stderr, "ПРЕДУПРЕЖДЕНИЕ: Скорее всего, введены не паспортные данные\n");
			break;
						
		default:
			fprintf(stderr, "ОШИБКА: Невозможно найти в записи такой элемент\n");
			return 1;
	}

	return 0;
}

int edit_rent_table()
{
	int i, id, row = -1;
	int input;

	// Вывод таблицы для наглядности
	print_client_table();

	// Запрос пользователю выбрать нужную запись
	printf("\n\n\tВ записи с каким кодом Вы хотите поменять значение -> ");
	scanf("%d", &id);
	printf("\n");

	for (i = 0; i < table_row[CLIENT_TABLE]; ++i)
		if( client_table[i].client_id == id )
			row = i;
	if( row == -1 )
	{
		fprintf(stderr, "ОШИБКА: Невозможно найти запись с таким кодом\n");
		return 1;
	}

	// Запрос пользователю выбрать нужный элемент записи и изменить его
	printf(
		"\tВведите, какой элемент Вы хотите изменить или удалить\n"
		"\t1 - Код автомобиля\n"
		"\t2 - Код клиента\n"
		"\t3 - Код сотрудника\n"
		"\t4 - Код услуги 1\n"
		"\t5 - Код услуги 2\n"
		"\t6 - Код услуги 3\n"
		"\t7 - День даты выдачи"
		"\t8 - Месяц даты выдачи"
		"\t9 - Год даты выдачи"
		"\t10 - Срок проката"
		"\t11 - День даты возврата"
		"\t12 - Месяц даты возврата"
		"\t13 - Год даты возврата"
		"\t14 - Цена проката"
		"\t15 - Пометка об оплате"
		"\t -> ");
	scanf("%d", &input);
	printf("\n");

	// В зависимости от выбора пользователя происходит запрос пользователю
	// на изменение необходимого поля, либо выход из функции
	switch (input)
	{
		case (1):
			printf("\tВведите код автомобиля (больше нуля) -> ");
			if( scanf("%d", &rent_table[row].car_id) )
				return 1;
			printf("\n");
			if( rent_table[row].car_id <= 0 )
			{
				fprintf(stderr, "ОШИБКА: введен код меньше нуля, таблица не добавится");
				return 1;
			}
			break;

		case (2):
			printf("\tВведите код клиента (больше нуля) -> ");
			if( scanf("%d", &rent_table[row].client_id) )
				return 1;
			printf("\n");
			if( rent_table[row].client_id <= 0 )
			{
				fprintf(stderr, "ОШИБКА: введен код меньше нуля, таблица не добавится");
				return 1;
			}
			break;

		case (3):
			printf("\tВведите код сотрудника (больше нуля) -> ");
			if( scanf("%d", &rent_table[row].employee_id) )
				return 1;
			printf("\n");
			if( rent_table[row].employee_id <= 0 )
			{
				fprintf(stderr, "ОШИБКА: введен код меньше нуля, таблица не добавится");
				return 1;
			}
			break;

		case (4):
			printf("\tВведите услуги 1 (больше нуля) -> ");
			if( scanf("%d", &rent_table[row].service1_id) )
				return 1;
			printf("\n");
			if( rent_table[row].service1_id <= 0 )
			{
				fprintf(stderr, "ОШИБКА: введен код меньше нуля, таблица не добавится");
				return 1;
			}
			break;

		case (5):
			printf("\tВведите услуги 2 (больше нуля) -> ");
			if( scanf("%d", &rent_table[row].service2_id) )
				return 1;
			printf("\n");
			if( rent_table[row].service2_id <= 0 )
			{
				fprintf(stderr, "ОШИБКА: введен код меньше нуля, таблица не добавится");
				return 1;
			}
			break;

		case (6):
			printf("\tВведите услуги 3 (больше нуля) -> ");
			if( scanf("%d", &rent_table[row].service3_id) )
				return 1;
			printf("\n");
			if( rent_table[row].service3_id <= 0 )
			{
				fprintf(stderr, "ОШИБКА: введен код меньше нуля, таблица не добавится");
				return 1;
			}
			break;

		case (7):
			printf("\tВведите день даты выдачи -> ");
			if( scanf("%d", &rent_table[row].delivery_date.day) )
				return 1;
			printf("\n");
			if( rent_table[row].delivery_date.day < 0 ||
				rent_table[row].delivery_date.day > 31 )
				fprintf(stderr, "ПРЕДУПРЕЖДЕНИЕ: Скорее всего, введена не день даты выдачи\n");
			break;

		case (8):
			printf("\tВведите месяц даты выдачи -> ");
			if( scanf("%d", &rent_table[row].delivery_date.month) )
				return 1;
			printf("\n");
			if( rent_table[row].delivery_date.month < 0 ||
				rent_table[row].delivery_date.month > 12 )
				fprintf(stderr, "ПРЕДУПРЕЖДЕНИЕ: Скорее всего, введена не день даты выдачи\n");
			break;

		case (9):
			printf("\tВведите год даты выдачи -> ");
			if( scanf("%d", &rent_table[row].delivery_date.year) )
				return 1;
			printf("\n");
			if( rent_table[row].delivery_date.year < 0 )
				fprintf(stderr, "ПРЕДУПРЕЖДЕНИЕ: Скорее всего, введена не день даты выдачи\n");
			break;

		case (10):
			printf("\tВведите срок проката -> ");
			if( scanf("%d", &rent_table[row].rent_time) )
				return 1;
			if( rent_table[row].rent_time < 0 )
				fprintf(stderr, "ПРЕДУПРЕЖДЕНИЕ: Скорее всего, введено не время проката\n");
			break;	

		case (11):
			printf("\tВведите день даты возврата -> ");
			if( scanf("%d", &rent_table[row].return_date.day) )
				return 1;
			printf("\n");
			if( rent_table[row].return_date.day < 0 ||
				rent_table[row].return_date.day > 31 )
				fprintf(stderr, "ПРЕДУПРЕЖДЕНИЕ: Скорее всего, введена не день даты возврата\n");
			break;

		case (12):
			printf("\tВведите месяц даты возврата -> ");
			if( scanf("%d", &rent_table[row].return_date.month) )
				return 1;
			printf("\n");
			if( rent_table[row].return_date.month < 0 ||
				rent_table[row].return_date.month > 12 )
				fprintf(stderr, "ПРЕДУПРЕЖДЕНИЕ: Скорее всего, введена не день даты возврата\n");
			break;

		case (13):
			printf("\tВведите год даты возврата -> ");
			if( scanf("%d", &rent_table[row].return_date.year) )
				return 1;
			printf("\n");
			if( rent_table[row].return_date.year < 0 )
				fprintf(stderr, "ПРЕДУПРЕЖДЕНИЕ: Скорее всего, введена не день даты возврата\n");
			break;

		case (14):
			printf("\tВведите цену проката -> ");
			if( scanf("%d", &rent_table[row].rent_price) )
				return 1;
			printf("\n");
			if( rent_table[row].rent_price < 0 )
				fprintf(stderr, "ПРЕДУПРЕЖДЕНИЕ: Скорее всего, введена не цена проката\n");
			break;

		case (15):
			printf("\tВведите пометку об оплате -> ");
			if( scanf("%s", rent_table[row].payment_mark) )
				return 1;
			printf("\n");
			break;

		default:
			fprintf(stderr, "ОШИБКА: Невозможно найти в записи такой элемент\n");
			return 1;
	}

	return 0;
}