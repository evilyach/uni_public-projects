# -*- coding: utf-8 -*-

# Подключение модулей
import main
import const
import database

# Встроенные библиотеки
import os

def print_employee_table():
    os.system("clear")

    print("\n\tТаблица \"Сотрудники\"\n")
    for i in range(0, 200):
        print("_", end="")
        print("", end="\n\n")
        print("| {:>14} | {:>14} | {:>40} | {:>7} | {:>3} | {:>60} | {:>15} | {:>21} |".format(
            "Код сотрудника",
            "Код должности",
            "ФИО",
            "Возраст",
            "Пол",
            "Адрес",
            "Телефон",
            "Паспортные данные"))

    for i in range(0, 200):
        print("_", end="")
        print("", end="\n\n")

    for i in range(0, main.table_row[const.EMPLOYEE_TABLE]):
        if database.employee_table[i].gender == database.Gender.male:
            gend = "М"
        else:
            gend = "Ж"

        if database.employee_table[i].employee_id > 0:
            print("| {:>14} | {:>14} | {:>40} | {:>7} | {:>3} | {:>60} | {:>15} | {:>21} |".format(
                database.employee_table[i].employee_id,
                database.employee_table[i].position_id,
                database.employee_table[i].name,
                database.employee_table[i].age,
                gend,
                database.employee_table[i].address,
                database.employee_table[i].phone,
                database.employee_table[i].passport))


def print_position_table():
    os.system("clear")

    print("\n\tТаблица \"Должности\"\n")
    for i in range(0, 200):
        print("_", end="")
        print("", end="\n\n")
        print("| {:>14} | {:>40} | {:>10} | {:>55} | {:>64} |".format(
            "Код должности",
            "Наименование",
            "Оклад",
            "Обязанности",
            "Требования"))

    for i in range(0, 200):
        print("_", end="")
        print("", end="\n\n")

    for i in range(0, main.table_row[const.POSITION_TABLE]):
        if database.position_table[i].position_id > 0:
            print("| {:>14} | {:>40} | {:>10} | {:>55} | {:>64} |".format(
                database.position_table[i].position_id,
                database.position_table[i].name,
                database.position_table[i].salary,
                database.position_table[i].duties,
                database.position_table[i].requirements))


def print_brand_table():
    os.system("clear")

    print("\n\tТаблица \"Марки автомобилей\"\n")
    for i in range(0, 200):
        print("_", end="")
        print("", end="\n\n")
        print("| {:>14} | {:>40} | {:>70} | {:>62} |".format(
            "Код марки",
            "Наименование",
            "Технические характристики",
            "Описание"))

    for i in range(0, 200):
        print("_", end="")
        print("", end="\n\n")

    for i in range(0, main.table_row[const.BRAND_TABLE]):
        if database.brand_table[i].brand_id > 0:
            print("| {:>14} | {:>40} | {:>70} | {:>62} |".format(
                database.brand_table[i].brand_id,
                database.brand_table[i].name,
                database.brand_table[i].specs,
                database.brand_table[i].description))


def print_service_table():
    os.system("clear")

    print("\n\tТаблица \"Дополнительные услуги\"\n")
    for i in range(0, 200):
        print("_", end="")
        print("", end="\n\n")
        print("| {:>14} | {:>40} | {:>122} | {:>10} |".format(
            "Код услуги",
            "Наименование",
            "Описание",
            "Цена"))

    for i in range(0, 200):
        print("_", end="")
        print("", end="\n\n")

    for i in range(0, main.table_row[const.SERVICE_TABLE]):
        if database.service_table[i].service_id > 0:
            print("| {:>14} | {:>40} | {:>122} | {:>10} |".format(
                database.service_table[i].service_id,
                database.service_table[i].name,
                database.service_table[i].description,
                database.service_table[i].price))


def print_car_table():
    os.system("clear")

    print("\n\tТаблица \"Автомобили\"\n")
    for i in range(0, 200):
        print("_", end="")
        print("", end="\n\n")
        print("| {:>14} | {:>14} | {:>14} | {:>10} | {:>10} | {:>10} | {:>8} | {:>10} | {:>10} | {:>10} | {:>10} | {:>20} | {:>19} |".format(
            "Код автомобиля",
            "Код марки",
            "Код механика",
            "№ регистр.",
            "№ кузова",
            "№ двигат.",
            "Год вып.",
            "Пробег",
            "Цена",
            "Прокат",
            "Дата ТО",
            "Спец. отм.",
            "Возврат"))

    for i in range(0, 200):
        print("_", end="")
        print("", end="\n\n")

    for i in range(0, main.table_row[const.SERVICE_TABLE]):
        if database.service_table[i].service_id > 0:
            print("| {:>14} | {:>14} | {:>14} | {:>10} | {:>10} | {:>10} | {:>8} | {:>10} | {:>10} | {:>10} | {:>2}.{:>2}.{:>4} | {:>20} | {:>19} |".format(
                database.car_table[i].car_id,
                database.car_table[i].brand_id,
                database.car_table[i].employee_id,
                database.car_table[i].reg_number,
                database.car_table[i].body_number,
                database.car_table[i].engine_number,
                database.car_table[i].release_year,
                database.car_table[i].mileage,
                database.car_table[i].price,
                database.car_table[i].rent_price,
                database.car_table[i].maintenance_date.day,
                database.car_table[i].maintenance_date.month,
                database.car_table[i].maintenance_date.year,
                database.car_table[i].special_marks,
                database.car_table[i].return_mark))


def print_client_table():
    os.system("clear")

    print("\n\tТаблица \"Клиенты\"\n")
    for i in range(0, 200):
        print("_", end="")
        print("", end="\n\n")
        print("| {:>14} | {:>40} | {:>3} | {:>13} | {:>65} | {:>21} | {:>21} |".format(
            "Код клиента",
            "ФИО",
            "Пол",
            "Дата рождения",
            "Адрес",
            "Телефон",
            "Паспортные данные"))

    for i in range(0, 200):
        print("_", end="")
        print("", end="\n\n")

    for i in range(0, main.table_row[const.EMPLOYEE_TABLE]):
        if database.employee_table[i].gender == database.Gender.male:
            gend = "М"
        else:
            gend = "Ж"

        if database.employee_table[i].employee_id > 0:
            print("| {:>14} | {:>40} | {:>3} | {:>2}.{:>2}.{:>4} | {:>65} | {:>21} | {:>21} |".format(
                database.client_table[i].client_id,
                database.client_table[i].name,
                gend,
                database.client_table[i].birth_date.day,
                database.client_table[i].birth_date.month,
                database.client_table[i].birth_date.year,
                database.client_table[i].address,
                database.client_table[i].phone,
                database.client_table[i].passport))


def print_rent_table():
    os.system("clear")

    print("\n\tТаблица \"Прокат\"\n")
    for i in range(0, 200):
        print("_", end="")
        print("", end="\n\n")
        print("| {:>14} | {:>14} | {:>14} | {:>14} | {:>14} | {:>14} | {:>13} | {:>12} | {:>13} | {:>12} | {:>31} |".format(
            "Код автомобиля",
            "Код клиента",
            "Код сотрудника",
            "Код услуги 1",
            "Код услуги 2",
            "Код услуги 3",
            "Дата выдачи",
            "Срок проката",
            "Дата возврата",
            "Цена проката",
            "Пометка об оплате"))

    for i in range(0, 200):
        print("_", end="")
        print("", end="\n\n")

    for i in range(0, main.table_row[const.SERVICE_TABLE]):
        if database.service_table[i].service_id > 0:
            print("| {:>14} | {:>14} | {:>14} | {:>14} | {:>14} | {:>14} | {:>2}.{:>2}.{:>4} | {:>12} | {:>2}.{:>2}.{:>4} | {:>12} | {:>31} |".format(
                database.rent_table[i].car_id,
                database.rent_table[i].client_id,
                database.rent_table[i].employee_id,
                database.rent_table[i].service1_id,
                database.rent_table[i].service2_id,
                database.rent_table[i].service3_id,
                database.rent_table[i].delivery_date.day,
                database.rent_table[i].delivery_date.month,
                database.rent_table[i].delivery_date.year,
                database.rent_table[i].rent_time,
                database.rent_table[i].return_date.day,
                database.rent_table[i].return_date.month,
                database.rent_table[i].return_date.year,
                database.rent_table[i].rent_price,
                database.rent_table[i].payment_mark))


def print_employee_info():
    print("\t\tДоступные работники:")
    for i in range(0, main.table_row[const.EMPLOYEE_TABLE]):
        if database.employee_table[i].employee_id > 0:
            print("\t\t{} - {}, код должности: {}".format(
                database.employee_table[i].employee_id,
                database.employee_table[i].name,
                database.employee_table[i].position_id))


def print_position_info():
    print("\t\tДоступные работники:")
    for i in range(0, main.table_row[const.POSITION_TABLE]):
        if database.position_table[i].position_id > 0:
            print("\t\t{} - {}".format(
                database.position_table[i].position_id,
                database.position_table[i].name))


def print_brand_info():
    print("\t\tДоступные марки автомобилей:")
    for i in range(0, main.table_row[const.BRAND_TABLE]):
        if database.brand_table[i].brand_id > 0:
            print("\t\t{} - {}".format(
                database.brand_table[i].brand_id,
                database.brand_table[i].name))


def print_service_info():
    print("\t\tДоступные дополнительные услуги:")
    for i in range(0, main.table_row[const.SERVICE_TABLE]):
        if database.service_table[i].service_id > 0:
            print("\t\t{} - {}".format(
                database.service_table[i].service_id,
                database.service_table[i].name))


def print_car_info():
    print("\t\tДоступные автомобили:")
    for i in range(0, main.table_row[const.CAR_TABLE]):
        if database.car_table[i].car_id > 0:
            print("\t\t{} - код марки: {}, регистрационный номер: {}".format(
                database.car_table[i].car_id,
                database.car_table[i].brand_id,
                database.car_table[i].reg_number))


def print_client_info():
    print("\t\tДоступные клиенты:")
    for i in range(0, main.table_row[const.CLIENT_TABLE]):
        if database.client_table[i].client_id > 0:
            print("\t\t{} - {}".format(
                database.client_table[i].client_id,
                database.client_table[i].name))