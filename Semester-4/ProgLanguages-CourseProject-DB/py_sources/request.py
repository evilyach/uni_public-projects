# -*- coding: utf-8 -*-

# Подключение модулей
import main
import const
import database
import out

# Встроенные библиотеки
import os


def hrd_request():
    os.system("clear")

    print("\n\tОтчет по запросу \"Отдел кадров\"\n")
    for i in range(0, main.table_row[const.EMPLOYEE_TABLE]):
        # Для корректного вывода пола
        if database.employee_table[i].gender == database.Gender.male:
            gend = "Мужской"
        else:
            gend = "Женский"

        print("\tНомер записи: {}".format(i+1))
        print("\tКод сотрудника: {}".format(database.employee_table[i].employee_id))
        print("\tФИО: {}".format(database.employee_table[i].name))
        print("\tВозраст: {}".format(database.employee_table[i].age))
        print("\tПол: {}".format(gend))
        print("\tАдрес: {}".format(database.employee_table[i].address))
        print("\tТелефон: {}".format(database.employee_table[i].phone))
        print("\tПаспортные данные: {}".format(database.employee_table[i].passport))
        print("\tКод должности: {}".format(database.employee_table[i].position_id))

        # Поиск соответствующей должности по коду и дальнейший вывод
        for j in range(1, main.table_row[const.POSITION_TABLE]):
            if database.employee_table[i].position_id == database.position_table[j].position_id:
                print("\tНаименование должности: {}".format(database.position_table[j].name))
                print("\tОклад: {}".format(database.position_table[j].salary))
                print("\tОбязанности: {}".format(database.position_table[j].duties))
                print("\tТребования: {}".format(database.position_table[j].requirements))


def autopark_request():
    os.system("clear")

    print("\n\tОтчет по запросу \"Автопарк\"\n")
    for i in range(0, main.table_row[const.CAR_TABLE]):
        print("\tНомер записи: {}".format(i+1))
        print("\tКод автомобиля: {}".format(database.car_table[i].car_id))
        print("\tРегистрационный номер: {}".format(database.car_table[i].reg_number))
        print("\tНомер кузова: {}".format(database.car_table[i].body_number))
        print("\tНомер двигателя: {}".format(database.car_table[i].engine_number))
        print("\tГод выпуска: {}".format(database.car_table[i].release_year))
        print("\tПробег: {}".format(database.car_table[i].mileage))
        print("\tЦена автомобиля: {}".format(database.car_table[i].price))
        print("\tЦена дня проката: {}".format(database.car_table[i].rent_price))
        print("\tДата последнего ТО: {:>2}.{:>2}.{:>4}".format(
            database.car_table[i].maintenance_date.day,
            database.car_table[i].maintenance_date.month,
            database.car_table[i].maintenance_date.year))
        print("\tСпециальные отметки: {}".format(database.car_table[i].special_marks))
        print("\tОтметка о возврате: {}".format(database.car_table[i].return_mark))
        print("\tКод марки: {}".format(database.car_table[i].brand_id))

        for j in range(0, main.table_row[const.BRAND_TABLE]):
            if database.car_table[i].brand_id == database.brand_table[j].brand_id:
                print("\tНаименование марки: {}".format(database.brand_table[j].name))
                print("\tТехнические характеристики: {}".format(database.brand_table[j].specs))
                print("\tОписание: {}".format(database.brand_table[j].description))

        print("\tКод сотрудника-механика: {}".format(database.car_table[i].employee_id))

        for j in range(0, main.table_row[const.EMPLOYEE_TABLE]):
            if database.car_table[i].employee_id == database.employee_table[j].employee_id:
                # Для корректного вывода пола
                if database.employee_table[j].gender == database.Gender.male:
                    gend = "Мужской"
                else:
                    gend = "Женский"

            print("\tНомер записи: {}".format(j+1))
            print("\tКод сотрудника: {}".format(database.employee_table[j].employee_id))
            print("\tФИО: {}".format(database.employee_table[j].name))
            print("\tВозраст: {}".format(database.employee_table[j].age))
            print("\tПол: {}".format(gend))
            print("\tАдрес: {}".format(database.employee_table[j].address))
            print("\tТелефон: {}".format(database.employee_table[j].phone))
            print("\tПаспортные данные: {}".format(database.employee_table[j].passport))
            print("\tКод должности: {}".format(database.employee_table[j].position_id))

            # Поиск соответствующей должности по коду и дальнейший вывод
            for k in range(1, main.table_row[const.POSITION_TABLE]):
                if database.employee_table[j].position_id == database.position_table[k].position_id:
                    print("\tНаименование должности: {}".format(database.position_table[k].name))
                    print("\tОклад: {}".format(database.position_table[k].salary))
                    print("\tОбязанности: {}".format(database.position_table[k].duties))
                    print("\tТребования: {}".format(database. position_table[k].requirements))


def rent_request():
    os.system("clear")

    print("\n\tОтчет по запросу \"Автомобили в прокате\"\n")
    for i in range(0, main.table_row[const.RENT_TABLE]):
        print("\tНомер записи: {}".format(i+1))
        print("\tКод автомобиля: {}".format(database.rent_table[i].car_id))

        for j in range(0, main.table_row[const.CAR_TABLE]):
            if database.rent_table[i].car_id == database.car_table[j].car_id:
                print("\tНомер записи: {}".format(j+1))
                print("\tКод автомобиля: {}".format(database.car_table[j].car_id))
                print("\tРегистрационный номер: {}".format(database.car_table[j].reg_number))
                print("\tНомер кузова: {}".format(database.car_table[j].body_number))
                print("\tНомер двигателя: {}".format(database.car_table[j].engine_number))
                print("\tГод выпуска: {}".format(database.car_table[j].release_year))
                print("\tПробег: {}".format(database.car_table[j].mileage))
                print("\tЦена автомобиля: {}".format(database.car_table[j].price))
                print("\tЦена дня проката: {}".format(database.car_table[j].rent_price))
                print("\tДата последнего ТО: {:>2}.{:>2}.{:>4}".format(
                    database.car_table[j].maintenance_date.day,
                    database.car_table[j].maintenance_date.month,
                    database.car_table[j].maintenance_date.year))
                print("\tСпециальные отметки: {}".format(database.car_table[j].special_marks))
                print("\tОтметка о возврате: {}".format(database.car_table[j].return_mark))
                print("\tКод марки: {}".format(database.car_table[j].brand_id))

                for k in range(0, main.table_row[const.BRAND_TABLE]):
                    if database.car_table[j].brand_id == database.brand_table[k]. brand_id:
                        print("\tНаименование марки: {}".format(database.brand_table[k].name))
                        print("\tТехнические характеристики: {}".format(database.brand_table[k].specs))
                        print("\tОписание: {}".format(database.brand_table[k].description))

                print("\tКод сотрудника-механика: {}".format(database.car_table[j].employee_id))

                for k in range(0, main.table_row[const.EMPLOYEE_TABLE]):
                    if database.car_table[j].employee_id == database.employee_table[k].employee_id:
                        # Для корректного вывода пола
                        if database.employee_table[k].gender == database.Gender.male:
                            gend = "Мужской"
                        else:
                            gend = "Женский"

                        print("\tНомер записи: {}".format(k+1))
                        print("\tКод сотрудника: {}".format(database.employee_table[k].employee_id))
                        print("\tФИО: {}".format(database.employee_table[k].name))
                        print("\tВозраст: {}".format(database.employee_table[k].age))
                        print("\tПол: {}".format(gend))
                        print("\tАдрес: {}".format(database.employee_table[k].address))
                        print("\tТелефон: {}".format(database.employee_table[k].phone))
                        print("\tПаспортные данные: {}".format(database.employee_table[k].passport))
                        print("\tКод должности: {}".format(database.employee_table[k].position_id))

                        # Поиск соответствующей должности по коду и дальнейший вывод
                        for l in range(1, main.table_row[const.POSITION_TABLE]):
                            if database.employee_table[k].position_id == database.position_table[l].position_id:
                                print("\tНаименование должности:{}".format(database.position_table[l].name))
                                print("\tОклад: {}".format(database.position_table[l].salary))
                                print("\tОбязанности: {}".format(database.position_table[l].duties))
                                print("\tТребования: {}".format(database.position_table[l].requirements))
                                print("\tКод клиента: {}".format(database.rent_table[i].client_id))

                for j in range(0, main.table_row[const.CLIENT_TABLE]):
                    if database.rent_table[i].client_id == database.client_table[j].client_id:
                        if database.client_table[j].gender == database.Gender.male:
                            gend = "Мужской"
                        else:
                            gend = "Женский"

                        print("\tФИО: {}".format(database.client_table[j].name))
                        print("\tПол: {}".format(gend))
                        print("\tДата рождения: {:>2}.{:>2}.{:>4}".format(
                            database.client_table[j].birth_date.day,
                            database.client_table[j].birth_date.month,
                            database.client_table[j].birth_date.year))
                        print("\tТелефон: {}".format(database.client_table[j].phone))
                        print("\tПаспортные данные: {}".format(database.client_table[j].passport))
                        print("\tКод должности: {}".format(database.client_table[j].position_id))
                        print("\tКод сотрудника: {}".format(database.rent_table[i].employee_id))

                for j in range(0, main.table_row[const.EMPLOYEE_TABLE]):
                    if database.rent_table[i].employee_id == database.client_table[j].employee_id:
                        # Для корректного вывода пола
                        if database.employee_table[j].gender == database.Gender.male:
                            gend = "Мужской"
                        else:
                            gend = "Женский"

                        print("\tНомер записи: {}".format(j+1))
                        print("\tКод сотрудника: {}".format(database.employee_table[j].employee_id))
                        print("\tФИО: {}".format(database.employee_table[j].name))
                        print("\tВозраст: {}".format(database.employee_table[j].age))
                        print("\tПол: {}".format(gend))
                        print("\tАдрес: {}".format(database.employee_table[j].address))
                        print("\tТелефон: {}".format(database.employee_table[j].phone))
                        print("\tПаспортные данные: {}".format(database.employee_table[j].passport))
                        print("\tКод должности: {}".format(database.employee_table[j].position_id))

                        # Поиск соответствующей должности по коду и дальнейший вывод
                        for k in range(1, main.table_row[const.POSITION_TABLE]):
                            if database.employee_table[j].position_id == database.position_table[k].position_id:
                                print("\tНаименование должности: {}".format(database. 
                                position_table[k].name))
                                print("\tОклад: {}".format(database.position_table[k]. 
                                salary))
                                print("\tОбязанности: {}".format(database.position_table[k].
                                duties))
                                print("\tТребования: {}".format(database.position_table[k]. 
                                requirements))

                print("\tКод услуги 1: {}".format(database.rent_table[i].service1_id))
                for j in range(0, main.table_row[const.SERVICE_TABLE]):
                    if database.rent_table[i].service1_id == database.service_table[j].service_id:
                        print("\tНаименование: {}".format(database.service_table[j].name))
                        print("\tОписание: {}".format(database.service_table[j].description))
                        print("\tЦена: {}".format(database.service_table[j].price))

                print("\tКод услуги 2: {}".format(database.rent_table[i].service2_id))
                for j in range(0, main.table_row[const.SERVICE_TABLE]):
                    if database.rent_table[i].service2_id == database.service_table[j].service_id:
                        print("\tНаименование: {}".format(database.service_table[j].name))
                        print("\tОписание: {}".format(database.service_table[j].description))
                        print("\tЦена: {}".format(database.service_table[j].price))

                print("\tКод услуги 3: {}".format(database.rent_table[i].service3_id))
                for j in range(0, main.table_row[const.SERVICE_TABLE]):
                    if database.rent_table[i].service3_id == database.service_table[j].service_id:
                        print("\tНаименование: {}".format(database.service_table[j].name))
                        print("\tОписание: {}".format(database.service_table[j].description))
                        print("\tЦена: {}".format(database.service_table[j].price))

                print("\tДата выдачи: {:>2}.{:>2}.{:>4}".format(
                    database.rent_table[i].delivery_date.day,
                    database.rent_table[i].delivery_date.month,
                    database.rent_table[i].delivery_date.year))
                print("\tСрок проката: {}".format(database.rent_table[i].rent_table))
                print("\tДата возврата: {:>2}.{:>2}.{:>4}".format(
                    database.rent_table[i].return_date.day,
                    database.rent_table[i].return_date.month,
                    database.rent_table[i].return_date.year))
                print("\tЦена проката: {}".format(database.rent_table[i].rent_price))
                print("\tПометка об оплате: {}".format(database.rent_table[i].payment_mark))


def hrd_filter_specific_position():
    os.system("clear")

    # Ввод фильтра
    out.print_position_info()
    temp = input("\n\tВведите код должности -> ")
    print("\n\tОтчет по запросу \"Отдел кадров\" с фильтром для отображения")
    print("\tсотрудников отдельных должностей\n")

    for i in range(0, main.table_row[const.EMPLOYEE_TABLE]):
        if temp == database.employee_table[i].position_id:
            # Для корректного вывода пола
            if database.employee_table[i].gender == database.Gender.male:
                gend = "Мужской"
            else:
                gend = "Женский"

            print("\tНомер записи: {}".format(i+1))
            print("\tКод сотрудника: {}".format(database.employee_table[i].employee_id))
            print("\tФИО: {}".format(database.employee_table[i].name))
            print("\tВозраст: {}".format(database.employee_table[i].age))
            print("\tПол: {}".format(gend))
            print("\tАдрес: {}".format(database.employee_table[i].address))
            print("\tТелефон: {}".format(database.employee_table[i].phone))
            print("\tПаспортные данные: {}".format(database.employee_table[i].passport))
            print("\tКод должности: {}".format(database.employee_table[i].position_id))

            # Поиск соответствующей должности по коду и дальнейший вывод
            for j in range(1, main.table_row[const.POSITION_TABLE]):
                if database.employee_table[i].position_id == database.position_table[j].position_id:
                    print("\tНаименование должности: {}".format(database.position_table[j].name))
                    print("\tОклад: {}".format(database.position_table[j].salary))
                    print("\tОбязанности: {}".format(database.position_table[j].duties))
                    print("\tТребования: {}".format(database.position_table[j].requirements))


def autopark_filter_specific_brand():
    os.system("clear")

    # Ввод фильтра
    out.print_brand_info()
    temp = input("\n\tВведите код марки -> ")
    print("\n\tОтчет по запросу \"Автопарк\" c фильтром для отображения")
    print("\tавтомобилей отдельных марок\n")

    for i in range(0, main.table_row[const.CAR_TABLE]):
        if temp == database.car_table[i].brand_id:
            print("\tНомер записи: {}".format(i+1))
            print("\tКод автомобиля: {}".format(database.car_table[i].car_id))
            print("\tРегистрационный номер: {}".format(database.car_table[i]. 
            reg_number))
            print("\tНомер кузова: {}".format(database.car_table[i].body_number))
            print("\tНомер двигателя: {}".format(database.car_table[i]. 
            engine_number))
            print("\tГод выпуска: {}".format(database.car_table[i].release_year))
            print("\tПробег: {}".format(database.car_table[i].mileage))
            print("\tЦена автомобиля: {}".format(database.car_table[i].price))
            print("\tЦена дня проката: {}".format(database.car_table[i].rent_price))
            print("\tДата последнего ТО: {:>2}.{:>2}.{:>4}".format(
                database.car_table[i].maintenance_date.day,
                database.car_table[i].maintenance_date.month,
                database.car_table[i].maintenance_date.year))
            print("\tСпециальные отметки: {}".format(database.car_table[i].special_marks))
            print("\tОтметка о возврате: {}".format(database.car_table[i].return_mark))
            print("\tКод марки: {}".format(database.car_table[i].brand_id))

            for j in range(0, main.table_row[const.BRAND_TABLE]):
                if database.car_table[i].brand_id == database.brand_table[j].brand_id:
                    print("\tНаименование марки: {}".format(database.brand_table[j].name))
                    print("\tТехнические характеристики: {}".format(database.brand_table[j].specs))
                    print("\tОписание: {}".format(database.brand_table[j]. description))
                    print("\tКод сотрудника-механика: {}".format(database.car_table[i].employee_id))

            for j in range(0, main.table_row[const.EMPLOYEE_TABLE]):
                if database.car_table[i].employee_id == database.employee_table[j].employee_id:
                    # Для корректного вывода пола
                    if database.employee_table[j].gender == database.Gender.male:
                        gend = "Мужской"
                    else:
                        gend = "Женский"

                    print("\tНомер записи: {}".format(j+1))
                    print("\tКод сотрудника: {}".format(database.employee_table[j]. 
                    employee_id))
                    print("\tФИО: {}".format(database.employee_table[j].name))
                    print("\tВозраст: {}".format(database.employee_table[j].age))
                    print("\tПол: {}".format(gend))
                    print("\tАдрес: {}".format(database.employee_table[j].address))
                    print("\tТелефон: {}".format(database.employee_table[j].phone))
                    print("\tПаспортные данные: {}".format(database.employee_table[j].passport))
                    print("\tКод должности: {}".format(database.employee_table[j].position_id))

                    # Поиск соответствующей должности по коду и дальнейший вывод
                    for k in range(1, main.table_row[const.POSITION_TABLE]):
                        if database.employee_table[j].position_id == database.position_table[k].position_id:
                            print("\tНаименование должности: {}".format(database.position_table[k].name))
                            print("\tОклад: {}".format(database.position_table[k].salary))
                            print("\tОбязанности: {}".format(database.position_table[k].duties))
                            print("\tТребования: {}".format(database.position_table[k].requirements))


def autopark_filter_in_and_off_rent():
    os.system("clear")

    # Вывод автомобилей, находящихся в прокате
    for i in range(0, main.table_row[const.CAR_TABLE]):
        for j in range(0, main.table_row[const.RENT_TABLE]):
            if database.car_table[i].car_id > 0 and database.rent_table[j].car_id > 0:
                if database.car_table[i].car_id == database.rent_table[j].car_id:
                    print("\t\t{} (рег. номер {}) - находится в прокате\n".format(
                        database.car_table[i].car_id,
                        database.car_table[i].reg_number))
                else:
                    print("\t\t{} (рег. номер {}) - не находится в прокате\n".format(
                        database.car_table[i].car_id,
                        database.car_table[i].reg_number))

    mode = input("\n\tАвтомобили в прокате - 1\n\tАвтомобили не в прокате - 2:\n\t -> ")
    for i in range(main.table_row[const.CAR_TABLE]):
        for j in range(main.table_row[const.RENT_TABLE]):
            if (mode == 1 and database.car_table[i].car_id == database.rent_table[i].car_id) or \
               (mode == 2 and database.car_table[i].car_id != database.rent_table[i].car_id):
                print("\n\tОтчет по запросу \"Автопарк\" c фильтром для отображения\n")
                print("\tавтомобилей, находящихся в прокате\n\n")
                print("\tНомер записи: {}".format(i+1))
                print("\tКод автомобиля: {}".format(database.car_table[i].car_id))
                print("\tРегистрационный номер: {}".format(database.car_table[i].reg_number))
                print("\tНомер кузова: {}".format(database.car_table[i].body_number))
                print("\tНомер двигателя: {}".format(database.car_table[i].engine_number))
                print("\tГод выпуска: {}".format(database.car_table[i].release_year))
                print("\tПробег: {}".format(database.car_table[i].mileage))
                print("\tЦена автомобиля: {}".format(database.car_table[i].price))
                print("\tЦена дня проката: {}".format(database.car_table[i].rent_price))
                print("\tДата последнего ТО: {:>2}.{:>2}.{:>4}".format(
                    database.car_table[i].maintenance_date.day,
                    database.car_table[i].maintenance_date.month,
                    database.car_table[i].maintenance_date.year))
                print("\tСпециальные отметки: {}".format(database.car_table[i].special_marks))
                print("\tОтметка о возврате: {}".format(database.car_table[i].return_mark))
                print("\tКод марки: {}".format(database.car_table[i].brand_id))

                for l in range(0, main.table_row[const.BRAND_TABLE]):
                    if database.car_table[i].brand_id == database.brand_table[l].brand_id:
                        print("\tНаименование марки: {}".format(database.brand_table[l].name))
                        print("\tТехнические характеристики: {}".format(database.brand_table[l].specs))
                        print("\tОписание: {}".format(database.brand_table[l].description))
                        print("\tКод сотрудника-механика: {}".format(database.car_table[i].employee_id))

                for l in range(0, main.table_row[const.EMPLOYEE_TABLE]):
                    if database.car_table[i].employee_id == database.employee_table[l].employee_id:
                        # Для корректного вывода пола
                        if database.employee_table[l].gender == database.Gender.male:
                            gend = "Мужской"
                        else:
                            gend = "Женский"

                        print("\tНомер записи: {}".format(l+1))
                        print("\tКод сотрудника: {}".format(database. 
                        employee_table[l].employee_id))
                        print("\tФИО: {}".format(database.employee_table[l].name))
                        print("\tВозраст: {}".format(database.employee_table[l].age))
                        print("\tПол: {}".format(gend))
                        print("\tАдрес: {}".format(database.employee_table[l].address))
                        print("\tТелефон: {}".format(database.employee_table[l].phone))
                        print("\tПаспортные данные: {}".format(database.employee_table[l].passport))
                        print("\tКод должности: {}".format(database.employee_table[l].position_id))

                        # Поиск соответствующей должности по коду и дальнейший вывод
                        for k in range(1, main.table_row[const.POSITION_TABLE]):
                            if database.employee_table[l].position_id == database.position_table[k].position_id:
                                print("\tНаименование должности: {}".format(database.position_table[k].name))
                                print("\tОклад: {}".format(database.position_table[k].salary))
                                print("\tОбязанности: {}".format(database.position_table[k].duties))
                                print("\tТребования: {}".format(database.position_table[k].requirements))


def autopark_filter_specific_delivery_and_return_date():
    os.system("clear")

    # Ввод
    mode = input("\n\tДата выдачи - 1\n\tДата возврата - 2:\n\t -> ")
    print("\n\tВведите дату (ДД.ММ.ГГГГ)")
    d = input("\t\tДень -> ")
    m = input("\t\tМесяц -> ")
    y = input("\t\tГод -> ")

    print("\n\tОтчет по запросу \"Автопарк\" c фильтром для отображения")
    print("\tавтомобилей, выданных и возвращённых в определённую дату\n")
    for i in range(0, main.table_row[const.CAR_TABLE]):
        for l in range(0, main.table_row[const.RENT_TABLE]):
            if (mode == 1 and d == database.rent_table[i].delivery_date.day \
                and m == database.rent_table[i].delivery_date.month \
                and y == database.rent_table[i].delivery_date.year) \
                or \
               (mode == 2 and d == database.rent_table[i].return_date.day \
               and m == database.rent_table[i].return_date.month \
               and y == database.rent_table[i].return_date.year):
                print("\tНомер записи: {}".format(i+1))
                print("\tКод автомобиля: {}".format(database.car_table[i].car_id))
                print("\tРегистрационный номер: {}".format(database.car_table[i].reg_number))
                print("\tНомер кузова: {}".format(database.car_table[i].body_number))
                print("\tНомер двигателя: {}".format(database.car_table[i].engine_number))
                print("\tГод выпуска: {}".format(database.car_table[i].release_year))
                print("\tПробег: {}".format(database.car_table[i].mileage))
                print("\tЦена автомобиля: {}".format(database.car_table[i].price))
                print("\tЦена дня проката: {}".format(database.car_table[i].rent_price))
                print("\tДата последнего ТО: {:>2}.{:>2}.{:>4}".format(
                    database.car_table[i].maintenance_date.day,
                    database.car_table[i].maintenance_date.month,
                    database.car_table[i].maintenance_date.year))
                print("\tСпециальные отметки: {}".format(database.car_table[i].special_marks))
                print("\tОтметка о возврате: {}".format(database.car_table[i].return_mark))
                print("\tКод марки: {}".format(database.car_table[i].brand_id))

                for j in range(0, main.table_row[const.BRAND_TABLE]):
                    if database.car_table[i].brand_id == database.brand_table[j].brand_id:
                        print("\tНаименование марки: {}".format(database.brand_table[j].name))
                        print("\tТехнические характеристики: {}".format(database.brand_table[j].specs))
                        print("\tОписание: {}".format(database.brand_table[j].description))
                        print("\tКод сотрудника-механика: {}".format(database.car_table[i].employee_id))

                for j in range(0, main.table_row[const.EMPLOYEE_TABLE]):
                    if database.car_table[i].employee_id == database.employee_table[j].employee_id:
                        # Для корректного вывода пола
                        if database.employee_table[j].gender == database.Gender.male:
                            gend = "Мужской"
                        else:
                            gend = "Женский"

                        print("\tНомер записи: {}".format(j+1))
                        print("\tКод сотрудника: {}".format(database.employee_table[j].employee_id))
                        print("\tФИО: {}".format(database.employee_table[j].name))
                        print("\tВозраст: {}".format(database.employee_table[j].age))
                        print("\tПол: {}".format(gend))
                        print("\tАдрес: {}".format(database.employee_table[j].address))
                        print("\tТелефон: {}".format(database.employee_table[j].phone))
                        print("\tПаспортные данные: {}".format(database.employee_table[j].passport))
                        print("\tКод должности: {}".format(database.employee_table[j].position_id))

                        # Поиск соответствующей должности по коду и дальнейший вывод
                        for k in range(1, main.table_row[const.POSITION_TABLE]):
                            if database.employee_table[j].position_id == database.position_table[k].position_id:
                                print("\tНаименование должности: {}".format(database.position_table[k].name))
                                print("\tОклад: {}".format(database.position_table[k].salary))
                                print("\tОбязанности: {}".format(database.position_table[k].duties))
                                print("\tТребования: {}".format(database.position_table[k].requirements))


def autopark_filter_paid_and_unpaid_rented_cars():
    os.system("clear")

    for i in range(0, main.table_row[const.RENT_TABLE]):
        print("\t{} - Отметка об оплате: {}".format(
            database.rent_table[i].car_id,
            database.rent_table[i].payment_mark))

    temp = input("\n\t Введите код автомобиля -> ")

    print("\n\tОтчет по запросу \"Автопарк\"\n")
    for i in range(0, main.table_row[const.CAR_TABLE]):
        if temp == database.car_table[i].car_id:
            print("\tНомер записи: {}".format(i+1))
            print("\tКод автомобиля: {}".format(database.car_table[i].car_id))
            print("\tРегистрационный номер: {}".format(database.car_table[i].reg_number))
            print("\tНомер кузова: {}".format(database.car_table[i].body_number))
            print("\tНомер двигателя: {}".format(database.car_table[i].engine_number))
            print("\tГод выпуска: {}".format(database.car_table[i].release_year))
            print("\tПробег: {}".format(database.car_table[i].mileage))
            print("\tЦена автомобиля: {}".format(database.car_table[i].price))
            print("\tЦена дня проката: {}".format(database.car_table[i].rent_price))
            print("\tДата последнего ТО: {:>2}.{:>2}.{:>4}".format(
                database.car_table[i].maintenance_date.day,
                database.car_table[i].maintenance_date.month,
                database.car_table[i].maintenance_date.year))
            print("\tСпециальные отметки: {}".format(database.car_table[i].special_marks))
            print("\tОтметка о возврате: {}".format(database.car_table[i].return_mark))
            print("\tКод марки: {}".format(database.car_table[i].brand_id))

            for j in range(0, main.table_row[const.BRAND_TABLE]):
                if database.car_table[i].brand_id == database.brand_table[j].brand_id:
                    print("\tНаименование марки: {}".format(database.brand_table[j].name))
                    print("\tТехнические характеристики: {}".format(database.brand_table[j].specs))
                    print("\tОписание: {}".format(database.brand_table[j].description))
                    print("\tКод сотрудника-механика: {}".format(database.car_table[i].employee_id))

            for j in range(0, main.table_row[const.EMPLOYEE_TABLE]):
                if database.car_table[i].employee_id == database.employee_table[j].employee_id:
                    # Для корректного вывода пола
                    if database.employee_table[j].gender == database.Gender.male:
                        gend = "Мужской"
                    else:
                        gend = "Женский"
                    print("\tНомер записи: {}".format(j+1))
                    print("\tКод сотрудника: {}".format(database.employee_table[j].employee_id))
                    print("\tФИО: {}".format(database.employee_table[j].name))
                    print("\tВозраст: {}".format(database.employee_table[j].age))
                    print("\tПол: {}".format(gend))
                    print("\tАдрес: {}".format(database.employee_table[j].address))
                    print("\tТелефон: {}".format(database.employee_table[j].phone))
                    print("\tПаспортные данные: {}".format(database.employee_table[j].passport))
                    print("\tКод должности: {}".format(database.employee_table[j].position_id))

                    # Поиск соответствующей должности по коду и дальнейший вывод
                    for k in range(1, main.table_row[const.POSITION_TABLE]):
                        if database.employee_table[j].position_id == database.position_table[k].position_id:
                            print("\tНаименование должности: {}".format(database.position_table[k].name))
                            print("\tОклад: {}".format(database.position_table[k].salary))
                            print("\tОбязанности: {}".format(database.position_table[k].duties))
                            print("\tТребования: {}".format(database.position_table[k].requirements))