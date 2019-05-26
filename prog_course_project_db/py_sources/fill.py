# -*- coding: utf-8 -*-

# Подключение модулей
import main
import const
import database
import out


# Класс исключения из-за неправильного пола
class GenderError(Exception):
    def __init__(self, value):
        self.value = value
    def __str__(self):
        return repr(self.value)


# Класс исключения из-за неправильного кода
class BadIdError(Exception):
    def __init__(self, value):
        self.value = value
    def __str__(self):
        return repr(self.value)


def check_date(date):
    if date.day < 0 or date.day > 31 or date.month < 0 or date.month > 12 or date.year < 0:
        print("ПРЕДУПРЕЖДЕНИЕ: Скорее всего, введена не дата")


def input_gender(desc):
    temp = input(desc)
    if temp[0] == "m" or temp[0] == "M":
        return database.Gender.male
    elif temp[0] == "f" or temp[0] == "F":
        return database.Gender.female
    else:
        raise GenderError


def input_date(date, desc):
    print(desc)
    date.day = input("\tВведите день -> ")
    date.month = input("\tВведите месяц -> ")
    date.year = input("\tВведите год -> ")


def fill_employee_table(row):
    database.employee_table.append(database.EmployeeT())
    main.activated = 1

    try:
        database.employee_table[row].employee_id = int(input("Введите код сотрудника (больше нуля) -> "))
        if database.employee_table[row].employee_id <= 0:
            raise BadIdError
        database.employee_table[row].name = input("Введите ФИО -> ")
        database.employee_table[row].age = int(input("Введите возраст -> "))
        if database.employee_table[row].age < 0:
            print("ПРЕДУПРЕЖДЕНИЕ: Скорее всего, введен не возраст")
        database.employee_table[row].gender = input_gender("Введите пол -> ")
        database.employee_table[row].address = input("Введите адрес -> ")
        database.employee_table[row].phone = input("Введите телефон -> ")
        database.employee_table[row].passport = input("Введите паспортные данные -> ")
        out.print_position_info()
        database.employee_table[row].position_id = int(input("Введите код должности (больше нуля) -> "))
        if database.employee_table[row].position_id < 0:
            raise BadIdError
        main.table_row[const.EMPLOYEE_TABLE] += 1
    except ValueError:
        database.employee_table.pop()
        print("ОШИБКА: не удалось распознать в строке целочисленное значение")
    except GenderError:
        database.employee_table.pop()
        print("ОШИБКА: не удалось распознать пол")
    except BadIdError:
        database.employee_table.pop()
        print("ОШИБКА: введен код меньше нуля, таблица не добавится")


def fill_position_table(row):
    database.position_table.append(database.PositionT())
    main.activated = 1

    try:
        database.position_table[row].position_id = int(input("Введите код должности (больше нуля) -> "))
        if database.position_table[row].position_id <= 0:
            raise BadIdError
        database.position_table[row].name = input("Введите наименование -> ")
        database.position_table[row].salary = int(input("Введите оклад -> "))
        database.position_table[row].duties = input("Введите обязанности -> ")
        database.position_table[row].requirements = input("Введите требования -> ")
        main.table_row[const.POSITION_TABLE] += 1
    except ValueError:
        database.position_table.pop()
        print("ОШИБКА: не удалось распознать в строке целочисленное значение")


def fill_brand_table(row):
    database.brand_table.append(database.BrandT())
    main.activated = 1

    try:
        database.brand_table[row].brand_id = int(input("Введите код марки (больше нуля) -> "))
        if database.brand_table[row].brand_id <= 0:
            raise BadIdError
        database.brand_table[row].name = input("Введите наименование -> ")
        database.brand_table[row].specs = input("Введите технические характеристики -> ")
        database.brand_table[row].description = input("Введите описание -> ")
        main.table_row[const.BRAND_TABLE] += 1
    except ValueError:
        database.brand_table.pop()
        print("ОШИБКА: не удалось распознать в строке целочисленное значение")


def fill_service_table(row):
    database.service_table.append(database.ServiceT())
    main.activated = 1
    try:
        database.service_table[row].service_id = int(input("Введите код услуги (больше нуля) -> "))
        if database.service_table[row].service_id <= 0:
            raise BadIdError
        database.service_table[row].name = input("Введите наименование -> ")
        database.service_table[row].description = input("Введите описание -> ")
        database.service_table[row].price = int(input("Введите цену -> "))
        main.table_row[const.SERVICE_TABLE] += 1
    except ValueError:
        database.brand_table.pop()
        print("ОШИБКА: не удалось распознать в строке целочисленное значение")


def fill_car_table(row):
    database.car_table.append(database.CarT())
    main.activated = 1

    try:
        database.car_table[row].car_id = int(input("Введите код автомобиля (больше нуля) -> "))
        if database.car_table[row].car_id <= 0:
            raise BadIdError
        out.print_brand_info()
        database.car_table[row].brand_id = int(input("Введите код марки (больше нуля) -> "))
        if database.car_table[row].brand_id <= 0:
            raise BadIdError
        out.print_employee_info()
        database.car_table[row].employee_id = int(input("Введите код сотрудникамеханика (больше нуля) -> "))
        if database.car_table[row].employee_id <= 0:
            raise BadIdError
        database.car_table[row].reg_number = int(input("Введите регистрационный номер -> "))
        database.car_table[row].body_number = int(input("Введите номер кузова -> "))
        database.car_table[row].engine_number = int(input("Введите номер двигателя -> "))
        database.car_table[row].release_year = int(input("Введите год выпуска -> "))
        database.car_table[row].mileage = int(input("Введите пробег -> "))
        database.car_table[row].price = int(input("Введите цену автомобиля -> "))
        database.car_table[row].rent_price = int(input("Введите цену дня проката -> "))
        input_date(database.car_table[row].maintenance_date, "Введите дату последнего ТО")
        check_date(database.car_table[row].maintenance_date)
        database.car_table[row].special_marks = input("Введите специальные отметки -> ")
        database.car_table[row].return_mark = input("Введите отметку о возврате ->")
        main.table_row[const.CAR_TABLE] += 1
    except ValueError:
        database.car_table.pop()
        print("ОШИБКА: не удалось распознать в строке целочисленное значение")


def fill_client_table(row):
    database.client_table.append(database.ClientT())
    main.activated = 1

    try:
        database.client_table[row].client_id = int(input("Введите код клиента (больше нуля) -> "))
        if database.client_table[row].client_id <= 0:
            raise BadIdError
        database.client_table[row].name = input("Введите ФИО -> ")
        database.client_table[row].gender = input_gender("Введите пол -> ")
        input_date(database.client_table[row].birth_date, "Введите дату рождения")
        check_date(database.client_table[row].birth_date)
        database.client_table[row].address = input("Введите адрес -> ")
        database.client_table[row].phone = input("Введите телефон -> ")
        database.client_table[row].passport = input("Введите паспортные данные -> ")
        main.table_row[const.CLIENT_TABLE] += 1
    except ValueError:
        database.client_table.pop()
        print("ОШИБКА: не удалось распознать в строке целочисленное значение")
    except GenderError as error:
        database.client_table.pop()
        print(error)


def fill_rent_table(row):
    database.rent_table.append(database.RentT())
    main.activated = 1

    try:
        out.print_car_info()
        database.rent_table[row].car_id = int(input("Введите код автомобиля (больше нуля) -> "))
        if database.rent_table[row].car_id <= 0:
            raise BadIdError
        out.print_client_info()
        database.rent_table[row].client_id = int(input("Введите код клиента (больше нуля) -> "))
        if database.rent_table[row].client_id <= 0:
            raise BadIdError
        out.print_employee_info()
        database.rent_table[row].employee_id = int(input("Введите код сотрудника (больше нуля) -> "))
        if database.rent_table[row].employee_id <= 0:
            raise BadIdError
        out.print_service_info()
        database.rent_table[row].service1_id = int(input("Введите код услуги 1 (больше нуля) -> "))
        if database.rent_table[row].service1_id <= 0:
            raise BadIdError
        database.rent_table[row].service2_id = int(input("Введите код услуги 2 (больше нуля) -> "))
        if database.rent_table[row].service2_id <= 0:
            raise BadIdError
        database.rent_table[row].service3_id = int(input("Введите код услуги 3 (больше нуля) -> "))
        if database.rent_table[row].service3_id <= 0:
            raise BadIdError
        input_date(database.rent_table[row].delivery_date, "Введите дату выдачи")
        check_date(database.rent_table[row].delivery_date)
        database.rent_table[row].rent_time = int(input("Введите срок проката -> "))
        input_date(database.rent_table[row].return_date, "Введите дату возврата")
        check_date(database.rent_table[row].return_date)
        database.rent_table[row].rent_price = int(input("Введите цену проката -> "))
        database.rent_table[row].payment_mark = input("Введите отметку об оплате -> ")
        main.table_row[const.RENT_TABLE] += 1
    except ValueError:
        database.client_table.pop()
        print("ОШИБКА: не удалось распознать в строке целочисленное значение")