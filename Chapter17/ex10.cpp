/*
    Посмотрите на решение упр. 7. Может ли ввод вызвать переполнение массива; иначе говоря, можете ли 
    вы ввести больше символов, чем выделено памяти (это серьезная ошибка)? Что произойдет, если вы 
    попытаетесь ввести больше символов, чем выделено памяти?

    Память увеличивается после ввода каждого символа, следовательно, программа работает корректно.
    Если попытаться ввести больше символов, чем выделено памяти, то данные будут записаны за пределами
    выделенной области памяти, что может повредить другие данные в памяти, привести к неопределённому 
    поведению программы, или даже к её аварийному завершению.
*/