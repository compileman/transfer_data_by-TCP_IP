#include  "set_parameter_structure.h"


///////////////////////////////////////////////////////////////////////////
/////////////////  struct Set_Parameter_Structure_1Byte { ... :

///конструктор
Set_Parameter_Structure_1Byte::Set_Parameter_Structure_1Byte( ushort parameter_ident , uchar parameter_value_buffer ):
    ParameterIdent( parameter_ident ), ParameterValueBuffer( parameter_value_buffer ) {

    ///Выделяем память под запасной блок памяти в структуре:
    this->UnusedPad = (void*) ::operator new ( sizeof( uchar ) );//// 8 бит

};


///деструктор
Set_Parameter_Structure_1Byte::~Set_Parameter_Structure_1Byte(){

    ///Удалям запасной блок памяти в структуре:
    operator delete[] ( UnusedPad );
    //////Верно такое удаление для области динамической памяти?

};



///////////////////////////////////////////////////////////////////////////
/////////////////  struct Set_Parameter_Structure { ... :



///консруктор
Set_Parameter_Structure::Set_Parameter_Structure(ushort start_keyword, ushort widget_ident ,
                                                   ushort parameter_ident, uchar parameter_value_buffer):
  StartKeyword(start_keyword),WidgetIdent(widget_ident)
{
    ///Выделяем память под запасной блок памяти в структуре:
    this->UnusedPad = (void*) ::operator new ( sizeof( ushort ) );/// 16 бит

    ///тут задаём тип параметра: parameter_ident , значение параметра : parameter_value_buffer ) :
    set_color_structure = new Set_Parameter_Structure_1Byte( parameter_ident , parameter_value_buffer);

}


///деструктор
Set_Parameter_Structure::~Set_Parameter_Structure(){

    ///Удалям запасной блок памяти в структуре:
    operator delete[] ( UnusedPad );
    //////Верно такое удаление для области динамической памяти?

    delete set_color_structure;

};



