#include "database.h"

int edit_employee_table()
{
	int i, id, row = -1;
	int input;
	
	// ����� ������� ��� �����������
	print_employee_table();

	// ������ ������������ ������� ������ ������
	printf("\n\n\t� ������ � ����� ����� �� ������ �������� �������� -> ");
	scanf("%d", &id);
	printf("\n");

	for (i = 0; i < table_row[EMPLOYEE_TABLE]; ++i)
		if( employee_table[i].employee_id == id )
			row = i;
	if( row == -1 )
	{
		fprintf(stderr, "������: ���������� ����� ������ � ����� �����\n");
		return 1;
	}

	// ������ ������������ ������� ������ ������� ������ � �������� ���
	printf(
		"\t�������, ����� ������� �� ������ �������� ��� �������\n"
		"\t1 - ��� ����������\n"
		"\t2 - ��� ���������\n"
		"\t3 - ���\n"
		"\t4 - �������\n"
		"\t5 - ���\n"
		"\t6 - �����\n"
		"\t7 - �������\n"
		"\t8 - ���������� ������\n"
		"\t -> ");
	scanf("%d", &input);
	printf("\n");

	// � ����������� �� ������ ������������ ���������� ������ ������������
	// �� ��������� ������������ ����, ���� ����� �� �������
	switch (input)
	{
		case (1):
			printf("\t������� ��� ���������� (������ ����) -> ");
			if( scanf("%d", &employee_table[row].employee_id) )
				return 1;
			printf("\n");
			if( employee_table[row].employee_id <= 0 )
			{
				fprintf(stderr, "������: ������ ��� ������ ����, ������� �� ���������");
				return 1;
			}
			break;

		case (2):
			print_position_info();
			printf("\t������� ��� ��������� (������ ����) -> ");
			if( scanf("%d", &employee_table[row].position_id) )
				return 1;
			printf("\n");
			if( employee_table[row].position_id <= 0 )
			{
				fprintf(stderr, "������: ������ ��� ������ ����, ������� �� ���������");
				return 1;
			}
			break;

		case (3):
			printf("\t������� ��� -> ");
			if( scanf("%s", employee_table[row].name) )
				return 1;
			printf("\n");
			break;

		case (4):
			printf("\t������� ������� -> ");
			if( scanf("%d", &employee_table[row].age) )
				return 1;
			printf("\n");
			if( (employee_table[row].age < 0) || (employee_table[row].age > 110) )
				fprintf(stderr, "��������������: ������ �����, ������ �� �������\n");
			break;

		case (5):
			if( input_gender( &employee_table[row].gender, 10,
				"������� ��� -> ") )
				return 1;
			break;

		case (6):
			printf("\t������� ����� -> ");
			if( scanf("%s", employee_table[row].address) )
				return 1;
			printf("\n");
			break;

		case (7):
			printf("\t������� ������� -> ");
			if( scanf("%s", employee_table[row].phone) )
				return 1;
			printf("\n");
			if( !isdigit(employee_table[row].phone[2]) )
				fprintf(stderr, "��������������: ������ �����, ������ �� �������\n");
			break;

		case (8):
			printf("\t������� ���������� ������ -> ");
			if( scanf("%s", employee_table[row].passport) )
				return 1;
			printf("\n");
			if( !isdigit(employee_table[row].passport[1]) )
				fprintf(stderr, "��������������: ������ �����, ������� �� ���������� ������\n");
			break;
						
		default:
			fprintf(stderr, "������: ���������� ����� � ������ ����� �������\n");
			return 1;
	}

	return 0;
}

int edit_position_table()
{
	int i, id, row = -1;
	int input;

	// ����� ������� ��� �����������
	print_position_table();

	// ������ ������������ ������� ������ ������
	printf("\n\n\t� ������ � ����� ����� �� ������ �������� �������� -> ");
	scanf("%d", &id);
	printf("\n");

	for (i = 0; i < table_row[POSITION_TABLE]; ++i)
		if( position_table[i].position_id == id )
			row = i;
	if( row == -1 )
	{
		fprintf(stderr, "������: ���������� ����� ������ � ����� �����\n");
		return 1;
	}

	// ������ ������������ ������� ������ ������� ������ � �������� ���
	printf(
		"\t�������, ����� ������� �� ������ �������� ��� �������\n"
		"\t1 - ��� ���������\n"
		"\t2 - ������������\n"
		"\t3 - �����\n"
		"\t4 - �����������\n"
		"\t5 - ����������\n"
		"\t -> ");
	scanf("%d", &input);
	printf("\n");

	// � ����������� �� ������ ������������ ���������� ������ ������������
	// �� ��������� ������������ ����, ���� ����� �� �������
	switch (input)
	{
		case (1):
			printf("\t������� ��� ��������� (������ ����) -> ");
			if( scanf("%d", &position_table[row].position_id) )
				return 1;
			printf("\n");
			if( position_table[row].position_id <= 0 )
			{
				fprintf(stderr, "������: ������ ��� ������ ����, ������� �� ���������");
				return 1;
			}
			break;

		case (2):
			printf("\t������� ������������ -> ");
			if( scanf("%s", position_table[row].name) )
				return 1;
			printf("\n");
			break;

		case (3):
			printf("\t������� ����� -> ");
			if( scanf("%d", &position_table[row].salary) )
				return 1;
			printf("\n");
			if( position_table[row].salary < 0 )
				fprintf(stderr, "��������������: ������ �����, ������ �� �����\n");
			break;

		case (4):
			printf("\t������� ����������� -> ");
			if( scanf("%s", position_table[row].requirements) )
				return 1;
			printf("\n");
			break;

		case (5):
			printf("\t������� ���������� -> ");
			if( scanf("%s", position_table[row].duties) )
				return 1;
			printf("\n");
			break;
						
		default:
			fprintf(stderr, "������: ���������� ����� � ������ ����� �������\n");
			return 1;
	}

	return 0;
}

int edit_brand_table()
{
	int i, id, row = -1;
	int input;

	// ����� ������� ��� �����������
	print_brand_table();

	// ������ ������������ ������� ������ ������
	printf("\n\n\t� ������ � ����� ����� �� ������ �������� �������� -> ");
	scanf("%d", &id);
	printf("\n");

	for (i = 0; i < table_row[BRAND_TABLE]; ++i)
		if( brand_table[i].brand_id == id )
			row = i;
	if( row == -1 )
	{
		fprintf(stderr, "������: ���������� ����� ������ � ����� �����\n");
		return 1;
	}

	// ������ ������������ ������� ������ ������� ������ � �������� ���
	printf(
		"\t�������, ����� ������� �� ������ �������� ��� �������\n"
		"\t1 - ��� �����\n"
		"\t2 - ������������\n"
		"\t3 - ����������� ��������������\n"
		"\t4 - ��������\n"
		"\t -> ");
	scanf("%d", &input);
	printf("\n");

	// � ����������� �� ������ ������������ ���������� ������ ������������
	// �� ��������� ������������ ����, ���� ����� �� �������
	switch (input)
	{
		case (1):
			printf("\t������� ��� ����� (������ ����) -> ");
			if( scanf("%d", &brand_table[row].brand_id) )
				return 1;
			printf("\n");
			if( brand_table[row].brand_id <= 0 )
			{
				fprintf(stderr, "������: ������ ��� ������ ����, ������� �� ���������");
				return 1;
			}
			break;

		case (2):
			printf("\t������� ������������ -> ");
			if( scanf("%s", brand_table[row].name) )
				return 1;
			printf("\n");
			break;

		case (3):
			printf("\t������� ����������� �������������� -> ");
			if( scanf("%s", brand_table[row].specs) )
				return 1;
			printf("\n");
			break;

		case (4):
			printf("\t������� �������� -> ");
			if( scanf("%s", brand_table[row].description) )
				return 1;
			printf("\n");
			break;
						
		default:
			fprintf(stderr, "������: ���������� ����� � ������ ����� �������\n");
			return 1;
	}

	return 0;
}

int edit_service_table()
{
	int i, id, row = -1;
	int input;

	// ����� ������� ��� �����������
	print_service_table();

	// ������ ������������ ������� ������ ������
	printf("\n\n\t� ������ � ����� ����� �� ������ �������� �������� -> ");
	scanf("%d", &id);
	printf("\n");

	for (i = 0; i < table_row[SERVICE_TABLE]; ++i)
		if( service_table[i].service_id == id )
			row = i;
	if( row == -1 )
	{
		fprintf(stderr, "������: ���������� ����� ������ � ����� �����\n");
		return 1;
	}

	// ������ ������������ ������� ������ ������� ������ � �������� ���
	printf(
		"\t�������, ����� ������� �� ������ �������� ��� �������\n"
		"\t1 - ��� ������\n"
		"\t2 - ������������\n"
		"\t3 - ��������\n"
		"\t4 - ����\n"
		"\t -> ");
	scanf("%d", &input);
	printf("\n");

	// � ����������� �� ������ ������������ ���������� ������ ������������
	// �� ��������� ������������ ����, ���� ����� �� �������
	switch (input)
	{
		case (1):
			printf("\t������� ��� ������ (������ ����) -> ");
			if( scanf("%d", &service_table[row].service_id) )
				return 1;
			printf("\n");
			if( service_table[row].service_id <= 0 )
			{
				fprintf(stderr, "������: ������ ��� ������ ����, ������� �� ���������");
				return 1;
			}
			break;

		case (2):
			printf("\t������� ������������ -> ");
			if( scanf("%s", service_table[row].name) )
				return 1;
			printf("\n");
			break;

		case (3):
			printf("\t������� �������� -> ");
			if( scanf("%s", service_table[row].description) )
				return 1;
			printf("\n");
			break;

		case (4):
			printf("\t������� ���� -> ");
			if( scanf("%d", &service_table[row].price) )
				return 1;
			printf("\n");
			if( service_table[row].price < 0 )
				fprintf(stderr, "��������������: ������ �����, ������� �� ����\n");
			break;
						
		default:
			fprintf(stderr, "������: ���������� ����� � ������ ����� �������\n");
			return 1;
	}

	return 0;
}

int edit_car_table()
{
	int i, id, row = -1;
	int input;

	// ����� ������� ��� �����������
	print_car_table();

	// ������ ������������ ������� ������ ������
	printf("\n\n\t� ������ � ����� ����� �� ������ �������� �������� -> ");
	scanf("%d", &id);
	printf("\n");

	for (i = 0; i < table_row[CAR_TABLE]; ++i)
		if( car_table[i].car_id == id )
			row = i;
	if( row == -1 )
	{
		fprintf(stderr, "������: ���������� ����� ������ � ����� �����\n");
		return 1;
	}

	// ������ ������������ ������� ������ ������� ������ � �������� ���
	printf(
		"\t�������, ����� ������� �� ������ �������� ��� �������\n"
		"\t1 - ��� ����������\n"
		"\t2 - ��� �����\n"
		"\t3 - ��� ��������\n"
		"\t4 - ��������������� �����\n"
		"\t5 - ����� ������\n"
		"\t6 - ����� ���������\n"
		"\t7 - ��� �������\n"
		"\t8 - ������\n"
		"\t9 - ���� ����������\n"
		"\t10 - ���� ��� �������\n"
		"\t11 - ���� ���� ���������� ��\n"
		"\t12 - ����� ���� ���������� ��\n"
		"\t13 - ��� ���� ���������� ��\n"
		"\t14 - ����������� �������\n"
		"\t15 - ������� � ��������"
		"\t -> ");
	scanf("%d", &input);
	printf("\n");

	// � ����������� �� ������ ������������ ���������� ������ ������������
	// �� ��������� ������������ ����, ���� ����� �� �������
	switch (input)
	{
		case (1):
			printf("\t������� ��� ���������� (������ ����) -> ");
			if( scanf("%d", &car_table[row].car_id) )
				return 1;
			printf("\n");
			if( car_table[row].car_id <= 0 )
			{
				fprintf(stderr, "������: ������ ��� ������ ����, ������� �� ���������");
				return 1;
			}
			break;

		case (2):
			printf("\t������� ��� ����� (������ ����) -> ");
			if( scanf("%d", &car_table[row].brand_id) )
				return 1;
			printf("\n");
			if( car_table[row].brand_id <= 0 )
			{
				fprintf(stderr, "������: ������ ��� ������ ����, ������� �� ���������");
				return 1;
			}
			break;

		case (3):
			printf("\t������� ��� ����� (������ ����) -> ");
			if( scanf("%d", &car_table[row].employee_id) )
				return 1;
			printf("\n");
			if( car_table[row].employee_id <= 0 )
			{
				fprintf(stderr, "������: ������ ��� ������ ����, ������� �� ���������");
				return 1;
			}
			break;

		case (4):
			printf("\t������� ��������������� ����� -> ");
			if( scanf("%d", &car_table[row].reg_number) )
				return 1;
			printf("\n");
			break;

		case (5):
			printf("\t������� ����� ������ -> ");
			if( scanf("%d", &car_table[row].body_number) )
				return 1;
			printf("\n");
			break;

		case (6):
			printf("\t������� ����� ��������� -> ");
			if( scanf("%d", &car_table[row].engine_number) )
				return 1;
			printf("\n");
			break;

		case (7):
			printf("\t������� ��� ������� -> ");
			if( scanf("%d", &car_table[row].release_year) )
				return 1;
			printf("\n");
			if( car_table[row].release_year < 0 )
				fprintf(stderr, "��������������: ������ �����, ������ �� ���\n");
			break;

		case (8):
			printf("\t������� ������ -> ");
			if( scanf("%d", &car_table[row].mileage) )
				return 1;
			printf("\n");
			if( car_table[row].mileage < 0 )
				fprintf(stderr, "��������������: ������ �����, ������ �� ������\n");
			break;

		case (9):
			printf("\t������� ���� ���������� -> ");
			if( scanf("%d", &car_table[row].price) )
				return 1;
			printf("\n");
			if( car_table[row].price < 0 )
				fprintf(stderr, "��������������: ������ �����, ������� �� ����\n");
			break;

		case (10):
			printf("\t������� ���� ��� ���������� -> ");
			if( scanf("%d", &car_table[row].rent_price) )
				return 1;
			printf("\n");
			if( car_table[row].rent_price < 0 )
				fprintf(stderr, "��������������: ������ �����, ������� �� ���� �������\n");
			break;

		case (11):
			printf("\t������� ���� ���� ���������� �� -> ");
			if( scanf("%d", &car_table[row].maintenance_date.day) )
				return 1;
			printf("\n");
			if( car_table[row].maintenance_date.day < 0 ||
				car_table[row].maintenance_date.day > 31 )
				fprintf(stderr, "��������������: ������ �����, ������� �� ���� ���� ���������� ��\n");
			break;

		case (12):
			printf("\t������� ����� ���� ���������� �� -> ");
			if( scanf("%d", &car_table[row].maintenance_date.month) )
				return 1;
			printf("\n");
			if( car_table[row].maintenance_date.month < 0 ||
				car_table[row].maintenance_date.month > 12 )
				fprintf(stderr, "��������������: ������ �����, ������� �� ����� ���� ���������� ��\n");
			break;

		case (13):
			printf("\t������� ��� ���� ���������� �� -> ");
			if( scanf("%d", &car_table[row].maintenance_date.year) )
				return 1;
			printf("\n");
			if( car_table[row].maintenance_date.year < 0 )
				fprintf(stderr, "��������������: ������ �����, ������� �� ��� ���� ���������� ��\n");
			break;

		case (14):
			printf("\t������� ����������� ������� -> ");
			if( scanf("%s", car_table[row].special_marks) )
				return 1;
			printf("\n");
			break;

		case (15):
			printf("\t������� ������� � �������� -> ");
			if( scanf("%s", car_table[row].return_mark) )
				return 1;
			printf("\n");
			break;
						
		default:
			fprintf(stderr, "������: ���������� ����� � ������ ����� �������\n");
			return 1;
	}

	return 0;
}

int edit_client_table()
{
	int i, id, row = -1;
	int input;

	// ����� ������� ��� �����������
	print_client_table();

	// ������ ������������ ������� ������ ������
	printf("\n\n\t� ������ � ����� ����� �� ������ �������� �������� -> ");
	scanf("%d", &id);
	printf("\n");

	for (i = 0; i < table_row[CLIENT_TABLE]; ++i)
		if( client_table[i].client_id == id )
			row = i;
	if( row == -1 )
	{
		fprintf(stderr, "������: ���������� ����� ������ � ����� �����\n");
		return 1;
	}

	// ������ ������������ ������� ������ ������� ������ � �������� ���
	printf(
		"\t�������, ����� ������� �� ������ �������� ��� �������\n"
		"\t1 - ��� �������\n"
		"\t2 - ���\n"
		"\t3 - ���\n"
		"\t4 - ���� ���� ��������\n"
		"\t5 - ����� ���� ��������\n"
		"\t6 - ��� ���� ��������\n"
		"\t7 - �����\n"
		"\t8 - �������\n"
		"\t9 - ���������� ������"
		"\t -> ");
	scanf("%d", &input);
	printf("\n");

	// � ����������� �� ������ ������������ ���������� ������ ������������
	// �� ��������� ������������ ����, ���� ����� �� �������
	switch (input)
	{
		case (1):
			printf("\t������� ��� ������� (������ ����) -> ");
			if( scanf("%d", &client_table[row].client_id) )
				return 1;
			printf("\n");
			if( client_table[row].client_id <= 0 )
			{
				fprintf(stderr, "������: ������ ��� ������ ����, ������� �� ���������");
				return 1;
			}
			break;

		case (2):
			printf("\t������� ��� -> ");
			if( scanf("%s", client_table[row].name) )
				return 1;
			printf("\n");
			break;

		case (3):
			if( input_gender( &client_table[row].gender, 10,
				"������� ��� -> ") )
				return 1;
			break;

		case (4):
			printf("\t������� ���� ���� �������� -> ");
			if( scanf("%d", &client_table[row].birth_date.day) )
				return 1;
			printf("\n");
			if( client_table[row].birth_date.day < 0 ||
				client_table[row].birth_date.day > 31 )
				fprintf(stderr, "��������������: ������ �����, ������ �� ���� ���� ��������\n");
			break;

		case (5):
			printf("\t������� ����� ���� �������� -> ");
			if( scanf("%d", &client_table[row].birth_date.month) )
				return 1;
			printf("\n");
			if( client_table[row].birth_date.month < 0 ||
				client_table[row].birth_date.month > 12 )
				fprintf(stderr, "��������������: ������ �����, ������ �� ����� ���� ��������\n");
			break;

		case (6):
			printf("\t������� ��� ���� �������� -> ");
			if( scanf("%d", &client_table[row].birth_date.year) )
				return 1;
			printf("\n");
			if( client_table[row].birth_date.year < 0 )
				fprintf(stderr, "��������������: ������ �����, ������ �� ��� ���� ��������\n");
			break;

		case (7):
			printf("\t������� ����� -> ");
			if( scanf("%s", client_table[row].address) )
				return 1;
			printf("\n");
			break;
	
		case (8):
			printf("\t������� ������� -> ");
			if( scanf("%s", client_table[row].phone) )
				return 1;
			printf("\n");
			if( !isdigit(client_table[row].phone[2]) )
				fprintf(stderr, "��������������: ������ �����, ������ �� �������\n");
			break;

		case (9):
			printf("\t������� ���������� ������ -> ");
			if( scanf("%s", client_table[row].passport) )
				return 1;
			printf("\n");
			if( !isdigit(client_table[row].passport[1]) )
				fprintf(stderr, "��������������: ������ �����, ������� �� ���������� ������\n");
			break;
						
		default:
			fprintf(stderr, "������: ���������� ����� � ������ ����� �������\n");
			return 1;
	}

	return 0;
}

int edit_rent_table()
{
	int i, id, row = -1;
	int input;

	// ����� ������� ��� �����������
	print_client_table();

	// ������ ������������ ������� ������ ������
	printf("\n\n\t� ������ � ����� ����� �� ������ �������� �������� -> ");
	scanf("%d", &id);
	printf("\n");

	for (i = 0; i < table_row[CLIENT_TABLE]; ++i)
		if( client_table[i].client_id == id )
			row = i;
	if( row == -1 )
	{
		fprintf(stderr, "������: ���������� ����� ������ � ����� �����\n");
		return 1;
	}

	// ������ ������������ ������� ������ ������� ������ � �������� ���
	printf(
		"\t�������, ����� ������� �� ������ �������� ��� �������\n"
		"\t1 - ��� ����������\n"
		"\t2 - ��� �������\n"
		"\t3 - ��� ����������\n"
		"\t4 - ��� ������ 1\n"
		"\t5 - ��� ������ 2\n"
		"\t6 - ��� ������ 3\n"
		"\t7 - ���� ���� ������"
		"\t8 - ����� ���� ������"
		"\t9 - ��� ���� ������"
		"\t10 - ���� �������"
		"\t11 - ���� ���� ��������"
		"\t12 - ����� ���� ��������"
		"\t13 - ��� ���� ��������"
		"\t14 - ���� �������"
		"\t15 - ������� �� ������"
		"\t -> ");
	scanf("%d", &input);
	printf("\n");

	// � ����������� �� ������ ������������ ���������� ������ ������������
	// �� ��������� ������������ ����, ���� ����� �� �������
	switch (input)
	{
		case (1):
			printf("\t������� ��� ���������� (������ ����) -> ");
			if( scanf("%d", &rent_table[row].car_id) )
				return 1;
			printf("\n");
			if( rent_table[row].car_id <= 0 )
			{
				fprintf(stderr, "������: ������ ��� ������ ����, ������� �� ���������");
				return 1;
			}
			break;

		case (2):
			printf("\t������� ��� ������� (������ ����) -> ");
			if( scanf("%d", &rent_table[row].client_id) )
				return 1;
			printf("\n");
			if( rent_table[row].client_id <= 0 )
			{
				fprintf(stderr, "������: ������ ��� ������ ����, ������� �� ���������");
				return 1;
			}
			break;

		case (3):
			printf("\t������� ��� ���������� (������ ����) -> ");
			if( scanf("%d", &rent_table[row].employee_id) )
				return 1;
			printf("\n");
			if( rent_table[row].employee_id <= 0 )
			{
				fprintf(stderr, "������: ������ ��� ������ ����, ������� �� ���������");
				return 1;
			}
			break;

		case (4):
			printf("\t������� ������ 1 (������ ����) -> ");
			if( scanf("%d", &rent_table[row].service1_id) )
				return 1;
			printf("\n");
			if( rent_table[row].service1_id <= 0 )
			{
				fprintf(stderr, "������: ������ ��� ������ ����, ������� �� ���������");
				return 1;
			}
			break;

		case (5):
			printf("\t������� ������ 2 (������ ����) -> ");
			if( scanf("%d", &rent_table[row].service2_id) )
				return 1;
			printf("\n");
			if( rent_table[row].service2_id <= 0 )
			{
				fprintf(stderr, "������: ������ ��� ������ ����, ������� �� ���������");
				return 1;
			}
			break;

		case (6):
			printf("\t������� ������ 3 (������ ����) -> ");
			if( scanf("%d", &rent_table[row].service3_id) )
				return 1;
			printf("\n");
			if( rent_table[row].service3_id <= 0 )
			{
				fprintf(stderr, "������: ������ ��� ������ ����, ������� �� ���������");
				return 1;
			}
			break;

		case (7):
			printf("\t������� ���� ���� ������ -> ");
			if( scanf("%d", &rent_table[row].delivery_date.day) )
				return 1;
			printf("\n");
			if( rent_table[row].delivery_date.day < 0 ||
				rent_table[row].delivery_date.day > 31 )
				fprintf(stderr, "��������������: ������ �����, ������� �� ���� ���� ������\n");
			break;

		case (8):
			printf("\t������� ����� ���� ������ -> ");
			if( scanf("%d", &rent_table[row].delivery_date.month) )
				return 1;
			printf("\n");
			if( rent_table[row].delivery_date.month < 0 ||
				rent_table[row].delivery_date.month > 12 )
				fprintf(stderr, "��������������: ������ �����, ������� �� ���� ���� ������\n");
			break;

		case (9):
			printf("\t������� ��� ���� ������ -> ");
			if( scanf("%d", &rent_table[row].delivery_date.year) )
				return 1;
			printf("\n");
			if( rent_table[row].delivery_date.year < 0 )
				fprintf(stderr, "��������������: ������ �����, ������� �� ���� ���� ������\n");
			break;

		case (10):
			printf("\t������� ���� ������� -> ");
			if( scanf("%d", &rent_table[row].rent_time) )
				return 1;
			if( rent_table[row].rent_time < 0 )
				fprintf(stderr, "��������������: ������ �����, ������� �� ����� �������\n");
			break;	

		case (11):
			printf("\t������� ���� ���� �������� -> ");
			if( scanf("%d", &rent_table[row].return_date.day) )
				return 1;
			printf("\n");
			if( rent_table[row].return_date.day < 0 ||
				rent_table[row].return_date.day > 31 )
				fprintf(stderr, "��������������: ������ �����, ������� �� ���� ���� ��������\n");
			break;

		case (12):
			printf("\t������� ����� ���� �������� -> ");
			if( scanf("%d", &rent_table[row].return_date.month) )
				return 1;
			printf("\n");
			if( rent_table[row].return_date.month < 0 ||
				rent_table[row].return_date.month > 12 )
				fprintf(stderr, "��������������: ������ �����, ������� �� ���� ���� ��������\n");
			break;

		case (13):
			printf("\t������� ��� ���� �������� -> ");
			if( scanf("%d", &rent_table[row].return_date.year) )
				return 1;
			printf("\n");
			if( rent_table[row].return_date.year < 0 )
				fprintf(stderr, "��������������: ������ �����, ������� �� ���� ���� ��������\n");
			break;

		case (14):
			printf("\t������� ���� ������� -> ");
			if( scanf("%d", &rent_table[row].rent_price) )
				return 1;
			printf("\n");
			if( rent_table[row].rent_price < 0 )
				fprintf(stderr, "��������������: ������ �����, ������� �� ���� �������\n");
			break;

		case (15):
			printf("\t������� ������� �� ������ -> ");
			if( scanf("%s", rent_table[row].payment_mark) )
				return 1;
			printf("\n");
			break;

		default:
			fprintf(stderr, "������: ���������� ����� � ������ ����� �������\n");
			return 1;
	}

	return 0;
}