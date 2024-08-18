#include "GUI.h"

using namespace Graph_lib;

class AirplaneWindow : public Graph_lib::Window
{
public:
    AirplaneWindow(Point xy, int w, int h, const string& title); 
    
private:
    // Данные
    unsigned int planeX;
    Image Plane;
    
    // Виджеты
    Button Start;
    Button Stop;
    
    // Обратные вызовы
    void CallCbStart();
    void CallCbStop();
    
    static void CbStartFlight(void* p);
    
    void StartFlight();
};
