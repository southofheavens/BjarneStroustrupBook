# Проектирование графических классов  

Я пропустил 6-7, 10-14 и 17 задания потому, что это задания, которые связаны с рисованием. Не очень хочется тратить на это время, я уже достаточно порисовал, пока изучал 12-ю и 13-ю главы.  

**How to compile**  
clang++ -std=c++14 -I/usr/local/include -L/usr/local/lib -lfltk -lfltk_images \
NameOfProgram.cpp ../src/Simple_window.cpp ../src/Graph.cpp ../src/GUI.cpp ../src/Window.cpp \
../src/ch14tools.cpp
