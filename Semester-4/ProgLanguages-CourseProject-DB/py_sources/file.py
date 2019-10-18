# -*- coding: utf-8 -*-

# Подключение модулей
import main
import const
import database

# Встроенные библиотеки
import os
import re


def save_file():
    os.system("clear")

    filename = input("\n\tВведите имя файла -> ")
    mode = input("\tВы хотите стереть данные из этого файла (0 - да, 1 - нет) -> ")

    if mode == 0:
        mode = "w"
    else:
        mode = "a+"

    with open(filename, mode) as f:
        for i in range(0, main.table_row[const.EMPLOYEE_TABLE]):
            if database.employee_table[i].employee_id > 0:
                if database.employee_table[i].gender == database.Gender.male:
                    g = 0
                else:
                    g = 1
                f.write("0;{};{};{};{};{};{};{};{}".format(
                    str(database.employee_table[i].employee_id),
                    str(database.employee_table[i].position_id),
                    database.employee_table[i].name,
                    str(database.employee_table[i].age),
                    str(g),
                    database.employee_table[i].address,
                    database.employee_table[i].phone,
                    database.employee_table[i].passport))
        for i in range(0, main.table_row[const.POSITION_TABLE]):
            if database.position_table[i].position_id > 0:
                f.write("1;{};{};{};{};{}".format(
                    str(database.position_table[i].position_id),
                    database.position_table[i].name,
                    str(database.position_table[i].salary),
                    database.position_table[i].duties,
                    database.position_table[i].requirements))
        for i in range(0, main.table_row[const.BRAND_TABLE]):
            if database.brand_table[i].brand_id > 0:
                f.write("2;{};{};{};{}".format(
                    str(database.brand_table[i].brand_id),
                    database.brand_table[i].name,
                    database.brand_table[i].specs,
                    database.brand_table[i].description))
        for i in range(0, main.table_row[const.SERVICE_TABLE]):
            if database.service_table[i].service_id > 0:
                f.write("3;{};{};{};{}".format(
                    str(database.service_table[i].service_id),
                    database.service_table[i].name,
                    database.service_table[i].description,
                    str(database.service_table[i].price)))
        for i in range(0, main.table_row[const.CAR_TABLE]):
            if database.car_table[i].car_id > 0:
                f.write("4;{};{};{};{};{};{};{};{};{};{};{};{};{};{};{}".format(
                    str(database.car_table[i].car_id),
                    str(database.car_table[i].brand_id),
                    str(database.car_table[i].employee_id),
                    str(database.car_table[i].reg_number),
                    str(database.car_table[i].body_number),
                    str(database.car_table[i].engine_number),
                    str(database.car_table[i].release_year),
                    str(database.car_table[i].mileage),
                    str(database.car_table[i].price),
                    str(database.car_table[i].rent_price),
                    str(database.car_table[i].maintenance_date.day),
                    str(database.car_table[i].maintenance_date.month),
                    str(database.car_table[i].maintenance_date.year),
                    database.car_table[i].special_marks,
                    database.car_table[i].return_mark))
        for i in range(0, main.table_row[const.CLIENT_TABLE]):
            if database.client_table[i].client_id > 0:
                if database.client_table[i].gender == database.Gender.male:
                    g = 0
                else:
                    g = 1
                f.write("5;{};{};{};{};{};{};{};{}".format(
                str(database.client_table[i].client_id),
                database.client_table[i].name,
                g,
                str(database.client_table[i].birth_date.day),
                str(database.client_table[i].birth_date.month),
                str(database.client_table[i].birth_date.year),
                database.client_table[i].address,
                database.client_table[i].phone,
                database.client_table[i].passport))
        for i in range(0, main.table_row[const.RENT_TABLE]):
            if database.rent_table[i].car_id > 0:
                f.write("6;{};{};{};{};{};{};{};{};{};{};{};{};{};{};{}".format(
                    str(database.rent_table[i].car_id),
                    str(database.rent_table[i].client_id),
                    str(database.rent_table[i].employee_id),
                    str(database.rent_table[i].service1_id),
                    str(database.rent_table[i].service2_id),
                    str(database.rent_table[i].service3_id),
                    str(database.rent_table[i].delivery_date.day),
                    str(database.rent_table[i].delivery_date.month),
                    str(database.rent_table[i].delivery_date.year),
                    str(database.rent_table[i].rent_time),
                    str(database.rent_table[i].return_date.day),
                    str(database.rent_table[i].return_date.month),
                    str(database.rent_table[i].return_date.year),
                    str(database.rent_table[i].rent_price),
                    database.rent_table[i].payment_mark))

def load_file():
    main.activated = 1
    main.table_row = [0] * 7
    os.system("clear")

    filename = input("\n\tВведите имя файла -> ")
    with open(filename, "r") as f:
        lines = f.readlines()

    for i in range(0, len(lines)):
        tokens = re.split(r";", lines[i])

        if tokens[0] == "0":
            database.employee_table[main.table_row[const.EMPLOYEE_TABLE]].employee_id = int(tokens[1])
            database.employee_table[main.table_row[const.EMPLOYEE_TABLE]].position_id = int(tokens[2])
            database.employee_table[main.table_row[const.EMPLOYEE_TABLE]].name = tokens[3]
            database.employee_table[main.table_row[const.EMPLOYEE_TABLE]].age = int(tokens[4])
            if tokens[5] == 0:
                database.employee_table[main.table_row[const.EMPLOYEE_TABLE]].gender = database.Gender.male
            else:
                database.employee_table[main.table_row[const.EMPLOYEE_TABLE]].gender = database.Gender.female
            database.employee_table[main.table_row[const.EMPLOYEE_TABLE]].address = tokens[6]
            database.employee_table[main.table_row[const.EMPLOYEE_TABLE]].phone = tokens[7]
            database.employee_table[main.table_row[const.EMPLOYEE_TABLE]].passport = tokens[8]
            main.table_row[const.EMPLOYEE_TABLE] += 1
        elif tokens[0] == "1":
            database.position_table[main.table_row[const.POSITION_TABLE]].position_id = int(tokens[1])
            database.position_table[main.table_row[const.POSITION_TABLE]].name = tokens[2]
            database.position_table[main.table_row[const.POSITION_TABLE]].salary = int(tokens[3])
            database.position_table[main.table_row[const.POSITION_TABLE]].duties = tokens[4]
            database.position_table[main.table_row[const.POSITION_TABLE]].requirements = tokens[5]
            main.table_row[const.POSITION_TABLE] += 1
        elif tokens[0] == "2":
            database.brand_table[main.table_row[const.BRAND_TABLE]].brand_id = int(tokens[1])
            database.brand_table[main.table_row[const.BRAND_TABLE]].name = tokens[2]
            database.brand_table[main.table_row[const.BRAND_TABLE]].specs = tokens[3]
            database.brand_table[main.table_row[const.BRAND_TABLE]].description = tokens[4]
            main.table_row[const.BRAND_TABLE] += 1
        elif tokens[0] == "3":
            database.service_table[main.table_row[const.SERVICE_TABLE]].service_id = int(tokens[1])
            database.service_table[main.table_row[const.SERVICE_TABLE]].name = tokens[2]
            database.service_table[main.table_row[const.SERVICE_TABLE]].description = tokens[3]
            database.service_table[main.table_row[const.SERVICE_TABLE]].price = int(tokens[4])
            main.table_row[const.SERVICE_TABLE] += 1
        elif tokens[0] == "4":
            database.car_table[main.table_row[const.CAR_TABLE]].car_id = int(tokens[1])
            database.car_table[main.table_row[const.CAR_TABLE]].brand_id = int(tokens[2])
            database.car_table[main.table_row[const.CAR_TABLE]].employee_id = int(tokens[3])
            database.car_table[main.table_row[const.CAR_TABLE]].reg_number = int(tokens[4])
            database.car_table[main.table_row[const.CAR_TABLE]].body_number = int(tokens[5])
            database.car_table[main.table_row[const.CAR_TABLE]].engine_number = int(tokens[6])
            database.car_table[main.table_row[const.CAR_TABLE]].release_year = int(tokens[7])
            database.car_table[main.table_row[const.CAR_TABLE]].price = int(tokens[8])
            database.car_table[main.table_row[const.CAR_TABLE]].rent_price = int(tokens[9])
            database.car_table[main.table_row[const.CAR_TABLE]].maintenance_date.day = int(tokens[10])
            database.car_table[main.table_row[const.CAR_TABLE]].maintenance_date.month = int(tokens[11])
            database.car_table[main.table_row[const.CAR_TABLE]].maintenance_date.year = int(tokens[12])
            database.car_table[main.table_row[const.CAR_TABLE]].special_marks = tokens[13]
            database.car_table[main.table_row[const.CAR_TABLE]].return_mark = tokens[14]
            main.table_row[const.CAR_TABLE] += 1
        elif tokens[0] == "5":
            database.client_table[main.table_row[const.CLIENT_TABLE]].client_id = int(tokens[1])
            database.client_table[main.table_row[const.CLIENT_TABLE]].name = tokens[2]
            if tokens[3] == "0":
                database.client_table[main.table_row[const.CLIENT_TABLE]].gender = database.Gender.male
            else:
                database.client_table[main.table_row[const.CLIENT_TABLE]].gender = database.Gender.female
            database.client_table[main.table_row[const.CLIENT_TABLE]].birth_date.day = int(tokens[4])
            database.client_table[main.table_row[const.CLIENT_TABLE]].birth_date.month = int(tokens[5])
            database.client_table[main.table_row[const.CLIENT_TABLE]].birth_date.year = int(tokens[6])
            database.client_table[main.table_row[const.CLIENT_TABLE]].address = tokens[7]
            database.client_table[main.table_row[const.CLIENT_TABLE]].phone = tokens[8]
            database.client_table[main.table_row[const.CLIENT_TABLE]].passport = tokens[9]
            main.table_row[const.CLIENT_TABLE] += 1
        elif tokens[0] == "6":
            database.rent_table[main.table_row[const.RENT_TABLE]].car_id = int(tokens[1])
            database.rent_table[main.table_row[const.RENT_TABLE]].client_id = int(tokens[2])
            database.rent_table[main.table_row[const.RENT_TABLE]].employee_id = int(tokens[3])
            database.rent_table[main.table_row[const.RENT_TABLE]].service1_id = int(tokens[4])
            database.rent_table[main.table_row[const.RENT_TABLE]].service2_id = int(tokens[5])
            database.rent_table[main.table_row[const.RENT_TABLE]].service3_id = int(tokens[6])
            database.rent_table[main.table_row[const.RENT_TABLE]].delivery_date.day = int(tokens[7])
            database.rent_table[main.table_row[const.RENT_TABLE]].delivery_date.month = int(tokens[8])
            database.rent_table[main.table_row[const.RENT_TABLE]].delivery_date.year = int(tokens[9])
            database.rent_table[main.table_row[const.RENT_TABLE]].rent_time = int(tokens[10])
            database.rent_table[main.table_row[const.RENT_TABLE]].return_date.day = int(tokens[11])
            database.rent_table[main.table_row[const.RENT_TABLE]].return_date.month = int(tokens[12])
            database.rent_table[main.table_row[const.RENT_TABLE]].return_date.year = int(tokens[13])
            database.rent_table[main.table_row[const.RENT_TABLE]].rent_price = int(tokens[14])
            database.rent_table[main.table_row[const.RENT_TABLE]].payment_mark = tokens[15]
            main.table_row[const.RENT_TABLE] += 1