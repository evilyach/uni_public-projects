* Лабораторная работа №1
Выполнил лабораторную работу №1: студент группы 641 Чесалин Илья Евгеньевич.  
Проверил: доцент кафедры САПР Телков И.А.  
Бригада №9.

** Иконки
Так как данные в архиве иконки низкого разрешения, заменил их на иконки, взятые с сайта icons8.com. Они свободно распространяются для некоммерческого использования. Условия лицензии выполнены.

** СОХРАНЕНИЕ
В варианте бригады №9 необходимо сохранить файл, используя расширение .gif.  
По умолчанию, Qt не поддерживает сохранение файлов в формате .gif, в соответствии с [документацией для класса QImage](https://doc.qt.io/qt-5/qimage.html):

```
The complete list of supported file formats are available through the QImageReader::supportedImageFormats() and QImageWriter::supportedImageFormats() functions. New file formats can be added as plugins. By default, Qt supports the following formats:

Format	Description								Qt's support
BMP		Windows Bitmap							Read/write
GIF		Graphic Interchange Format (optional)	Read
JPG		Joint Photographic Experts Group		Read/write
...
```

Несмотря на фразу "new file formats can be added as plugins", к сожалению, рабочих плагинов для сохранения *изображений* в формате .gif нет.  
В качестве решения можно либо использовать скрипт, например, на Python, и вызывать его из программы, однако для этого необходимо устанавливать сторонние библиотеки.  
Я избрал решение использовать библиотеку ffmpeg, ее не нужно устанавливать, однако она весит 64 Мб, поэтому ее необходимо [скачать](https://ffmpeg.zeranoe.com/builds/win64/static/ffmpeg-20190826-0821bc4-win64-static.zip) и распаковать в корень проекта, где находится исполняемый файл.
Если необходимо прямо в программе сделать механизм скачивания и распаковки этого файла, прошу отписаться, однако для этого потребуется написать еще больше кода, чем было написано, ибо Qt требует самостоятельной реализации скачивания по ссылкам.