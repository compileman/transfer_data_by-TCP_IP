#ifndef SET_PARAMETER_STRUCTURE_H
#define SET_PARAMETER_STRUCTURE_H



typedef unsigned short ushort;
typedef unsigned char uchar;


///////////////////////////////////////////////////////////////////////////
/////////////////  struct Set_Parameter_Structure_1Byte :


struct Set_Parameter_Structure_1Byte {

public:
    Set_Parameter_Structure_1Byte( ushort parameter_ident , uchar parameter_value_buffer );
    ~Set_Parameter_Structure_1Byte();

  ushort ParameterIdent;
  uchar ParameterValueBuffer;
  void* UnusedPad;

};


///////////////////////////////////////////////////////////////////////////
/////////////////  struct Set_Parameter_Structure :


struct Set_Parameter_Structure {

    Set_Parameter_Structure( ushort start_keyword, ushort widget_ident , ushort parameter_ident , uchar parameter_value_buffer );
    ~Set_Parameter_Structure();

  ushort StartKeyword;
  ushort CommandSize;
  ushort WidgetIdent;
  void* UnusedPad;

  Set_Parameter_Structure_1Byte* set_color_structure;

};

#endif // SET_PARAMETER_STRUCTURE_H
